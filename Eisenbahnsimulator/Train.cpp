#include "Train.h"

Train::Train(String^ nm, Direction start, Direction goal, TileObject^ to)
{
	String^ Name = nm;
	Tile = to;
	StartDirection = start;
	GoalDirection = goal;
}
