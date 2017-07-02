#pragma once
#include "Rail.h"

public ref class SignalRail : Rail { //A rail with a signal
private:
	double greenDuration;
	double redDuration;
	double timer;
	//TODO: ImagePath property
public:
	Boolean IsGreen;


	SignalRail(int xi, int yi, Directions dir, double gdur, double rdur);
	void Tick(double time); //Time passes, activity may change
};