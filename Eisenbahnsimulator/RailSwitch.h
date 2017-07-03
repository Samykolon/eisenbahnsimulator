#pragma once
#include "Rail.h"

public ref class RailSwitch : Rail{
	Direction SwitchDirection;	//Determines to which direction the train is guided when the switch is activated
	Boolean Active; // Determines if the dwitch has been activated

	RailSwitch(Directions railDir, Direction switchDir, String^ imagePath, String^ name);
	
};