#pragma once
#include "Position.h"

public ref class Pose : Point {
	double orientation;
public:
	property double Orientation {
		void set(double angle) {
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
	Pose(int xi, int yi, double orientation) {

	}

};