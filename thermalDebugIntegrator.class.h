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
			int v = ((int *)value)[0];
			ThermalStep step = this->getCurrentStep();

			if(!step.newVariable(type, name, value))
				return false;

			this->setCurrentStep(step);
			return true;
		}

		bool addOperator(){
			return true;
		}

};
