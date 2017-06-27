#pragma once
#include "Object.h"

using namespace System;

public ref class Train {
	enum class Direction { East, North, West, South };
public:
	property String^ Name;
	property double Speed;
	property double MaxSpeed;
	property int X;
	property int Y;
	property double TileProgress; //A number between 0  and 2+pi/4 that determines the location of the train on the tile
	property Direction StartDirection;
	property Direction GoalDirection;
	Train(String^ nm, int ix, int iy, Direction start, Direction goal);

};