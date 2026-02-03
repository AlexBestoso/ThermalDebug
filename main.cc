#include <string>
#include <stdio.h>
#include <typeinfo>
#include "thermalDebugIntegrator.class.h"

int main(int argc, char *argv[]){
	ThermalDebugIntegrator tdi;
	int a=5;
	int b=4;
	printf("Creating Algorithm...\n");
	tdi.newAlgorithm("Test Algo", "An algorithm to test the core functionality of thermal debug.", "./sample.ted");
	printf("Creating step.\n");
	tdi.newStep("Random Step", "A step that does something so we can test.", "main.cc", 10, 10);
	printf("Declaring variable A.\n");
	tdi.declareStepVariable("int", "a", (void *)&a);
	printf("Declaring variable B.\n");
	tdi.declareStepVariable("int", "b", (void *)&b);
	
	return 0;
}
