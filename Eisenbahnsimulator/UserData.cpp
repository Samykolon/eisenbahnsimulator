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


void Userdata::AddTrain(TrainType _trainType, int _posX, int _posY)
{
	Rail^ currentRail = dynamic_cast<Rail^>(map->GetTile(_posX, _posY)); //Tries to cast the object into a Rail

	if (currentRail != nullptr) { //Executed if the train is placed on a Rail
		Direction startDirection;
		Direction goalDirection;
		int directionsFound = 0;
		if (currentRail->LeadsTo(Direction::East)) { //Find startDirection
			startDirection = Direction::East;
		}
		else if (currentRail->LeadsTo(Direction::North)) {
			startDirection = Direction::North;
		}
		else if (currentRail->LeadsTo(Direction::West)) {
			startDirection = Direction::West;
		}
		else {
			System::Windows::Forms::MessageBox::Show(L"Fehlerhaftes Gleis...\nDas sollte nicht passieren. ");
		}

		if (currentRail->LeadsTo(Direction::North)) { //Find goalDirection
			goalDirection = Direction::North;
		}
		else if (currentRail->LeadsTo(Direction::West)) {
			goalDirection = Direction::West;
		}
		else if (currentRail->LeadsTo(Direction::South)) {
			goalDirection = Direction::South;
		}
		else {
			System::Windows::Forms::MessageBox::Show(L"Fehlerhaftes Gleis...\nDas sollte nicht passieren. ");
		}

		trainList->Add(gcnew Train(_trainType, L"Zug " + trainList->Count + 1, startDirection, goalDirection, currentRail, L"Rails/Bush.png", tileSize));
	}


	//Hier wird ein Zug hinzugefügt
}