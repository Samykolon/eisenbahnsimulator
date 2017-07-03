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
	Dictionary<String^, Train ^>^ trains;
	Dictionary<String ^, List<String^>^>^ categories;
	List<String^>^ categoryList;
public:

	Appdata(); 
	TileObject ^getTile(String^ keyString);
	Train^ getTrain(String^ keyString);
	String ^getLangString(String ^ str);
	List<String^>^ getCategory(String^ keyString);
	List<String^>^ getCategoryList();
	
	bool isTile(String^ str);
	bool isTrain(String ^str);

};