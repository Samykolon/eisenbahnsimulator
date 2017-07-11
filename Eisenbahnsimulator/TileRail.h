#pragma once
#include "TileObject.h"
#include "Pose.h"

using namespace System;

[Serializable]
public ref class Rail : TileObject
{
protected:
	bool isGreen;


public:
	Directions EndDirections; //The directions of both rail ends
	Boolean LeadsTo(Direction dir); //Returns true if the Rail leads to the specified direction

public:
	Rail(Directions _dir, String^ imagePath, String^ name);
	virtual Pose getPose(Direction startDirection, double tileProgress, int tileSize); //Returns the pixel position of a train on a rail
	property bool IsGreen
	{
		bool get();
	}
};