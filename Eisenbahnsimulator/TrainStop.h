#pragma once
#include "Rail.h"

public ref class TrainStop : Rail { //A train stop
	int Importance; //The likeliness of a train stopping there

	TrainStop(Directions dir, int imp): Rail(dir), Importance(imp){}
};