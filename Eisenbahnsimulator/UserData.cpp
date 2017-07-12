#include "UserData.h"

Userdata::Userdata(int _height, int _width)
{
	trainList = gcnew List<Train^>;
	map = gcnew Map(_height, _width, L"Rails/grass_background.png");
	tileSize = 128;
}

void Userdata::AddTrain(Train ^_train)
{
	_train->Name += " " + (trainList->Count + 1);
	trainList->Add(_train);
}