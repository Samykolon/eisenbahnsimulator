#include "SignalRail.h"

inline SignalRail::SignalRail(int xi, int yi, Directions dir, double gdur, double rdur) : Rail(xi, yi, dir), greenDuration(gdur), redDuration(rdur){
	timer = 0;
	IsGreen = true;
	//TODO: Show if active
	switch (dir) //set Correct
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

inline void SignalRail::Tick(double time)
{
	timer += time; //Time passes
	
	if (timer < greenDuration) { //Green phase
		IsGreen = true;		
	}
	else if (timer < greenDuration + redDuration) { //Red Phase
		IsGreen = false;
	}
	else { //Return to loop beginning
		timer = 0;
		IsGreen = true;
	}
}

