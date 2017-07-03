#include "MainFrame.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Eisenbahnsimulator::MainFrame form;
	Application::Run(%form);
}

int Eisenbahnsimulator::MainFrame::CalcTileCoord(int pixCoord)
{
	int X = 1;
	while (true) {
		if (pixCoord < X * TileSize) {
			return X;
		}
		X++;
	}	
}

void Eisenbahnsimulator::MainFrame::AddTrain(TrainType tt, int xi, int yi)
{
	Rail^ currentRail = dynamic_cast<Rail^>(TileMap->GetTile(xi, yi)); //Tries to cast the object into a Rail

	if (currentRail != nullptr){ //Executed if the train is placed on a Rail
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
			MessageBox::Show("Fehlerhaftes Gleis...\nDas sollte nicht passieren. ");
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
			MessageBox::Show("Fehlerhaftes Gleis...\nDas sollte nicht passieren. ");
		}
		
		Trains->Add(gcnew Train(tt, L"Zug " + Trains->Count + 1, startDirection, goalDirection, currentRail));
	}
		

	//Hier wird ein Zug hinzugef・t
}
