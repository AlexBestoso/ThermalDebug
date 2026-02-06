#include <string>
#include <stdio.h>
#include <typeinfo>
#include "thermalDebugIntegrator.class.h"

int main(int argc, char *argv[]){
	int a=0, b=0, x, y, z;
	ThermalDebugIntegrator tdi;

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

	tdi.operation("a", "=", 5);//a=5;
	tdi.operation("b", "=", 4);//b=4;
	printf("A: %d\n", a);
	printf("B: %d\n", b);
	tdi.operation("a", "+", "b", "x");//x = a + b;
	printf("X: %d\n", x);
	tdi.operation("x", "*", "a", "y");//y = x * a;
	printf("Y: %d\n", y);
	tdi.operation("y", "^", "b", "z");//z = y ^ b;
	printf("Z: %d\n", z);
	
	return 0;
}
