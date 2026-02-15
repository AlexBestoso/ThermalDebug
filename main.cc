#include <string>
#include <stdio.h>
#include <typeinfo>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "./ThermalDebugIntegrator.class.h"
#include "./ThermalDebug.class.h"

int main(int argc, char *argv[]){
	if(thermalDbg.loadAlgorithms(argc, argv) == false) return 1;
	return 0;
}
