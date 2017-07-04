#include "TileObject.h"

inline TileObject::TileObject(String^ _imagePath, String^ _id_name)
{
	// initialize position with zero
	coord = gcnew Pos(0, 0);
	imagePath = _imagePath;
	id_name = _id_name;
}

String^ TileObject::ImagePath::get()
{
	return imagePath;
}

void TileObject::ImagePath::set(String^ _imagePath) 
{
	imagePath = _imagePath;
}

Pos^ TileObject::Position::get()
{
	return coord;
}

void TileObject::Position::set(Pos^ _position) {
	coord = _position;
}

void TileObject::Tick(double time)
{

}

Object ^TileObject::Clone()
{
	TileObject ^temp = static_cast<TileObject^>(MemberwiseClone());
	temp->coord = gcnew Pos(0, 0);
	return temp;
}