struct thermalDebugDisplayStruct{
	char *display_buffer;
	size_t display_buffer_size;
};
typedef struct thermalDebugDisplayStruct thermdisp_t;

struct thermalDebugErrorStruct{
	int id;
	std::string msg;
	std::string functionName;
	bool failed;
};
typedef struct thermalDebugErrorStruct thermerr_t;

struct thermalDebugAlgorithmCache{
	ted_t *algorithms;
	size_t algorithmsCount;
};
typedef struct thermalDebugAlgorithmCache thermalgo_t;

class ThermalDebug{
	private:
		thermdisp_t display;
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
			this->display.display_buffer = NULL;
			this->display.display_buffer_size = 0;
			
			this->algoCache.algorithms = NULL;
			this->algoCache.algorithmsCount = 0;
		
			this->clearError();
		}

		~ThermalDebug(){
			if(this->display.display_buffer != NULL){
				delete[] this->display.display_buffer;
				this->display.display_buffer = NULL;
			}

			if(this->algoCache.algorithms != NULL){
				delete[] this->algoCache.algorithms;
			}
		}

		bool loadAlgorithms(int argc, char *argv[]){
			if(argc <= 0 || argv == NULL) return true;
			for(int i=0; i<argc; i++){
				const char *fileName = argv[i];
				// validate file names
				if(this->inputIsFile(fileName) == false){
					printf("%s is an invalid input.\n", fileName);
					return false;
				}
				// ... create a ted_t object.
				// add object via reallocating to the cache.
			}
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
