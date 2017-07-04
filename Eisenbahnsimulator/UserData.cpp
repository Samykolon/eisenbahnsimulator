#include "UserData.h"

Userdata::Userdata(int _height, int _width)
{
	trainList = gcnew List<Train^>;
	map = gcnew Map(_height, _width);
}

void Userdata::SaveDataToFile(String ^ filename)
{
	throw gcnew System::NotImplementedException();
}

void Userdata::LoadDataFromFile(String ^ filename)
{
	throw gcnew System::NotImplementedException();
}

void Userdata::AddTrain()
{
	throw gcnew System::NotImplementedException();
}
