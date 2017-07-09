#include "TileRailSwitch.h"

RailSwitch::RailSwitch(Directions railDir, Direction switchDir, Direction straightSwitch, String^ imagePath, String^ name) : Rail(railDir, imagePath, name) {
	//TODO: Check if the switch direction and the rail directions are the same?
	//TODO: Assign correct images
	SwitchDirection = switchDir;
	StraightSwitchDirection = straightSwitch;
}

void RailSwitch::Switch(List<Train^> trains)
{
	//Check if no train is on the same tile
	for each (Train^ tr in trains)
	{
		if (tr->Tile == this) { 
			return;
		}
	}
	//Insert switch code here, and change ImagePath
	if (IsStraight) {
		//EndDirections = FixedDirection + SwitchDirection
	}
	else {
		//EndDirections = FixedDirection + SwitchDirection
	}
}

