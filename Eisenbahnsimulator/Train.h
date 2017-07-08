#pragma once
#include "TileObject.h"
#include "TileRail.h"

ref class Train;

#include "AppData.h"


using namespace System;

public enum class TrainType { SteamEngine, DieselEngine, ElectricLocomotive };

public ref class Train : public ICloneable
{
protected:
	TrainType Type;
	String^ name;
	String^ imagePath;
	double Speed;
	double MaxSpeed;
	double TileProgress;	//A number between 0 and 2+pi/4 (curve) or 4 that determines the location of the train on the tile
	int tileSize;
	Direction StartDirection;
	Direction GoalDirection;
	TileObject^ Tile;		// Determines the tile location and the type of object the Train is driving on
	Pose CurrentPose; //The train's current pose

public:
	Train(TrainType typ, String ^ nm, String^ _imagePath, int _maxSpeed);//, Direction start, Direction goal, Rail ^ to, String^ _imagePath, int tileSize);
	void setOnRail(Rail^ _rail);
#pragma region Properties
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
	
	property int TileSize
	{
		int get();
		void set(int _tileSize);
	}
#pragma endregion
	virtual Object ^Clone();
	virtual Object ^Clone(String ^_name);

	void tick(double _time);

};