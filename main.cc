#include <string>
#include <stdio.h>
#include <typeinfo>
#include "thermalDebugIntegrator.class.h"

int main(int argc, char *argv[]){
	printf("Hello\n");
	ThermalVariable variable;
	float val = 123.145666f;
	variable.create("float", "val", &val);
	float data = variable.getValueFloat();//((int *)variable.getValue())[0];
	printf("Variable: %s %s %lf\n", variable.getDataType().c_str(), variable.getName().c_str(), data);

	val = 5.123;
	data = variable.getValueFloat();
	printf("updated Variable: %s %s %f\n", variable.getDataType().c_str(), variable.getName().c_str(), data);

	return 0;
}
