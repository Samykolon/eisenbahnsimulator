#pragma once
#include "TileObject.h"
#include "TileRail.h"

ref class Train;

#include "AppData.h"


using namespace System;

public enum class TrainType { SteamEngine, DieselEngine, ElectricLocomotive };

public ref class Train : public ICloneable
{
public:
	TrainType Type;
	String^ Name;
	String^ imagePath;
	double Speed; 
	double MaxSpeed;
	double TileProgress;	//A number between 0 and 2+pi/4 (curve) or 4 that determines the location of the train on the tile
	Direction StartDirection;
	Direction GoalDirection;
	TileObject^ Tile;		// Determines the tile location and the type of object the Train is driving on
public:
	Train(TrainType typ, String ^ nm, Direction start, Direction goal, Rail ^ to, String^ _imagePath);

	property String^ ImagePath
	{
		String^ get() {
			return imagePath;
		}
		void set(String^ _imagePath) {
			imagePath = _imagePath;
		}
	}
	
	virtual Object ^Clone();

};