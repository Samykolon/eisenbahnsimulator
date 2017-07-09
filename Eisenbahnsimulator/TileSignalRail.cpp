#include "TileSignalRail.h"


inline SignalRail::SignalRail(Directions dir, double gdur, double rdur, String^ imagePath_1, String^ imagePath_2, String ^name) : Rail(dir, imagePath_1, name), greenDuration(gdur), redDuration(rdur){
	timer = 0;
	IsGreen = true;
	imagePath1 = imagePath_1;
	imagePath2 = imagePath_2;
	//TODO: Show if active
	
}

inline void SignalRail::Tick(double time)
{
	timer = timer + time*20; //Time passes
	double completeTime = greenDuration + redDuration;
	if (timer <= greenDuration) {
		IsGreen = true;
	}
	else if (timer <= completeTime) {
		IsGreen = false;
	}
	else {
		timer = 0;
	}
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

