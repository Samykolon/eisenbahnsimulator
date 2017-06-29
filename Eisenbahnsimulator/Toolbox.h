#pragma once


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


void updateToolbox(System::Windows::Forms::ListView^  listViewToolbox, System::Windows::Forms::ComboBox^  Combo, System::Windows::Forms::ImageList^ I0, System::Windows::Forms::ImageList^ I1, System::Windows::Forms::ImageList^ I2, System::Windows::Forms::ImageList^ I3, System::Windows::Forms::ImageList^ I4, System::Windows::Forms::ImageList^ I5, array<System::Windows::Forms::ListViewItem^>^A0, array<System::Windows::Forms::ListViewItem^>^A1, array<System::Windows::Forms::ListViewItem^>^A2, array<System::Windows::Forms::ListViewItem^>^A3, array<System::Windows::Forms::ListViewItem^>^A4, array<System::Windows::Forms::ListViewItem^>^A5)
{
	
	listViewToolbox->Clear();
	switch (Combo->SelectedIndex)
	{
	case 0:
		listViewToolbox->Items->Clear();
		listViewToolbox->LargeImageList = I0;
		listViewToolbox->Items->AddRange(A0);
		break;
	case 1:
		listViewToolbox->Items->Clear();
		listViewToolbox->LargeImageList = I1;
		listViewToolbox->Items->AddRange(A1);
		break;
	case 2:
		listViewToolbox->Items->Clear();
		listViewToolbox->LargeImageList = I2;
		listViewToolbox->Items->AddRange(A2);
		break;
	case 3:
		listViewToolbox->Items->Clear();
		listViewToolbox->LargeImageList = I3;
		listViewToolbox->Items->AddRange(A3);
		break;
	case 4:
		listViewToolbox->Items->Clear();
		listViewToolbox->LargeImageList = I4;
		listViewToolbox->Items->AddRange(A4);
		break;
	case 5:
		listViewToolbox->Items->Clear();
		listViewToolbox->LargeImageList = I5;
		listViewToolbox->Items->AddRange(A5);
		break;

	default:
		listViewToolbox->Items->Clear();
		listViewToolbox->LargeImageList = I5;
		listViewToolbox->Items->AddRange(A5);
		break;

	}
	
	
}

