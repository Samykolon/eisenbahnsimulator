#include "AppData.h"
#include "TileObject.h"
#include "Rail.h"

Appdata::Appdata()
{
	// Loads the god damn fucking Data

	tiles = gcnew Dictionary<String ^,TileObject^>;
	lang = gcnew Dictionary<String^, String^>;
	// Tiles will be loaded only on startup
	tiles->Add("Rail_East_South", gcnew Rail(Directions::EastSouth,  L"Rail_Curve_RightBottom.png", "Rail_East_South"));
	tiles->Add("Rail_East_West",  gcnew Rail(Directions::EastWest,   L"Rail_Normal_Hor.png",		"Rail_East_West"));
	tiles->Add("Rail_East_North", gcnew Rail(Directions::NorthEast,  L"Rail_Curve_RightTop.png",	"Rail_East_North"));
	tiles->Add("Rail_South_West", gcnew Rail(Directions::SouthWest,  L"Rail_Curve_LeftBottom.png",	"Rail_South_West"));
	tiles->Add("Rail_South_North",gcnew Rail(Directions::NorthSouth, L"Rail_Normal_Vert.png",		"Rail_South_North"));
	tiles->Add("Rail_West_North", gcnew Rail(Directions::NorthWest,  L"Rail_Curve_LeftTop.png",		"Rail_West_North"));

	// Lade Sprachdatei
	lang->Add("Rail_East_South"	, "Schiene Süd-Ost");
	lang->Add("Rail_East_West"	, "Schiene Ost-West");
	lang->Add("Rail_East_North"	, "Schiene Ost-Nord");
	lang->Add("Rail_South_West"	, "Schiene Süd-West");
	lang->Add("Rail_South_North", "Schiene Süd-Nord");
	lang->Add("Rail_West_North"	, "Schiene West-Nord");
}

TileObject ^ Appdata::getTile(int listIndex, int index)
{

	// if index is out of bounds
	if (tiles->Count <= index || index < 0)
	{
		return nullptr;
	}
	return tiles[index];
}

String^ Appdata::getLangString(String ^ str)
{
	String ^temp;
	if (lang->TryGetValue(str, temp))
		return temp;
}
