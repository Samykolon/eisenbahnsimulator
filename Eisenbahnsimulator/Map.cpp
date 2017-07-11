﻿#include "Map.h"

Map::Map(int _height, int _width)
{
	Height = _height;
	Width = _width;
	TMap = gcnew List<TileObject^>(_height * _width);
}

TileObject^ Map::GetTile(int _posX, int _posY) // returns Object at position x, y	
{
	Point tempPosition = Point(_posX, _posY);
	
	int count = TMap->Count;

	for (int i = 0; i < count; i++)
	{
		if (TMap[i]->Position == tempPosition)
		{
			return TMap[i];
		}
	}
	return nullptr;
}

inline TileObject^ Map::TileAt(int i)
{
	return TMap[i];
}

void Map::SetTile(TileObject ^ _obj, int _posX, int _posY) //Sets the object at x, y
{
	_obj->Position = Point(_posX, _posY);

	// Check if an object is already there
	for (int i = TMap->Count - 1; i >= 0; i--) //Reverse for loop, to make deletion possible
	{
		if (TMap[i]->Position == _obj->Position)
		{
			TMap->RemoveAt(i); //Remove objects that are overwritten
			break; 
		}
	}
	TMap->Add(_obj); //Add object 	
}

void Map::DeleteTile(TileObject^ _obj, int _posX, int _posY)
{
	_obj->Position = Point(_posX, _posY);
	for (int i = TMap->Count - 1; i >= 0; i--) //Reverse for loop, to make deletion possible
	{
		if (TMap[i]->Position == _obj->Position)
		{
			TMap->RemoveAt(i);
			TMap->Remove(_obj);//Remove objects that are overwritten
			break; // TODO : Maybe dont break I don't know
		}
	}
}

int Map::GetCount()
{
	return TMap->Count;	
}
