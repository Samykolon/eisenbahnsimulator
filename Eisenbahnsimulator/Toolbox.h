#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void toolbox(void)
{
	System::Windows::Forms::ListView^  listView1;
	listView1 = (gcnew System::Windows::Forms::ListView());
	listView1->Location = System::Drawing::Point(8, 23);
	listView1->Name = L"Elements";
	listView1->Size = System::Drawing::Size(253, 784);
	listView1->TabIndex = 0;
	listView1->UseCompatibleStateImageBehavior = false;
}