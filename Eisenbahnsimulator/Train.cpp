#include "Train.h"

inline Train::Train(TrainType typ, String^ nm, Direction start, Direction goal, Rail^ to, String^ _imagePath)
{
	imagePath = _imagePath;
	TrainType Type = typ;
	String^ Name = nm;
	Tile = to;
	StartDirection = start;
	GoalDirection = goal;
}
