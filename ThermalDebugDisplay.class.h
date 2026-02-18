#include "./ThermalBox.class.h"
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

		bool initBackground(thermbox_t *box){
			if(box == NULL){
				printf("thermbox_t *box is null\n");
				return false;
			}
			if(box->data == NULL || box->data_size <= 0){
				printf("thermbox_t *box->data isn't allocated\n");
				return false;
			}

			if(!this->thermalBox.generateBoxData(box)){
				printf("ThermalBox::generateBoxData() failed to generate background data.\n");
				return false;
			}


			
			return true;
		}

		bool mapString(thermbox_t *box, int x, int y, std::string str){
			if(!this->thermalBox.mapString(box, x, y, str)){
				printf("ThermalBox::mapString() failed to map string to box.\n");
				return false;
			}
			return true;
		}

		void printBox(thermbox_t *box){
			if(box == NULL) return;
			if(box->data == NULL || box->data_size <= 0) return;
			for(int i=0; i<box->data_size; i++){
				wprintf(L"%lc", box->data[i]);
			}
		}
};
