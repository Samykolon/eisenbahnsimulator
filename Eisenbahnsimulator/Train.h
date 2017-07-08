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
	String^ name;
	String^ imagePath;
	double Speed; 
	double MaxSpeed;
	double TileProgress;	//A number between 0 and 2+pi/4 (curve) or 4 that determines the location of the train on the tile
	Direction StartDirection;
	Direction GoalDirection;
	TileObject^ Tile;		// Determines the tile location and the type of object the Train is driving on
	Pose CurrentPose; //The train's current pose
public:
	Train(TrainType typ, String ^ nm, Direction start, Direction goal, Rail ^ to, String^ _imagePath, int tileSize);

	property String^ ImagePath
	{
		String^ get();
		void set(String^ _imagePath);
	}
	property String^ Name
	{
		String^ get();
		void set(String^ _name);
	}
	
	virtual Object ^Clone();
	virtual Object ^Clone(String ^_name);

};