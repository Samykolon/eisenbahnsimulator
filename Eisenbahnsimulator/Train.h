#pragma once
#include "TileObject.h"
#include "Rail.h"

using namespace System;

public enum class TrainType { SteamEngine, DieselEngine, ElectricLocomotive };

public ref class Train {
public:
	TrainType Type;
	String^ Name;
	double Speed; 
	double MaxSpeed;
	double TileProgress;	//A number between 0 and 2+pi/4 (curve) or 4 that determines the location of the train on the tile
	Direction StartDirection;
	Direction GoalDirection;
	TileObject^ Tile;		// Determines the tile location and the type of object the Train is driving on
public:
	Train(TrainType typ, String ^ nm, Direction start, Direction goal, Rail ^ to);
};