﻿#include "TileRail.h"

using namespace System;

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

Pose Rail::Drive(Direction startDirection, double% tileProgress, int tileSize, double% speed, double MaxSpeed) 
{
	if (speed < MaxSpeed) { //Accelerate train
		speed += 1;
	}
	tileProgress += speed / 200.0;
	//System::Windows::Forms::MessageBox::Show(tileProgress + " " + speed);
	switch (EndDirections)
	{
	case Directions::NorthEast:
		if (startDirection == Direction::North) {
			if (tileProgress < 1) {
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize, (position.Y - 1) * tileSize + tileProgress / 4.0 * tileSize, 3.0/2.0 * Math::PI);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1); //phi in radian
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize +  (1 - Math::Cos(phi)) * tileSize / 4.0, (position.Y - 1) * tileSize + tileSize * 0.25 + tileSize / 4.0 * Math::Sin(phi), 3.0 / 2.0 * Math::PI + phi);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * tileSize + 0.75 * tileSize + (tileProgress - 2.57079632679) * tileSize/4.0, (position.Y - 1) * tileSize + 0.5 * tileSize, 0);
			}
			else				
				return Pose(-1, -1, 0);
		}
		else { //startdirection == East
			if (tileProgress < 1) {
				    return Pose((position.X - 1) * tileSize + tileSize - (tileProgress / 4.0 * tileSize), (position.Y - 1) * tileSize + 0.5 * tileSize, Math::PI);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * tileSize + tileSize * 0.75 - 0.25 * tileSize * Math::Sin(phi), (position.Y - 1) * tileSize + 0.5 * tileSize - 0.25 * tileSize * (1 - Math::Cos(phi)), Math::PI - phi);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize, (position.Y - 1) * tileSize + tileSize * 0.25 - (tileProgress - 2.57079632679) * 0.25 * tileSize, Math::PI/2.0);
			}
			else
				return Pose(-1, -1, 0);
		}
		break;
	case Directions::NorthSouth:
		if (tileProgress < 4) {
			if (startDirection == Direction::North) {
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize, (position.Y - 1) * tileSize + tileProgress/4.0 * tileSize, 3.0 / 2.0 * Math::PI);
			}
			else //Startdirection == South
			{
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize, (position.Y - 1) * tileSize + tileSize - (tileProgress / 4.0 * tileSize), Math::PI / 2.0);
			}
		}
		else {
			return Pose(-1, -1, 0);
		}
		break;
	case Directions::NorthWest:
		if (startDirection == Direction::North) {
			if (tileProgress < 1) {
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize, (position.Y - 1) * tileSize + tileProgress / 4.0 * tileSize, 3.0 / 2.0 * Math::PI);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize - (1 - Math::Cos(phi)) * tileSize * 0.25, (position.Y - 1) * tileSize + 0.25 * tileSize +  0.25 * Math::Sin(phi) * tileSize, 3.0 / 2.0 * Math::PI - phi);
			}
			else if (tileProgress < 3.57079632679) {
				
				    return Pose((position.X - 1) * tileSize + 0.25 * tileSize - ((tileProgress - 2.57079632679) * tileSize/4.0), (position.Y - 1) * tileSize + 0.5 * tileSize, Math::PI);
			}
			else
				return Pose(-1, -1, 0);
		}
		else { //startdirection == West
			if (tileProgress < 1) {
				return Pose((position.X - 1) * tileSize + tileProgress / 4.0 * tileSize, (position.Y - 1) * tileSize + 0.5 * tileSize, 0);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * tileSize + 0.25 * tileSize + Math::Sin(phi) * tileSize * 0.25, (position.Y - 1) * tileSize + 0.5 * tileSize - (1 - Math::Cos(phi)) * tileSize * 0.25, phi);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize, (position.Y - 1) * tileSize + 0.25 * tileSize - ((tileProgress- 2.57079632679) * 0.25 * tileSize), Math::PI / 2.0);
			}
			else
				return Pose(-1, -1, 0);
		}
		break;
	case Directions::EastSouth:
		if (startDirection == Direction::South) {
			if (tileProgress < 1) {
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize, (position.Y - 1) * tileSize + tileSize - (tileProgress / 4.0 * tileSize), Math::PI / 2.0);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize + 0.25 * tileSize * (1 - Math::Cos(phi)), (position.Y - 1) * tileSize + 0.75 * tileSize - (0.25  * tileSize * Math::Sin(phi)), (Math::PI / 2.0) - phi);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * tileSize + 0.75 * tileSize + (tileProgress - 2.57079632679) * 0.25 * tileSize, (position.Y - 1) * tileSize + 0.5 * tileSize, 0);
			}
			else
				return Pose(-1, -1, 0);
		}
		else { //startdirection == East
			if (tileProgress < 1) {
				return Pose((position.X - 1) * tileSize + tileSize - (tileProgress / 4.0 * tileSize), (position.Y - 1) * tileSize + 0.5 * tileSize, Math::PI);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * tileSize + tileSize * 0.75 - tileSize * 0.25 * Math::Sin(phi), (position.Y - 1) * tileSize + 0.5 * tileSize + 0.25 * tileSize * (1 - Math::Cos(phi)), Math::PI + phi);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize, (position.Y - 1) * tileSize + 0.75 * tileSize + (tileProgress - 2.57079632679) / 4.0 * tileSize, 3.0 / 2.0 * Math::PI);
			}
			else
				return Pose(-1, -1, 0);
		}
		break;
	case Directions::EastWest: 
		if (tileProgress < 4) {
			if (startDirection == Direction::West) {
				return Pose((position.X - 1) * tileSize + tileProgress / 4.0 * tileSize, (position.Y - 1) * tileSize + 0.5 * tileSize, 0);
			}
			else //startdirection == east
			{
				return Pose((position.X - 1) * tileSize + tileSize - (tileProgress / 4.0 * tileSize), (position.Y - 1) * tileSize + 0.5 * tileSize, Math::PI);
			}
		}
		else {
			return Pose(-1, -1, 0);
		}
		break;
	case Directions::SouthWest:
		if (startDirection == Direction::South) {
			if (tileProgress < 1) {
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize, (position.Y - 1) * tileSize + tileSize - (tileProgress / 4.0 * tileSize), Math::PI / 2.0);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize - 0.25 * tileSize * (1 - Math::Cos(phi)), (position.Y - 1) * tileSize + 0.75 * tileSize - 0.25 * tileSize * Math::Sin(phi), (Math::PI / 2.0) + phi);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * tileSize + 0.25 * tileSize - ((tileProgress- 2.57079632679) / 4.0 * tileSize), (position.Y - 1) * tileSize + 0.5 * tileSize, Math::PI);
			}
			else
				return Pose(-1, -1, 0);
		}
		else { //startdirection == West
			if (tileProgress < 1) {
				return Pose((position.X - 1) * tileSize + tileProgress / 4.0 * tileSize, (position.Y - 1) * tileSize + 0.5 * tileSize, 0);
			}
			else if (tileProgress < 2.57079632679) {
				double phi = (tileProgress - 1);
				return Pose((position.X - 1) * tileSize + 0.25 * tileSize + 0.25 * tileSize * Math::Sin(phi), (position.Y - 1) * tileSize + 0.5 * tileSize + 0.25 * tileSize * (1 - Math::Cos(phi)), - phi);
			}
			else if (tileProgress < 3.57079632679) {
				return Pose((position.X - 1) * tileSize + 0.5 * tileSize, (position.Y - 1) * tileSize + 0.75 * tileSize + (tileProgress- 2.57079632679) / 4.0 * tileSize, 3.0 / 2.0 * Math::PI);
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
