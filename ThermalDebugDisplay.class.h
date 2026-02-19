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
		ThermalBox thermalBox;
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

	public:
		ThermalDebugDisplay(void){
			setlocale(LC_ALL, "en_US.UTF-8");
			this->data.display_buffer = NULL;
			this->data.display_buffer_size = 0;
			this->fetchWidthHeight();

		}
	
		int getWidth(void){
			this->fetchWidthHeight();
			return this->data.display_width;
		}
		int getHeight(void){
			this->fetchWidthHeight();
			return this->data.display_height;
		}

		~ThermalDebugDisplay(){
			if(this->data.display_buffer != NULL){
				delete[] this->data.display_buffer;
				this->data.display_buffer = NULL;
			}
		}


		void printBox(thermbox_t *box){
			if(box == NULL) return;
			if(box->data == NULL || box->data_size <= 0) return;
			for(int i=0; i<box->data_size; i++){
				wprintf(L"%lc", box->data[i]);
			}
		}
};
