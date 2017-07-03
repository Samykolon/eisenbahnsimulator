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
	// Tiles will be loaded only on startup
	tiles->Add(L"Tile_Rail_East_South", gcnew Rail(Directions::EastSouth,  L"Rail_Curve_RightBottom.png", "Rail_East_South"));
	tiles->Add(L"Tile_Rail_East_West",  gcnew Rail(Directions::EastWest,   L"Rail_Normal_Hor.png",		"Rail_East_West"));
	tiles->Add(L"Tile_Rail_East_North", gcnew Rail(Directions::NorthEast,  L"Rail_Curve_RightTop.png",	"Rail_East_North"));
	tiles->Add(L"Tile_Rail_South_West", gcnew Rail(Directions::SouthWest,  L"Rail_Curve_LeftBottom.png",	"Rail_South_West"));
	tiles->Add(L"Tile_Rail_South_North",gcnew Rail(Directions::NorthSouth, L"Rail_Normal_Vert.png",		"Rail_South_North"));
	tiles->Add(L"Tile_Rail_West_North", gcnew Rail(Directions::NorthWest,  L"Rail_Curve_LeftTop.png",		"Rail_West_North"));
	/*
	trains->Add(L"Train_steam_locomotive",gcnew Train());
	trains->Add(L"Train_electric_locomotive", gcnew Train());
	trains->Add(L"Train_diesel_locomotive", gcnew Train());
	*/
	


	// Create Categories for Toolbox
	List<String^>^ categoryRails = gcnew List<String^>;
	List<String^>^ categoryTrains = gcnew List<String^>;
	List<String^>^ categoryRailSwitches = gcnew List<String^>;
	List<String^>^ categoryDecoractions = gcnew List<String^>;
	List<String^>^ categoryRailStop = gcnew List<String^>;
	List<String^>^ categoryEnvironment = gcnew List<String^>;
	List<String^>^ categoryAll = gcnew List <String^>;
	// Rails
	categoryRails->Add(L"Tile_Rail_East_South");
	categoryRails->Add(L"Tile_Rail_East_West");
	categoryRails->Add(L"Tile_Rail_East_North");
	categoryRails->Add(L"Tile_Rail_South_West");
	categoryRails->Add(L"Tile_Rail_South_North");
	categoryRails->Add(L"Tile_Rail_West_North");

	
	categories->Add(L"category_Rails", categoryRails);
	categories->Add(L"category_Trains", categoryTrains);
	categories->Add(L"category_RailSwitches", categoryRailSwitches);
	categories->Add(L"category_Decoration", categoryDecoractions);
	categories->Add(L"category_RailStops", categoryRailStop);
	categories->Add(L"category_Environment", categoryEnvironment);
	categories->Add(L"category_All", categoryAll);
	

	categoryList->Add(L"category_Rails");
	categoryList->Add(L"category_Trains");
	categoryList->Add(L"category_RailSwitches");
	categoryList->Add(L"category_Decoration");
	categoryList->Add(L"category_RailStops");
	categoryList->Add(L"category_Environment");
	categoryList->Add(L"category_All");


	// Lade Sprachdatei
	lang->Add(L"Tile_Rail_East_South", L"Schiene Süd-Ost");
	lang->Add(L"Tile_Rail_East_West", L"Schiene Ost-West");
	lang->Add(L"Tile_Rail_East_North", L"Schiene Ost-Nord");
	lang->Add(L"Tile_Rail_South_West", L"Schiene Süd-West");
	lang->Add(L"Tile_Rail_South_North", L"Schiene Süd-Nord");
	lang->Add(L"Tile_Rail_West_North", L"Schiene West-Nord");


	lang->Add(L"category_Rails", L"Schienen");
	lang->Add(L"category_Trains", L"Züge");
	lang->Add(L"category_RailSwitches", L"Weichen");
	lang->Add(L"category_Decoration", L"Dekoration");
	lang->Add(L"category_RailStops", L"Haltestellen");
	lang->Add(L"category_Environment", L"Umgebung");
	lang->Add(L"category_All", L"Alle");
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

bool Appdata::isTile(String ^ str)
{
	return tiles->ContainsKey(str);
}

bool Appdata::isTrain(String ^ str)
{
	return trains->ContainsKey(str);
}