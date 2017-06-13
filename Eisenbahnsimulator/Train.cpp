#include "Train.h"

Train::Train(String^ nm, int ix, int iy, Direction start, Direction goal)
{
	String^ Name = nm;
	X = ix;
	Y = iy;
	StartDirection = start;
	GoalDirection = goal;
}
