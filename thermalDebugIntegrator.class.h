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

		bool operate(){

			return false;
		}
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
		
		bool operation(std::string varA, std::string operation, int integer){
			return false;	
		}
		bool operation(std::string varA, std::string operation, std::string varB){
			return this->operation(varA, operation, varB, "");
		}
		bool operation(std::string varA, std::string operation, std::string varB, std::string outputVar){
			ThermalStep step = this->getCurrentStep();
			ThermalVariable a = step.getVariableByName(varA);
			ThermalVariable b = step.getVariableByName(varB);
			ThermalVariable out = step.getVariableByName(outputVar);
			ThermalOperation thermalOperation;
			int operationIndex = thermalOperation.stringToOperationIndex(operation);
			switch(operationIndex){
				case THERMAL_OPERATOR_INVALID:
					return false;
				case THERMAL_OPERATOR_EQUALS:{
					thermalOperation.equals(a, b);
					break;
				}
				case THERMAL_OPERATOR_PLUS:
					break;
				case THERMAL_OPERATOR_MINUS:
					break;
				case THERMAL_OPERATOR_MULTIPLY:
					break;
				case THERMAL_OPERATOR_DIVIDE:
					break;
				case THERMAL_OPERATOR_XOR:
					break;
				case THERMAL_OPERATOR_OR:
					break;
				case THERMAL_OPERATOR_AND:
					break;
				case THERMAL_OPERATOR_SHIFT_LEFT:
					break;
				case THERMAL_OPERATOR_SHIFT_RIGHT:
					break;
				case THERMAL_OPERATOR_MOD:
					break;
				case THERMAL_OPERATOR_PLUS_EQUALS:
					break;
				case THERMAL_OPERATOR_MINUS_EQUALS:
					break;
				case THERMAL_OPERATOR_MULTIPLY_EQUALS:
					break;
				case THERMAL_OPERATOR_DIVIDE_EQUALS:
					break;
				case THERMAL_OPERATOR_XOR_EQUALS:
					break;
				case THERMAL_OPERATOR_OR_EQUALS:
					break;
				case THERMAL_OPERATOR_AND_EQUALS:
					break;
				case THERMAL_OPERATOR_SHIFT_LEFT_EQUALS:
					break;
				case THERMAL_OPERATOR_SHIFT_RIGHT_EQUALS:
					break;
				case THERMAL_OPERATOR_MOD_EQUALS:
					break;
			}
			return true;
		}
};
