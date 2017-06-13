#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void toolbox(System::Windows::Forms::ListView^  listViewToolbox)
{
	listViewToolbox->FullRowSelect = true;
	listViewToolbox->View = View::Details;
	listViewToolbox->Sorting = SortOrder::Ascending;
	listViewToolbox->GridLines = true;
	listViewToolbox->LabelEdit = true;
	ListViewItem^ item1 = gcnew ListViewItem("Schiene", 0);
	item1->SubItems->Add("");
	ListViewItem^ item2 = gcnew ListViewItem("Schienenkurve", 1);
	item2->SubItems->Add("");
	ListViewItem^ item3 = gcnew ListViewItem("Weiche", 2);
	item3->SubItems->Add("");


	// Create columns for the items and subitems.
	listViewToolbox->Columns->Add("Element", -2, HorizontalAlignment::Left);
	listViewToolbox->Columns->Add("", -2, HorizontalAlignment::Left);
	
	

	array<ListViewItem^>^temp1 = { item1,item2,item3 };
	listViewToolbox->Items->AddRange(temp1);

	ImageList^ imageListSmall = gcnew ImageList;
	
	
	
}