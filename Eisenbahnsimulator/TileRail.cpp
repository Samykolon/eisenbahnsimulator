#include "TileRail.h"

using namespace System;

inline Boolean TileRail::LeadsTo(Direction dir)
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

Direction TileRail::EndDirection(Direction _startDir)
{
	switch (EndDirections)
	{
	case Directions::NorthSouth:
		if (_startDir == Direction::North) {
			return Direction::South;
		}
		else
			return Direction::North;
		break;
	case Directions::WestEast:
		if (_startDir == Direction::West) {
			return Direction::East;
		}
		else
			return Direction::West;
		break;
	case Directions::WestNorth:
		if (_startDir == Direction::West) {
			return Direction::North;
		}
		else
			return Direction::West;
		break;
	case Directions::WestSouth:
		if (_startDir == Direction::West) {
			return Direction::South;
		}
		else
			return Direction::West;
		break;
	case Directions::NorthEast:
		if (_startDir == Direction::North) {
			return Direction::East;
		}
		else
			return Direction::North;
		break;
	case Directions::SouthEast:
		if (_startDir == Direction::East) {
			return Direction::South;
		}
		else
			return Direction::East;
		break;
	default:
		break;
	}
	return _startDir;
}

bool TileRail::reserve() // returns true if successful, false if failed
{
	if (!reserved)
	{
		reserved = true;
		return true;
	}
	return false;
}

inline TileRail::TileRail(Directions _dir, String^ imagePath, String^ name) :TileObject(imagePath, name)
{
	isGreen = true;
	EndDirections = _dir;
}

