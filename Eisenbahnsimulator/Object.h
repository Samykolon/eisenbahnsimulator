#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class TileObject abstract
{
public:
	int PosX;
	int PosY;
};


public ref class Signal
{
private:


};

enum class Directions { //Two cardinal directions
	NorthEast = 0, EastNorth = 0, NorthSouth = 1, SouthNorth = 1,
	NorthWest = 2, WestNorth = 2, EastSouth = 3, SouthEast = 3,
	EastWest = 4, WestEast = 4, SouthWest = 5, WestSouth = 5
};

enum class Direction { East, North, West, South }; //One cardinal direction

public ref class Rail : TileObject
{
private:
	Signal ^signal;

public:
	Rail(Directions _dir)
	{
		Directions = _dir;
		signal = nullptr;
	}
	void setSignal(Signal ^_sig)
	{
		signal = _sig;
	}
	Signal ^setSignal()
	{
		return signal;
	}
	Directions Directions; //The directions of both rail ends

	Boolean LeadsTo(Direction dir); //Returns true if the Rail leads to the specified direction
};



public ref class Map
{
private:
	int Height;
	int Width;
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
			if (_map[i]->PosX == posX && _map[i]->PosY == posY)
			{
				return _map[i];
			}
		}
		return nullptr;
	}

	TileObject^ SetTile(int posX, int posY, TileObject^ obj)
	{
		obj->PosY = posY;
		obj->PosX = posX;
		_map->Add(obj);
		return obj;
	}
};