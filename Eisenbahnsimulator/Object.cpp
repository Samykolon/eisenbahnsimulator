#pragma once

using namespace System;
using namespace System::Collections::Generic;


ref class signal;
ref class TileObject;
ref class rail;


public ref class TileObject abstract
{
public:
	int posX;
	int posY;
	int width;
	int height;
};


public ref class signal
{
private:


};

enum Direction {
	NorthEast = 0, EastNorth = 0, NorthSouth = 1, SouthNorth = 1,
	NorthWest = 2, WestNorth = 2, EastSouth = 3, SouthEast = 3,
	EastWest = 4, WestEast = 4, SouthWest = 5, WestSouth = 5
};
public ref class rail : TileObject
{
private:
	signal ^Signal;

public:
	rail(Direction _dir)
	{
		dir = _dir;
		Signal = nullptr;
	}
	void setSignal(signal ^_sig)
	{
		Signal = _sig;
	}
	signal ^setSignal()
	{
		return Signal;
	}
	Direction dir;
};



public ref class map
{
private:
	int height;
	int width;
	List<TileObject^>^_map;

public:

	map(int _height, int _width)
	{
		height = _height;
		width = _width;
	}

	// returns Object at position x, y	
	TileObject^ getTile(int posX, int posY)
	{
		int count = _map->Count;

		for (int i = 0; i < count; i++)
		{
			if (_map[i]->posX == posX && _map[i]->posY == posY)
			{
				return _map[i];
			}
		}
		return nullptr;
	}

	TileObject^ setTile(int posX, int posY, TileObject^ obj)
	{
		obj->posY = posY;
		obj->posX = posX;
		_map->Add(obj);
		return obj;
	}
};