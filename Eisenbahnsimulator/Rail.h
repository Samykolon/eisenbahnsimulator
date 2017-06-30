#pragma once
#include "TileObject.h"
#include "Signal.h"

using namespace System;

public ref class Rail : TileObject
{
public:
	Directions EndDirections; //The directions of both rail ends
	Boolean LeadsTo(Direction dir); //Returns true if the Rail leads to the specified direction

public:
	Rail(Directions _dir)
	{
		EndDirections = _dir;
	
	}

	
};