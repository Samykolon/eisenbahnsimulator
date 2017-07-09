#include "UserData.h"

Userdata::Userdata(int _height, int _width)
{
	trainList = gcnew List<Train^>;
	map = gcnew Map(_height, _width);
	tileSize = 128;
}

void Userdata::SaveDataToFile(String ^ filename)
{
	throw gcnew System::NotImplementedException();
}

void Userdata::LoadDataFromFile(String ^ filename)
{
	throw gcnew System::NotImplementedException();
}


void Userdata::AddTrain(Train ^_train)
{
	_train->Name += " " + (trainList->Count + 1);
	trainList->Add(_train);
}