#pragma once
#include "TileRail.h"

public ref class SignalRail : Rail { //A rail with a signal
private:
	
	double greenDuration;
	double redDuration;
	double timer;
	String ^imagePath1, ^imagePath2;
	//TODO: ImagePath property
public:
	Boolean IsGreen;
	property String^ ImagePath {
		String^ get() override{
			if (IsGreen) {
				return imagePath1;//(imagePath->Remove(imagePath->Length - 4) + L"_SignalGreen.png");//Append correct signal to standard imagePath

			}
			else
				return imagePath2;//(imagePath->Remove(imagePath->Length - 4) + L"_SignalRed.png");
		}		
	}
	SignalRail(Directions dir, double gdur, double rdur, String^ imagePath_1, String^ imagePath_2, String ^name);
	void Tick(double time) override; //Time passes, activity may change
	
};