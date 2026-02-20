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

/* *\
 * Erase Function Codes
\* */
#define THERMAL_ANSIESC_ERASE_IN_DISPLAY L"\x1b[J"
#define THERMAL_ANSIESC_ERASE_CURSOR_TO_EOS L"\x1b[0J"
#define THERMAL_ANSIESC_ERASE_CURSOR_TO_BOS L"\x1b[1J"
#define THERMAL_ANSIESC_ERASE_SCREEN L"\x1b[2J"
#define THERMAL_ANSIESC_ERASE_SAVED_LINES L"\x1b[3J"
#define THERMAL_ANSIESC_ERASE_IN_LINE L"\x1b[K"
#define THERMAL_ANSIESC_ERASE_CURSOR_TO_EOL L"\x1b[0K"
#define THERMAL_ANSIESC_ERASE_CURSOR_TO_SOL L"\x1b[1K"
#define THERMAL_ANSIESC_ERASE_LINE L"\x1b[2K"

/* *\
 * Colors and Graphics Modes
\* */
#define THERMAL_ANSIESC_GRAPHICS_RESET L"0"
#define THERMAL_ANSIESC_GRAPHICS_BOLD L"1"
#define THERMAL_ANSIESC_GRAPHICS_BOLD_RESET L"22"
#define THERMAL_ANSIESC_GRAPHICS_FAINT L"2"
#define THERMAL_ANSIESC_GRAPHICS_FAINT_RESET L"22"
#define THERMAL_ANSIESC_GRAPHICS_ITALIC L"3"
#define THERMAL_ANSIESC_GRAPHICS_ITALIC_RESET L"23"
#define THERMAL_ANSIESC_GRAPHICS_UNDERLINE L"4"
#define THERMAL_ANSIESC_GRAPHICS_UNDERLINE_RESET L"24"
#define THERMAL_ANSIESC_GRAPHICS_BLINKING L"5"
#define THERMAL_ANSIESC_GRAPHICS_BLINKING_RESET L"25"
#define THERMAL_ANSIESC_GRAPHICS_REVERSE L"7"
#define THERMAL_ANSIESC_GRAPHICS_REVERSE_RESET L"27"
#define THERMAL_ANSIESC_GRAPHICS_INVISIBLE L"8"
#define THERMAL_ANSIESC_GRAPHICS_INVISIBLE_RESET L"28"
#define THERMAL_ANSIESC_GRAPHICS_STRIKETHROUGH L"9"
#define THERMAL_ANSIESC_GRAPHICS_STRIKETHROUGH_RESET L"29"

#define THERMAL_ANSIESC_GRAPHICS_FGBLACK L"30"
#define THERMAL_ANSIESC_GRAPHICS_BGBLACK L"40"
#define THERMAL_ANSIESC_GRAPHICS_FGRED L"31"
#define THERMAL_ANSIESC_GRAPHICS_BGRED L"41"
#define THERMAL_ANSIESC_GRAPHICS_FGGREEN L"32"
#define THERMAL_ANSIESC_GRAPHICS_BGGREEN L"42"
#define THERMAL_ANSIESC_GRAPHICS_FGYELLOW L"33"
#define THERMAL_ANSIESC_GRAPHICS_BGYELLOW L"43"
#define THERMAL_ANSIESC_GRAPHICS_FGBLUE L"34"
#define THERMAL_ANSIESC_GRAPHICS_BGBLUE L"44"
#define THERMAL_ANSIESC_GRAPHICS_FGMAGENTA L"35"
#define THERMAL_ANSIESC_GRAPHICS_BGMAGENTA L"45"
#define THERMAL_ANSIESC_GRAPHICS_FGCYAN L"36"
#define THERMAL_ANSIESC_GRAPHICS_BGCYAN L"46"
#define THERMAL_ANSIESC_GRAPHICS_FGWHITE L"37"
#define THERMAL_ANSIESC_GRAPHICS_BGWHITE L"47"
#define THERMAL_ANSIESC_GRAPHICS_FGDEFAULT L"39"
#define THERMAL_ANSIESC_GRAPHICS_BGDEFAULT L"49"
#define THERMAL_ANSIESC_GRAPHICS_FGRESET L"0"
#define THERMAL_ANSIESC_GRAPHICS_BGRESET L"0"

