﻿#include "Train.h"

Direction Train::FindOppositeDirection(Direction dir)
{
	switch (dir)
	{
	case Direction::East:
		return Direction::West;
		break;
	case Direction::North:
		return Direction::South;
		break;
	case Direction::West:
		return Direction::East;
		break;
	case Direction::South:
		return Direction::North;
		break;
	default:
		break;
	}
	return Direction();
}

inline Train::Train(TrainType typ, String^ _name, String^ _imagePath, int _maxSpeed)//, Direction start, Direction goal, Rail^ to, String^ _imagePath, int tileSize)
{
	imagePath = _imagePath;
	Type = typ;
	Name = _name;
	MaxSpeed = _maxSpeed;
	Speed = 0;
	SpeedLimit = _maxSpeed;
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
	if (_rail->LeadsTo(Direction::North) && startDirection != Direction::North)
	{
		goalDirection = Direction::North;
	}
	else if (_rail->LeadsTo(Direction::West) && startDirection != Direction::West)
	{
		goalDirection = Direction::West;
	}
	else if (_rail->LeadsTo(Direction::South) && startDirection != Direction::South)
	{
		goalDirection = Direction::South;
	}
	else
	{
		throw gcnew System::Exception("Wrong track... " + "This shouldn't happen");
	}	
	TileProgress = 1;
	Tile = _rail;
	StartDirection = startDirection;
	GoalDirection = goalDirection;
	CurrentPose = _rail->getPose(StartDirection, TileProgress);
	//Windows::Forms::MessageBox::Show(CurrentPose.X + " " + CurrentPose.Y + " " + StartDirection.ToString() + " " + tileSize);
}

