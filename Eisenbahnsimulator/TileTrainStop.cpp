#include "TileTrainStop.h"

inline TrainStop::TrainStop(Directions dir, double waitTime, String^ imagePath, String^ name) : TileRail(dir, imagePath, name){
	WaitingTime = waitTime;
}
