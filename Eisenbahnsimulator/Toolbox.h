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

int selectedTBIndex(System::Windows::Forms::ListView^  listViewToolbox, System::Windows::Forms::ComboBox^ Combo)
{

	int i = listViewToolbox->SelectedIndices[0];
	int item = -1;
	switch (Combo->SelectedIndex)
	{
	case 0:
		switch (i) {
		case 0:
			return item = 10;
		case 1:
			return item = 11;
		case 2:
			return item = 12;
		case 3:
			return item = 13;
		case 4:
			return item = 14;
		case 5:
			return item = 15;
		default:
			return item = -1;
		}

	case 1:
		switch (i) {
		case 0:
			return item = 20;
		case 1:
			return item = 21;
		case 2:
			return item = 22;
		case 3:
			return item = 23;
		case 4:
			return item = 24;
		case 5:
			return item = 25;
		case 6:
			return item = 261;
		case 7:
			return item = 262;
		case 8:
			return item = 263;
		case 9:
			return item = 264;
		case 10:
			return item = 265;
		case 11:
			return item = 266;
		case 12:
			return item = 267;
		case 13:
			return item = 268;
		default:
			return item = -1;
		}

	case 2:
		switch (i) {
		case 0:
			return item = 30;
		case 1:
			return item = 31;
		default:
			return item = -1;
		}
	case 3:
		switch (i) {
		case 0:
			return item = 40;
		case 1:
			return item = 41;
		case 2:
			return item = 42;
		case 3:
			return item = 43;
		default:
			return item = -1;
		}
	case 4:
		switch (i) {
		case 0:
			return item = 50;
		case 1:
			return item = 51;
		case 2:
			return item = 52;
		default:
			return item = -1;
		}
	case 5:
		switch (i) {
		case 0:
			return item = 10;
		case 1:
			return item = 11;
		case 2:
			return item = 12;
		case 3:
			return item = 13;
		case 4:
			return item = 14;
		case 5:
			return item = 15;
		case 6:
			return item = 20;
		case 7:
			return item = 21;
		case 8:
			return item = 22;
		case 9:
			return item = 23;
		case 10:
			return item = 24;
		case 11:
			return item = 25;
		case 12:
			return item = 261;
		case 13:
			return item = 262;
		case 14:
			return item = 263;
		case 15:
			return item = 264;
		case 16:
			return item = 265;
		case 17:
			return item = 266;
		case 18:
			return item = 267;
		case 19:
			return item = 268;
		case 20:
			return item = 30;
		case 21:
			return item = 31;
		case 22:
			return item = 40;
		case 23:
			return item = 41;
		case 24:
			return item = 42;
		case 25:
			return item = 43;
		case 26:
			return item = 50;
		case 27:
			return item = 51;
		case 28:
			return item = 52;
		default:
			return item = -1;
		}

	default:
		return item = -1;

	}

		
}

