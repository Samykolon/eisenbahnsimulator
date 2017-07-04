﻿#pragma once

#include "TileObject.h"
#include "Train.h"
using namespace System::Drawing;


using namespace System;
using namespace System::Collections::Generic;


enum class category {train, rail, railSwitch, decoraction, railStop, environment};

public ref class Appdata
{
	Dictionary<String^, String^>^ lang;
	Dictionary<String^, TileObject^>^ tiles;
	Dictionary<String^, Train ^>^ trains;
	Dictionary<String^, List<String^>^>^ categories;
	Dictionary<String^, String^>^ imagePaths;
	List<String^>^ categoryList;
	Dictionary < String^, Image^ >^ images;
public:

	Appdata(); 
	TileObject ^getTile(String^ keyString);
	Train^ getTrain(String^ keyString);
	String ^getLangString(String ^ keyString);
	List<String^>^ getCategory(String^ keyString);
	List<String^>^ getCategoryList();
	
	
	String^ getImagePath(String^ keyString);

	bool isTile(String^ str);
	bool isTrain(String ^str);
	Image ^getImageFromPath(String ^keyString);
	Image ^getImage(String ^keyString);

};