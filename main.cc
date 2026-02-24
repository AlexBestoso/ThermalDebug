#include <string>
#include <stdio.h>
#include <typeinfo>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <wchar.h>
#include <locale.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdint>
#include "./ThermalDebugIntegrator.class.h"
#include "./ThermalDebug.class.h"

int main(int argc, char *argv[]){
	fwide(stdout, 1);
	signal(SIGWINCH, THERMAL_DISPLAY_FUNC_RESIZE);

	if(thermalDbg.loadAlgorithms(argc, argv) == false) return 1;
	if(thermalDbg.loadDisplay() == false) return 1;

	// TODO: define how we will loop.
	thermalDbg.run();

	thermalDbg.killDisplay();
}
