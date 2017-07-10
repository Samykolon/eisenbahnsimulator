﻿#include "TileSignalRail.h"


inline SignalRail::SignalRail(Directions dir, String^ imagePath_1, String^ imagePath_2, String ^name) : Rail(dir, imagePath_1, name){
	IsGreen = true;
	imagePath1 = imagePath_1;
	imagePath2 = imagePath_2;
	//TODO: Show if active
	
}

void SignalRail::Switch()
{
	isGreen = !isGreen;
}

