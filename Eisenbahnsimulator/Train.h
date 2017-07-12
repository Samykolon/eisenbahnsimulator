#pragma once
#include "TileObject.h"
#include "TileRail.h"
#include "Map.h"

ref class Train; //Forward declaration because of classes including each other

#include "AppData.h"
#include "TileTrainStop.h"


using namespace System;

public enum class TrainType { SteamEngine, DieselEngine, ElectricLocomotive };
[Serializable]
public ref class Train : public ICloneable
{
protected:
	String^ name;
	String^ imagePath;
		//A number between 0 and 2+pi/2 (curve) or 4 that determines the location of the train on the tile
	int tileSize;
	double Speed;
	double MaxSpeed;
	double speedLimit;
	
	Boolean drivesforward;
	double waitingTimeLeft;
	Boolean hasAlreadyStopped;
	Pose currentPose; //A pose that describes the train's current position on the panel, coordinates and orientation
public:
	property Direction StartDirection;
	property int X;
	property int Y;
	property Direction GoalDirection;
	property double TileProgress;	
	property TrainType Type;
	TileObject^ Tile;		// Determines the tile location and the type of object the Train is driving on
	static Direction FindOppositeDirection(Direction dir);
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
	property double MaximumSpeed
	{
		double get();
		void set(double _MaxSpeed);
	}
	property Boolean DrivesForward
	{
		Boolean get();
		void set(Boolean _drivesforward);
	}
	property double SpeedLimit
	{
		double get();
		void set(double _speedLimit);
	}
	property double CurrentSpeed
	{
		double get();
		void set(double _speed);
	}

	property Pose CurrentPose
	{
		Pose get();
		void set(Pose pose);
	}

#pragma endregion
	virtual Object ^Clone();
	virtual Object ^Clone(String ^_name);

	void Tick(double _time, Map^ map); //Updates the train's pose
	void SwitchDirection();

};