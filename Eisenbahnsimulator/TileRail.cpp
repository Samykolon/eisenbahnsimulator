#include "TileRail.h"

inline Boolean Rail::LeadsTo(Direction dir)
{
	switch (dir)
	{
	case Direction::East:
		if (EndDirections == Directions::EastNorth || EndDirections == Directions::EastSouth || EndDirections == Directions::EastWest) {
			return true;
		}
		else
			return false;
		break;
	case Direction::North:
		if (EndDirections == Directions::EastNorth || EndDirections == Directions::NorthSouth || EndDirections == Directions::NorthWest) {
			return true;
		}
		else
			return false;
		break;
	case Direction::West:
		if (EndDirections == Directions::WestEast || EndDirections == Directions::WestNorth || EndDirections == Directions::WestSouth) {
			return true;
		}
		else
			return false;
		break;
	case Direction::South:
		if (EndDirections == Directions::SouthEast || EndDirections == Directions::SouthNorth || EndDirections == Directions::SouthWest) {
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

inline Rail::Rail(Directions _dir, String^ imagePath, String^ name) :TileObject(imagePath, name)
{/*
	switch (_dir)
	{
	case Directions::NorthEast:
		ImagePath = L"Rail_Curve_RightTop.png";
		break;
	case Directions::NorthSouth:
		ImagePath = L"Rail_Normal_Vert.png";
		break;
	case Directions::NorthWest:
		ImagePath = L"Rail_Curve_LeftTop.png";
		break;
	case Directions::EastSouth:
		ImagePath = L"Rail_Curve_RightBottom.png";
		break;
	case Directions::EastWest:
		ImagePath = L"Rail_Normal_Hor.png";
		break;
	case Directions::SouthWest:
		ImagePath = L"Rail_Curve_LeftBottom.png";
		break;
	default:
		break;
	}*/
	EndDirections = _dir;
}
