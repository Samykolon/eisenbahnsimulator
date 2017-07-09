#pragma once

using namespace System::Drawing;

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