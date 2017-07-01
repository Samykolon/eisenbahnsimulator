#pragma once
#include "TileObject.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class Map
{
	List<TileObject^>^ TMap;
	public:
	int Height; //Height of the tile map
	int Width;	//Width of the tile map
	
	Map(int _height, int _width); //Construct the tilemap

		
	TileObject^ GetTile(int posX, int posY);// returns Object at position x, y

	TileObject^ SetTile(int posX, int posY, TileObject^ obj);	//sets Object at x, y and initializes its coordinates
	int GetCount(); //Returns the number of objects it contains
};