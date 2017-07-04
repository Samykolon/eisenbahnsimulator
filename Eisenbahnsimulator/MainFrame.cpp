﻿#include "MainFrame.h"

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

void Eisenbahnsimulator::MainFrame::AddTrain(TrainType _trainType, int _posX, int _posY)
{
	Rail^ currentRail = dynamic_cast<Rail^>(userdata->map->GetTile(_posX, _posY)); //Tries to cast the object into a Rail

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
		
		userdata->trainList->Add(gcnew Train(_trainType, L"Zug " + userdata->trainList->Count + 1, startDirection, goalDirection, currentRail, ""));
	}
		

	//Hier wird ein Zug hinzugefügt
}
