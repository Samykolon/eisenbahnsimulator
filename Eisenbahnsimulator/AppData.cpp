#include "AppData.h"
#include "TileObject.h"
#include "TileRail.h"

Appdata::Appdata()
{
	tiles = gcnew Dictionary<String ^,TileObject^>;
	lang = gcnew Dictionary<String^, String^>;
	trains = gcnew Dictionary<String^, Train ^>;
	categories = gcnew Dictionary<String^, List<String^>^>;
	categoryList = gcnew List<String^>;
	imagePaths = gcnew Dictionary<String^, String^>;
	images = gcnew Dictionary<String ^, Image^>;


	// Tiles will be loaded only on startup
	tiles->Add(L"Tile_Rail_East_South", gcnew Rail(Directions::EastSouth, L"Rails/Rail_Curve_RightBottom.png", "Tile_Rail_East_South"));
	tiles->Add(L"Tile_Rail_East_West", gcnew Rail(Directions::EastWest, L"Rails/Rail_Normal_Hor.png", "Tile_Rail_East_West"));
	tiles->Add(L"Tile_Rail_East_North", gcnew Rail(Directions::NorthEast, L"Rails/Rail_Curve_RightTop.png", "Tile_Rail_East_North"));
	tiles->Add(L"Tile_Rail_South_West", gcnew Rail(Directions::SouthWest, L"Rails/Rail_Curve_LeftBottom.png", "Tile_Rail_South_West"));
	tiles->Add(L"Tile_Rail_South_North", gcnew Rail(Directions::NorthSouth, L"Rails/Rail_Normal_Vert.png", "Tile_Rail_South_North"));
	tiles->Add(L"Tile_Rail_West_North", gcnew Rail(Directions::NorthWest, L"Rails/Rail_Curve_LeftTop.png", "Tile_Rail_West_North"));
	/*
	trains->Add(L"Train_steam_locomotive",gcnew Train());
	trains->Add(L"Train_electric_locomotive", gcnew Train());
	trains->Add(L"Train_diesel_locomotive", gcnew Train());
	*/
//	trains->Add(L"train",gcnew Train(TrainType::ElectricLocomotive,"dsa",Direction::East,Direction::North,))




	// Create Categories for Toolbox
	List<String^>^ categoryRails = gcnew List<String^>;
	List<String^>^ categoryTrains = gcnew List<String^>;
	List<String^>^ categoryRailSwitches = gcnew List<String^>;
	List<String^>^ categoryDecoractions = gcnew List<String^>;
	List<String^>^ categoryRailStop = gcnew List<String^>;
	List<String^>^ categoryEnvironment = gcnew List<String^>;
	List<String^>^ categoryAll = gcnew List <String^>;
	
	// Items in rail category in this order
	categoryRails->Add(L"Tile_Rail_South_North");
	categoryRails->Add(L"Tile_Rail_East_West");
	categoryRails->Add(L"Tile_Rail_East_South");
	categoryRails->Add(L"Tile_Rail_East_North");
	categoryRails->Add(L"Tile_Rail_South_West");
	categoryRails->Add(L"Tile_Rail_West_North");

	// Items in train category in this order
	//categoryTrains->Add(L"Train");

	// link categorie List with identifier
	categories->Add(L"Category_Rails", categoryRails);
	categories->Add(L"Category_Trains", categoryTrains);
	categories->Add(L"Category_RailSwitches", categoryRailSwitches);
	categories->Add(L"Category_Decoration", categoryDecoractions);
	categories->Add(L"Category_RailStops", categoryRailStop);
	categories->Add(L"Category_Environment", categoryEnvironment);
	categories->Add(L"Category_All", categoryAll);
	
	// order of categories in dropbox
	categoryList->Add(L"Category_Rails");
	categoryList->Add(L"Category_Trains");
	categoryList->Add(L"Category_RailSwitches");
	categoryList->Add(L"Category_Decoration");
	categoryList->Add(L"Category_RailStops");
	categoryList->Add(L"Category_Environment");
	categoryList->Add(L"Category_All");


	// Load Names to indentifier
	lang->Add(L"Tile_Rail_East_South", L"Schiene Süd-Ost");
	lang->Add(L"Tile_Rail_East_West", L"Schiene Ost-West");
	lang->Add(L"Tile_Rail_East_North", L"Schiene Ost-Nord");
	lang->Add(L"Tile_Rail_South_West", L"Schiene Süd-West");
	lang->Add(L"Tile_Rail_South_North", L"Schiene Süd-Nord");
	lang->Add(L"Tile_Rail_West_North", L"Schiene West-Nord");


	lang->Add(L"Category_Rails", L"Schienen");
	lang->Add(L"Category_Trains", L"Züge");
	lang->Add(L"Category_RailSwitches", L"Weichen");
	lang->Add(L"Category_Decoration", L"Dekoration");
	lang->Add(L"Category_RailStops", L"Haltestellen");
	lang->Add(L"Category_Environment", L"Umgebung");
	lang->Add(L"Category_All", L"Alle");


	// Load images to imagePaths from tiles
	for each (KeyValuePair<String^, TileObject^>^ tile in tiles)
	{
		imagePaths->Add(tile->Key, tile->Value->ImagePath);
	}
	for each (KeyValuePair<String^, Train^>^ train in trains)
	{
		imagePaths->Add(train->Key, train->Value->ImagePath);
	}
}

String^ Appdata::getLangString(String ^ keyString)
{
	String ^temp;
	if (lang->TryGetValue(keyString, temp))
		return temp;
	throw "Key not found in dictionary lang. Key: " + keyString;
}

TileObject^ Appdata::getTile(String^ keyString)
{
	TileObject^ temp;
	if (tiles->TryGetValue(keyString, temp))
		return temp;
	throw "Key not found in dictionary tiles. Key: " + keyString;
}

Train^ Appdata::getTrain(String^ keyString)
{
	Train^ temp;
	if (trains->TryGetValue(keyString, temp))
		return temp;
	throw "Key not found in dictionary trains. Key: " + keyString;
}

List<String^>^ Appdata::getCategory(String^ keyString)
{
	List<String^>^ temp;
	if (categories->TryGetValue(keyString, temp))
		return temp;
	throw "Key not found in dictionary trains. Key: " + keyString;
}

List<String^>^ Appdata::getCategoryList()
{
	return categoryList;
}

String ^ Appdata::getImagePath(String ^ keyString)
{
	if(imagePaths->ContainsKey(keyString))
		return imagePaths[keyString];
	return nullptr;
}

bool Appdata::isTile(String ^ str)
{
	return tiles->ContainsKey(str);
}

bool Appdata::isTrain(String ^ str)
{
	return trains->ContainsKey(str);
}

Image ^ Appdata::getImage(String ^ keyString)
{
	if (images->ContainsKey(keyString))
	{
		return images[keyString];
	}
	String^ path = getImagePath(keyString);
	
	if (path != nullptr)
	{
		images->Add(keyString, Image::FromFile(path));
	}
	return images[keyString];
}
