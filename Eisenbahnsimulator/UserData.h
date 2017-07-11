#pragma once
#include "Map.h"
#include "Train.h"
#include "AppData.h"

[Serializable]
ref class Userdata
{
public:
	List<Train^>^ trainList;
	Map^ map;
	Userdata(int _height, int _width);
	void AddTrain(Train ^_train);
	int tileSize;
};