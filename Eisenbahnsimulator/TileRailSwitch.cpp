#include "TileRailSwitch.h"

RailSwitch::RailSwitch(Directions railDir, Direction thirdDir, String^ imagePath, String^ name) : Rail(railDir, imagePath, name) {
	//TODO: Check if the switch direction and the rail directions are the same?
	//TODO: Assign correct images
	ThirdDirection = thirdDir;
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
	//Insert switch code here
}

