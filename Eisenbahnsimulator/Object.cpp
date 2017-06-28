#include "Object.h"

Boolean Rail::LeadsTo(Direction dir)
{
	switch (dir)
	{
	case Direction::East:
		if (Directions == Directions::EastNorth || Directions == Directions::EastSouth || Directions == Directions::EastWest) {
			return true;
		}
		else
			return false;
		break;
	case Direction::North:
		if (Directions == Directions::EastNorth || Directions == Directions::NorthSouth || Directions == Directions::NorthWest) {
			return true;
		}
		else
			return false;
		break;
	case Direction::West:
		if (Directions == Directions::WestEast || Directions == Directions::WestNorth || Directions == Directions::WestSouth) {
			return true;
		}
		else
			return false;
		break;
	case Direction::South:
		if (Directions == Directions::SouthEast || Directions == Directions::SouthNorth || Directions == Directions::SouthWest) {
			return true;
		}
		else
			return false;
		break;
	default:
		break;
	}
	
	return Boolean();
}
