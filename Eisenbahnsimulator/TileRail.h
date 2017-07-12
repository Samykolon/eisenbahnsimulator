#pragma once
#include "TileObject.h"
#include "Pose.h"

using namespace System;

[Serializable]
public ref class TileRail : TileObject
{
protected:
	bool isGreen;
	bool reserved;

public:
	Directions EndDirections; //The directions of both rail ends
	Boolean LeadsTo(Direction dir); //Returns true if the Rail leads to the specified direction

	Direction EndDirection(Direction _startDir);

	bool reserve();
	void setFree();
public:
	TileRail(Directions _dir, String^ imagePath, String^ name);
	virtual Pose getPose(Direction startDirection, double tileProgress); //Returns the position of a train on a rail
	property bool IsGreen
	{
		bool get();
	}

	property bool isRail
	{
		bool get() override;
	}
	property bool isReserved
	{
		bool get() override;
	}
};