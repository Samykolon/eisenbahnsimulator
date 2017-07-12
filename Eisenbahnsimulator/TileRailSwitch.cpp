#include "TileRailSwitch.h"

RailSwitch::RailSwitch(Directions railDir, Direction switchDir, Direction straightSwitch, String^ imagePath, String^ name) : Rail(railDir, imagePath, name) {
	//TODO: Check if the switch direction and the rail directions are the same?
	//TODO: Assign correct images
	SwitchDirection = switchDir;
	StraightSwitchDirection = straightSwitch;
	FixedDirection = Train::FindOppositeDirection(straightSwitch);
	IsStraight = true;
}

void RailSwitch::Switch(List<Train^>^ trains)
{
	//Check if no train is on the same tile
	for each (Train^ tr in trains)
	{
		if (tr->Tile == this && tr->CurrentSpeed > 0) {
			return;
		}
	}

	if (IsStraight) {
		if (EndDirections == Directions::NorthSouth) {
			if (SwitchDirection == Direction::West) {
				if (StraightSwitchDirection == Direction::North) {
					imagePath = L"Rails/Rail_Switch_LeftBottom_Yes.png";
				}
				else {//StraightSwitch = South
					imagePath = L"Rails/Rail_Switch_LeftTop_Yes.png";
				}
			}
			else { //SwitchDirection == East
				if (StraightSwitchDirection == Direction::North) {
					imagePath = L"Rails/Rail_Switch_RightBottom_Yes.png";
				}
				else {//StraightSwitch = South
					imagePath = L"Rails/Rail_Switch_RightTop_Yes.png";
				}
			}
		}
		else { //Directions == WestEast
			if (SwitchDirection == Direction::North) {
				if (StraightSwitchDirection == Direction::East) {
					imagePath = L"Rails/Rail_Switch_TopLeft_Yes.png";
				}
				else {//StraightSwitch = West
					imagePath = L"Rails/Rail_Switch_TopRight_Yes.png";
				}
			}
			else { //SwitchDirection == South
				if (StraightSwitchDirection == Direction::East) {
					imagePath = L"Rails/Rail_Switch_BottomLeft_Yes.png";
				}
				else {//StraightSwitch = West
					imagePath = L"Rails/Rail_Switch_BottomRight_Yes.png";
				}
			}
		}
		EndDirections = AddDirections(FixedDirection, SwitchDirection); //Change logical enddirections

		//TODO: Change Imagepath
		IsStraight = false;
	}
	else {
		EndDirections = AddDirections(FixedDirection, StraightSwitchDirection); //Set straight again
		if (EndDirections == Directions::NorthSouth) {
			if (SwitchDirection == Direction::West) {
				if (StraightSwitchDirection == Direction::North) {
					imagePath = L"Rails/Rail_Switch_LeftBottom_No.png";
				}
				else {//StraightSwitch = South
					imagePath = L"Rails/Rail_Switch_LeftTop_No.png";
				}
			}
			else { //SwitchDirection == East
				if (StraightSwitchDirection == Direction::North) {
					imagePath = L"Rails/Rail_Switch_RightBottom_No.png";
				}
				else {//StraightSwitch = South
					imagePath = L"Rails/Rail_Switch_RightTop_No.png";
				}
			}
		}
		else { //Directions == WestEast
			if (SwitchDirection == Direction::North) {
				if (StraightSwitchDirection == Direction::East) {
					imagePath = L"Rails/Rail_Switch_TopLeft_No.png";
				}
				else {//StraightSwitch = West
					imagePath = L"Rails/Rail_Switch_TopRight_No.png";
				}
			}
			else { //SwitchDirection == South
				if (StraightSwitchDirection == Direction::East) {
					imagePath = L"Rails/Rail_Switch_BottomLeft_No.png";
				}
				else {//StraightSwitch = West
					imagePath = L"Rails/Rail_Switch_BottomRight_No.png";
				}
			}
		}
		IsStraight = true;
	}
}

