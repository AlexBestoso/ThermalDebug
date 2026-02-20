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

		bool allocateDisplay(void){
			if(this->data.display_buffer != NULL) delete[] this->data.display_buffer;
			if(this->data.display_width <= 0 || this->data.display_height <= 0) return false;
			this->data.display_buffer_size = this->data.display_width * this->data.display_height;
			this->data.display_buffer = new (std::nothrow) wchar_t[this->data.display_buffer_size];
			if(this->data.display_buffer == NULL) return false;
			for(int i=0; i<this->data.display_buffer_size; i++)
				this->data.display_buffer[i] = L' ';
			return true;
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
			this->allocateDisplay();

		}	

		~ThermalDebugDisplay(){
			if(this->data.display_buffer != NULL){
				delete[] this->data.display_buffer;
				this->data.display_buffer = NULL;
			}
		}

		int getWidth(void){
			return this->data.display_width;
		}
		int getHeight(void){
			return this->data.display_height;
		}
		size_t getSize(void){
			return this->data.display_buffer_size;
		}
		wchar_t *getDisplayBuffer(void){
			return this->data.display_buffer;
		}

		bool rawWrite(wchar_t *rawData, size_t rawDataSize, int offset){
			if(rawData == NULL) return false;
			if(rawDataSize <= 0) return false;
			if(offset < 0) return false;
			if(offset >= this->data.display_buffer_size) return false;
			if(this->data.display_buffer == NULL) return false;
			if(this->data.display_buffer_size <= 0) return false;

			for(int i=offset, r=0; i<this->data.display_buffer_size && r<rawDataSize; i++, r++){
				this->data.display_buffer[i] = rawData[r];
			}
			return true;
		}

		void clearScreen(void){
			wprintf(L"%ls%ls", THERMAL_ANSIESC_CURSOR_HOME, THERMAL_ANSIESC_ERASE_SCREEN);
		}

		void setCursorPos(int x, int y){
			wprintf(L"\x1b[%d;%dH", x, y);
		}

		void refreshDisplaySize(void){
			this->fetchWidthHeight();	
		}

		bool startDisplay(void){
			this->alternateScreen(true);

			return true;
		}

		bool stopDisplay(void){
			this->alternateScreen(false);
			return true;
		}

		bool mapBox(ThermalBox src, int xpos, int ypos){
			if(xpos >= this->data.display_width || ypos >= this->data.display_height) return false;

			thermbox_t *box = src.getData();
			if(box == NULL) return false;

			size_t bDataSize = box->data_size;
			wchar_t *bData = box->data;
			if(bData == NULL || bDataSize <= 0) return false;

			int bwidth = box->width;
			int bheight = box->height;
			int swidth = this->data.display_width;
			int sheight = this->data.display_height;

			int boxXOffset = 0;
			int boxYOffset = 0;
			
			if(xpos < 0){
				xpos *= -1;
				xpos = bwidth - xpos;
				if(xpos < 0) return false;
				boxXOffset = xpos - 1;
				xpos = 0;
			}
			if(ypos < 0){
				ypos *= -1;
				ypos = bheight - ypos;
				if(ypos < 0) return false;
				boxYOffset = ypos - 1;
				ypos = 0;
			}

			this->setCursorPos(0, 0);

			int pos = xpos + (swidth * ypos);
			for(int i=pos, lineI = xpos, b=0, lineB=boxXOffset; i<this->data.display_buffer_size && b<bDataSize; i++, b++){
				this->data.display_buffer[i] = bData[b];
				lineI++;
				lineB++;
				if(lineB >= bwidth){
					b += boxXOffset;
					lineB = boxXOffset;
				}
				if(lineI >= swidth){
					i += xpos;
					lineI = xpos;
				}
			}

			
			return true;
		}

		bool draw(void){
			this->setCursorPos(0, 0);
			for(int i=0; i<this->data.display_buffer_size; i++)
				wprintf(L"%lc", this->data.display_buffer[i]);
			return true;	
		}

};
