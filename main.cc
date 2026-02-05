#include <string>
#include <stdio.h>
#include <typeinfo>
#include "thermalDebugIntegrator.class.h"

int main(int argc, char *argv[]){
	ThermalDebugIntegrator tdi;
	int a, b, x, y, z;
	printf("Creating Algorithm...\n");
	tdi.newAlgorithm("Test Algo", "An algorithm to test the core functionality of thermal debug.", "./sample.ted");
	printf("Creating step.\n");
	tdi.newStep("Random Step", "A step that does something so we can test.", "main.cc", 10, 10);
	printf("Declaring variables.\n");
	tdi.declareStepVariable("int", "a", (void *)&a);
	tdi.declareStepVariable("int", "b", (void *)&b);
	tdi.declareStepVariable("int", "b", (void *)&b);
	tdi.declareStepVariable("int", "x", (void *)&x);
	tdi.declareStepVariable("int", "y", (void *)&y);
	tdi.declareStepVariable("int", "z", (void *)&z);

	tdi.operationEquals("a", 5);//a=5;
	tdi.operationEquals("b", 4);//b=4;
	x = a + b;
	y = x * a;
	z = y ^ b;
	
	return 0;
}
