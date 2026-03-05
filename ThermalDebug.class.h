#include "./UI/ThermalUI.h"
#include "./ThermalDebugErrorStruct.class.h"
#include "./ThermalDebugDisplay.class.h"
#include "./ThermalDebugAlgorithmCache.class.h"

class ThermalDebug{
	private:
		bool running;
		ThermalDebugDisplay display;
		ThermalBackgroundBox bgBox;
		ThermalAlgoStreamBox *algoStreamBoxes;
		size_t algoStreamBoxes_s;

		thermerr_t error;
		thermalgo_t algoCache;
		ThermalEmissionDump dumper;

		void setError(int code, std::string func, std::string msg){
			this->error.id = code;
			this->error.functionName = func;
			this->error.msg = msg;
			this->error.failed = true;
		}

		bool inputIsFile(const char *src){
			// check if src is a command
			struct stat st;
			if(stat(src, &st) == -1)
				return false;
			return true;
		}

		bool loadStreams(void){
			if(this->algoStreamBoxes != NULL){
				delete[] this->algoStreamBoxes;
				this->algoStreamBoxes = NULL;
			}

			this->algoStreamBoxes_s = this->algoCache.algorithmsCount;
			if(this->algoStreamBoxes_s <= 0) return false;
			
			this->algoStreamBoxes = new (std::nothrow) ThermalAlgoStreamBox[this->algoStreamBoxes_s];
			if(this->algoStreamBoxes == NULL){
				// TODO: implement error handling.
				return false;
			}

			for(int i=0; i<this->algoStreamBoxes_s; i++){
				this->algoStreamBoxes[i].setArea(this->display.getWidth(), this->display.getHeight());
				this->algoStreamBoxes[i].mapAlgorithmName(1, 2, (const char *)this->algoCache.algorithms[i].algorithmName);
				this->algoStreamBoxes[i].buildBox();
			}
			return true;
		}

		bool loadBackground(void){
			std::string tmp = "Thermal Debug - 0.0.0 Alpha";
			if(!this->bgBox.setBoxArea(this->display.getWidth(), this->display.getHeight())){
				printf("Failed to set background box area.\n");
				return false;
			}
	
			/*   // cusotm box borders and fills
			if(!this->bgBox.generateData()){
				printf("Failed to generate data.\n");
				return false;
			}*/

			if(!this->bgBox.generateBoxDoubleLine()){
				printf("Failed to generate data.\n");
				return false;
			}
	
			if(!this->bgBox.mapString(2, 1, tmp)){
				printf("Failed to map string to background box.\n");
				return false;
			}
			tmp = "Algorithm Count : " + std::to_string(this->algoCache.algorithmsCount);
			if(!this->bgBox.mapString(2, 2, tmp)){
				printf("Failed to map algorithm count string to background box.\n");
				return false;
			}
			return true;
		}

	public:
		bool hasError(thermerr_t *out){
			out = &this->error;
			return this->error.failed;
		}
		void clearError(void){
			this->error.id = -1;
			this->error.msg = "";
			this->error.functionName = "";
			this->error.failed = false;
		}

		ThermalDebug(){
			this->running = false;
			this->algoCache.algorithms = NULL;
			this->algoCache.algorithmsCount = 0;
			this->algoStreamBoxes = NULL;
			this->algoStreamBoxes_s = 0;
		
			this->clearError();
		}

		~ThermalDebug(){
			if(this->algoCache.algorithms != NULL){
				delete[] this->algoCache.algorithms;
			}

			if(this->algoStreamBoxes != NULL){
				delete[] this->algoStreamBoxes;
				this->algoStreamBoxes = NULL;
			}
		}

		bool loadAlgorithms(int argc, char *argv[]){
			if(argc <= 0 || argv == NULL) return true;
			for(int i=1; i<argc; i++){
				const char *fileName = argv[i];
				// validate file names
				if(this->inputIsFile(fileName) == false){
					printf("%s is an invalid input.\n", fileName);
					return false;
				}
				if(!this->dumper.readData(fileName)){
					printf("%s may not be a ted file.\n", fileName);
					return false;
				}
				ted_t ted = this->dumper.getData();
				
				// add object via reallocating to the cache.
				if(this->algoCache.algorithmsCount < 0) this->algoCache.algorithmsCount = 0;
				int prevCount = this->algoCache.algorithmsCount;
				this->algoCache.algorithmsCount++;
				ted_t *tmp = new (std::nothrow) ted_t[prevCount+1];
				if(tmp == NULL){
					printf("Allocation failure.\n");
					return false;
				}
				
				for(int a=0; a<prevCount && this->algoCache.algorithms != NULL; a++)
					tmp[a] = this->algoCache.algorithms[a];
				if(this->algoCache.algorithms != NULL) delete[] this->algoCache.algorithms;
				this->algoCache.algorithms = new ted_t[this->algoCache.algorithmsCount];
				for(int a=0; a<prevCount; a++)
					this->algoCache.algorithms[a] = tmp[a];
				delete[] tmp;
				
				this->algoCache.algorithms[this->algoCache.algorithmsCount-1] = ted;
			}
			return true;
		}

		bool loadDisplay(void){
			this->display.startDisplay();
			this->loadBackground();

			return true;
		}

		bool killDisplay(void){
			this->display.stopDisplay();
			return true;
		}

		bool run(void){
			this->running = true;
			this->loadBackground();
			this->loadStreams();
			this->display.clearScreen();
		
			if(!this->display.mapBox(this->bgBox, 0, 0)){
				return false;
			}
			
			for(int i=0; i<this->algoCache.algorithmsCount; i++){
				this->display.setCursorPos(0,0);
				if(!this->display.mapBox(this->algoStreamBoxes[i], 1, 5)){
					return false;
				}
			}
		
			wprintf(L"Testing keystroke. Press any key: \n");
			wprintf(L"You pressed %c\n", this->display.getKeyPress());
			sleep(1);

			this->display.draw();
			fflush(stdout);
			while(this->running){
				if(this->display.resizeReady()){
                        		fflush(stdout);
					this->display.refreshDisplaySize();
					this->display.setCursorPos(0,0);
					this->loadBackground();
					this->display.clearScreen();
                        		this->display.mapBox(this->bgBox, 0, 0);
					for(int i=0; i<this->algoCache.algorithmsCount; i++)
						this->display.mapBox(this->algoStreamBoxes[i], 1, 5);
					this->display.draw();
					THERMAL_DISPLAY_FLAG_RESIZE = false;
                        		fflush(stdout);
					
				}
			}
			return true;
		}
		
}thermalDbg;
