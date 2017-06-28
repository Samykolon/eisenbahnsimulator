#pragma once
#include "Rail.h"

public ref class SignalRail : Rail { //A rail with a signal
	double Duration;

	SignalRail(Directions dir, double dur) : Rail(dir), Duration(dur) {}
};