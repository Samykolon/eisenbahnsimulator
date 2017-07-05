#pragma once
using namespace System;
using namespace System::Drawing;

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
	Point position;
public:
	//TODO: Make virtual?
	TileObject(String^ _imagePath, String^ _id_name); 

	virtual void Tick(double time);

	virtual Object ^Clone();

	virtual property Point Position
	{
		Point get();
		void set(Point _position);
	}

	virtual property String^ ImagePath
	{
		String^ get();
		void set(String ^_imagePath);
	}
};
