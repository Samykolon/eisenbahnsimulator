#pragma once
#include "TileRail.h"

[Serializable]
public ref class TrainStop : TileRail { //A train stop
public:
	property double WaitingTime;
	property double TimeLeft;
			
public:
	TrainStop(Directions dir, double waitTime,  String^ imagePath, String^ name);		
};