#pragma once
#include "TileObject.h"
#include "Signal.h"

using namespace System;

public ref class Rail : TileObject
{
private:
	Signal ^signal;

public:
	Rail(Directions _dir)
	{
		Directions = _dir;
		signal = nullptr;
	}
	void setSignal(Signal ^_sig)
	{
		signal = _sig;
	}
	Signal ^setSignal()
	{
		return signal;
	}
	Directions Directions; //The directions of both rail ends

	Boolean LeadsTo(Direction dir); //Returns true if the Rail leads to the specified direction
};