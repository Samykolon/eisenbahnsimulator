#include "TileObject.h"

inline TileObject::TileObject(String^ _imagePath, String^ _name)
{
	// initialize position with zero
	coord = gcnew Pos(0, 0);
	imagePath = _imagePath;
	name = _name;
}

void TileObject::setPosition(int _x, int _y)
{
	coord->posX = _x;
	coord->posY = _y;
}

