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
	
	Map(int _height, int _width)
	{
		Height = _height;
		Width = _width;
		TMap = gcnew List<TileObject^>(_height * _width);
	}

	// returns Object at position x, y	
	TileObject^ GetTile(int posX, int posY)
	{
		
		int count = TMap->Count;

		for (int i = 0; i < count; i++)
		{
			if (TMap[i]->X == posX && TMap[i]->Y == posY)
			{
				return TMap[i];
			}
		}
		return nullptr;
	}

	TileObject^ SetTile(int posX, int posY, TileObject^ obj) //Sets the object at x, y and initializes the object's coordinates
	{
		// Check if an object is already there
		for (int i = TMap->Count - 1; i >= 0; i--) //Reverse for loop, to make deletion possible
		{
			if (TMap[i]->X == posX && TMap[i]->Y == posY) {
				TMap->RemoveAt(i); //Remove objects that are overwritten
			}

		}		
		obj->Y = posY;
		obj->X = posX;
		TMap->Add(obj);
		return obj;
	}
};