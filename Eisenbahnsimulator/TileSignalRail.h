#pragma once
#include "TileRail.h"

[Serializable]
public ref class SignalRail : TileRail { //A rail with a signal
private:

	String ^imagePath1, ^imagePath2;
public:
	property String^ ImagePath {
		String^ get() override {
			if (isGreen) {
				return imagePath1;

			}
			else
				return imagePath2;
		}
	}
	SignalRail(Directions dir, String^ imagePath_1, String^ imagePath_2, String ^name);
	void Switch(); //Switches the signal from green to red an vice versa

};