#pragma once
#include "TileRail.h"

public ref class TrainStop : Rail { //A train stop
	int Importance; //The likeliness of a train stopping there
		
public:
	TrainStop(Directions dir, int imp, String^ imagePath, String^ name);
};