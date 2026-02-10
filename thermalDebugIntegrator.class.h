
#include "./ThermalVariable.class.h"
#include "./ThermalOperation.class.h"

#include "./ThermalStep.class.h"

#include "./ThermalAlgorithm.class.h"

class ThermalDebugIntegrator{
	private:
		bool processingAlgo;
		int stepIdx;
		int operationIdx;
		ThermalAlgorithm currentAlgo;

		bool operate(ThermalVariable a, std::string operation, ThermalVariable b, ThermalVariable c){
			ThermalOperation thermalOperation;
			int operationIndex = thermalOperation.stringToOperationIndex(operation);
			uint64_t ghostStorage = a.getValueUint64();
			switch(operationIndex){
				case THERMAL_OPERATOR_INVALID:
					return false;
				case THERMAL_OPERATOR_EQUALS:{
					c.create(a.getDataType(), a.getName(), &ghostStorage);
					thermalOperation.equals(a, b);
					break;
				}
				case THERMAL_OPERATOR_PLUS:{
					thermalOperation.add(a, b, c);
					uint64_t dbg = a.getValueAutocast();
					break;
				}
				case THERMAL_OPERATOR_MINUS:
					thermalOperation.subtract(a, b, c);
					break;
				case THERMAL_OPERATOR_MULTIPLY:
					thermalOperation.multiply(a, b, c);
					break;
				case THERMAL_OPERATOR_DIVIDE:
					thermalOperation.divide(a, b, c);
					break;
				case THERMAL_OPERATOR_XOR:
					thermalOperation.XOR(a, b, c);
					break;
				case THERMAL_OPERATOR_OR:
					thermalOperation.OR(a, b, c);
					break;
				case THERMAL_OPERATOR_AND:
					thermalOperation.AND(a, b, c);
					break;
				case THERMAL_OPERATOR_SHIFT_LEFT:
					thermalOperation.shiftLeft(a, b, c);
					break;
				case THERMAL_OPERATOR_SHIFT_RIGHT:
					thermalOperation.shiftRight(a, b, c);
					break;
				case THERMAL_OPERATOR_MOD:
					thermalOperation.mod(a, b, c);
					break;
				case THERMAL_OPERATOR_PLUS_EQUALS:
					c.create(a.getDataType(), a.getName(), &ghostStorage);
					thermalOperation.addEqual(a, b);
					break;
				case THERMAL_OPERATOR_MINUS_EQUALS:
					c.create(a.getDataType(), a.getName(), &ghostStorage);
					thermalOperation.subtractEqual(a, b);
					break;
				case THERMAL_OPERATOR_MULTIPLY_EQUALS:
					c.create(a.getDataType(), a.getName(), &ghostStorage);
					thermalOperation.multiplyEqual(a, b);
					break;
				case THERMAL_OPERATOR_DIVIDE_EQUALS:
					c.create(a.getDataType(), a.getName(), &ghostStorage);
					thermalOperation.divideEqual(a, b);
					break;
				case THERMAL_OPERATOR_XOR_EQUALS:
					c.create(a.getDataType(), a.getName(), &ghostStorage);
					thermalOperation.xorEqual(a, b);
					break;
				case THERMAL_OPERATOR_OR_EQUALS:
					c.create(a.getDataType(), a.getName(), &ghostStorage);
					thermalOperation.orEqual(a, b);
					break;
				case THERMAL_OPERATOR_AND_EQUALS:
					c.create(a.getDataType(), a.getName(), &ghostStorage);
					thermalOperation.andEqual(a, b);
					break;
				case THERMAL_OPERATOR_SHIFT_LEFT_EQUALS:
					c.create(a.getDataType(), a.getName(), &ghostStorage);
					thermalOperation.shiftLeftEqual(a, b);
					break;
				case THERMAL_OPERATOR_SHIFT_RIGHT_EQUALS:
					c.create(a.getDataType(), a.getName(), &ghostStorage);
					thermalOperation.shiftRightEqual(a, b);
					break;
				case THERMAL_OPERATOR_MOD_EQUALS:
					c.create(a.getDataType(), a.getName(), &ghostStorage);
					thermalOperation.modEqual(a, b);
					break;
			}

			
			this->currentAlgo.dumpOperation(this->stepIdx, a, b, c, operationIndex);

			return false;
		}
	public:
	
		ThermalDebugIntegrator(){
			this->processingAlgo = false;
			this->stepIdx = -1;
		}
		
		~ThermalDebugIntegrator(){

		}

		ThermalEmissionDump getTed(void){
			return this->currentAlgo.getDump();
		}

		bool newAlgorithm(std::string name, std::string desc, std::string outFile){
			if(this->processingAlgo) return false;
			this->processingAlgo = true;
			this->currentAlgo.reset();
			this->currentAlgo.setName(name);
			this->currentAlgo.setDescription(desc);
			this->currentAlgo.setOutputLoc(outFile);
			this->currentAlgo.initDump();
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
			ThermalStep *stepChain = this->currentAlgo.getStepChain();
			if(stepChain == NULL || this->stepIdx < 0 || !ret ) return false;
			
			ThermalStep step = stepChain[this->stepIdx];
			ret = this->currentAlgo.dumpStep(step);
			
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
			ThermalVariable variable = step.getVariableByIndex(step.getVariableCount()-1);
			this->currentAlgo.dumpStepVariable(this->stepIdx, variable);
			return true;
		}

		bool operation(std::string varA, std::string operation, int integer){
			ThermalStep step = this->getCurrentStep();
			ThermalVariable a = step.getVariableByName(varA);
			ThermalVariable rawInteger;
			ThermalVariable ghostVar;
			uint64_t ghostInt = (uint64_t)integer;
			rawInteger.create("uint64_t", "rawInteger", (void *)&ghostInt);
			
			return this->operate(a, operation, rawInteger, ghostVar);	
		}
		bool operation(std::string varA, std::string operation, std::string varB){
			ThermalStep step = this->getCurrentStep();
			ThermalVariable a = step.getVariableByName(varA);
			ThermalVariable b = step.getVariableByName(varB);
			ThermalVariable ghostOut;
			return this->operate(a, operation, b, ghostOut);
		}
		bool operation(std::string varA, std::string operation, std::string varB, std::string outputVar){
			ThermalStep step = this->getCurrentStep();
			ThermalVariable a = step.getVariableByName(varA);
			ThermalVariable b = step.getVariableByName(varB);
			ThermalVariable out = step.getVariableByName(outputVar);
			return this->operate(a, operation, b, out);
		}
};
