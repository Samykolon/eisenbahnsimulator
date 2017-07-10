﻿#pragma once
#include "TileObject.h"
#include "TileRail.h"
#include "Map.h"

ref class Train; //Forward declaration because of classes including each other

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
	double TileProgress;	//A number between 0 and 2+pi/2 (curve) or 4 that determines the location of the train on the tile
	int tileSize;
	Direction StartDirection;
	Direction GoalDirection;
public:
	TileObject^ Tile;		// Determines the tile location and the type of object the Train is driving on
	Pose CurrentPose; //A pose that describes the train's current position on the panel, including pixel coordinates and orientation
	static Direction FindOppositeDirection(Direction dir);
	double MaxSpeed;
public:
	Train(TrainType typ, String ^ nm, String^ _imagePath, int _maxSpeed);//, Direction start, Direction goal, Rail ^ to, String^ _imagePath, int tileSize);
	void setOnRail(Rail^ _rail); //Initializes the train's pose, directions, tileprogress
	void setOnRail(Rail^ newRail, Direction startDir); //Initializes the train's directions coming from another rail
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

	void Tick(double _time, Map^ map); //Updates the train's pose

};