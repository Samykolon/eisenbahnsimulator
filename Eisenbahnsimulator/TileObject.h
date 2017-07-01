#pragma once
using namespace System;

public enum class Directions { //Two cardinal directions
	NorthEast = 0, EastNorth = 0, NorthSouth = 1, SouthNorth = 1,
	NorthWest = 2, WestNorth = 2, EastSouth = 3, SouthEast = 3,
	EastWest = 4, WestEast = 4, SouthWest = 5, WestSouth = 5
};

public enum class Direction { East, North, West, South }; //One cardinal direction

public ref class TileObject abstract //A basic tile
{
public:
	int X;	//x coordinate
	int Y;	//y coordinate
	String^ ImagePath;

	//TODO: Make virtual?
	TileObject(int xi, int yi); //Constructs a Tileobject with an X and Y coordinate
	
};
