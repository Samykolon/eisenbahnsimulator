#pragma once
using namespace System;

public ref class Train {
	enum Direction { East, North, West, South };
public:
	property String^ Name;
	property double Speed;
	property double MaxSpeed;
	property int X;
	property int Y;
	property double TileProgress;
	property Direction StartDirection;
	property Direction GoalDirection;
	Train(String^ nm, int ix, int iy, Direction start, Direction goal);

};