void Train::setOnRail(Rail ^ newRail, Direction _startDir)
{
	hasAlreadyStopped = false;
	if (newRail == nullptr) { //Rail is empty
		Tile = newRail; 
		speedLimit = Speed = 0; //Train is stuck
		return;
	}
	else if (!(newRail->LeadsTo(FindOppositeDirection(_startDir)))) {//Do nothing if the rail isn't connecting properly
		Tile = newRail;
		speedLimit = Speed = 0; //Train is stuck
		return;
		
	}
	else {
		
		TileProgress = 0;
		StartDirection = FindOppositeDirection(_startDir);
		Tile = newRail;
		CurrentPose = newRail->getPose(StartDirection, TileProgress);

		switch (newRail->EndDirections)
		{
		case Directions::NorthSouth:
			if (StartDirection == Direction::North) {
				GoalDirection = Direction::South;
			}
			else
				GoalDirection = Direction::North;
			break;
		case Directions::WestEast:
			if (StartDirection == Direction::West) {
				GoalDirection = Direction::East;
			}
			else
				GoalDirection = Direction::West;
			break;
		case Directions::WestNorth:
			if (StartDirection == Direction::West) {
				GoalDirection = Direction::North;
			}
			else
				GoalDirection = Direction::West;
			break;
		case Directions::WestSouth:
			if (StartDirection == Direction::West) {
				GoalDirection = Direction::South;
			}
			else
				GoalDirection = Direction::West;
			break;
		case Directions::NorthEast:
			if (StartDirection == Direction::North) {
				GoalDirection = Direction::East;
			}
			else
				GoalDirection = Direction::North;
			break;
		case Directions::SouthEast:
			if (StartDirection == Direction::East) {
				GoalDirection = Direction::South;
			}
			else
				GoalDirection = Direction::East;
			break;
		default:
			break;
		}
	}

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

double Train::MaximumSpeed::get()
{
	return MaxSpeed;
}

void Train::MaximumSpeed::set(double _MaxSpeed)
{
	MaxSpeed = _MaxSpeed;
}

Boolean Train::DrivesForward::get()
{
	return drivesforward;
}

void Train::DrivesForward::set(Boolean _drivesforward)
{
	drivesforward = _drivesforward;
}

double Train::SpeedLimit::get()
{
	return speedLimit;
}

void Train::SpeedLimit::set(double _speedLimit)
{
	speedLimit = _speedLimit;
}

double Train::CurrentSpeed::get()
{
	return Speed;
}

void Train::CurrentSpeed::set(double _speed)
{
	Speed = _speed;
}

void Train::Tick(double _time, Map^ map)
{
	//String^ fileName = "textfile.txt";
	//IO::StreamWriter^ sw = IO::File::AppendText(fileName);
	//sw->WriteLine(Tile->Position.X.ToString() + " " + Tile->Position.Y.ToString());

	if (Tile == nullptr) return; // Not placed on a tile yet/drove into an empty tile
	if (hasAlreadyStopped == true && waitingTimeLeft > 0) {
		waitingTimeLeft -= 10000 * _time;
		return;
	} else if (hasAlreadyStopped == false && TileProgress > 2 && Tile->GetType() == TrainStop::typeid) { //Train stops to wait for passengers
		waitingTimeLeft = static_cast<TrainStop^>(Tile)->WaitingTime;
		hasAlreadyStopped = true;
		return;
	}

	Rail^ rail = dynamic_cast<Rail^>(Tile);	//Previous/current rail
	Pose newPose;
	if (rail != nullptr && speedLimit != 0) { //If the train is on a rail and actually able to drive
		if (rail->IsGreen)
		{
			if (Speed < MaxSpeed && Speed < SpeedLimit) { //Accelerate train
				Speed += _time*2;
			}
			else if (Speed > SpeedLimit)
				Speed -= _time*2;

			TileProgress += Speed*_time;
		}
		newPose = rail->getPose(StartDirection, TileProgress);

		if (newPose.X != -1) { //Train is on the same tile 
			//Windows::Forms::MessageBox::Show(newPose.X.ToString() + "TileProgress " + TileProgress);
			CurrentPose = newPose;   //Give train its newest pose;

		}
		else { //Need to fetch new tile			
			TileProgress = 0;
			if (!(rail->Position.X == 0 && GoalDirection == Direction::West || rail->Position.X > map->Width && GoalDirection == Direction::East || rail->Position.Y == 0 && GoalDirection == Direction::North || rail->Position.Y > map->Height && GoalDirection == Direction::South)) { //Check if the train leaves the map boundaries

				//sw->WriteLine("Old: " + Tile->Position.X + " " + Tile->Position.Y + "\ntileProgress: " + TileProgress + "\nStartdirection " + StartDirection.ToString() + "\nGoalDirection: " + GoalDirection.ToString() + "\n Enddirections:" + static_cast<Rail^>(Tile)->EndDirections.ToString());
				switch (GoalDirection) //Set correct new rail depending on goaldirection
				{
				case Direction::East:
					rail = dynamic_cast<Rail^>(map->GetTile(Tile->Position.X + 1, Tile->Position.Y)); //Fetch next tile
					X = Tile->Position.X + 1;
					Y = Tile->Position.Y;
					break;
				case Direction::North:
					rail = dynamic_cast<Rail^>(map->GetTile(Tile->Position.X, Tile->Position.Y - 1));
					X = Tile->Position.X;
					Y = Tile->Position.Y - 1;
					break;
				case Direction::West:
					rail = dynamic_cast<Rail^>(map->GetTile(Tile->Position.X - 1, Tile->Position.Y));
					X = Tile->Position.X - 1;
					Y = Tile->Position.Y;
					break;
				case Direction::South:
					rail = dynamic_cast<Rail^>(map->GetTile(Tile->Position.X, Tile->Position.Y + 1));
					X = Tile->Position.X;
					Y = Tile->Position.Y + 1;
					break;
				default:
					break;
				}


				setOnRail(rail, GoalDirection); //Sets the train on the rail, initializes its new variables, sets new Pose, resets tileProgress
				//sw->WriteLine("New: " + Tile->Position.X + " " + Tile->Position.Y + "\ntileProgress: " + TileProgress + "\nStartdirection " + StartDirection.ToString() + "\nGoalDirection: " + GoalDirection.ToString() + "\n Enddirections:" + static_cast<Rail^>(Tile)->EndDirections.ToString());
			}
		}
	}
	//sw->Close();
}

void Train::SwitchDirection()
{
	Direction temp = StartDirection;
	StartDirection = GoalDirection;
	GoalDirection = temp;
}

Pose Train::CurrentPose::get()
{
	return currentPose*tileSize;
}

void Train::CurrentPose::set(Pose _pose)
{
	currentPose = _pose;
}
