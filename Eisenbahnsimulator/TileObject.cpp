#include "TileObject.h"

inline TileObject::TileObject(String^ _imagePath, String^ _name)
{
	X = 0;
	Y = 0;
	imagePath = _imagePath;
	name = _name;
}

void TileObject::setPosition(int _x, int _y)
{
	x = _x;
	y = _y;
}
