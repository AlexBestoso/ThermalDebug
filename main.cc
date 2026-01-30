#include <string>
#include <stdio.h>
#include "thermalDebugIntegrator.class.h"

int main(int argc, char *argv[]){
	printf("Hello\n");
	ThermalVariable nig;
	nig.create("int", "penis", std::to_string(42069));
	int nog = ((int*)nig.getValue())[0];
	printf("Nog : %d\n", nog);
	return 0;
}
