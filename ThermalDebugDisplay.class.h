/* *\
 * General ASCII Codes
\* */
#define THERMAL_ANSIESC_BEL L"\x07"	// Terminal Bell
#define THERMAL_ANSIESC_BS L"\x08"	// Backspace
#define THERMAL_ANSIESC_HT L"\x09"	// Horizontal Tab
#define THERMAL_ANSIESC_LF L"\x0a"	// Newline
#define THERMAL_ANSIESC_VT L"\x0b"	// Vertical Tab
#define THERMAL_ANSIESC_FF L"\x0c"	// Formfeed / New Page
#define THERMAL_ANSIESC_CR L"\x0d"	// Carriage Return
#define THERMAL_ANSIESC_ESC L"\x1b"	// Escape Character
#define THERMAL_ANSIESC_DEL L"\x7f"	// Delete Character

/* *\
 * Cursor Control Codes
\* */
#define THERMAL_ANSIESC_CURSOR_HOME L"\x1b[H"	// Go to position 0,0
#define THERMAL_ANSIESC_CURSOR_GOTO(l, c) L"\x1b[" #l L";" #c L"H"	// go to arbitrary position
#define THERMAL_ANSIESC_CURSOR_JUMPTO(l, c) L"\x1b[" #l L";" #c L"f"	// go to arbitrary position
#define THERMAL_ANSIESC_CURSOR_UP(amt) L"\x1b[" #amt L"A"	// Move cursor up x amount
#define THERMAL_ANSIESC_CURSOR_DOWN(amt) L"\x1b[" #amt L"B"	// Move cursor down x amount
#define THERMAL_ANSIESC_CURSOR_RIGHT(amt) L"\x1b[" #amt L"C"	// Move cursor right x amount
#define THERMAL_ANSIESC_CURSOR_LEFT(amt) L"\x1b[" #amt L"D"	// Move cursor left x amount
#define THERMAL_ANSIESC_CURSOR_DOWNRST(amt) L"\x1b[" #amt L"E"	// Move line down x amount, and move cursor to start of line.
#define THERMAL_ANSIESC_CURSOR_UPRST(amt) L"\x1b[" #amt L"F"	// Move line up x amount, and move cursor to start of line.
#define THERMAL_ANSIESC_CURSOR_COL(pos) L"\x1b[" #pos L"G"	// Move cursor to column position x.
#define THERMAL_ANSIESC_CURSOR_REQUEST_POSITION L"\x1b[6n"	// prints the cursor position as \x1b[#;#R
#define THERMAL_ANSIESC_CURSOR_UPONE L"\x1b M"	// Move the cursor up one line and scroll if required.
#define THERMAL_ANSIESC_CURSOR_SAVEPOS L"\x1b 7"	// Save the position of the cursor
#define THERMAL_ANSIESC_CURSOR_RESTORPOS L"\x1b 8"	// restore the postion of the cursor to the last save
#define THERMAL_ANSIESC_CURSOR_SAVEPOS_SCO L"\x1b[s"	// Compatibility alternative for the above 2
#define THERMAL_ANSIESC_CURSOR_RESTORPOS_SCO L"\x1b[u"	// Compatibility alternative for the above 2



struct thermalDebugDisplayStruct{
	int display_width;
	int display_height;
	size_t display_buffer_size;
	wchar_t *display_buffer;
};
typedef struct thermalDebugDisplayStruct thermdisp_t;


class ThermalDebugDisplay{
	private:
		thermdisp_t data;
		/*
		 * This function works only in linux terminals.
		 * A #ifdef statement can be used to implement windows
		 * support. Which I'm not doing right now 🐧
		 * */
		void fetchWidthHeight(void){
			struct winsize w;
			ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
			this->data.display_width = w.ws_col;
			this->data.display_height = w.ws_row;
		}

		void alternateScreen(bool enable){
			if(enable){
				wprintf(L"\033[?1049h");
			}else{
				wprintf(L"\033[?1049l");
			}
		}

	public:
		ThermalDebugDisplay(void){
			setlocale(LC_ALL, "en_US.UTF-8");
			this->data.display_buffer = NULL;
			this->data.display_buffer_size = 0;
			this->fetchWidthHeight();

		}	

		~ThermalDebugDisplay(){
			if(this->data.display_buffer != NULL){
				delete[] this->data.display_buffer;
				this->data.display_buffer = NULL;
			}
		}

		int getWidth(void){
			this->fetchWidthHeight();
			return this->data.display_width;
		}
		int getHeight(void){
			this->fetchWidthHeight();
			return this->data.display_height;
		}

		bool startDisplay(void){
			this->alternateScreen(true);

			return true;
		}

		bool stopDisplay(void){
			this->alternateScreen(false);
			return true;
		}

		bool draw(void){
			wprintf(L"%ls\n", THERMAL_ANSIESC_CURSOR_GOTO(4, 4));	
			return true;	
		}

};
