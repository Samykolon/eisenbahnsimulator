#include "TileSignalRail.h"


inline SignalRail::SignalRail(Directions dir, double gdur, double rdur, String^ imagePath_1, String^ imagePath_2, String ^name) : Rail(dir, imagePath_1, name), greenDuration(gdur), redDuration(rdur){
	timer = 0;
	IsGreen = true;
	imagePath1 = imagePath_1;
	imagePath2 = imagePath_2;
	//TODO: Show if active
	
}


Pose SignalRail::Drive(Direction startDirection, double % tileProgress, int tileSize, double % speed, double maxSpeed, double speedLimit)
{
	double sp = 0;
	if (IsGreen) {
		return Rail::Drive(startDirection, tileProgress, tileSize, speed, maxSpeed, speedLimit);
	}
	else		
		return Rail::Drive(startDirection, tileProgress, tileSize, sp, 0, 0);
	
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

