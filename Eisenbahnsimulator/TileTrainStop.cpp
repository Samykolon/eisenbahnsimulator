#include "TileTrainStop.h"

inline TrainStop::TrainStop(Directions dir, double waitTime, String^ imagePath, String^ name) : Rail(dir, imagePath, name){
	WaitingTime = waitTime;
}

void TrainStop::Tick()
{
	
}
