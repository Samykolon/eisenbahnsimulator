#pragma once
using namespace System;

ref class TileObject;
ref class Rail;
ref class SignalRail;
ref class TrainStop;
ref class SignalRail;
ref class RailSwitch;
ref class Decoraction;

public ref class Pos
{
public:
	int posX;
	int posY;

	bool operator == (Pos ^_position)
	{
		// true if position x and y are equal
		return (_position->posX == posX && _position->posY == posY);
	}
	Pos(int _posX, int _posY) : posX(_posX), posY(_posY){}
};

public enum class Directions { //Two cardinal directions
	NorthEast = 0, EastNorth = 0, NorthSouth = 1, SouthNorth = 1,
	NorthWest = 2, WestNorth = 2, EastSouth = 3, SouthEast = 3,
	EastWest = 4, WestEast = 4, SouthWest = 5, WestSouth = 5
};

public enum class Direction { East, North, West, South }; //One cardinal direction

public ref class TileObject abstract : public ICloneable//A basic tile
{
protected:
	String^ imagePath;
	String^ name;
public:
	Pos ^coord; // coordinates of Tile
	//TODO: Make virtual?
	TileObject(String^ _imagePath, String^ _name); //Constructs a Tileobject with an X and Y coordinate

	void setPosition(int _x, int _y);
	Pos ^getPosition()
	{
		return coord;
	}

	virtual void Tick(double d)
	{

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
	virtual Object ^Clone()
	{
		return MemberwiseClone();
	}

};
