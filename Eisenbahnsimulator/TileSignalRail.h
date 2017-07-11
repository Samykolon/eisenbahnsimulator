#pragma once
#include "TileRail.h"

[Serializable]
public ref class SignalRail : Rail { //A rail with a signal
private:
		
	String ^imagePath1, ^imagePath2;
	//TODO: ImagePath property
public:
	//Boolean IsGreen;
	property String^ ImagePath {
		String^ get() override{
			if (isGreen) {
				return imagePath1;//(imagePath->Remove(imagePath->Length - 4) + L"_SignalGreen.png");//Append correct signal to standard imagePath

			}
			else
				return imagePath2;//(imagePath->Remove(imagePath->Length - 4) + L"_SignalRed.png");
		}		
	}
	SignalRail(Directions dir, String^ imagePath_1, String^ imagePath_2, String ^name);
	void Switch(); //Switches the signal from green to red an vice versa

};