void toolbox(System::Windows::Forms::ListView^  listViewToolbox, System::Windows::Forms::ComboBox^  Combo, System::Windows::Forms::ImageList^ I0, System::Windows::Forms::ImageList^ I1, System::Windows::Forms::ImageList^ I2, System::Windows::Forms::ImageList^ I3, System::Windows::Forms::ImageList^ I4, System::Windows::Forms::ImageList^ I5, array<System::Windows::Forms::ListViewItem^>^A0, array<System::Windows::Forms::ListViewItem^>^A1, array<System::Windows::Forms::ListViewItem^>^A2, array<System::Windows::Forms::ListViewItem^>^A3, array<System::Windows::Forms::ListViewItem^>^A4, array<System::Windows::Forms::ListViewItem^>^A5)
{
	
	Combo->Items->Add("Schienen");
	Combo->Items->Add("Signale und Weichen");
	Combo->Items->Add("Haltepunkte");
	Combo->Items->Add("Umgebung");
	Combo->Items->Add("Z・e");
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
	ListViewItem^ item261 = gcnew ListViewItem("Weiche", 13);
	ListViewItem^ item262 = gcnew ListViewItem("Weiche", 14);
	ListViewItem^ item263 = gcnew ListViewItem("Weiche", 15);
	ListViewItem^ item264 = gcnew ListViewItem("Weiche", 16);
	ListViewItem^ item265 = gcnew ListViewItem("Weiche", 17);
	ListViewItem^ item266 = gcnew ListViewItem("Weiche", 18);
	ListViewItem^ item267 = gcnew ListViewItem("Weiche", 19);
	ListViewItem^ item268 = gcnew ListViewItem("Weiche", 20);
	ListViewItem^ item30 = gcnew ListViewItem("Kleiner Bahnhof", 21);
	ListViewItem^ item31 = gcnew ListViewItem("Groﾟer Bahnhof", 22);
	ListViewItem^ item40 = gcnew ListViewItem("Laubbaum", 23);
	ListViewItem^ item41 = gcnew ListViewItem("Nadelbaum", 24);
	ListViewItem^ item42 = gcnew ListViewItem("Strauch", 25);
	ListViewItem^ item43 = gcnew ListViewItem("Haus", 26);
	ListViewItem^ item50 = gcnew ListViewItem("Dampflokomotive", 27);
	ListViewItem^ item51 = gcnew ListViewItem("Diesellokomotive", 28);
	ListViewItem^ item52 = gcnew ListViewItem("Elektrolokomotive", 29);


	// Create columns for the items and subitems.
	listViewToolbox->Columns->Add("Element", -2, HorizontalAlignment::Left);
	
	// Load Images 
	Image ^Rail_Normal_Vert = (Image::FromFile(L"Rails/Rail_Normal_Vert.png"));
	Image ^Rail_Normal_Hor = (Image::FromFile(L"Rails/Rail_Normal_Hor.png"));
	Image ^Rail_Curve_LeftTop = (Image::FromFile(L"Rails/Rail_Curve_LeftTop.png"));
	Image ^Rail_Curve_RightTop = (Image::FromFile(L"Rails/Rail_Curve_RightTop.png"));
	Image ^Rail_Curve_RightBottom = (Image::FromFile(L"Rails/Rail_Curve_RightBottom.png"));
	Image ^Rail_Curve_LeftBottom = (Image::FromFile(L"Rails/Rail_Curve_LeftBottom.png"));
	Image ^Rail_Normal_Vert_Signal = (Image::FromFile(L"Rails/Rail_Normal_Vert_SignalBoth.png"));
	Image ^Rail_Normal_Hor_Signal = (Image::FromFile(L"Rails/Rail_Normal_Hor_SignalBoth.png"));
	Image ^Rail_Curve_LeftTop_Signal = (Image::FromFile(L"Rails/Rail_Curve_LeftTop_Signal_C.png"));
	Image ^Rail_Curve_RightTop_Signal = (Image::FromFile(L"Rails/Rail_Curve_RightTop_Signal_C.png"));
	Image ^Rail_Curve_RightBottom_Signal = (Image::FromFile(L"Rails/Rail_Curve_RightBottom_Signal_C.png"));
	Image ^Rail_Curve_LeftBottom_Signal = (Image::FromFile(L"Rails/Rail_Curve_LeftBottom_Signal_C.png"));
	Image ^Rail_Switch_BL = (Image::FromFile(L"Rails/Rail_Switch_BL_C.png"));
	
	// Fill Imagelists
	I0->ImageSize = Size(48, 48);
	I0->Images->Add(Rail_Normal_Vert);
	I0->Images->Add(Rail_Normal_Hor);
	I0->Images->Add(Rail_Curve_LeftTop);
	I0->Images->Add(Rail_Curve_RightTop);
	I0->Images->Add(Rail_Curve_RightBottom);
	I0->Images->Add(Rail_Curve_LeftBottom);

	
	I1->ImageSize = Size(48, 48);
	I1->Images->Add(Rail_Normal_Vert_Signal);
	I1->Images->Add(Rail_Normal_Hor_Signal);
	I1->Images->Add(Rail_Curve_LeftTop_Signal);
	I1->Images->Add(Rail_Curve_RightTop_Signal);
	I1->Images->Add(Rail_Curve_RightBottom_Signal);
	I1->Images->Add(Rail_Curve_LeftBottom_Signal);
	I1->Images->Add(Rail_Switch_BL);
	I1->Images->Add(Rail_Switch_BL);
	I1->Images->Add(Rail_Switch_BL);
	I1->Images->Add(Rail_Switch_BL);
	I1->Images->Add(Rail_Switch_BL);
	I1->Images->Add(Rail_Switch_BL);
	I1->Images->Add(Rail_Switch_BL);
	I1->Images->Add(Rail_Switch_BL);

	I2->ImageSize = Size(48, 48);
	I2->Images->Add(Rail_Normal_Vert);
	I2->Images->Add(Rail_Normal_Vert);

	I3->ImageSize = Size(48, 48);
	I3->Images->Add(Rail_Normal_Vert);
	I3->Images->Add(Rail_Normal_Vert);
	I3->Images->Add(Rail_Normal_Vert);
	I3->Images->Add(Rail_Normal_Vert);

	I4->ImageSize = Size(48, 48);
	I4->Images->Add(Rail_Normal_Vert);
	I4->Images->Add(Rail_Normal_Vert);
	I4->Images->Add(Rail_Normal_Vert);

	
	I5->ImageSize = Size(48, 48);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Hor);
	I5->Images->Add(Rail_Curve_LeftTop);
	I5->Images->Add(Rail_Curve_RightTop);
	I5->Images->Add(Rail_Curve_RightBottom);
	I5->Images->Add(Rail_Curve_LeftBottom);
	I5->Images->Add(Rail_Normal_Vert_Signal);
	I5->Images->Add(Rail_Normal_Hor_Signal);
	I5->Images->Add(Rail_Curve_LeftTop_Signal);
	I5->Images->Add(Rail_Curve_RightTop_Signal);
	I5->Images->Add(Rail_Curve_RightBottom_Signal);
	I5->Images->Add(Rail_Curve_LeftBottom_Signal);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);
	I5->Images->Add(Rail_Normal_Vert);


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
	A1[6] = item261;
	A1[7] = item262;
	A1[8] = item263;
	A1[9] = item264;
	A1[10] = item265;
	A1[11] = item266;
	A1[12] = item267;
	A1[13] = item268;

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
	A5[12] = item261;
	A5[13] = item262;
	A5[14] = item263;
	A5[15] = item264;
	A5[16] = item265;
	A5[17] = item266;
	A5[18] = item267;
	A5[19] = item268;
	A5[20] = item30;
	A5[21] = item31;
	A5[22] = item40;
	A5[23] = item41;
	A5[24] = item42;
	A5[25] = item43;
	A5[26] = item50;
	A5[27] = item51;
	A5[28] = item52;

		
		
}