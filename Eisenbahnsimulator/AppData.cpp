#include "AppData.h"
#include "TileObject.h"
#include "TileRail.h"
#include "TileSignalRail.h"
#include "TileDecoration.h"
#include "TileTrainStop.h"
#include "TileRailSwitch.h"
Appdata::Appdata()
{
	tiles = gcnew Dictionary<String ^, TileObject^>;
	lang = gcnew Dictionary<String^, String^>;
	trains = gcnew Dictionary<String^, Train ^>;
	categories = gcnew Dictionary<String^, List<CategoryItem>^>;
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

	tiles->Add(L"Tile_Rail_Signal_North_South", gcnew SignalRail(Directions::NorthSouth, L"Rails/Rail_Normal_Vert_SignalGreen.png", L"Rails/Rail_Normal_Vert_SignalRed.png", L"Tile_Rail_Signal_North_South"));
	tiles->Add(L"Tile_Rail_Signal_West_East", gcnew SignalRail(Directions::EastWest, L"Rails/Rail_Normal_Hor_SignalGreen.png", L"Rails/Rail_Normal_Hor_SignalRed.png", L"Tile_Rail_Signal_West_East"));
	tiles->Add(L"Tile_Rail_Signal_North_East", gcnew SignalRail(Directions::NorthEast, L"Rails/Rail_Curve_RightTop_SignalGreen.png", L"Rails/Rail_Curve_RightTop_SignalRed.png", L"Tile_Rail_Signal_West_East"));
	tiles->Add(L"Tile_Rail_Signal_North_West", gcnew SignalRail(Directions::NorthWest, L"Rails/Rail_Curve_LeftTop_SignalGreen.png", L"Rails/Rail_Curve_LeftTop_SignalRed.png", L"Tile_Rail_Signal_West_East"));
	tiles->Add(L"Tile_Rail_Signal_South_East", gcnew SignalRail(Directions::EastSouth, L"Rails/Rail_Curve_RightBottom_SignalGreen.png", L"Rails/Rail_Curve_RightBottom_SignalRed.png", L"Tile_Rail_Signal_West_East"));
	tiles->Add(L"Tile_Rail_Signal_South_West", gcnew SignalRail(Directions::SouthWest, L"Rails/Rail_Curve_LeftBottom_SignalGreen.png", L"Rails/Rail_Curve_LeftBottom_SignalRed.png", L"Tile_Rail_Signal_West_East"));

	trains->Add(L"train_electric", gcnew Train(TrainType::ElectricLocomotive, "train_electric", L"Rails/Rail_Curve_LeftTop.png", 5));
	trains->Add(L"train_steam", gcnew Train(TrainType::SteamEngine, "train_steam", L"Rails/Rail_Curve_LeftTop.png", 1));
	trains->Add(L"train_diesel", gcnew Train(TrainType::DieselEngine, "train_diesel", L"Rails/Rail_Curve_LeftTop.png", 10));

	tiles->Add(L"Tile_Rail_Switch_Bottom_Left", gcnew RailSwitch(Directions::WestEast, Direction::South, Direction::East, L"Rails/Rail_Switch_BottomLeft_No.png", L"Tile_Rail_Switch_Bottom_Left"));
	tiles->Add(L"Tile_Rail_Switch_Bottom_Right", gcnew RailSwitch(Directions::EastWest, Direction::South, Direction::West, L"Rails/Rail_Switch_BottomRight_No.png", L"Tile_Rail_Switch_Bottom_Right"));
	tiles->Add(L"Tile_Rail_Switch_Top_Left", gcnew RailSwitch(Directions::WestEast, Direction::North, Direction::East, L"Rails/Rail_Switch_TopLeft_No.png", L"Tile_Rail_Switch_Top_Left"));
	tiles->Add(L"Tile_Rail_Switch_Top_Right", gcnew RailSwitch(Directions::EastWest, Direction::North, Direction::West, L"Rails/Rail_Switch_TopRight_No.png", L"Tile_Rail_Switch_Top_Right"));
	tiles->Add(L"Tile_Rail_Switch_Left_Bottom", gcnew RailSwitch(Directions::SouthNorth, Direction::West, Direction::North, L"Rails/Rail_Switch_LeftBottom_No.png", L"Tile_Rail_Switch_Left_Bottom"));
	tiles->Add(L"Tile_Rail_Switch_Left_Top", gcnew RailSwitch(Directions::NorthSouth, Direction::West, Direction::South, L"Rails/Rail_Switch_LeftTop_No.png", L"Tile_Rail_Switch_Left_Top"));
	tiles->Add(L"Tile_Rail_Switch_Right_Bottom", gcnew RailSwitch(Directions::SouthNorth, Direction::East, Direction::North, L"Rails/Rail_Switch_RightBottom_No.png", L"Tile_Rail_Switch_Right_Left"));
	tiles->Add(L"Tile_Rail_Switch_Right_Top", gcnew RailSwitch(Directions::NorthSouth, Direction::East, Direction::South, L"Rails/Rail_Switch_RightTop_No.png", L"Tile_Rail_Switch_Right_Top"));

	tiles->Add(L"FoliageTree", gcnew Decoration(DecoType::FoliageTree, L"Rails/FoliageTree.png", "FoliageTree"));
	tiles->Add(L"Conifer", gcnew Decoration(DecoType::Conifer, L"Rails/Conifer.png", "Conifer"));
	tiles->Add(L"Bush", gcnew Decoration(DecoType::Bush, L"Rails/Bush.png", "Bush"));
	tiles->Add(L"House", gcnew Decoration(DecoType::House, L"Rails/House.png", "House"));
	tiles->Add(L"House2", gcnew Decoration(DecoType::House, L"Rails/House2.png", "House2"));
	tiles->Add(L"House3", gcnew Decoration(DecoType::House, L"Rails/House3.png", "House3"));

	tiles->Add(L"Station", gcnew TrainStop(Directions::EastWest, 1, L"Rails/Station1.png", L"Station"));

	// Create Categories for Toolbox
	List<CategoryItem>^ categoryRails = gcnew List<CategoryItem>;
	List<CategoryItem>^ categoryTrains = gcnew List<CategoryItem>;
	List<CategoryItem>^ categoryRailSwitches = gcnew List<CategoryItem>;
	List<CategoryItem>^ categoryDecorations = gcnew List<CategoryItem>;
	List<CategoryItem>^ categoryRailStop = gcnew List<CategoryItem>;
	List<CategoryItem>^ categoryAll = gcnew List <CategoryItem>;

	// Items in rail category in this order
	categoryRails->Add(CategoryItem(L"Tile_Rail_South_North", L"Rails/Rail_Normal_Vert.png"));
	categoryRails->Add(CategoryItem(L"Tile_Rail_East_West", L"Rails/Rail_Normal_Hor.png"));
	categoryRails->Add(CategoryItem(L"Tile_Rail_East_South", L"Rails/Rail_Curve_RightBottomC.png"));
	categoryRails->Add(CategoryItem(L"Tile_Rail_East_North", L"Rails/Rail_Curve_RightTopC.png"));
	categoryRails->Add(CategoryItem(L"Tile_Rail_South_West", L"Rails/Rail_Curve_LeftBottomC.png"));
	categoryRails->Add(CategoryItem(L"Tile_Rail_West_North", L"Rails/Rail_Curve_LeftTopC.png"));

	categoryRails->Add(CategoryItem(L"Tile_Rail_Signal_North_South", L"Rails/Rail_Normal_Vert_SignalBoth.png"));
	categoryRails->Add(CategoryItem(L"Tile_Rail_Signal_West_East", L"Rails/Rail_Normal_Hor_SignalBoth.png"));
	categoryRails->Add(CategoryItem(L"Tile_Rail_Signal_North_East", L"Rails/Rail_Curve_RightTop_Signal_C.png"));
	categoryRails->Add(CategoryItem(L"Tile_Rail_Signal_North_West", L"Rails/Rail_Curve_LeftTop_Signal_C.png"));
	categoryRails->Add(CategoryItem(L"Tile_Rail_Signal_South_East", L"Rails/Rail_Curve_RightBottom_Signal_C.png"));
	categoryRails->Add(CategoryItem(L"Tile_Rail_Signal_South_West", L"Rails/Rail_Curve_LeftBottom_Signal_C.png"));

	categoryRailSwitches->Add(CategoryItem(L"Tile_Rail_Switch_Bottom_Left", L"Rails/Rail_Switch_BottomLeft_C.png"));
	categoryRailSwitches->Add(CategoryItem(L"Tile_Rail_Switch_Bottom_Right", L"Rails/Rail_Switch_BottomRight_C.png"));
	categoryRailSwitches->Add(CategoryItem(L"Tile_Rail_Switch_Top_Left", L"Rails/Rail_Switch_TopLeft_C.png"));
	categoryRailSwitches->Add(CategoryItem(L"Tile_Rail_Switch_Top_Right", L"Rails/Rail_Switch_TopRight_C.png"));
	categoryRailSwitches->Add(CategoryItem(L"Tile_Rail_Switch_Left_Bottom", L"Rails/Rail_Switch_LeftBottom_C.png"));
	categoryRailSwitches->Add(CategoryItem(L"Tile_Rail_Switch_Left_Top", L"Rails/Rail_Switch_LeftTop_C.png"));
	categoryRailSwitches->Add(CategoryItem(L"Tile_Rail_Switch_Right_Bottom", L"Rails/Rail_Switch_RightBottom_C.png"));
	categoryRailSwitches->Add(CategoryItem(L"Tile_Rail_Switch_Right_Top", L"Rails/Rail_Switch_RightTop_C.png"));

	// Items in train category in this order
	categoryTrains->Add(CategoryItem(L"train_electric", L"Rails/House.png"));
	categoryTrains->Add(CategoryItem(L"train_diesel", L"Rails/House.png"));
	categoryTrains->Add(CategoryItem(L"train_steam", L"Rails/House.png"));

	categoryDecorations->Add(CategoryItem(L"FoliageTree", L"Rails/FoliageTree.png"));
	categoryDecorations->Add(CategoryItem(L"Conifer", L"Rails/Conifer.png"));
	categoryDecorations->Add(CategoryItem(L"Bush", L"Rails/Bush.png"));
	categoryDecorations->Add(CategoryItem(L"House", L"Rails/House.png"));
	categoryDecorations->Add(CategoryItem(L"House2", L"Rails/House2.png"));
	categoryDecorations->Add(CategoryItem(L"House3", L"Rails/House3.png"));

	categoryRailStop->Add(CategoryItem(L"Station", L"Rails/Station1.png"));




	// Items in All category
	for each (CategoryItem item in categoryRails)
	{
		categoryAll->Add(item);
	}
	for each (CategoryItem item in categoryTrains)
	{
		categoryAll->Add(item);
	}
	for each (CategoryItem item in categoryRailSwitches)
	{
		categoryAll->Add(item);
	}
	for each (CategoryItem item in categoryDecorations)
	{
		categoryAll->Add(item);
	}
	for each (CategoryItem item in categoryRailStop)
	{
		categoryAll->Add(item);
	}

	// link categorie List with identifier
	categories->Add(L"Category_Rails", categoryRails);
	categories->Add(L"Category_Trains", categoryTrains);
	categories->Add(L"Category_RailSwitches", categoryRailSwitches);
	categories->Add(L"Category_Decoration", categoryDecorations);
	categories->Add(L"Category_RailStops", categoryRailStop);
	categories->Add(L"Category_All", categoryAll);

	// order of categories in dropbox
	categoryList->Add(L"Category_All");
	categoryList->Add(L"Category_Rails");
	categoryList->Add(L"Category_Trains");
	categoryList->Add(L"Category_RailSwitches");
	categoryList->Add(L"Category_Decoration");
	categoryList->Add(L"Category_RailStops");
	//categoryList->Add(L"Category_Environment");



	// Load Names to indentifier
	lang->Add(L"Tile_Rail_East_South", L"Schiene Kurve");
	lang->Add(L"Tile_Rail_East_West", L"Schiene Gerade");
	lang->Add(L"Tile_Rail_East_North", L"Schiene Kurve");
	lang->Add(L"Tile_Rail_South_West", L"Schiene Kurve");
	lang->Add(L"Tile_Rail_South_North", L"Schiene Gerade");
	lang->Add(L"Tile_Rail_West_North", L"Schiene Kurve");

	lang->Add(L"Tile_Rail_Signal_North_South", L"Signalschiene Gerade");
	lang->Add(L"Tile_Rail_Signal_West_East", L"Signalschiene Gerade");
	lang->Add(L"Tile_Rail_Signal_North_East", L"Signalschiene Kurve");
	lang->Add(L"Tile_Rail_Signal_North_West", L"Signalschiene Kurve");
	lang->Add(L"Tile_Rail_Signal_South_East", L"Signalschiene Kurve");
	lang->Add(L"Tile_Rail_Signal_South_West", L"Signalschiene Kurve");

	lang->Add(L"train_steam", L"Dampflok");
	lang->Add(L"train_electric", L"Elektrischer Zug");
	lang->Add(L"train_diesel", L"Dieselzug");

	lang->Add(L"Tile_Rail_Switch_Bottom_Left", L"Weiche");
	lang->Add(L"Tile_Rail_Switch_Bottom_Right", L"Weiche");
	lang->Add(L"Tile_Rail_Switch_Top_Left", L"Weiche");
	lang->Add(L"Tile_Rail_Switch_Top_Right", L"Weiche");
	lang->Add(L"Tile_Rail_Switch_Left_Bottom", L"Weiche");
	lang->Add(L"Tile_Rail_Switch_Left_Top", L"Weiche");
	lang->Add(L"Tile_Rail_Switch_Right_Bottom", L"Weiche");
	lang->Add(L"Tile_Rail_Switch_Right_Top", L"Weiche");

	lang->Add(L"FoliageTree", L"Laubbaum");
	lang->Add(L"Conifer", L"Nadelbaum");
	lang->Add(L"Bush", L"Strauch");
	lang->Add(L"House", L"Haus");
	lang->Add(L"House2", L"Haus");
	lang->Add(L"House3", L"Haus");

	lang->Add(L"Station", L"Bahnhof");

	lang->Add(L"Category_Rails", L"Schienen");
	lang->Add(L"Category_Trains", L"Züge");
	lang->Add(L"Category_RailSwitches", L"Weichen");
	lang->Add(L"Category_Decoration", L"Dekoration");
	lang->Add(L"Category_RailStops", L"Haltestellen");
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
	return keyString;
	throw gcnew System::Exception("Key not found in dictionary lang. Key: " + keyString);
}

