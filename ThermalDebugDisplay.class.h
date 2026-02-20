#include "./Display/ThermalAnsiesc.h"

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
				wprintf(THERMAL_ANSIESC_NONSTD_ALTERNATE_BUFFER_EN);
			}else{
				wprintf(THERMAL_ANSIESC_NONSTD_ALTERNATE_BUFFER_DIS);
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
