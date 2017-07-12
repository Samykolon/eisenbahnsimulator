#include "TileObject.h"

inline TileObject::TileObject(String^ _imagePath, String^ _id_name)
{
	// initialize position with zero
	position = Point(0, 0);
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

Point TileObject::Position::get()
{
	return position;
}

void TileObject::Position::set(Point _position) {
	position = _position;
}

Object ^TileObject::Clone()
{
	TileObject ^temp = static_cast<TileObject^>(MemberwiseClone());
	return temp;
}