#pragma once
using namespace System;

ref class TileObject;
ref class Rail;
ref class SignalRail;
ref class TrainStop;
ref class SignalRail;
ref class RailSwitch;
ref class Decoraction;


struct pos
{
	int posX;
	int posY;

	bool operator == (pos position)
	{
		if (position.posX == posX && position.posY == posY)
		{
			return true;
		}
		return false;
	}

};

public enum class Directions { //Two cardinal directions
	NorthEast = 0, EastNorth = 0, NorthSouth = 1, SouthNorth = 1,
	NorthWest = 2, WestNorth = 2, EastSouth = 3, SouthEast = 3,
	EastWest = 4, WestEast = 4, SouthWest = 5, WestSouth = 5
};

public enum class Direction { East, North, West, South }; //One cardinal direction

public ref class TileObject abstract //A basic tile
{
protected:
	String^ imagePath;
	String^ name;
public:
	int x;	//x coordinate
	int y;	//y coordinate

	//TODO: Make virtual?
	TileObject(String^ _imagePath, String^ _name); //Constructs a Tileobject with an X and Y coordinate

	void setPosition(int _x, int _y);
	pos	getPosition()
	{
		pos temp = { x, y };
		return temp;
	}

	// TODO: is this really necessary? At least set
	virtual property String^ ImagePath 
	{
		String^ get() {
			return imagePath;
		}
		void set(String^ _imagePath) {
			imagePath = _imagePath;
		}
	}
};
