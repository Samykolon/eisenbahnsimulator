#include "Train.h"

inline Train::Train(TrainType typ, String^ nm, Direction start, Direction goal, Rail^ to, String^ _imagePath, int tileSize)
{
	imagePath = _imagePath;
	TrainType Type = typ;
	String^ Name = nm;
	Tile = to;
	StartDirection = start;
	GoalDirection = goal;
	CurrentPose = to->Drive(start, 1, tileSize);
}

Object ^ Train::Clone()
{
	return MemberwiseClone();
}
