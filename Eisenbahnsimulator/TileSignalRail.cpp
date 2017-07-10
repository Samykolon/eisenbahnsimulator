#include "TileSignalRail.h"


inline SignalRail::SignalRail(Directions dir, String^ imagePath_1, String^ imagePath_2, String ^name) : Rail(dir, imagePath_1, name){
	IsGreen = true;
	imagePath1 = imagePath_1;
	imagePath2 = imagePath_2;
	//TODO: Show if active
	
}


Pose SignalRail::Drive(Direction startDirection, double % tileProgress, int tileSize, double % speed, double maxSpeed)
{
	double sp = 0;
	if (IsGreen) {
		return Rail::Drive(startDirection, tileProgress, tileSize, speed, maxSpeed);
	}
	else		
		return Rail::Drive(startDirection, tileProgress, tileSize, sp, 0);
	
}

void SignalRail::Switch()
{
	if (IsGreen) {
		IsGreen = false;
	}
	else {
		IsGreen = true;
	}
}

