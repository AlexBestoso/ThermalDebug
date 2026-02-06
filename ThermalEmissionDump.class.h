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
	char *algorithmName[128];
	char *description[1024];
	uint64_t stepCount;
	tedstep_t *steps;
};
typedef struct thermalEmissionDump ted_t;

class ThermalEmissionDump{
	private:
		int descriptor;
		ted_t data;
	public:
};
