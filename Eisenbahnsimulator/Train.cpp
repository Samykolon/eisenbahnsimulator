#include "Train.h"

Train::Train(TrainType typ, String^ nm, Direction start, Direction goal, TileObject^ to)
{
	TrainType Type = typ;
	String^ Name = nm;
	Tile = to;
	StartDirection = start;
	GoalDirection = goal;
}
