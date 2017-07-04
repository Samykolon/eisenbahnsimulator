#pragma once
public ref class Pos
{
public:
	int posX;
	int posY;

	bool operator == (Pos ^_position);
	Pos(int _posX, int _posY);
	Pos(const Pos% pos);
};




public enum class Directions { //Two cardinal directions
	NorthEast = 0, EastNorth = 0, NorthSouth = 1, SouthNorth = 1,
	NorthWest = 2, WestNorth = 2, EastSouth = 3, SouthEast = 3,
	EastWest = 4, WestEast = 4, SouthWest = 5, WestSouth = 5
};

public enum class Direction { East, North, West, South }; //One cardinal direction