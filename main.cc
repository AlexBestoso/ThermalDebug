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
#include <termios.h>
#include "./ThermalDebugIntegrator.class.h"
#include "./ThermalDebug.class.h"

int main(int argc, char *argv[]){

	fwide(stdout, 1);
	
	if(thermalDbg.loadAlgorithms(argc, argv) == false) return 1;
	if(thermalDbg.loadDisplay() == false) return 1;

	struct termios t;
	tcgetattr(1, &t);
	termInitSrc = t;
	atexit(THERMAL_CLEANUP);
	signal(SIGTERM, THERMAL_DIE);
	signal(SIGINT, THERMAL_DIE);
	signal(SIGWINCH, THERMAL_DISPLAY_FUNC_RESIZE);
	
	t.c_lflag &= (~ECHO & ~ICANON);
	tcsetattr(1, TCSANOW, &t);


	// TODO: define how we will loop.
	
	thermalDbg.run();

	thermalDbg.killDisplay();
}
