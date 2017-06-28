#pragma once
#include "Rail.h"

public ref class SignalRail : Rail { //A rail with a signal
	Signal^ Signal;

	SignalRail(Directions dir) : Rail(dir) {
		Signal = nullptr;
	}
	

};