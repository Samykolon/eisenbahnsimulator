#pragma once
#include "TileRail.h"
#include "Train.h"

public ref class RailSwitch : Rail{	
public:
	Direction ThirdDirection;	//The direction not currently enabled
	Boolean Active; // Determines if the switch has been activated
	RailSwitch(Directions railDir, Direction switchDir, String^ imagePath, String^ name);
	void Switch(List<Train^> trains);

};