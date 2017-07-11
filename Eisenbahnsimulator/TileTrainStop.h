#pragma once
#include "TileRail.h"

[Serializable]
public ref class TrainStop : Rail { //A train stop
public:
	property double WaitingTime;
	property double TimeLeft;
	
		
public:
	TrainStop(Directions dir, double waitTime,  String^ imagePath, String^ name);	
	void Tick() override;
};