Pose TileRail::getPose(Direction startDirection, double tileProgress)
{
	switch (EndDirections)
	{
	case Directions::NorthEast:
		if (startDirection == Direction::North) {
			if (tileProgress < 1) {
				return Pose((position.X - 1) + 0.5 * 1.0, (position.Y - 1) * 1 + tileProgress / 4.0 * 1.0, 270);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1); //phi in radian
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0 + (1 - Math::Cos(phi)) * 1.0 / 4.0, (position.Y - 1) * 1.0 + 1.0 * 0.25 + 1.0 / 4.0 * Math::Sin(phi), 270 + phi * 180 / Math::PI);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * 1.0 + 0.75 * 1.0 + (tileProgress - 2.57079632679) * 1.0 / 4.0, (position.Y - 1) * 1.0 + 0.5 * 1.0, 0);
			}
			else
				return Pose(-1, -1, 0);
		}
		else { //startdirection == East
			if (tileProgress < 1) {
				return Pose((position.X - 1) * 1.0 + 1.0 - (tileProgress / 4.0 * 1.0), (position.Y - 1) * 1.0 + 0.5 * 1.0, 180);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * 1.0 + 1.0 * 0.75 - 0.25 * 1.0 * Math::Sin(phi), (position.Y - 1) * 1.0 + 0.5 * 1.0 - 0.25 * 1.0 * (1 - Math::Cos(phi)), 180 - phi * 180 / Math::PI);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0, (position.Y - 1) * 1.0 + 1.0 * 0.25 - (tileProgress - 2.57079632679) * 0.25 * 1.0, 90);
			}
			else
				return Pose(-1, -1, 0);
		}
		break;
	case Directions::NorthSouth:
		if (tileProgress < 4) {
			if (startDirection == Direction::North) {
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0, (position.Y - 1) * 1.0 + tileProgress / 4.0 * 1.0, 270);
			}
			else //Startdirection == South
			{
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0, (position.Y - 1) * 1.0 + 1.0 - (tileProgress / 4.0 * 1.0), 90);
			}
		}
		else {
			return Pose(-1, -1, 0);
		}
		break;
	case Directions::NorthWest:
		if (startDirection == Direction::North) {
			if (tileProgress < 1) {
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0, (position.Y - 1) * 1.0 + tileProgress / 4.0 * 1.0, 270);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0 - (1 - Math::Cos(phi)) * 1.0 * 0.25, (position.Y - 1) * 1.0 + 0.25 * 1.0 + 0.25 * Math::Sin(phi) * 1.0, 270 - phi * 180 / Math::PI);
			}
			else if (tileProgress < 3.57079632679) {

				return Pose((position.X - 1) * 1.0 + 0.25 * 1.0 - ((tileProgress - 2.57079632679) * 1.0 / 4.0), (position.Y - 1) * 1.0 + 0.5 * 1.0, 180);
			}
			else
				return Pose(-1, -1, 0);
		}
		else { //startdirection == West
			if (tileProgress < 1) {
				return Pose((position.X - 1) * 1.0 + tileProgress / 4.0 * 1.0, (position.Y - 1) * 1.0 + 0.5 * 1.0, 0);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * 1.0 + 0.25 * 1.0 + Math::Sin(phi) * 1.0 * 0.25, (position.Y - 1) * 1.0 + 0.5 * 1.0 - (1 - Math::Cos(phi)) * 1.0 * 0.25, phi * 180 / Math::PI);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0, (position.Y - 1) * 1.0 + 0.25 * 1.0 - ((tileProgress - 2.57079632679) * 0.25 * 1.0), 90);
			}
			else
				return Pose(-1, -1, 0);
		}
		break;
	case Directions::EastSouth:
		if (startDirection == Direction::South) {
			if (tileProgress < 1) {
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0, (position.Y - 1) * 1.0 + 1.0 - (tileProgress / 4.0 * 1.0), 90);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0 + 0.25 * 1.0 * (1 - Math::Cos(phi)), (position.Y - 1) * 1.0 + 0.75 * 1.0 - (0.25  * 1.0 * Math::Sin(phi)), 90 - phi * 180 / Math::PI);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * 1.0 + 0.75 * 1.0 + (tileProgress - 2.57079632679) * 0.25 * 1.0, (position.Y - 1) * 1.0 + 0.5 * 1.0, 0);
			}
			else
				return Pose(-1, -1, 0);
		}
		else { //startdirection == East
			if (tileProgress < 1) {
				return Pose((position.X - 1) * 1.0 + 1.0 - (tileProgress / 4.0 * 1.0), (position.Y - 1) * 1.0 + 0.5 * 1.0, 180);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * 1.0 + 1.0 * 0.75 - 1.0 * 0.25 * Math::Sin(phi), (position.Y - 1) * 1.0 + 0.5 * 1.0 + 0.25 * 1.0 * (1 - Math::Cos(phi)), 180 + phi * 180 / Math::PI);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0, (position.Y - 1) * 1.0 + 0.75 * 1.0 + (tileProgress - 2.57079632679) / 4.0 * 1.0, 270);
			}
			else
				return Pose(-1, -1, 0);
		}
		break;
	case Directions::EastWest:
		if (tileProgress < 4) {
			if (startDirection == Direction::West) {
				return Pose((position.X - 1) * 1.0 + tileProgress / 4.0 * 1.0, (position.Y - 1) * 1.0 + 0.5 * 1.0, 0);
			}
			else //startdirection == east
			{
				return Pose((position.X - 1) * 1.0 + 1.0 - (tileProgress / 4.0 * 1.0), (position.Y - 1) * 1.0 + 0.5 * 1.0, 180);
			}
		}
		else {
			return Pose(-1, -1, 0);
		}
		break;
	case Directions::SouthWest:
		if (startDirection == Direction::South) {
			if (tileProgress < 1) {
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0, (position.Y - 1) * 1.0 + 1.0 - (tileProgress / 4.0 * 1.0), 90);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0 - 0.25 * 1.0 * (1 - Math::Cos(phi)), (position.Y - 1) * 1.0 + 0.75 * 1.0 - 0.25 * 1.0 * Math::Sin(phi), 90 + phi * 180 / Math::PI);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * 1.0 + 0.25 * 1.0 - ((tileProgress - 2.57079632679) / 4.0 * 1.0), (position.Y - 1) * 1.0 + 0.5 * 1.0, 180);
			}
			else
				return Pose(-1, -1, 0);
		}
		else { //startdirection == West
			if (tileProgress < 1) {
				return Pose((position.X - 1) * 1.0 + tileProgress / 4.0 * 1.0, (position.Y - 1) * 1.0 + 0.5 * 1.0, 0);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * 1.0 + 0.25 * 1.0 + 0.25 * 1.0 * Math::Sin(phi), (position.Y - 1) * 1.0 + 0.5 * 1.0 + 0.25 * 1.0 * (1 - Math::Cos(phi)), -phi * 180 / Math::PI);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * 1.0 + 0.5 * 1.0, (position.Y - 1) * 1.0 + 0.75 * 1.0 + (tileProgress - 2.57079632679) / 4.0 * 1.0, 270);
			}
			else
				return Pose(-1, -1, 0);
		}
		break;
	default:
		return Pose(-1, -1, 0);
		break;
	}

}

bool TileRail::IsGreen::get()
{
	return isGreen;
}

bool TileRail::isRail::get()
{
	return true;
}

void TileRail::setFree()
{
	reserved = false;
}