#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void updateToolbox(System::Windows::Forms::ListView^ listViewToolbox, System::Windows::Forms::ComboBox^ Combo)
{
	

}

void toolbox(System::Windows::Forms::ListView^  listViewToolbox, System::Resources::ResourceManager^ rm, System::Windows::Forms::ComboBox^  Combo)
{
	Combo->Items->Add("Schienen");
	Combo->Items->Add("Signale und Weichen");
	Combo->Items->Add("Haltepunkte");
	Combo->Items->Add("Umgebung");
	Combo->Items->Add("Alle");
	Combo->SelectedIndex = 4;
	listViewToolbox->FullRowSelect = true;
	listViewToolbox->View = View::Tile;
	listViewToolbox->Sorting = SortOrder::Ascending;
	listViewToolbox->GridLines = true;
	listViewToolbox->LabelEdit = false;

	//Listviewitems
	ListViewItem^ item1 = gcnew ListViewItem("Schiene vertikal", 0);
	ListViewItem^ item2 = gcnew ListViewItem("Schiene horizontal", 1);
	ListViewItem^ item3 = gcnew ListViewItem("Schienenkurve", 2);
	ListViewItem^ item4 = gcnew ListViewItem("Schienenkurve", 2);
	ListViewItem^ item5 = gcnew ListViewItem("Schienenkurve", 2);
	ListViewItem^ item6 = gcnew ListViewItem("Schienenkurve", 2);
	ListViewItem^ item40 = gcnew ListViewItem("Laubbaum", 40);
	ListViewItem^ item41 = gcnew ListViewItem("Nadelbaum", 41);
	ListViewItem^ item42 = gcnew ListViewItem("Strauch", 42);
	ListViewItem^ item43 = gcnew ListViewItem("Haus", 43);
	ListViewItem^ item7 = gcnew ListViewItem("Placeholder", 99);

	// Create columns for the items and subitems.
	listViewToolbox->Columns->Add("Element", -2, HorizontalAlignment::Left);

	// Resource-Manager
	rm = gcnew System::Resources::ResourceManager("Eisenbahnsimulator.MainFrame", System::Reflection::Assembly::GetExecutingAssembly());


	// Load Images and Create ImageLists
	Image ^Rail_Normal_Vert = safe_cast<Image^> (rm->GetObject("Rail_Normal_Vert"));
	Image ^Rail_Normal_Hor = safe_cast<Image^> (rm->GetObject("Rail_Normal_Hor"));
	Image ^Rail_Curve_LeftTop = safe_cast<Image^> (rm->GetObject("Rail_Curve_LeftTopC"));
	Image ^Rail_Curve_RightTop = safe_cast<Image^> (rm->GetObject("Rail_Curve_RightTopC"));
	Image ^Rail_Curve_RightBottom = safe_cast<Image^> (rm->GetObject("Rail_Curve_RightBottomC"));
	Image ^Rail_Curve_LeftBottom = safe_cast<Image^> (rm->GetObject("Rail_Curve_LeftBottomC"));
	ImageList^ imageListAlle = gcnew ImageList;
	imageListAlle->ImageSize = Size(48, 48);
	imageListAlle->Images->Add(Rail_Normal_Vert);
	imageListAlle->Images->Add(Rail_Normal_Hor);
	imageListAlle->Images->Add(Rail_Curve_LeftTop);
	imageListAlle->Images->Add(Rail_Curve_RightTop);
	imageListAlle->Images->Add(Rail_Curve_RightBottom);
	imageListAlle->Images->Add(Rail_Curve_LeftBottom);
	ImageList^ imageListSchienen = gcnew ImageList;
	imageListSchienen->ImageSize = Size(48, 48);
	imageListSchienen->Images->Add(Rail_Normal_Vert);
	imageListSchienen->Images->Add(Rail_Normal_Hor);
	imageListSchienen->Images->Add(Rail_Curve_LeftTop);
	imageListSchienen->Images->Add(Rail_Curve_RightTop);
	imageListSchienen->Images->Add(Rail_Curve_RightBottom);
	imageListSchienen->Images->Add(Rail_Curve_LeftBottom);


	// Image-List Arrays
	array<ListViewItem^>^Alle = { item1,item2,item3, item6, item4, item5, item40, item41, item42, item43 };
	array<ListViewItem^>^Schienen = { item1,item2,item3, item4, item5, item6};
	
	// Fill Listview based on selected Combobox-Item
	switch (Combo->SelectedIndex)
	{
	case 0:
		listViewToolbox->LargeImageList = imageListSchienen;
		listViewToolbox->Items->AddRange(Schienen);
	default:
		listViewToolbox->LargeImageList = imageListAlle;
		listViewToolbox->Items->AddRange(Alle);

	}
	

	
}