void toolbox(System::Windows::Forms::ListView^  listViewToolbox, System::Resources::ResourceManager^ rm, System::Windows::Forms::ComboBox^  Combo, System::Windows::Forms::ImageList^ I0, System::Windows::Forms::ImageList^ I1, System::Windows::Forms::ImageList^ I2, System::Windows::Forms::ImageList^ I3, System::Windows::Forms::ImageList^ I4, System::Windows::Forms::ImageList^ I5, array<System::Windows::Forms::ListViewItem^>^A0, array<System::Windows::Forms::ListViewItem^>^A1, array<System::Windows::Forms::ListViewItem^>^A2, array<System::Windows::Forms::ListViewItem^>^A3, array<System::Windows::Forms::ListViewItem^>^A4, array<System::Windows::Forms::ListViewItem^>^A5)
{
	Combo->Items->Add("Schienen");
	Combo->Items->Add("Signale und Weichen");
	Combo->Items->Add("Haltepunkte");
	Combo->Items->Add("Umgebung");
	Combo->Items->Add("Züge");
	Combo->Items->Add("Alle");
	Combo->SelectedIndex = 5;
	listViewToolbox->FullRowSelect = true;
	listViewToolbox->View = View::Tile;
	listViewToolbox->Sorting = SortOrder::None;
	listViewToolbox->GridLines = true;
	listViewToolbox->LabelEdit = false;

	//Listviewitems
	ListViewItem^ item10 = gcnew ListViewItem("Schiene vertikal", 1);
	ListViewItem^ item11 = gcnew ListViewItem("Schiene horizontal", 2);
	ListViewItem^ item12 = gcnew ListViewItem("Schienenkurve", 3);
	ListViewItem^ item13 = gcnew ListViewItem("Schienenkurve", 4);
	ListViewItem^ item14 = gcnew ListViewItem("Schienenkurve", 5);
	ListViewItem^ item15 = gcnew ListViewItem("Schienenkurve", 6);
	ListViewItem^ item20 = gcnew ListViewItem("Schiene vertikal mit Signal", 7);
	ListViewItem^ item21 = gcnew ListViewItem("Schiene horizontal mit Signal", 8);
	ListViewItem^ item22 = gcnew ListViewItem("Schienenkurve mit Signal", 9);
	ListViewItem^ item23 = gcnew ListViewItem("Schienenkurve mit Signal", 10);
	ListViewItem^ item24 = gcnew ListViewItem("Schienenkurve mit Signal", 11);
	ListViewItem^ item25 = gcnew ListViewItem("Schienenkurve mit Signal", 12);
	ListViewItem^ item26 = gcnew ListViewItem("Weiche", 13);
	ListViewItem^ item27 = gcnew ListViewItem("Weiche", 14);
	ListViewItem^ item28 = gcnew ListViewItem("Weiche", 15);
	ListViewItem^ item29 = gcnew ListViewItem("Weiche", 16);
	ListViewItem^ item30 = gcnew ListViewItem("Kleiner Bahnhof", 17);
	ListViewItem^ item31 = gcnew ListViewItem("Großer Bahnhof", 18);
	ListViewItem^ item40 = gcnew ListViewItem("Laubbaum", 19);
	ListViewItem^ item41 = gcnew ListViewItem("Nadelbaum", 20);
	ListViewItem^ item42 = gcnew ListViewItem("Strauch", 21);
	ListViewItem^ item43 = gcnew ListViewItem("Haus", 22);
	ListViewItem^ item50 = gcnew ListViewItem("Dampflokomotive", 23);
	ListViewItem^ item51 = gcnew ListViewItem("Diesellokomotive", 24);
	ListViewItem^ item52 = gcnew ListViewItem("Elektrolokomotive", 25);
	ListViewItem^ item999 = gcnew ListViewItem("Placeholder", 99);

	// Create columns for the items and subitems.
	listViewToolbox->Columns->Add("Element", -2, HorizontalAlignment::Left);
	
	// Load Images 
	Image ^Rail_Normal_Vert = safe_cast<Image^> (rm->GetObject("Rail_Normal_Vert"));
	Image ^Rail_Normal_Hor = safe_cast<Image^> (rm->GetObject("Rail_Normal_Hor"));
	Image ^Rail_Curve_LeftTop = safe_cast<Image^> (rm->GetObject("Rail_Curve_LeftTopC"));
	Image ^Rail_Curve_RightTop = safe_cast<Image^> (rm->GetObject("Rail_Curve_RightTopC"));
	Image ^Rail_Curve_RightBottom = safe_cast<Image^> (rm->GetObject("Rail_Curve_RightBottomC"));
	Image ^Rail_Curve_LeftBottom = safe_cast<Image^> (rm->GetObject("Rail_Curve_LeftBottomC"));
	
	// Fill Imagelists
	I0->ImageSize = Size(48, 48);
	I0->Images->Add(Rail_Normal_Vert);
	I0->Images->Add(Rail_Normal_Hor);
	I0->Images->Add(Rail_Curve_LeftTop);
	I0->Images->Add(Rail_Curve_RightTop);
	I0->Images->Add(Rail_Curve_RightBottom);
	I0->Images->Add(Rail_Curve_LeftBottom);
	
	I1->ImageSize = Size(48, 48);

	I2->ImageSize = Size(48, 48);

	I3->ImageSize = Size(48, 48);

	I4->ImageSize = Size(48, 48);
	
	I5->ImageSize = Size(48, 48);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Hor);
	I5->Images->Add(Rail_Curve_LeftTop);
	I5->Images->Add(Rail_Curve_RightTop);
	I5->Images->Add(Rail_Curve_RightBottom);
	I5->Images->Add(Rail_Curve_LeftBottom);


	// Image-List Arrays
	A0[0] = item10;
	A0[1] = item11;
	A0[2] = item12;
	A0[3] = item13;
	A0[4] = item14;
	A0[5] = item15;
	
	A1[0] = item20;
	A1[1] = item21;
	A1[2] = item22;
	A1[3] = item23;
	A1[4] = item24;
	A1[5] = item25;
	A1[6] = item26;
	A1[7] = item27;
	A1[8] = item28;
	A1[9] = item29;

	A2[0] = item30;
	A2[1] = item31;

	A3[0] = item40;
	A3[1] = item41;
	A3[2] = item42;
	A3[3] = item43;
	
	A4[0] = item50;
	A4[1] = item51;
	A4[2] = item52;

	A5[0] = item10;
	A5[1] = item11;
	A5[2] = item12;
	A5[3] = item13;
	A5[4] = item14;
	A5[5] = item15;
	A5[6] = item20;
	A5[7] = item21;
	A5[8] = item22;
	A5[9] = item23;
	A5[10] = item24;
	A5[11] = item25;
	A5[12] = item26;
	A5[13] = item27;
	A5[14] = item28;
	A5[15] = item29;
	A5[16] = item30;
	A5[17] = item31;
	A5[18] = item40;
	A5[19] = item41;
	A5[20] = item42;
	A5[21] = item43;
	A5[22] = item50;
	A5[23] = item51;
	A5[24] = item52;

		
		
}