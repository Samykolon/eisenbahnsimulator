﻿#include "Train.h"

inline Train::Train(TrainType typ, String^ _name, String^ _imagePath, int _maxSpeed)//, Direction start, Direction goal, Rail^ to, String^ _imagePath, int tileSize)
{
	imagePath = _imagePath;
	Type = typ;
	Name = _name;
	MaxSpeed = _maxSpeed;
	/*Tile = to;
	StartDirection = start;
	GoalDirection = goal;
	CurrentPose = to->Drive(start, 1, tileSize);*/
}

void Train::setOnRail(Rail ^ _rail)
{
	if (_rail == nullptr) return;

	Direction startDirection;
	Direction goalDirection;
	int directionsFound = 0;
	//Find startDirection
	if (_rail->LeadsTo(Direction::East))
	{ 
		startDirection = Direction::East;
	}
	else if (_rail->LeadsTo(Direction::North))
	{
		startDirection = Direction::North;
	}
	else if (_rail->LeadsTo(Direction::West))
	{
		startDirection = Direction::West;
	}
	else 
	{
		throw gcnew System::Exception("Wrong track... " + "This shouldn't happen");
	}

	//Find goalDirection
	if (_rail->LeadsTo(Direction::North))
	{ 
		goalDirection = Direction::North;
	}
	else if (_rail->LeadsTo(Direction::West))
	{
		goalDirection = Direction::West;
	}
	else if (_rail->LeadsTo(Direction::South))
	{
		goalDirection = Direction::South;
	}
	else 
	{
		throw gcnew System::Exception("Wrong track... " + "This shouldn't happen");
	}

	Tile = _rail;
	StartDirection = startDirection;
	GoalDirection = goalDirection;
	CurrentPose = _rail->Drive(startDirection, 1, tileSize);
}

Object ^ Train::Clone()
{
	Train ^trainClone = static_cast<Train^>(MemberwiseClone());
	trainClone->Name = gcnew String(Name);
	return trainClone;
}

Object ^ Train::Clone(String ^ _name)
{
	Train^ trainClone = static_cast<Train^>(Clone());
	trainClone->Name = _name;
	return trainClone;
}

String^ Train::Name::get()
{
	return name;
}

void Train::Name::set(String^ _name)
{
	name = _name;
}

String^ Train::ImagePath::get()
{
	return imagePath;
}

void Train::ImagePath::set(String^ _imagePath)
{
	imagePath = _imagePath;
}

int Train::TileSize::get()
{
	return tileSize;
}

void Train::TileSize::set(int _tileSize)
{
	tileSize = _tileSize;
}

// WENN MAN SCHON EINE ZUGKLASSE HAT, DANN KANN MAN DIE FUNKTIONEN DIE DEN ZUG VERÄNDERN AUCH IN DIE VERDAMMT ZUGKLASSE SCHREIBEN UND NICHT IRGENDWO IN DIE MAINFRAME.H!!!!!!!!!!!!!!!!!!!!!!!!!
void Train::tick(double _time)
{
	if (Tile == nullptr) return; // Not placed on a tile yet

	TileProgress += Speed / 100; //Increase the train's progress
	Rail^ rail = dynamic_cast<Rail^>(Tile);
	if (rail != nullptr) {
		CurrentPose = rail->Drive(StartDirection, TileProgress, TileSize); //Give train its newest pose;
	}
}