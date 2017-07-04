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

Pos ^ Rail::Drive(Direction startDirection, double tileProgress, double speed, int tileSize)
{
	switch (EndDirections)
	{
	case Directions::NorthEast:

		break;
	case Directions::NorthSouth:
		if (tileProgress < 4) {
			if (startDirection == Direction::North) {
				return gcnew Pos((coord->posX - 1) * tileSize + 0.5 * tileSize, (coord->posY - 1) * tileSize + tileProgress/4.0 * tileSize);
			}
			else
			{
				return gcnew Pos((coord->posX - 1) * tileSize + 0.5 * tileSize, (coord->posY - 1) * tileSize + tileSize - (tileProgress / 4.0 * tileSize));
			}
		}
		else {
			return gcnew Pos(-1, -1);
		}
		break;
	case Directions::NorthWest:
		break;
	case Directions::EastSouth:
		break;
	case Directions::EastWest: 
		if (tileProgress < 4) {
			if (startDirection == Direction::East) {
				return gcnew Pos((coord->posY - 1) * tileSize + tileProgress / 4.0 * tileSize, (coord->posX - 1) * tileSize + 0.5 * tileSize);
			}
			else
			{
				return gcnew Pos((coord->posY - 1) * tileSize + tileSize - (tileProgress / 4.0 * tileSize), (coord->posX - 1) * tileSize + 0.5 * tileSize);
			}
		}
		else {
			return gcnew Pos(-1, -1);
		}
		break;
	case Directions::SouthWest:
		break;
	default:
		break;
	}

	//out of Tile:
	return gcnew Pos(-1, -1);
}
