#pragma once
using namespace System;

ref class TileObject;
ref class Rail;
ref class SignalRail;
ref class TrainStop;
ref class RailSwitch;
ref class Decoraction;

#include "Position.h"

public ref class TileObject abstract : public ICloneable//A basic tile
{
protected:
	String^ imagePath;
	String^ id_name;
	Pos^ coord;
public:
	//TODO: Make virtual?
	TileObject(String^ _imagePath, String^ _id_name); 

	virtual void Tick(double time);

	virtual Object ^Clone();

	virtual property Pos^ Position
	{
		Pos^ get();
		void set(Pos^ _position);
	}

	virtual property String^ ImagePath
	{
		String^ get();
		void set(String ^_imagePath);
	}
};
