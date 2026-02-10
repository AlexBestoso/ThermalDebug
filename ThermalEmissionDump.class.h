#define TEDVAR_T_SIZE 32 + 32
struct thermalVariableDump{
	char variableType[32];
	char variableName[32];
};
typedef struct thermalVariableDump tedvar_t;

#define TEDOP_T_SIZE 4 + 4 + 4 + 4 + 4 + 4 + 4
struct thermalOperationDump{
	uint64_t variableAIndex;
	uint64_t variableAValue;

	uint64_t operation;
	
	uint64_t variableBIndex;
	uint64_t variableBValue;
	
	uint64_t variableCIndex;
	uint64_t variableCValue;
};
typedef struct thermalOperationDump tedop_t;

#define TEDSTEP_T_SIZE (4 + 4 + 4 + 4 + 64 + 256 + 1024)
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

#define TED_T_SIZE (4 + 128 + 1024 + 4)
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
			if(stepIdx < 0 || stepIdx >= this->data.stepCount) return -1;
			tedstep_t step = this->data.steps[stepIdx];
			std::string target = variable.getName();
			
			for(int i=0; i<step.variableCount; i++){
				tedvar_t v = step.variables[i];
				std::string name = v.variableName;
				if(target == name){
					return i;
				}
			}
			return -1;
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
			return "?";
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
			ptr->operation = opMacro;

			uint64_t varA = a.getValueAutocast();
			uint64_t varB = b.getValueAutocast();
			uint64_t varC = c.getValueAutocast();
			
			ptr->variableAIndex = this->getStepVariableIndex(stepIndex, a);
			ptr->variableAValue = varA;
			ptr->variableBIndex = this->getStepVariableIndex(stepIndex, b);
			ptr->variableBValue = varB;
			ptr->variableCIndex = this->getStepVariableIndex(stepIndex, c);
			ptr->variableCValue = varC;

			return true;
		}

		bool generateTed(void){
			
			return true;
		}

		bool writeData(void){
			// Allocate buffer
			size_t outSize = TED_T_SIZE;
			for(int s=0; s<this->data.stepCount; s++){
				outSize += TEDSTEP_T_SIZE;
				for(int v=0; v<this->data.steps[s].variableCount; v++)
					outSize += TEDVAR_T_SIZE;
				for(int o=0; o<this->data.steps[s].operationCount; o++)
				outSize += TEDOP_T_SIZE;
			}
			char *out = new (std::nothrow) char[outSize];
			if(out == NULL) return false;
			
			// Populate buffer.
			int oi=0;
			for(int i=0; i<4; i++, oi++)
				out[oi] = (this->data.magic & (0xff<<((3-i)*8))) >> ((3-i)*8);
			for(int i=0; i<128; i++, oi++)
				out[oi] = this->data.algorithmName[i];
			for(int i=0; i<1024; i++, oi++)
				out[oi] = this->data.description[i];
			for(int i=0; i<4; i++, oi++)
				out[oi] = (this->data.stepCount & (0xff<<((3-i)*8))) >> ((3-i)*8);

			for(int s=0; s<this->data.stepCount; s++){
				tedstep_t step = this->data.steps[s];
				for(int i=0; i<4; i++, oi++)
					out[oi] = (step.startLine & (0xff<<((3-i)*8))) >> ((3-i)*8);
				for(int i=0; i<4; i++, oi++)
					out[oi] = (step.endLine & (0xff<<((3-i)*8))) >> ((3-i)*8);
				for(int i=0; i<4; i++, oi++)
					out[oi] = (step.variableCount & (0xff<<((3-i)*8))) >> ((3-i)*8);
				for(int i=0; i<4; i++, oi++)
					out[oi] = (step.operationCount & (0xff<<((3-i)*8))) >> ((3-i)*8);
				for(int i=0; i<64; i++, oi++)
					out[oi] = step.stepName[i];
				for(int i=0; i<256; i++, oi++)
					out[oi] = step.sourceFile[i];
				for(int i=0; i<1024; i++, oi++)
					out[oi] = step.stepDescription[i];

				for(int v=0; v<step.variableCount; v++){
					tedvar_t variable = step.variables[v];
					for(int i=0; i<32; i++, oi++)
						out[oi] = variable.variableType[32];
					for(int i=0; i<32; i++, oi++)
						out[oi] = variable.variableName[32];
				}

				for(int o=0; o<step.operationCount; o++){
					tedop_t operation = step.operations[o];
					for(int i=0; i<4; i++, oi++)
						out[oi] = (operation.variableAIndex & (0xff<<((3-i)*8))) >> ((3-i)*8);
					for(int i=0; i<4; i++, oi++)
						out[oi] = (operation.variableAValue & (0xff<<((3-i)*8))) >> ((3-i)*8);
					for(int i=0; i<4; i++, oi++)
						out[oi] = (operation.operation & (0xff<<((3-i)*8))) >> ((3-i)*8);
					for(int i=0; i<4; i++, oi++)
						out[oi] = (operation.variableBIndex & (0xff<<((3-i)*8))) >> ((3-i)*8);
					for(int i=0; i<4; i++, oi++)
						out[oi] = (operation.variableBValue & (0xff<<((3-i)*8))) >> ((3-i)*8);
					for(int i=0; i<4; i++, oi++)
						out[oi] = (operation.variableCIndex & (0xff<<((3-i)*8))) >> ((3-i)*8);
					for(int i=0; i<4; i++, oi++)
						out[oi] = (operation.variableCValue & (0xff<<((3-i)*8))) >> ((3-i)*8);
				}
			}

			return true;
		}
		bool readData(std::string target){
			uint8_t *buffer = NULL;
			size_t bufferSize = 0;
			return this->readData(buffer, bufferSize);
		}
		bool readData(uint8_t *buffer, size_t bufferSize){
			
			return true;
		}
		
};
