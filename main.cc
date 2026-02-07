#include <string>
#include <stdio.h>
#include <typeinfo>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "thermalDebugIntegrator.class.h"

int main(int argc, char *argv[]){
	int a, b, x, y, z;
	ThermalDebugIntegrator tdi;

	printf("Creating Algorithm...\n");
	tdi.newAlgorithm("Test Algo", "An algorithm to test the core functionality of thermal debug.", "./sample.ted");
	
	printf("Creating step.\n");
	tdi.newStep("Random Step", "A step that does something so we can test.", "main.cc", 17, 31);
	
	printf("Declaring variables.\n");
	tdi.declareStepVariable("int", "a", (void *)&a);
	tdi.declareStepVariable("int", "b", (void *)&b);
	tdi.declareStepVariable("int", "b", (void *)&b);
	tdi.declareStepVariable("int", "x", (void *)&x);
	tdi.declareStepVariable("int", "y", (void *)&y);
	tdi.declareStepVariable("int", "z", (void *)&z);

	tdi.operation("a", "=", 5);
	tdi.operation("b", "=", 4);
	tdi.operation("a", "+", "b", /*=*/ "x");
	tdi.operation("x", "*", "a", /*=*/ "y");
	tdi.operation("y", "^", "b", /*=*/ "z");

	ThermalEmissionDump Ted = tdi.getTed();
	printf("Generated .ted file to %s:\n", Ted.getOutFileName().c_str());
	ted_t ted = Ted.getData();
	printf("Maigic Number: 0x%lx\nAlgorithm Name : %s\nAlgorithm Description: %s\nAlgorithm Step Count: %ld\n", ted.magic, ted.algorithmName, ted.description, ted.stepCount);
	printf("\n\t...Steps...\n\n");
	for(int i=0; i<ted.stepCount; i++){
		tedstep_t s = ted.steps[i];
		printf("Step Name: %s\n\tStep Description: %s\n\tSource File: %s\n\tLine range: %ld to %ld\n\tVariable Count: %ld\n", s.stepName, s.stepDescription, s.sourceFile, s.startLine, s.endLine, s.variableCount);
		for(int j=0; j<s.variableCount; j++){
			tedvar_t v = s.variables[j];
			printf("\t\t%s %s\n", v.variableType, v.variableName);
		}
		printf("\tOperation Count: %ld\n", s.operationCount);
	}
	
	return 0;
}
