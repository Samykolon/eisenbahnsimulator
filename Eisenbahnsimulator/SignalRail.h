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
	property String^ ImagePath {
		String^ get() override{
			if (IsGreen) {					
				return (imagePath->Remove(imagePath->Length - 4) + L"_SignalGreen.png");//Append correct signal to standard imagePath
				
			}
			else
				return (imagePath->Remove(imagePath->Length - 4) + L"_SignalRed.png");
		}		
	}
	SignalRail(int xi, int yi, Directions dir, double gdur, double rdur);
	void Tick(double time); //Time passes, activity may change
	
};