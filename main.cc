#include <string>
#include <stdio.h>
#include <typeinfo>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "./ThermalDebugIntegrator.class.h"
#include "./ThermalDebug.class.h"

int main(int argc, char *argv[]){
	thermalDbg.color_greenFg();
	printf("We're currently under construction. Please use the other sidewalk.\n");	
	thermalDbg.color_reset();
	return 0;
}
