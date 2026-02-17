#include <string>
#include <stdio.h>
#include <typeinfo>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <wchar.h>
#include <locale.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdint>
#include "./ThermalDebugIntegrator.class.h"
#include "./ThermalDebug.class.h"

int main(int argc, char *argv[]){
	fwide(stdout, 1);
	if(thermalDbg.loadAlgorithms(argc, argv) == false) return 1;
	if(thermalDbg.loadDisplay() == false) return 1;
	
	return 0;
}
