#include "RailSwitch.h"

RailSwitch::RailSwitch(int xi, int yi, Directions railDir, Direction switchDir) : Rail(xi, yi, railDir) {
	//TODO: Check if the switch direction and the rail directions are the same?
	//TODO: Assign correct images
	SwitchDirection = switchDir;
}
