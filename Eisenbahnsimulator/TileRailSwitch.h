#pragma once
#include "TileRail.h"
#include "Train.h"

public ref class RailSwitch : Rail{	
public:
	Boolean IsStraight;	//The direction currently enabled
	Direction StraightSwitchDirection; //Straight direction, can be enabled or disabled
	Direction SwitchDirection;	//The direction perpendicular to the rail
	Direction FixedDirection;	//The direction that never switches
	Boolean Active; // Determines if the switch has been activated
	RailSwitch(Directions railDir, Direction switchDir, Direction straightSwitch, String^ imagePath, String^ name);
	void Switch(List<Train^> trains); //Switches the switch direction with the 
};