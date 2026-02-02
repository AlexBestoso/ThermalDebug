#include <string>
#include <stdio.h>
#include <typeinfo>
#include "thermalDebugIntegrator.class.h"

int main(int argc, char *argv[]){
	printf("Hello\n");
	ThermalVariable variable;
	int val = 1234567;
	variable.create("float", "val", &val);
	int data = variable.getValueInt();//((int *)variable.getValue())[0];
	printf("Variable: %s %s %d\n", variable.getDataType().c_str(), variable.getName().c_str(), data);

	val = 987654321;
	data = variable.getValueInt();
	printf("updated Variable: %s %s %d\n", variable.getDataType().c_str(), variable.getName().c_str(), data);

	return 0;
}
