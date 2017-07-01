#include "SignalRail.h"

inline SignalRail::SignalRail(int xi, int yi, Directions dir, double dur) : Rail(xi, yi, dir), Duration(dur) {
	
	//TODO: Show if active
	switch (dir)
	{
	case Directions::NorthEast:
		ImagePath = L"Rail_Curve_RightTop_SignalGreen.png";
		break;
	case Directions::NorthSouth:
		ImagePath = L"Rail_Normal_Vert_SignalGreen.png";
		break;
	case Directions::NorthWest:
		ImagePath = L"Rail_Curve_LeftTop_SignalGreen.png";
		break;
	case Directions::EastSouth:
		ImagePath = L"Rail_Curve_RightBottom_SignalGreen.png";
		break;
	case Directions::EastWest:
		ImagePath = L"Rail_Normal_Hor_SignalGreen.png";
		break;
	case Directions::SouthWest:
		ImagePath = L"Rail_Curve_LeftBottom_SignalGreen.png";
		break;
	default:
		break;
	}
}
