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

		int getStepVariableIndex(int stepIdx, ThermalVariable variable){
			int ret=-1;
			
			return ret;
		}
	public:
		bool specialEquals(int macro){
			return macro >= THERMAL_OPERATOR_COMBINED_OFFSET;
		}
		std::string operationMacroToString(int macro){
			switch(macro){
				case THERMAL_OPERATOR_EQUALS:
					return "=";
				case THERMAL_OPERATOR_PLUS:
					return "+";
				case THERMAL_OPERATOR_MINUS:
					return "-";
				case THERMAL_OPERATOR_MULTIPLY:
					return "*";
				case THERMAL_OPERATOR_DIVIDE:
					return "/";
				case THERMAL_OPERATOR_XOR:
					return "^";
				case THERMAL_OPERATOR_OR:
					return "|";
				case THERMAL_OPERATOR_AND:
					return "&";
				case THERMAL_OPERATOR_SHIFT_LEFT:
					return "<<";
				case THERMAL_OPERATOR_SHIFT_RIGHT:
					return ">>";
				case THERMAL_OPERATOR_MOD:
					return "%";
				case THERMAL_OPERATOR_PLUS_EQUALS:
					return "+=";
				case THERMAL_OPERATOR_MINUS_EQUALS:
					return "-=";
				case THERMAL_OPERATOR_MULTIPLY_EQUALS:
					return "*=";
				case THERMAL_OPERATOR_DIVIDE_EQUALS:
					return "/=";
				case THERMAL_OPERATOR_XOR_EQUALS:
					return "^=";
				case THERMAL_OPERATOR_OR_EQUALS:
					return "|=";
				case THERMAL_OPERATOR_AND_EQUALS:
					return "&=";
				case THERMAL_OPERATOR_SHIFT_LEFT_EQUALS:
					return "<<=";
				case THERMAL_OPERATOR_SHIFT_RIGHT_EQUALS:
					return ">>=";
				case THERMAL_OPERATOR_MOD_EQUALS:
					return "%=";
			}
			return "";
		}
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

		bool addOperation(int stepIndex, ThermalVariable a, ThermalVariable b, ThermalVariable c, int opMacro){
			if(stepIndex < 0 || stepIndex >= this->data.stepCount)
				return false;
			if(this->data.steps == NULL){
				return false;
			}
			
			tedstep_t *step = &this->data.steps[stepIndex];
			int startingOperationCount = step->operationCount;
			step->operationCount++;
			if(step == NULL) return false;

			tedop_t *tmp = new (std::nothrow) tedop_t[startingOperationCount+1];
			if(tmp == NULL){
				step->operationCount--;
				return false;
			}

			for(int i=0; i<startingOperationCount; i++)
				tmp[i] = step->operations[i];

			if(step->operations != NULL) delete[] step->operations;
			step->operations = new (std::nothrow) tedop_t[step->operationCount];
			if(step->operations == NULL){
				step->operationCount = 0;
				delete[] tmp;
				return false;
			}
			
			for(int i=0; i<startingOperationCount; i++)
				step->operations[i] = tmp[i];
			delete[] tmp;

			tedop_t *ptr = &step->operations[step->operationCount-1];
			ptr->operation = (char)opMacro;

			/*if(opMacro > THERMAL_OPERATOR_COMBINED_OFFSET){ // a ?= b
				ptr->variableAIndex = this->getStepVariableIndex(stepIndex, a);
				ptr->variableAValue = a.getValueUint64();
				ptr->variableBIndex = this->getStepVariableIndex(stepIndex, b);
				ptr->variableBValue b.getValueUint64();
				ptr->variableCIndex = = this->getStepVariableIndex(stepIndex, c);
				ptr->variableCValue c.getValueUint64();
			}else{ // a ? b = c*/
				ptr->variableAIndex = this->getStepVariableIndex(stepIndex, a);
				ptr->variableAValue = a.getValueUint64();
				ptr->variableBIndex = this->getStepVariableIndex(stepIndex, b);
				ptr->variableBValue = b.getValueUint64();
				ptr->variableCIndex = this->getStepVariableIndex(stepIndex, c);
				ptr->variableCValue = c.getValueUint64();
			//}


			return true;
		}
};
