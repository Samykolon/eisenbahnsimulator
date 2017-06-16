#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void toolbox(System::Windows::Forms::ListView^  listViewToolbox, System::Resources::ResourceManager^ rm)
{
	listViewToolbox->FullRowSelect = true;
	listViewToolbox->View = View::Tile;
	listViewToolbox->Sorting = SortOrder::Ascending;
	listViewToolbox->GridLines = true;
	listViewToolbox->LabelEdit = false;
	ListViewItem^ item1 = gcnew ListViewItem("Schiene vertikal", 0);
	ListViewItem^ item2 = gcnew ListViewItem("Schiene horizontal", 1);
	ListViewItem^ item3 = gcnew ListViewItem("Schienenkurve", 2);
	ListViewItem^ item4 = gcnew ListViewItem("Schienenkurve", 4);
	ListViewItem^ item5 = gcnew ListViewItem("Schienenkurve", 4);
	ListViewItem^ item6 = gcnew ListViewItem("Schienenkurve", 5);
	ListViewItem^ item7 = gcnew ListViewItem("Placeholder", 6);

	// Create columns for the items and subitems.
	listViewToolbox->Columns->Add("Element", -2, HorizontalAlignment::Left);
	
	
	

	array<ListViewItem^>^temp1 = { item1,item2,item3, item4, item5, item6, item7 };
	listViewToolbox->Items->AddRange(temp1);

	
	rm = gcnew System::Resources::ResourceManager("Eisenbahnsimulator.MainFrame", System::Reflection::Assembly::GetExecutingAssembly());

	Image ^Rail_Normal_Vert = safe_cast<Image^> (rm->GetObject("Rail_Normal_Vert"));
	Image ^Rail_Normal_Hor = safe_cast<Image^> (rm->GetObject("Rail_Normal_Hor"));
	Image ^Rail_Curve_LeftTop = safe_cast<Image^> (rm->GetObject("Rail_Curve_LeftTopC"));
	Image ^Rail_Curve_RightTop = safe_cast<Image^> (rm->GetObject("Rail_Curve_RightTopC"));
	Image ^Rail_Curve_RightBottom = safe_cast<Image^> (rm->GetObject("Rail_Curve_RightBottomC"));
	Image ^Rail_Curve_LeftBottom = safe_cast<Image^> (rm->GetObject("Rail_Curve_LeftBottomC")); 
	ImageList^ imageListLarge = gcnew ImageList;
	imageListLarge->ImageSize = Size(48, 48);
	imageListLarge->Images->Add(Rail_Normal_Vert);
	imageListLarge->Images->Add(Rail_Normal_Hor);
	imageListLarge->Images->Add(Rail_Curve_LeftTop);
	imageListLarge->Images->Add(Rail_Curve_RightTop);
	imageListLarge->Images->Add(Rail_Curve_RightBottom);
	imageListLarge->Images->Add(Rail_Curve_LeftBottom); 
	listViewToolbox->LargeImageList = imageListLarge;
	
	
	
}