#include <string>
#include <stdio.h>
#include <typeinfo>
#include "thermalDebugIntegrator.class.h"

int main(int argc, char *argv[]){
	printf("Hello\n");
	ThermalVariable variable;
	int val = 1234;
	variable.create("int", "val", (void *)&val);
	printf("Variable: %s %s %d\n", variable.getDataType().c_str(), variable.getName().c_str(), ((int *)variable.getValue())[0]);

	val = 5;

	printf("updated Variable: %s %s %d\n", variable.getDataType().c_str(), variable.getName().c_str(), ((int *)variable.getValue())[0]);

	return 0;
}
