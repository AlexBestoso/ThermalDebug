#include "./ThermalInput.class.h"
#include "./ThermalOutput.class.h"
struct thermalOperation{
	std::string name;
	std::string description;
	size_t inputCount;
	ThermalInput *inputs;
	size_t outputCount;
	ThermalOutput *outputs;
};
#include "./ThermalOperation.class.h"

struct thermalStep{
	std::string name;
	std::string description;
	std::string srcFileName;
	int startingLineNumber;
	int endingLineNumber;
	size_t operationCount;
	ThermalOperation *operationChain;
	
};
#include "./ThermalStep.class.h"

struct thermalAlgorithm{
	std::string name;
	std::string description;
	std::string outputLoc;
	size_t outBufferSize;
	uint8_t *outBuff;
	size_t stepCount;
	ThermalStep *stepChain;
};
#include "./ThermalAlgorithm.class.h"

class ThermalDebugIntegrator{
	private:
		ThermalAlgorithm currentAlgo;
	public:
	
		ThermalDebugIntegrator(){

		}
		
		~ThermalDebugIntegrator(){

		}
};
