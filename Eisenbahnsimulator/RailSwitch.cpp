#include "RailSwitch.h"

RailSwitch::RailSwitch(Directions railDir, Direction switchDir, String^ imagePath, String^ name) : Rail(railDir, imagePath, name) {
	//TODO: Check if the switch direction and the rail directions are the same?
	//TODO: Assign correct images
	SwitchDirection = switchDir;
}
