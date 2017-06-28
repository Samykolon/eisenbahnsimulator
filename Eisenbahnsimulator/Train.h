#pragma once
#include "Object.h"

using namespace System;

public ref class Train {
	
public:
	property String^ Name;
	property double Speed; 
	property double MaxSpeed;
	property double TileProgress;	//A number between 0 and 2+pi/4 (curve) or 4 that determines the location of the train on the tile
	property Direction StartDirection;
	property Direction GoalDirection;
	TileObject^ Tile;		// Determines the tile location and the type of object the Train is driving on
	Train(String ^ nm, Direction start, Direction goal, TileObject ^ to);
};