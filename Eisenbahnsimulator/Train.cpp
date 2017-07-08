#include "Train.h"

inline Train::Train(TrainType typ, String^ _name, Direction start, Direction goal, Rail^ to, String^ _imagePath, int tileSize)
{
	imagePath = _imagePath;
	Type = typ;
	Name = _name;
	Tile = to;
	StartDirection = start;
	GoalDirection = goal;
	CurrentPose = to->Drive(start, 1, tileSize);
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