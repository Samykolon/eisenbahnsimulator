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

		
	TileObject^ GetTile(int posX, int posY);//Returns Object at position x, y
	TileObject^ TileAt(int i); //Returns object at specified index

	void SetTile(TileObject^ obj);	//Adds image at x, y to its list and overwrites object that are already there
	
	int GetCount(); //Returns the number of objects it contains
};