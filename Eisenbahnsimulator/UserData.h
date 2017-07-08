#pragma once
#include "Map.h"
#include "Train.h"

ref class Userdata
{
public:
	List<Train^>^ trainList;
	Map^ map;
	Userdata(int _height, int _width);
	void SaveDataToFile(String^ filename);
	void LoadDataFromFile(String ^filename);
	void AddTrain(TrainType tt, int xi, int yi);
	int tileSize;
};