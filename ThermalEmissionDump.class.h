struct thermalVariableDump{
	char variableType[32];
	char variableName[32];
};
typedef struct thermalVariableDump tedvar_t;

struct thermalOperationDump{
	uint64_t variableAIndex;
	uint64_t variableAValue;

	char operation;
	
	uint64_t variableBIndex;
	uint64_t variableBValue;
	
	uint64_t variableCIndex;
	uint64_t variableCValue;
};
typedef struct thermalOperationDump tedop_t;

struct thermalStepDump{
	uint64_t startLine;
	uint64_t endLine;
	uint64_t variableCount;
	uint64_t operationCount;
	char stepName[64];
	char sourceFile[256];
	char stepDescription[1024];
	tedvar_t *variables;
	tedop_t *operations;
};

typedef struct thermalStepDump tedstep_t;
struct thermalEmissionDump{
	uint64_t magic = 0xd5245511;
	char algorithmName[128];
	char description[1024];
	uint64_t stepCount;
	tedstep_t *steps;
};
typedef struct thermalEmissionDump ted_t;

class ThermalEmissionDump{
	private:
		int descriptor;
		std::string outputLoc;
		ted_t data;
		bool dumpStarted;
		bool hasSteps;

		bool fileExists(std::string f){
			struct stat st;
			if(stat(f.c_str(), &st) != 0)
				return false;
			return true;
		}
	public:
		ThermalEmissionDump(){
			this->data.steps = NULL;
			this->dumpStarted = false;
			this->hasSteps = false;
		}
		std::string getOutFileName(void){
			return this->outputLoc;
		}
		ted_t getData(void){
			return this->data;
		}
		void startAlgorithm(struct thermalAlgorithm algoData){
			this->dumpStarted = true;
			this->hasSteps = false;
			this->data.magic=0xd5245511;
			for(int i=0; i<1024; i++){
				if(i<128)
					this->data.algorithmName[i] = 0x00;
				this->data.description[i] = 0x00;
			}
			for(int i=0; i<128 && i<algoData.name.length(); i++)
				this->data.algorithmName[i] = algoData.name[i];
			for(int i=0; i<1024 && i<algoData.description.length(); i++)
				this->data.description[i] = algoData.description[i];

			this->data.stepCount = 0;
			if(this->data.steps != NULL){
				delete[] this->data.steps;
				this->data.steps = NULL;
			}
			this->outputLoc = algoData.outputLoc;
		}

		bool addStep(ThermalStep step){
			if(!dumpStarted) return false;
			size_t startSize = this->data.stepCount;
			this->data.stepCount++;
			tedstep_t *tmp = new (std::nothrow) tedstep_t[startSize+1];
			if(tmp == NULL){
				this->data.stepCount--;
				return false;
			}
			for(int i=0; i<startSize; i++)
				tmp[i] = this->data.steps[i];

			if(this->data.steps != NULL) delete[] this->data.steps;
			this->data.steps = new (std::nothrow) tedstep_t[this->data.stepCount];
			if(this->data.steps == NULL){
				this->data.stepCount = 0;
				delete[] tmp;
				return false;
			}
			for(int i=0; i<startSize; i++)
				this->data.steps[i] = tmp[i];
			delete[] tmp;

			tedstep_t *ptr = &this->data.steps[this->data.stepCount-1];
			ptr->startLine = step.getStartingLineNumber();
			ptr->endLine = step.getEndingLineNumber();
			ptr->variableCount = step.getVariableCount();
			ptr->operationCount = step.getOperationCount();
			std::string name = step.getName();
			for(int i=0, nameMax=name.length(); i<64; i++){
				if(i<nameMax)
					ptr->stepName[i] = name[i];
				else
					ptr->stepName[i] = 0x00;
			}
			name = step.getSrcFileName();
			for(int i=0, srcMax=name.length(); i<256; i++){
				if(i<srcMax)
					ptr->sourceFile[i] = name[i];
				else
					ptr->sourceFile[i] = 0x00;
			}
			name = step.getDescription();
			for(int i=0, descMax=name.length(); i<1024; i++){
				if(i<descMax)
					ptr->stepDescription[i] = name[i];
				else
					ptr->stepDescription[i] = 0x00;
			}

			ptr->variables = NULL;
			ptr->operations = NULL;
			
			this->hasSteps = true;
			return true;
		}

		bool addVariable(int stepIndex, ThermalVariable variable){
			if(!this->hasSteps)
				return false;
			if(stepIndex < 0 || stepIndex >= this->data.stepCount){
				return false;
			}
			tedstep_t *step = &this->data.steps[stepIndex];
			int startingVariableCount = step->variableCount;
			step->variableCount++;
			tedvar_t *tmp = new (std::nothrow) tedvar_t[startingVariableCount+1];
			if(tmp == NULL){
				step->variableCount--;
				return false;
			}

			for(int i=0; i<startingVariableCount; i++)
				tmp[i] = step->variables[i];

			if(step->variables != NULL) delete[] step->variables;
			step->variables = new (std::nothrow) tedvar_t[step->variableCount];
			if(step->variables == NULL){
				step->variableCount = 0;
				delete[] tmp;
				return false;
			}
			
			for(int i=0; i<startingVariableCount; i++)
				step->variables[i] = tmp[i];
			delete[] tmp;

			tedvar_t *ptr = &step->variables[step->variableCount-1];
			
			std::string type = variable.getDataType();
			std::string name = variable.getName();
			for(int i=0, t=type.length(), n=name.length(); i<32; i++){
				if(i<t)
					ptr->variableType[i] = type[i];
				else
					ptr->variableType[i] = 0x00;

				if(i<n)
					ptr->variableName[i] = name[i];
				else
					ptr->variableName[i] = 0x00;
			}

			return true;
		}
};