TileObject^ Appdata::getTile(String^ keyString)
{
	TileObject^ temp;
	if (tiles->TryGetValue(keyString, temp))
		return temp;
	throw gcnew System::Exception("Key not found in dictionary tiles. Key: " + keyString);
}

Train^ Appdata::getTrain(String^ keyString)
{
	Train^ temp;
	if (trains->TryGetValue(keyString, temp))
		return temp;
	throw gcnew System::Exception("Key not found in dictionary trains. Key: " + keyString);
}

List<CategoryItem>^ Appdata::getCategory(String^ keyString)
{
	List<CategoryItem>^ temp;
	if (categories->TryGetValue(keyString, temp))
		return temp;
	throw gcnew System::Exception("Key not found in dictionary trains. Key: " + keyString);
}

List<String^>^ Appdata::getCategoryList()
{
	return categoryList;
}

String ^ Appdata::getImagePath(String ^ keyString)
{
	if (imagePaths->ContainsKey(keyString))
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

Image ^ Appdata::getImageFromPath(String ^ filePath)
{
	if (images->ContainsKey(filePath))
	{
		return images[filePath];
	}
	if (filePath != nullptr)
	{
		if (System::IO::File::Exists(filePath))
		{
			images->Add(filePath, Image::FromFile(filePath));
		}
		else
		{
			throw gcnew System::Exception("File: " + filePath + " doesn't exist");
		}
	}
	return images[filePath];
}

Image ^ Appdata::getImage(String ^ keyString)
{
	String^ path = getImagePath(keyString);
	if (path != nullptr)
	{
		return getImageFromPath(path);
	}
	throw gcnew System::Exception("No Image under this keyString: " + keyString);
	return nullptr;
}
