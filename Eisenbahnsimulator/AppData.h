#pragma once

#include "TileObject.h"
#include "Train.h"
using namespace System::Drawing;


using namespace System;
using namespace System::Collections::Generic;


value struct CategoryItem {
	String ^keyString;
	String ^iconPath;
	CategoryItem(String ^_keyString, String^ _iconPath)
	{
		keyString = _keyString;
		iconPath = _iconPath;
	}
};

public ref class Appdata
{
public:
	Dictionary<String^, String^>^ lang;
	Dictionary<String^, TileObject^>^ tiles;
	Dictionary<String^, Train ^>^ trains;
	Dictionary<String^, List<CategoryItem>^>^ categories;
	Dictionary<String^, String^>^ imagePaths; 
	List<String^>^ categoryList; 
	Dictionary < String^, Image^ >^ images; // manages loaded images
public:

	Appdata(); 
	TileObject ^getTile(String^ keyString);
	Train^ getTrain(String^ keyString);
	String ^getLangString(String ^ keyString);
	List<CategoryItem>^ getCategory(String^ keyString);
	List<String^>^ getCategoryList();
	
	
	String^ getImagePath(String^ keyString);

	bool isTile(String^ str);
	bool isTrain(String ^str);
	Image ^getImageFromPath(String ^keyString);
	Image ^getImage(String ^keyString);

};