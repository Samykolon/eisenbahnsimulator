#pragma once

#include "TileObject.h"
#include "Train.h"

using namespace System;
using namespace System::Collections::Generic;


enum class category {train, rail, railSwitch, decoraction, railStop, environment};

public ref class Appdata
{
	Dictionary<String^, String^>^ lang;
	Dictionary<String^, TileObject^>^ tiles;
	List<Train ^>^ trains;
	List<String ^>^ categories;
public:

	Appdata(); 
	TileObject ^getTile(int listIndex, int index);
	String ^getLangString(String ^ str);
};