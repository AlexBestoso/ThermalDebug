struct thermalStep{
	std::string name;
	std::string description;
	std::string srcFileName;
	int startingLineNumber;
	int endingLineNumber;

	size_t variableCount;
	ThermalVariable *variables;

	size_t operationCount;
	ThermalOperation *operationChain;
	
};

class ThermalStep{
	private:
		struct thermalStep data;
		bool stepOpen;

		bool validateNewVariable(std::string t, std::string n, void *v){
			for(int i=0; i<this->data.variableCount; i++){
				ThermalVariable var = this->data.variables[i];
				if(var.getName() == n && var.getDataType() == t && (v == var.getValue())){
					return false;
				}	
			}
			return true;
		}
	public:
		void init(void){
			this->data.name = "";
			this->data.description = "";
			this->data.srcFileName = "";
			this->data.startingLineNumber = 0;
			this->data.endingLineNumber = 0;
			this->data.operationCount = 0;
			this->data.operationChain = NULL;
			this->data.variableCount = 0;
			this->data.variables = NULL;
			this->stepOpen = false;
		}
		void reset(void){
			this->stepOpen = false;
			this->data.name = "";
			this->data.description = "";
			this->data.srcFileName = "";
			this->data.startingLineNumber = 0;
			this->data.endingLineNumber = 0;
			this->data.variableCount = 0;
			if(this->data.variables != NULL)
				delete[] this->data.variables;
			this->data.variables = NULL;
			this->data.operationCount = 0;
			if(this->data.operationChain != NULL)
				delete[] this->data.operationChain;
			this->data.operationChain = NULL;

		}

		std::string getName(void){
			return this->data.name;
		}
		void setName(std::string v){
			this->data.name = v;
		}

		std::string getDescription(void){
        		return this->data.description;
		}
		void setDescription(std::string v){
			this->data.description = v;
		}

		std::string getSrcFileName(void){
        		return this->data.srcFileName;
		}
		void setSrcFileName(std::string v){
			this->data.srcFileName = v;
		}		

		int getStartingLineNumber(void){
        		return this->data.startingLineNumber;
		}
		void setStartingLineNumber(int v){
			this->data.startingLineNumber = v;
		}

		int getEndingLineNumber(void){
        		return this->data.endingLineNumber;
		}
		void setEndingLineNumber(int v){
			this->data.endingLineNumber = v;
		}

		size_t getVariableCount(void){
        		return this->data.variableCount;
		}
		void setVariableCount(size_t v){
			this->data.variableCount = v;
		}

		ThermalVariable *getVariables(void){
        		return this->data.variables;
		}
		void setVariables(ThermalVariable *v){
			this->data.variables = v;
		}
	
		size_t getOperationCount(void){
        		return this->data.operationCount;
		}
		void setOperationCount(size_t v){
			this->data.operationCount = v;
		}

		ThermalOperation *getOperationChain(void){
        		return this->data.operationChain;
		}
		void setOperationChain(ThermalOperation *v){
			this->data.operationChain = v;
		}

		ThermalStep(){
			this->init();
		}
		
		~ThermalStep(){
			//this->reset(); causes a segfault for some reason.
		}

		bool newStep(std::string name, std::string desc, std::string srcFileLoc, int lineNumStart, int lineNumEnd){
			this->reset();
			this->data.name = name;
			this->data.description = desc;
			this->data.srcFileName = srcFileLoc;
			this->data.startingLineNumber = lineNumStart;
			this->data.endingLineNumber = lineNumEnd;

			return true;

		}

		bool newVariable(std::string dataType, std::string variableName, void *data){
			if(this->data.variables == NULL){
				this->data.variableCount = 1;
				this->data.variables = new (std::nothrow) ThermalVariable[this->data.variableCount];
				if(this->data.variables == NULL) return false;
			}else if(this->data.variableCount <= 0){
				this->data.variableCount = 1;
				delete[] this->data.variables;
				this->data.variables = new (std::nothrow) ThermalVariable[this->data.variableCount];
				if(this->data.variables == NULL) return false;
			}else{
				if(!this->validateNewVariable(dataType, variableName, data)){
					printf("Duplicate variable entry.\n");
					return false;
				}
				ThermalVariable *tmp = new (std::nothrow) ThermalVariable[this->data.variableCount];
				if(tmp == NULL) return false;
				for(int i=0; i<this->data.variableCount; i++)
					tmp[i] = this->data.variables[i];
				delete[] this->data.variables;

				this->data.variables = new (std::nothrow) ThermalVariable[this->data.variableCount+1];
				if(this->data.variables == NULL) return false;
				for(int i=0; i<this->data.variableCount; i++)
					this->data.variables[i] = tmp[i];
				delete[] tmp;
				tmp = NULL;
				this->data.variableCount++;
			}

			this->data.variables[this->data.variableCount-1].create(dataType, variableName, data);
			return true;
		}

		ThermalVariable getVariableByName(std::string var){
			ThermalVariable ret;
			ThermalVariable *variables = this->getVariables();
			size_t variableCount = this->getVariableCount();
			if(variableCount > 0 && variables != NULL){
				for(int i=0; i<variableCount; i++){
					if(variables[i].getName() == var){
						return variables[i];
					}
				}
			}
			return ret;
		}

		ThermalVariable getVariableByIndex(int idx){
			ThermalVariable ret;
			if(idx < 0 || idx >= this->getVariableCount()) return ret;
			ThermalVariable *variables = this->getVariables();
			ret = variables[idx];
			return ret;
		}
		
		void newOperation(){

		}
};
