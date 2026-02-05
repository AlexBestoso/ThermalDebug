#include "./ThermalVariable.class.h"
struct thermalOperation{
	std::string name;
	std::string description;
	size_t variableCount;
	ThermalVariable *variables;
};
#include "./ThermalOperation.class.h"

#include "./ThermalStep.class.h"

struct thermalAlgorithm{
	std::string name;
	std::string description;
	std::string outputLoc;
	size_t *outBuffSize;
	uint8_t *outBuff;
	size_t stepCount;
	ThermalStep *stepChain;
};
#include "./ThermalAlgorithm.class.h"

class ThermalDebugIntegrator{
	private:
		bool processingAlgo;
		int stepIdx;
		int operationIdx;
		ThermalAlgorithm currentAlgo;
	public:
	
		ThermalDebugIntegrator(){
			this->processingAlgo = false;
			this->stepIdx = -1;
		}
		
		~ThermalDebugIntegrator(){

		}

		bool newAlgorithm(std::string name, std::string desc, std::string outFile){
			if(this->processingAlgo) return false;
			this->processingAlgo = true;
			this->currentAlgo.reset();
			this->currentAlgo.setName(name);
			this->currentAlgo.setDescription(desc);
			this->currentAlgo.setOutputLoc(outFile);
			return true;
		}

		ThermalAlgorithm *getAlgorithm(void){
			return &currentAlgo;
		}

		void setStepIdx(int idx){
			this->stepIdx = idx;
		}
		
		void setOutputBuffer(uint8_t *outAddr, size_t *outsizeAddr){
			this->currentAlgo.setOutBuffSize(outsizeAddr);
                        this->currentAlgo.setOutBuff(outAddr);
		}

		void finishAlgorithm(void){
			this->processingAlgo = false;
		}

		bool newStep(std::string name, std::string description, std::string srcFileName, int startingLineNumber, int endingLineNumber){
			bool ret = this->currentAlgo.newStep(name, description, srcFileName, startingLineNumber, endingLineNumber);
			this->stepIdx = this->currentAlgo.getStepCount() - 1;
			return ret;
		}

		ThermalStep getCurrentStep(void){
			ThermalStep ret;
			if(this->stepIdx < 0 || this->stepIdx >= this->currentAlgo.getStepCount()){
				return ret;
			}

			ret = this->currentAlgo.getStep(this->stepIdx);
			return ret;
		}

		void setCurrentStep(ThermalStep v){
			if(this->stepIdx < 0 || this->stepIdx >= this->currentAlgo.getStepCount()){
				return;
			}
			this->currentAlgo.setStep(this->stepIdx, v);
		}


		bool declareStepVariable(std::string type, std::string name, void *value){
			ThermalStep step = this->getCurrentStep();

			if(!step.newVariable(type, name, value))
				return false;

			this->setCurrentStep(step);
			step = this->getCurrentStep();
			return true;
		}

		bool operationEquals(std::string varA, int val){
			ThermalStep step = this->getCurrentStep();
			ThermalVariable variable = step.getVariableByName(varA);
			variable.setValueInt(val);
			return true;
		}
		bool operationEquals(std::string varA, void *value){
			ThermalStep step = this->getCurrentStep();
			ThermalVariable variable = step.getVariableByName(varA);
			variable.setValue(value);
			return true;
		}
		bool operation(std::string varA, std::string operation, std::string varB, std::string outputVar){
			ThermalOperation thermalOperation;
			int operationIndex = thermalOperation.stringToOperation(operation);
			switch(operationIndex){
				case THERMAL_OPERATOR_INVALID:
					return false;
				case THERMAL_OPERATOR_EQUALS:
				case THERMAL_OPERATOR_PLUS:
				case THERMAL_OPERATOR_MINUS:
				case THERMAL_OPERATOR_MULTIPLY:
				case THERMAL_OPERATOR_DIVIDE:
				case THERMAL_OPERATOR_XOR:
				case THERMAL_OPERATOR_OR:
				case THERMAL_OPERATOR_AND:
				case THERMAL_OPERATOR_SHIFT_LEFT:
				case THERMAL_OPERATOR_SHIFT_RIGHT:
				case THERMAL_OPERATOR_MOD:
				case THERMAL_OPERATOR_PLUS_EQUALS:
				case THERMAL_OPERATOR_MINUS_EQUALS:
				case THERMAL_OPERATOR_MULTIPLY_EQUALS:
				case THERMAL_OPERATOR_DIVIDE_EQUALS:
				case THERMAL_OPERATOR_XOR_EQUALS:
				case THERMAL_OPERATOR_OR_EQUALS:
				case THERMAL_OPERATOR_AND_EQUALS:
				case THERMAL_OPERATOR_SHIFT_LEFT_EQUALS:
				case THERMAL_OPERATOR_SHIFT_RIGHT_EQUALS:
				case THERMAL_OPERATOR_MOD_EQUALS:
			}
			return true;
		}
};
