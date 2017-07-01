#pragma once
#include "Rail.h"

public ref class SignalRail : Rail { //A rail with a signal
	double Duration;

	SignalRail(int xi, int yi, Directions dir, double dur);
};