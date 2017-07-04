#pragma once

#include "AppData.h"
#include "UserData.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void updateToolbox(int _categoryIndex, Appdata^ _appdata, ListView^ _listView)
{
	_listView->Items->Clear();
	_listView->Columns->Add("Element", -2, HorizontalAlignment::Left);


	List<String ^>^ categoryList = _appdata->getCategoryList();
	List<String^>^ category = _appdata->getCategory(categoryList[_categoryIndex]);
	ImageList^ imageList = gcnew ImageList;
	imageList->ImageSize = Size(48, 48);
	for (int i = 0; i < category->Count; i++)
	{
		_listView->Items->Add(_appdata->getLangString(category[i]),i);
		imageList->Images->Add(_appdata->getImage(category[i]));
	}
	_listView->LargeImageList = imageList;
}

void updateTrainList(Userdata^ _userdata, Appdata^ _appdata, ListBox^ _listBox)
{
	_listBox->Items->Clear();
	for each (Train^ train in _userdata->trainList)
		_listBox->Items->Add(train->Name);

}