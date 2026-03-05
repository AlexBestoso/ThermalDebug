#include "./Display/ThermalAnsiesc.h"

struct thermalDebugDisplayStruct{
	int display_width;
	int display_height;
	size_t display_buffer_size;
	wchar_t *display_buffer;
};
typedef struct thermalDebugDisplayStruct thermdisp_t;

bool THERMAL_DISPLAY_FLAG_RESIZE = false;
void THERMAL_DISPLAY_FUNC_RESIZE(int i){
	THERMAL_DISPLAY_FLAG_RESIZE = true;
}

struct termios termInitSrc;

void THERMAL_CLEANUP(void){
	tcsetattr(1, TCSANOW, &termInitSrc);
	wprintf(L"%ls%ls%ls", THERMAL_ANSIESC_ERASE_SCREEN, THERMAL_ANSIESC_NONSTD_ALTERNATE_BUFFER_DIS, THERMAL_ANSIESC_NONSTD_CURSOR_VISIBLE);
	
}
void THERMAL_DIE(int i){
	exit(1);
}


class ThermalDebugDisplay{
	private:
		bool drawReady;
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

		int extractBit(int in, int bitPos){
			return (in & (1<<bitPos)) >> bitPos;
		}


	public:
		ThermalDebugDisplay(void){
			setlocale(LC_ALL, "en_US.UTF-8");
			this->data.display_buffer = NULL;
			this->data.display_buffer_size = 0;
			this->fetchWidthHeight();
			this->allocateDisplay();
			this->drawReady = true;

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

		void setCursorVisible(bool visible){
			if(visible)
				wprintf(L"%ls", THERMAL_ANSIESC_NONSTD_CURSOR_VISIBLE);
			else
				wprintf(L"%ls", THERMAL_ANSIESC_NONSTD_CURSOR_INVISIBLE);
		}

		void refreshDisplaySize(void){
			this->fetchWidthHeight();	
			this->allocateDisplay();
		}

		bool startDisplay(void){
			this->alternateScreen(true);
			this->setCursorVisible(false);

			return true;
		}

		bool stopDisplay(void){
			this->alternateScreen(false);
			this->setCursorVisible(true);
			return true;
		}

		bool mapBox(ThermalBox src, int xpos, int ypos){
			if(xpos >= this->data.display_width || ypos >= this->data.display_height) return false;

			thermbox_t *box = src.getData();
			if(box == NULL){
				return false;
			}

			size_t bDataSize = box->data_size;
			wchar_t *bData = box->data;
			if(bData == NULL || bDataSize <= 0){
				return false;
			}

			int bwidth = box->width;
			int bheight = box->height;
			int swidth = this->data.display_width;
			int sheight = this->data.display_height;

			if((xpos+bwidth) < 0) return true;
			if((ypos+bheight) < 0) return true;

			int yChange = 0;
			if(ypos != 0){
				if(ypos < 0){
					yChange = (bwidth-1) * ((-1) * ypos);
				}else{
					yChange = (bwidth-1) * ypos;
				}
			}

			int xChange = 0;
			if(xpos != 0){
				if(xpos < 0){
					xChange = xpos * -1;
				}else{
					xChange = xpos;
				}
			}

			// x,y position of a theoretical cursors that would place the box
			// This is supposed to be manipulated once per iteration in the following for loop.
			int hyperCursorRowPos=xpos;
			int hyperCursorColPos=ypos;

			int iStart = 0;
			if(ypos > 0) iStart += (ypos * swidth);
			if(xpos > 0) iStart += xpos;
			int iOffset = iStart % swidth;

			for(int j=0, i=iStart; j<bDataSize && i<this->data.display_buffer_size; j++){
				// x,y position of j within the box data buffer
				int boxRowPos    = j % bwidth;
				int boxColPos = bheight == 0 ? 0 : j / bheight;

				// x,y position of i within the screen data buffer.
				int screenRowPos = i % swidth;
				int screenColPos = sheight == 0 ? 0 : i / sheight;

				int magicViewNumber = (hyperCursorRowPos >= 0) & 0b1111;
				magicViewNumber += ((hyperCursorRowPos < swidth)<<1) & 0b1111; 
				magicViewNumber += ((hyperCursorColPos >= 0)<<2) & 0b1111;
				magicViewNumber += ((hyperCursorColPos <= sheight)<<3) & 0b1111;

				if(magicViewNumber == 0b1111){
					this->data.display_buffer[i] = bData[j];
					if((j%bwidth) == bwidth-1){
						hyperCursorRowPos = xpos;
						hyperCursorColPos++;
						int diff = swidth - screenRowPos;
						i+=diff+iOffset;
					}else{
						i++;
						hyperCursorRowPos++;
					}
				}else{ // not in view...
					bool hyperEOL=false;
					if(!this->extractBit(magicViewNumber, 0)){// rowPos is before the screen
						if((j%bwidth) == bwidth-1){
							hyperCursorRowPos = xpos;
                                                	hyperCursorColPos++;
							int diff = swidth - screenRowPos;
							i+=diff+iOffset;
						}else{
							hyperCursorRowPos++;
						}
					}else if(!this->extractBit(magicViewNumber, 1)){// rowPos is beyond the screen

						while((j%bwidth) != 0) j++;
						j--;
						while((i%swidth) != 0) i++;
						i+= iOffset;	
						hyperCursorRowPos = xpos;
                                                hyperCursorColPos++;
						
					}

					if(!this->extractBit(magicViewNumber, 2)){// colPos is before the screen
						j += bwidth;
						j--;
						hyperCursorRowPos = xpos;
                                                hyperCursorColPos++;

					}else if(this->extractBit(magicViewNumber, 4)){// colPos is beyond the screen
						wprintf(L"J coords (%d, %d)\n", boxRowPos, boxColPos);
						wprintf(L"I coords (%d, %d)\n", screenRowPos, screenColPos);
						wprintf(L"mgk:%x rowPos:%d, colPos:%d\n", magicViewNumber, hyperCursorRowPos, hyperCursorColPos);
						
					}
				}

			}	
			return true;
		}

		bool resizeReady(void){
			bool ret = THERMAL_DISPLAY_FLAG_RESIZE;
			THERMAL_DISPLAY_FLAG_RESIZE = false;
			return ret;
		}

		bool draw(void){
			this->setCursorPos(0, 0);
			for(int i=0; i<this->data.display_buffer_size; i++)
				wprintf(L"%lc", this->data.display_buffer[i]);
			return true;	
		}

		char getKeyPress(void){
			char ret;
			read(1, &ret, 1);
			return ret;
		}

};
