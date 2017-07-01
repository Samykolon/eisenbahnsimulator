#include "Map.h"



Map::Map(int _height, int _width)
{
	Height = _height;
	Width = _width;
	TMap = gcnew List<TileObject^>(_height * _width);
}

TileObject^ Map::GetTile(int posX, int posY) // returns Object at position x, y	
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

void Map::SetTile(TileObject ^ obj) //Sets the object at x, y
{
	// Check if an object is already there
	for (int i = TMap->Count - 1; i >= 0; i--) //Reverse for loop, to make deletion possible
	{
		if (TMap[i]->X == obj->X && TMap[i]->Y == obj->Y) {
			TMap->RemoveAt(i); //Remove objects that are overwritten
		}

	}
	TMap->Add(obj); //Add object 	
}

int Map::GetCount()
{
	return TMap->Count;	
}
