#include "./UI/ThermalUI.h"
#include "./ThermalDebugErrorStruct.class.h"
#include "./ThermalDebugDisplay.class.h"
#include "./ThermalDebugAlgorithmCache.class.h"

class ThermalDebug{
	private:
		ThermalDebugDisplay display;
		ThermalBackgroundBox bgBox;
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

		bool loadBackground(){
			std::string tmp = "Thermal Debug - 0.0.0 Alpha";
			if(!this->bgBox.setBoxArea(this->display.getWidth(), this->display.getHeight())){
				printf("Failed to set background box area.\n");
				return false;
			}
			if(!this->bgBox.generateData()){
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
			this->algoCache.algorithms = NULL;
			this->algoCache.algorithmsCount = 0;
		
			this->clearError();
		}

		~ThermalDebug(){
			if(this->algoCache.algorithms != NULL){
				delete[] this->algoCache.algorithms;
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
			this->bgBox.printBox();
			this->display.draw();
			fflush(stdout);
			return true;
		}
		

		void color_reset(void){
			printf("\033[0m");
		}
		void color_bright(void){
			printf("\033[1m");
		}
		void color_underline(void){
			printf("\033[4m");
		}
		void color_flashing(void){
			printf("\033[5m");
		}
		void color_blackFg(void){
			printf("\033[30m");
		}
		void color_redFg(void){
			printf("\033[31m");	
		}
		void color_greenFg(void){
			printf("\033[32m");
		}
		void color_yellowFg(void){
			printf("\033[33m");
		}
		void color_blueFg(void){
			printf("\033[34m");
		}
		void color_purpleFg(void){
			printf("\033[35m");
		}
		void color_cyanFg(void){
			printf("\033[36m");
		}
		void color_whiteFg(void){
			printf("\033[37m");
		}
		void color_blackBg(void){
			printf("\033[40m");
		}
		void color_redBg(void){
			printf("\033[41m");
		}
		void color_greenBg(void){
			printf("\033[42m");
		}
		void color_yellowBg(void){
			printf("\033[43m");
		}
		void color_blueBg(void){
			printf("\033[44m");
		}
		void color_purpleBg(void){
			printf("\033[45m");
		}
		void color_cyanBg(void){
			printf("\033[46m");
		}
		void color_whiteBg(void){
			printf("\033[47m");
		}

}thermalDbg;
