#include "TileRailSwitch.h"

RailSwitch::RailSwitch(Directions railDir, Direction switchDir, Direction straightSwitch, String^ imagePath, String^ name) : Rail(railDir, imagePath, name) {
	//TODO: Check if the switch direction and the rail directions are the same?
	//TODO: Assign correct images
	SwitchDirection = switchDir;
	StraightSwitchDirection = straightSwitch;
}

void RailSwitch::Switch(List<Train^>^ trains)
{
	System::Windows::Forms::MessageBox::Show("Old directions: " + EndDirections.ToString());
	//Check if no train is on the same tile
	for each (Train^ tr in trains)
	{
		if (tr->Tile == this) { 
			return;
		}
	}

	if (IsStraight) {
		EndDirections = AddDirections(FixedDirection, SwitchDirection); //Change logical enddirections
		//TODO: Change Imagepath
		System::Windows::Forms::MessageBox::Show("New directions: " + EndDirections.ToString());
	}
	else {
		EndDirections = AddDirections(FixedDirection, StraightSwitchDirection);
		System::Windows::Forms::MessageBox::Show("New directions: " + EndDirections.ToString());
	}
}

