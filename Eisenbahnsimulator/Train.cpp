#include "Train.h"

inline Train::Train(TrainType _type, String^ _name, String^ _imagePath, int _maxSpeed)
{
	imagePath = _imagePath;
	Type = _type;
	Name = _name;
	MaxSpeed = _maxSpeed;
	Speed = 0;
	SpeedLimit = _maxSpeed;
	rails = gcnew List<TileRail^>;
	stuck = false;
}

Object ^ Train::Clone()
{
	Train ^trainClone = static_cast<Train^>(MemberwiseClone());
	trainClone->Name = gcnew String(Name);
	trainClone->rails = gcnew List<TileRail^>;
	return trainClone;
}

Object ^ Train::Clone(String ^ _name)
{
	Train^ trainClone = static_cast<Train^>(Clone());
	trainClone->Name = _name;
	trainClone->rails = gcnew List<TileRail^>;
	return trainClone;
}

bool Train::setOnRail(Map^ map, TileRail ^ _rail)
{
	if (_rail == nullptr) return false;

	Direction startDirection;
	Direction goalDirection;
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
	if(!setOnRail(map, _rail, startDirection))
	{
		for each(TileRail^ rail in rails)
		{
			rail->setFree();
		}
		return false;
	}
	stuck = false;
	return true;
}

bool Train::setOnRail(Map^ map, TileRail ^ _newRail, Direction _startDir)
{
	hasAlreadyStopped = false;
	
	Direction dispose;
	// The rail after the new one
	TileRail ^newRail2 = nextRail(map, _newRail, _startDir, dispose);
	TileRail ^newRail3 = nextRail(map, _newRail, FindOppositeDirection(_startDir), dispose);

	// stop when nullptr

	if (_newRail == nullptr || newRail2 == nullptr || newRail3 == nullptr)
	{
		rail = _newRail;
		speedLimit = Speed = 0; //Train is stuck
		return false;
	}


	// try to reserve previous rail if not already reserved
	if (!rails->Contains(newRail2))
	{
		if (!newRail2->reserve())
		{
			stuck = true;
			Speed = 0; //Train is stuck
			return false;
		}
		rails->Add(newRail2);
	}
	// try to reserve current rail if not already reserved
	if (!rails->Contains(_newRail))
	{
		if (!_newRail->reserve()) 
		{
			stuck = true;
			Speed = 0; //Train is stuck
			return false;
		}
		rails->Add(_newRail);
	}
	// try to reserve next rail if not already reserved
	if (!rails->Contains(newRail3))
	{
		if (!newRail3->reserve()) 
		{
			stuck = true;
			Speed = 0; //Train is stuck
			return false;
		}
		rails->Add(newRail3);
	}

	if (rails->Count > 3)
	{
		rails[0]->setFree();
		rails->RemoveAt(0);
	}

	//Do nothing if the rail isn't connecting properly
	/*
	if (!(_newRail->LeadsTo(FindOppositeDirection(_startDir)))) {
		rail = _newRail;
		speedLimit = Speed = 0; //Train is stuck
		return false;
	}*/

	TileProgress = 0;
	StartDirection = FindOppositeDirection(_startDir);
	rail = _newRail;
	CurrentPose = _newRail->getPose(StartDirection, TileProgress);
	GoalDirection = _newRail->EndDirection(StartDirection);
	stuck = false;
	return true;
}

void Train::Tick(double _time, Map^ map)
{
	if (rail == nullptr) return; // Not placed on a tile yet/drove into an empty tile
	if (hasAlreadyStopped == true && waitingTimeLeft > 0) {
		waitingTimeLeft -= 10000 * _time;
		return;
	} else if (hasAlreadyStopped == false && TileProgress > 2 && rail->GetType() == TrainStop::typeid) { //Train stops to wait for passengers
		waitingTimeLeft = static_cast<TrainStop^>(rail)->WaitingTime;
		hasAlreadyStopped = true;
		return;
	}

	Pose newPose;
	if (rail != nullptr && speedLimit != 0) { //If the train is on a rail and actually able to drive
		if (rail->IsGreen)
		{
			if (Speed < MaxSpeed && Speed < SpeedLimit) { //Accelerate train
				Speed += _time*2;
			}
			else if (Speed > SpeedLimit)
				Speed -= _time*2;

			// Change Tileprogress if not stuck
			if(!stuck)
				TileProgress += Speed*_time;
		}
		newPose = rail->getPose(StartDirection, TileProgress);

		if (newPose.X != -1) { //Train is on the same tile 
			CurrentPose = newPose;   //Give train its newest pose;

		}
		else { //Need to fetch new tile			
			//TileProgress = 0;
			Direction newStartDir;
			TileRail^ newRail = nextRail(map, rail, StartDirection, newStartDir);
			if (newRail != nullptr)
			{
				setOnRail(map, newRail, GoalDirection);
			}
		}
	}
}
void Train::freeRails()
{
	for each(TileRail^ rail in rails)
		rail->setFree();
	rails->Clear();
}


void Train::SwitchDirection()
{
	rails->Reverse();
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

TileRail ^Train::Rail::get()
{
	return rail;
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

TileRail^ nextRail(Map^ _map, TileRail^ _currentRail, Direction _startDir, Direction% _newStartDir)
{
	if (_currentRail == nullptr) return nullptr;

	// position of current rail
	int _currentRailX = _currentRail->Position.X;
	int _currentRailY = _currentRail->Position.Y;

	// goal direction of current rail
	Direction goalDir = _currentRail->EndDirection(_startDir);

	// start direction of next rail
	_newStartDir = FindOppositeDirection(goalDir);

	// init position of next rail
	int _nextRailX = _currentRailX;
	int _nextRailY = _currentRailY;

	switch (goalDir)
	{
	case Direction::East:
		_nextRailX += 1;
		break;
	case Direction::North:
		_nextRailY -= 1;
		break;
	case Direction::West:
		_nextRailX -= 1;
		break;
	case Direction::South:
		_nextRailY += 1;
		break;
	}

	// get tile at next position
	TileObject ^tile = _map->GetTile(_nextRailX, _nextRailY);

	// Check if tile not nullpointer and that tile is a Rail
	if (tile == nullptr) return nullptr;
	if (!tile->isRail) return nullptr;

	return dynamic_cast<TileRail^>(tile);
}