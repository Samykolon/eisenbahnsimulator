#pragma once

using namespace System;
using namespace System::Drawing;

public enum class Directions { //Two cardinal directions
	NorthEast = 0, EastNorth = 0, NorthSouth = 1, SouthNorth = 1,
	NorthWest = 2, WestNorth = 2, EastSouth = 3, SouthEast = 3,
	EastWest = 4, WestEast = 4, SouthWest = 5, WestSouth = 5
};

public enum class Direction { East, North, West, South }; //One cardinal direction

Directions AddDirections(Direction d1, Direction d2); //Returns Directions for two directions

[Serializable]
public value class Pose {
	double orientation;
public:
	int X;
	int Y;
public:
	property double Orientation { //Orientation in degrees, mathematical direction, the direction an object is facing
		void set(double angle) { //Angle is always between 0 and 360 degrees
			while(angle >= 360){
				angle = angle - 360;
			}
			while (angle < 0) {
				angle = angle + 360;
			}
			orientation = angle;
		}
		double get() {
			return orientation;
		}
	}
	Pose(int xi, int yi, double ori) {
		X = xi;
		Y = yi;
		orientation = ori;
	}

};