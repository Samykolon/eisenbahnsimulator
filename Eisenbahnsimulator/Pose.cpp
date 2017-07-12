#include "Pose.h"

Directions AddDirections(Direction d1, Direction d2)
{
	if (d1 == Direction::North && d2 == Direction::South || d1 == Direction::South && d2 == Direction::North) {
		return Directions::NorthSouth;
	}
	else if(d1 == Direction::North && d2 == Direction::West || d1 == Direction::West && d2 == Direction::North)
	{
		return Directions::NorthWest;
	}
	else if (d1 == Direction::North && d2 == Direction::East || d1 == Direction::East && d2 == Direction::North) {
		return Directions::NorthEast;
	}
	else if (d1 == Direction::South && d2 == Direction::West || d1 == Direction::West && d2 == Direction::South)
	{
		return Directions::SouthWest;
	}
	else if (d1 == Direction::East && d2 == Direction::South || d1 == Direction::South && d2 == Direction::East) {
		return Directions::EastSouth;
	}
	else if (d1 == Direction::East && d2 == Direction::West || d1 == Direction::West && d2 == Direction::East)
	{
		return Directions::EastWest;
	}
	else
		throw gcnew System::Exception("Direction definition error");
	
}

Direction FindOppositeDirection(Direction dir)
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
};