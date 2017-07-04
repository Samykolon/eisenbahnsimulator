#include "Position.h"

bool Pos::operator == (Pos ^_position)
{
	// true if position x and y are equal
	return (_position->posX == posX && _position->posY == posY);
}
Pos::Pos(const Pos% pos)
{

}

Pos::Pos(int _posX, int _posY) : posX(_posX), posY(_posY)
{

}
