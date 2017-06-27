#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;




void updateToolbox(System::Windows::Forms::ListView^ listViewToolbox, System::Windows::Forms::ComboBox^ Combo, System::Windows::Forms::ImageList^ I1, System::Windows::Forms::ImageList^ I2, array<System::Windows::Forms::ListViewItem^>^A1, array<System::Windows::Forms::ListViewItem^>^A2)
{
	listViewToolbox->Items->Clear();
	listViewToolbox->Clear();
	switch (Combo->SelectedIndex)
	{
	case 0:
		listViewToolbox->LargeImageList = I1;
		listViewToolbox->Items->AddRange(A1);

	default:
		listViewToolbox->LargeImageList = I2;
		listViewToolbox->Items->AddRange(A2);

	}
	
	
}

void toolbox(System::Windows::Forms::ListView^  listViewToolbox, System::Resources::ResourceManager^ rm, System::Windows::Forms::ComboBox^  Combo, System::Windows::Forms::ImageList^ I1, System::Windows::Forms::ImageList^ I2, array<System::Windows::Forms::ListViewItem^>^A1, array<System::Windows::Forms::ListViewItem^>^A2)
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
	ListViewItem^ item10 = gcnew ListViewItem("Schiene vertikal", 0);
	ListViewItem^ item11 = gcnew ListViewItem("Schiene horizontal", 1);
	ListViewItem^ item12 = gcnew ListViewItem("Schienenkurve", 2);
	ListViewItem^ item13 = gcnew ListViewItem("Schienenkurve", 2);
	ListViewItem^ item14 = gcnew ListViewItem("Schienenkurve", 2);
	ListViewItem^ item15 = gcnew ListViewItem("Schienenkurve", 2);
	ListViewItem^ item40 = gcnew ListViewItem("Laubbaum", 40);
	ListViewItem^ item41 = gcnew ListViewItem("Nadelbaum", 41);
	ListViewItem^ item42 = gcnew ListViewItem("Strauch", 42);
	ListViewItem^ item43 = gcnew ListViewItem("Haus", 43);
	ListViewItem^ item999 = gcnew ListViewItem("Placeholder", 99);

	// Create columns for the items and subitems.
	listViewToolbox->Columns->Add("Element", -2, HorizontalAlignment::Left);

	// Resource-Manager
	rm = gcnew System::Resources::ResourceManager("Eisenbahnsimulator.Pictures", System::Reflection::Assembly::GetExecutingAssembly());


	// Load Images and Create ImageLists
	Image ^Rail_Normal_Vert = safe_cast<Image^> (rm->GetObject("Rail_Normal_Vert"));
	Image ^Rail_Normal_Hor = safe_cast<Image^> (rm->GetObject("Rail_Normal_Hor"));
	Image ^Rail_Curve_LeftTop = safe_cast<Image^> (rm->GetObject("Rail_Curve_LeftTopC"));
	Image ^Rail_Curve_RightTop = safe_cast<Image^> (rm->GetObject("Rail_Curve_RightTopC"));
	Image ^Rail_Curve_RightBottom = safe_cast<Image^> (rm->GetObject("Rail_Curve_RightBottomC"));
	Image ^Rail_Curve_LeftBottom = safe_cast<Image^> (rm->GetObject("Rail_Curve_LeftBottomC"));
	
	
	I1->ImageSize = Size(48, 48);
	I1->Images->Add(Rail_Normal_Vert);
	I1->Images->Add(Rail_Normal_Hor);
	I1->Images->Add(Rail_Curve_LeftTop);
	I1->Images->Add(Rail_Curve_RightTop);
	I1->Images->Add(Rail_Curve_RightBottom);
	I1->Images->Add(Rail_Curve_LeftBottom);
	
	I2->ImageSize = Size(48, 48);
	I2->Images->Add(Rail_Normal_Vert);
	I2->Images->Add(Rail_Normal_Hor);
	I2->Images->Add(Rail_Curve_LeftTop);
	I2->Images->Add(Rail_Curve_RightTop);
	I2->Images->Add(Rail_Curve_RightBottom);
	I2->Images->Add(Rail_Curve_LeftBottom);


	// Image-List Arrays
	A1[0] = item10;
	A1[1] = item11;
	A1[2] = item12;
	A1[3] = item13;
	A1[4] = item14;
	A1[5] = item15;
	A1[6] = item40;
	A1[7] = item41;
	A1[8] = item42;
	A1[9] = item43;
	A2[0] = item10;
	A2[1] = item11;
	A2[2] = item12;
	A2[3] = item13;
	A2[4] = item14;
	A2[5] = item15;
		
	// Fill Listview based on selected Combobox-Item
	
	

	
}