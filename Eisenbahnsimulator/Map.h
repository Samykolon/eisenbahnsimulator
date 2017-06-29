#pragma once
#include "TileObject.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class Map
{
private:
	int Height; //Height of the tile map
	int Width;	//Width of the tile map
	List<TileObject^>^ _map;

public:

	Map(int _height, int _width)
	{
		Height = _height;
		Width = _width;
	}

	// returns Object at position x, y	
	TileObject^ GetTile(int posX, int posY)
	{
		int count = _map->Count;

		for (int i = 0; i < count; i++)
		{
			if (_map[i]->X == posX && _map[i]->Y == posY)
			{
				return _map[i];
			}
		}
		return nullptr;
	}

	TileObject^ SetTile(int posX, int posY, TileObject^ obj) //Sets the object at x, y and initializes the object's coordinates
	{
		//TODO: Check if an object is already there
		obj->Y = posY;
		obj->X = posX;
		_map->Add(obj);
		return obj;
	}
};