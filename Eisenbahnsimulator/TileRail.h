#pragma once
#include "TileObject.h"
#include "Pose.h"

using namespace System;

public ref class Rail : TileObject
{
public:
	Directions EndDirections; //The directions of both rail ends
	Boolean LeadsTo(Direction dir); //Returns true if the Rail leads to the specified direction

public:
	Rail(Directions _dir, String^ imagePath, String^ name);
	virtual Pose Drive(Direction startDirection, double% tileProgress, int tileSize, double% speed, double maxSpeed, double speedLimit); //Returns the pixel position of a train on a rail
};