// aixterm colors
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_FGBLACK L"90"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_BGBLACK L"100"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_FGRED L"91"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_BGRED L"101"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_FGGREEN L"92"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_BGGREEN L"102"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_FGYELLOW L"93"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_BGYELLOW L"103"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_FGBLUE L"94"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_BGBLUE L"104"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_FGMAGENTA L"95"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_BGMAGENTA L"105"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_FGCYAN L"96"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_BGCYAN L"106"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_FGWHITE L"97"
#define THERMAL_ANSIESC_GRAPHICS_BRIGHT_BGWHITE L"107"


#define THERMAL_ANSIESC_GRAPHICS_CELL(mode, fg, bg) L"\x1b[" #mode L";" #fg L";" #bg L"m"
#define THERMAL_ANSIESC_GRAPHICS_BGCOLOR_256(color_id) L"\x1b[48;5;" #color_id L"m"
#define THERMAL_ANSIESC_GRAPHICS_FGCOLOR_256(color_id) L"\x1b[38;5;" #color_id L"m"
#define THERMAL_ANSIESC_GRAPHICS_FGCOLOR_RGB(r, g, b) L"\x1b[38;2;" #r L";" #g L";" #b L"m"
#define THERMAL_ANSIESC_GRAPHICS_BGCOLOR_RGB(r, g, b) L"\x1b[48;2;" #r L";" #g L";" #b L"m"

/* *\
 * Screen Mode Codes
\* */
#define THERMAL_ANSIESC_SCREENMODE_SET(val) L"\x1b[=" #val L"h"
#define THERMAL_ANSIESC_SCREENMODE_UNSET(val) L"\x1b[=" #val L"l"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_40x25 L"\x1b[=0h"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_40x25_RESET L"\x1b[=0l"
#define THERMAL_ANSIESC_SCREENMODE_COLOR_40x25 L"\x1b[=1h"
#define THERMAL_ANSIESC_SCREENMODE_COLOR_40x25_RESET L"\x1b[=1l"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_80x25 L"\x1b[=2h"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_80x25_RESET L"\x1b[=2l"
#define THERMAL_ANSIESC_SCREENMODE_COLOR_80x25 L"\x1b[=3h"
#define THERMAL_ANSIESC_SCREENMODE_COLOR_80x25_RESET L"\x1b[=3l"
#define THERMAL_ANSIESC_SCREENMODE_4COLOR_320x200 L"\x1b[=4h"
#define THERMAL_ANSIESC_SCREENMODE_4COLOR_320x200_RESET L"\x1b[=4l"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_320x200 L"\x1b[=5h"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_320x200_RESET L"\x1b[=5l"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_640x200 L"\x1b[=6h"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_640x200_RESET L"\x1b[=6l"
#define THERMAL_ANSIESC_SCREENMODE_LINEWRAP L"\x1b[=7h"
#define THERMAL_ANSIESC_SCREENMODE_LINEWRAP_RESET L"\x1b[=7l"
#define THERMAL_ANSIESC_SCREENMODE_COLOR_320x200 L"\x1b[=13h"
#define THERMAL_ANSIESC_SCREENMODE_COLOR_320x200_RESET L"\x1b[=13l"
#define THERMAL_ANSIESC_SCREENMODE_16COLOR_640x200 L"\x1b[=14h"
#define THERMAL_ANSIESC_SCREENMODE_16COLOR_640x200_RESET L"\x1b[=14l"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_640x350 L"\x1b[=15h"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_640x350_RESET L"\x1b[=15l"
#define THERMAL_ANSIESC_SCREENMODE_COLOR_640x350 L"\x1b[=16h"
#define THERMAL_ANSIESC_SCREENMODE_COLOR_640x350_RESET L"\x1b[=16l"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_640x480 L"\x1b[=17h"
#define THERMAL_ANSIESC_SCREENMODE_MONOCHROME_640x480_RESET L"\x1b[=17l"
#define THERMAL_ANSIESC_SCREENMODE_COLOR_640x480 L"\x1b[=18h"
#define THERMAL_ANSIESC_SCREENMODE_COLOR_640x480_RESET L"\x1b[=18l"
#define THERMAL_ANSIESC_SCREENMODE_256COLOR_320x200 L"\x1b[=19h"
#define THERMAL_ANSIESC_SCREENMODE_256COLOR_320x200_RESET L"\x1b[=19l"


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
