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


	// get name list of the different categories like rails, trains,...
	List<String ^>^ categoryList = _appdata->getCategoryList(); 

	// load the elements of the currently selected category
	List<CategoryItem>^ category = _appdata->getCategory(categoryList[_categoryIndex]);

	ImageList^ imageList = gcnew ImageList;
	imageList->ImageSize = Size(48, 48);
	for each (CategoryItem categoryItem in category)
	{
		// Add Descriptive Name
		_listView->Items->Add(_appdata->getLangString(categoryItem.keyString));
		// Add Image
		imageList->Images->Add(_appdata->getImageFromPath(categoryItem.iconPath));
	}
	_listView->LargeImageList = imageList;
}

void updateTrainList(Userdata^ _userdata, Appdata^ _appdata, ListBox^ _listBox)
{
	_listBox->Items->Clear();
	for each (Train^ train in _userdata->trainList)
	{
		if(train->Name != nullptr)
			_listBox->Items->Add(train->Name);
	}
		

}