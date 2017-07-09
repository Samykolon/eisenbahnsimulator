#pragma once
#include "TileRail.h"

public ref class TrainStop : Rail { //A train stop
public:
	int Importance; //The likeliness of a train stopping there
	double WaitingTime;
	double TimeLeft;
		
public:
	TrainStop(Directions dir, int imp, String^ imagePath, String^ name);	
};