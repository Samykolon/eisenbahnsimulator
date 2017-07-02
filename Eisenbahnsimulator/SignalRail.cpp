#include "SignalRail.h"

inline SignalRail::SignalRail(int xi, int yi, Directions dir, double gdur, double rdur) : Rail(xi, yi, dir), greenDuration(gdur), redDuration(rdur){
	timer = 0;
	IsGreen = true;
	//TODO: Show if active
	
}

inline void SignalRail::Tick(double time)
{
	timer = timer + time; //Time passes
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

