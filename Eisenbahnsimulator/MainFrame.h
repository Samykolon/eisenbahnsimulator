#pragma once
#include "Toolbox.h"

#include "Train.h"

#include "TileDecoration.h"
#include "TileTrainStop.h"
#include "TileRailSwitch.h"
#include "TileSignalRail.h"
#include "TileRail.h"

#include "Map.h"

#include "NewDialog.h"
#include "BetterPanel.h"

#include "AppData.h"
#include "UserData.h"

namespace Eisenbahnsimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	/*public ref class ExtendedListView : public System::Windows::Forms::ListView
	{
	public:
		ExtendedListView();

		virtual void KeyPress(KeyEventArgs e) override
		{
			if (e.KeyCode == Keys::W || e.KeyCode == Keys::A || e.KeyCode == Keys::S || e.KeyCode == Keys::D)
			{
				MessageBox::Show("Test");
				return;
			}
		}

	}; */


	public ref class MainFrame : public System::Windows::Forms::Form
	{

	public:
		MainFrame(void)
		{
			InitializeComponent();
			appdata = gcnew Appdata();
			userdata = gcnew Userdata(100, 100); // Creates also map
			timer->Start();
			// loadCategories
			{
				List<String ^>^ categoryList = appdata->getCategoryList();
				for (int i = 0; i < categoryList->Count; i++)
				{
					//Adds the categories as String
					ComboBoxCategorySelection->Items->Add(appdata->getLangString(categoryList[i]));
				}
			}
			ComboBoxCategorySelection->SelectedIndex = 0;

			listViewSelectElements->FullRowSelect = true;
			listViewSelectElements->View = View::Tile;
			listViewSelectElements->Sorting = SortOrder::None;
			listViewSelectElements->GridLines = true;
			listViewSelectElements->LabelEdit = false;
			updateToolbox(ComboBoxCategorySelection->SelectedIndex, appdata, listViewSelectElements);

			//
			//TODO: Add the constructor code here
			//

			selectedItem = -1;
			static_cast<BetterPanel^>(panel1)->SetStyle(ControlStyles::AllPaintingInWmPaint, true);
			static_cast<BetterPanel^>(panel1)->SetStyle(ControlStyles::DoubleBuffer, true);
			CoordinateOffset = Point(0, 0);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainFrame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  dateiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  neuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  speichernToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ladenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  schließenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ansichtToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  hilfeToolStripMenuItem;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::GroupBox^  groupBox3;


	private: System::Windows::Forms::ComboBox^  ComboBoxCategorySelection;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  trackBar2;

	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button2;


	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  überToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  einstellungenToolStripMenuItem;
	private: System::Windows::Forms::ListView^  listViewSelectElements;

	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;


	private: System::ComponentModel::IContainer^  components;

			 //private: System::Windows::Forms::ListView^  listView1;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->dateiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->neuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->speichernToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ladenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->schließenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ansichtToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->einstellungenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hilfeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->überToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->ComboBoxCategorySelection = (gcnew System::Windows::Forms::ComboBox());
			this->listViewSelectElements = (gcnew System::Windows::Forms::ListView());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->dateiToolStripMenuItem,
					this->ansichtToolStripMenuItem, this->hilfeToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1901, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// dateiToolStripMenuItem
			// 
			this->dateiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->neuToolStripMenuItem,
					this->speichernToolStripMenuItem, this->ladenToolStripMenuItem, this->schließenToolStripMenuItem
			});
			this->dateiToolStripMenuItem->Name = L"dateiToolStripMenuItem";
			this->dateiToolStripMenuItem->Size = System::Drawing::Size(57, 24);
			this->dateiToolStripMenuItem->Text = L"Datei";
			// 
			// neuToolStripMenuItem
			// 
			this->neuToolStripMenuItem->Name = L"neuToolStripMenuItem";
			this->neuToolStripMenuItem->Size = System::Drawing::Size(149, 26);
			this->neuToolStripMenuItem->Text = L"Neu";
			this->neuToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFrame::neuToolStripMenuItem_Click);
			// 
			// speichernToolStripMenuItem
			// 
			this->speichernToolStripMenuItem->Name = L"speichernToolStripMenuItem";
			this->speichernToolStripMenuItem->Size = System::Drawing::Size(149, 26);
			this->speichernToolStripMenuItem->Text = L"Speichern";
			this->speichernToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFrame::speichernToolStripMenuItem_Click);
			// 
			// ladenToolStripMenuItem
			// 
			this->ladenToolStripMenuItem->Name = L"ladenToolStripMenuItem";
			this->ladenToolStripMenuItem->Size = System::Drawing::Size(149, 26);
			this->ladenToolStripMenuItem->Text = L"Laden";
			this->ladenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFrame::ladenToolStripMenuItem_Click);
			// 
			// schließenToolStripMenuItem
			// 
			this->schließenToolStripMenuItem->Name = L"schließenToolStripMenuItem";
			this->schließenToolStripMenuItem->Size = System::Drawing::Size(149, 26);
			this->schließenToolStripMenuItem->Text = L"Schließen";
			this->schließenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFrame::schließenToolStripMenuItem_Click);
			// 
			// ansichtToolStripMenuItem
			// 
			this->ansichtToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->einstellungenToolStripMenuItem });
			this->ansichtToolStripMenuItem->Name = L"ansichtToolStripMenuItem";
			this->ansichtToolStripMenuItem->Size = System::Drawing::Size(93, 24);
			this->ansichtToolStripMenuItem->Text = L"Bearbeiten";
			this->ansichtToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFrame::ansichtToolStripMenuItem_Click);
			// 
			// einstellungenToolStripMenuItem
			// 
			this->einstellungenToolStripMenuItem->Name = L"einstellungenToolStripMenuItem";
			this->einstellungenToolStripMenuItem->Size = System::Drawing::Size(172, 26);
			this->einstellungenToolStripMenuItem->Text = L"Einstellungen";
			// 
			// hilfeToolStripMenuItem
			// 
			this->hilfeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->überToolStripMenuItem });
			this->hilfeToolStripMenuItem->Name = L"hilfeToolStripMenuItem";
			this->hilfeToolStripMenuItem->Size = System::Drawing::Size(53, 24);
			this->hilfeToolStripMenuItem->Text = L"Hilfe";
			// 
			// überToolStripMenuItem
			// 
			this->überToolStripMenuItem->Name = L"überToolStripMenuItem";
			this->überToolStripMenuItem->Size = System::Drawing::Size(125, 26);
			this->überToolStripMenuItem->Text = L"Über...";
			this->überToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFrame::überToolStripMenuItem_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->Location = System::Drawing::Point(296, 34);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1593, 700);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainFrame::panel1_Paint);
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainFrame::panel1_MouseDown);
			this->panel1->MouseEnter += gcnew System::EventHandler(this, &MainFrame::panel1_MouseEnter);
			this->panel1->MouseLeave += gcnew System::EventHandler(this, &MainFrame::panel1_MouseLeave);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainFrame::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainFrame::panel1_MouseUp);
			this->panel1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MainFrame::panel1_MouseWheel);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->groupBox1->Controls->Add(this->ComboBoxCategorySelection);
			this->groupBox1->Controls->Add(this->listViewSelectElements);
			this->groupBox1->Location = System::Drawing::Point(17, 34);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(268, 700);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Elemente";
			// 
			// ComboBoxCategorySelection
			// 
			this->ComboBoxCategorySelection->FormattingEnabled = true;
			this->ComboBoxCategorySelection->Location = System::Drawing::Point(8, 23);
			this->ComboBoxCategorySelection->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ComboBoxCategorySelection->Name = L"ComboBoxCategorySelection";
			this->ComboBoxCategorySelection->Size = System::Drawing::Size(253, 24);
			this->ComboBoxCategorySelection->TabIndex = 1;
			this->ComboBoxCategorySelection->DropDownClosed += gcnew System::EventHandler(this, &MainFrame::ComboToolbox_DropDownClosed);
			// 
			// listViewSelectElements
			// 
			this->listViewSelectElements->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->listViewSelectElements->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->listViewSelectElements->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->listViewSelectElements->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->listViewSelectElements->Location = System::Drawing::Point(7, 52);
			this->listViewSelectElements->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listViewSelectElements->MultiSelect = false;
			this->listViewSelectElements->Name = L"listViewSelectElements";
			this->listViewSelectElements->Size = System::Drawing::Size(255, 642);
			this->listViewSelectElements->TabIndex = 0;
			this->listViewSelectElements->TileSize = System::Drawing::Size(168, 60);
			this->listViewSelectElements->UseCompatibleStateImageBehavior = false;
			this->listViewSelectElements->View = System::Windows::Forms::View::Tile;
			this->listViewSelectElements->SelectedIndexChanged += gcnew System::EventHandler(this, &MainFrame::listViewSelectElements_SelectedIndexChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->groupBox3->Controls->Add(this->radioButton4);
			this->groupBox3->Controls->Add(this->radioButton2);
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->trackBar2);
			this->groupBox3->Location = System::Drawing::Point(293, 742);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4);
			this->groupBox3->Size = System::Drawing::Size(268, 212);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Ausgewählter Zug";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(164, 102);
			this->radioButton4->Margin = System::Windows::Forms::Padding(4);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(89, 21);
			this->radioButton4->TabIndex = 6;
			this->radioButton4->Text = L"rückwärts";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MainFrame::radioButton4_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Location = System::Drawing::Point(13, 102);
			this->radioButton2->Margin = System::Windows::Forms::Padding(4);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(82, 21);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"vorwärts";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->button4->Location = System::Drawing::Point(13, 139);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(247, 28);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Zug entfernen";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainFrame::button4_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->Location = System::Drawing::Point(12, 175);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(247, 28);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Alle Züge stoppen";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainFrame::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 65);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Geschwindigkeit";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(8, 26);
			this->trackBar2->Margin = System::Windows::Forms::Padding(4);
			this->trackBar2->Maximum = 110;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(251, 56);
			this->trackBar2->TabIndex = 1;
			this->trackBar2->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MainFrame::trackBar2_Scroll);
			this->trackBar2->MouseEnter += gcnew System::EventHandler(this, &MainFrame::trackBar2_MouseEnter);
			this->trackBar2->MouseLeave += gcnew System::EventHandler(this, &MainFrame::trackBar2_MouseLeave);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(569, 742);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1320, 212);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = L"MessageBox/Konsole";
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Liste der vorhandenen Züge" });
			this->listBox1->Location = System::Drawing::Point(17, 742);
			this->listBox1->Margin = System::Windows::Forms::Padding(4);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(267, 212);
			this->listBox1->TabIndex = 9;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainFrame::listBox1_SelectedIndexChanged);
			// 
			// timer
			// 
			this->timer->Interval = 13;
			this->timer->Tick += gcnew System::EventHandler(this, &MainFrame::timer_Tick);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MainFrame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1901, 962);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MinimumSize = System::Drawing::Size(797, 593);
			this->Name = L"MainFrame";
			this->ShowIcon = false;
			this->Text = L"Eisenbahnsimulator";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Appdata^ appdata;
		Userdata^ userdata;
		Train^ SelectedTrain;
		int SelectedTI = -1;    //Selected Trainindex - connected with the listbox
		Boolean trackbarinuse = 0;  // Determines if user hovers over trackbar or not

		int selectedItem;	//Number of selected toolbox item
		int CalcTileCoord(int pixCoord); //Calculates tile coordinate out of pixel coordinate
		void CheckMessageBox();

		Point CoordinateOffset;
		bool mouseOverPanel; // True if mouse is over panel
		Int32 lastTc; // Ticks since startup

		int x, y; // position of mouse over panel
		int xWhenMiddleButtonPressed, yWhenMiddleButtonPressed; // position of mouse when middle button is pressed


	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void ansichtToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void neuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//Open the NewDialog and create a map with the returned size
		::DialogResult confirmResult;
		if (userdata != nullptr) {

			confirmResult = MessageBox::Show(L"Wollen Sie die bisherige Arbeitsfläche überschreiben?", L"Bestätigen", MessageBoxButtons::YesNo);

		}
		if (confirmResult != ::DialogResult::No) {
			NewDialog^ newD = gcnew NewDialog();
			if (newD->ShowDialog(this) == ::DialogResult::OK) { //User pressed OK
				int sizeX;
				int sizeY;
				if (!(int::TryParse(newD->XText, sizeX) && (int::TryParse(newD->YText, sizeY)))) { //Checks if both texts can be converted into Ints
					MessageBox::Show(L"Bitte geben sie nur ganze Zahlen ein.");
				}
				else if (sizeX <= 0 || sizeY <= 0) {
					MessageBox::Show(L"Beide Zahlen müssen größer als 0 sein.");
				}
				else {
					userdata->map = gcnew Map(sizeX, sizeY); //Create new map
					panel1->Invalidate(); //Draw main map
					textBox1->AppendText(L"Neue Arbeitsfläche wurde erfolgreich erstellt!!\r\n");

				}
			}
			timer->Start();
		}
	}
	private: System::Void schließenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void überToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		MessageBox::Show(L"Eisenbahnsimulator\nVersion 1.0.0\nCopyright by Samuel Dressel, Hannes Krumbiegel, Johannes Bley und Florian Köhler");

	}


	private: System::Void ComboToolbox_DropDownClosed(System::Object^  sender, System::EventArgs^  e) {
		// Update Toolbox
		updateToolbox(ComboBoxCategorySelection->SelectedIndex, appdata, listViewSelectElements);

	}

	private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		int X = CalcTileCoord(e->X + CoordinateOffset.X);	//Calculates the logical tile coordinates the user clicks on
		int Y = CalcTileCoord(e->Y + CoordinateOffset.Y);

		if (e->Button == System::Windows::Forms::MouseButtons::Left) {

			if (userdata != nullptr) { //Checks if the user has created a TileMap

				if (selectedItem != -1)
				{

					String^ categoryKey = appdata->getCategoryList()[ComboBoxCategorySelection->SelectedIndex];
					String^ selectedItemKey = appdata->getCategory(categoryKey)[selectedItem].keyString;

					if (appdata->isTile(selectedItemKey))
					{
						TileObject ^temp = static_cast<TileObject^>(appdata->getTile(selectedItemKey)->Clone());
						userdata->map->SetTile(temp, X, Y);
						for each (Train^ train in userdata->trainList) { //Set stuck trains on new tile
							if (train->X == X && train->Y == Y) {
								Rail^ newRail = dynamic_cast<Rail^>(temp);
								if (newRail != nullptr && newRail->LeadsTo(Train::FindOppositeDirection(train->GoalDirection))) {
									train->setOnRail(newRail, train->GoalDirection);
									train->SpeedLimit = train->MaximumSpeed;
								}
							}
						}
					}
					else if (appdata->isTrain(selectedItemKey))
					{
						Rail^ currentRail = dynamic_cast<Rail^>(userdata->map->GetTile(X, Y)); //Tries to cast the object into a Rail
						if (currentRail != nullptr)
						{
							Train ^train = appdata->getTrain(selectedItemKey);
							train->TileSize = userdata->tileSize;
							train->setOnRail(currentRail);
							train->DrivesForward = 1;    // set Direction to "Forward"

							userdata->AddTrain(dynamic_cast<Train^>(train->Clone()));
							CheckMessageBox();
							textBox1->AppendText(train->Name + L" wurde erfolgreich hinzugefügt!\r\n");


						}

						updateTrainList(userdata, appdata, listBox1);
						if (listBox1->Items->Count == 1 && (listBox1->Items[0]->ToString() != "Liste der vorhandenen Züge"))
							listBox1->SelectedIndex = 0;

					}
					panel1->Invalidate();
				}
			}
		}
		else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			if (selectedItem == -1)
			{
				TileObject^ currentTile = userdata->map->GetTile(X, Y);
				RailSwitch^ railSw = dynamic_cast<RailSwitch^>(currentTile);
				if (railSw != nullptr) {
					railSw->Switch(userdata->trainList);
					for each (Train^ train in userdata->trainList) //Set trains that had been stopped by the railroad switches' status in motion again
					{
						if (train->X == railSw->Position.X && train->Y == railSw->Position.Y && train->CurrentSpeed == 0 && railSw->LeadsTo(Train::FindOppositeDirection(train->GoalDirection))) {
							train->setOnRail(railSw, train->GoalDirection);
							train->SpeedLimit = train->MaximumSpeed;
						}
					}
				}
				else {
					SignalRail^ sRail = dynamic_cast<SignalRail^>(currentTile);
					if (sRail != nullptr) {
						sRail->Switch();
					}
				}
			}
			else
			{
				selectedItem = -1;
				listViewSelectElements->SelectedIndices->Clear();
			}

		}

		else if (e->Button == System::Windows::Forms::MouseButtons::Middle) {

			xWhenMiddleButtonPressed = e->X;
			yWhenMiddleButtonPressed = e->Y;
			// delete function in Mouse up event
		}
	}

	private: System::Void listViewSelectElements_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

		if (listViewSelectElements->SelectedItems->Count > 0)
		{
			selectedItem = listViewSelectElements->SelectedIndices[0];
		}
		else
			selectedItem = -1;

	}

	public:	 Bitmap^ RotateImage(Image^ image, Point offset, float angle)
	{
		if (image == nullptr)
			throw gcnew ArgumentNullException("image");

		//create a new empty bitmap to hold rotated image
		Bitmap^ rotatedBmp = gcnew Bitmap(userdata->tileSize, userdata->tileSize);
		rotatedBmp->SetResolution(image->HorizontalResolution* userdata->tileSize / image->Width, image->VerticalResolution* userdata->tileSize / image->Height);

		//make a graphics object from the empty bitmap
		Graphics^ g = Graphics::FromImage(rotatedBmp);

		//Put the rotation point in the center of the image
		g->TranslateTransform(offset.X, offset.Y);

		//rotate the image
		g->RotateTransform(angle);

		//move the image back
		g->TranslateTransform(-offset.X, -offset.Y);

		//draw passed in image onto graphics object
		g->DrawImage(image, Point(0, 0));
		/*
		Pen^ pen = gcnew Pen(Color::Red);
		g->DrawRectangle(pen, 0, 0, userdata->tileSize, userdata->tileSize);*/
		return rotatedBmp;
	}


	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  paintEventArgs) { //Draws everything

		if (userdata != nullptr) { //If a TileMap has been created

			int X = CalcTileCoord(x + CoordinateOffset.X);	//Calculates the logical tile coordinates the user clicks on
			int Y = CalcTileCoord(y + CoordinateOffset.Y);

			int maxXTile = Math::Min(userdata->map->Width, CalcTileCoord(panel1->Width - 2)); //Calculate the number of tiles that need to be drawn on the panel
			int maxYTile = Math::Min(userdata->map->Height, CalcTileCoord(panel1->Height - 2));
			Graphics^ graphics = paintEventArgs->Graphics;
			graphics->TranslateTransform(-CoordinateOffset.X, -CoordinateOffset.Y); //Move the panel

			// 2000 is image width and height
			// 128 is fitted for image
			int sizeX = (2000 / 128) * userdata->tileSize;
			int sizeY = (2000 / 128) * userdata->tileSize;
			int repeatX = 2000 / sizeX + 1;
			int repeatY = 2000 / sizeY + 1;
			for (int i = 0; i < repeatX; i++)
			{
				for (int i2 = 0; i2 < repeatY; i2++)
				{
					graphics->DrawImage(appdata->getImageFromPath(L"Rails/grass_background.png"), CoordinateOffset.X - CoordinateOffset.X%userdata->tileSize + sizeX*i, CoordinateOffset.Y - CoordinateOffset.Y%userdata->tileSize + sizeY*i2, sizeX, sizeY); //Draw grass - what is better?
				}

			}
			//Debug test

			for (int i = 0; i < userdata->map->GetCount(); i++)
			{
				TileObject^ toBeDrawn = userdata->map->TileAt(i);
				//TODO: Check if the tile is out of range				
				graphics->DrawImage(appdata->getImageFromPath(toBeDrawn->ImagePath),
					(toBeDrawn->Position.X - 1) * userdata->tileSize,
					(toBeDrawn->Position.Y - 1) * userdata->tileSize,
					userdata->tileSize, userdata->tileSize); //Draws all tiles in the tile map
			}

			for each (Train^ train in userdata->trainList) { //Draw all trains' current poses
				Image^ trainPic = Image::FromFile(train->ImagePath); //Is garbage collected
				float halfSize = userdata->tileSize / 2.0;
				trainPic = (RotateImage(trainPic, Point(halfSize, halfSize), -train->CurrentPose.Orientation));
				graphics->DrawImage(trainPic, (float)train->CurrentPose.X - halfSize, (float)train->CurrentPose.Y - halfSize, (float)userdata->tileSize, (float)userdata->tileSize);
			}

			Pen^ penRed = gcnew Pen(Color::Green);
			// Highlights the tile over which the mouse is over
			if (mouseOverPanel)
			{
				if (selectedItem != -1)
				{
					// Selected Toolbox item:
					String^ categoryKey = appdata->getCategoryList()[ComboBoxCategorySelection->SelectedIndex];
					String^ selectedItemKey = appdata->getCategory(categoryKey)[selectedItem].keyString;
					String^ path = "";
					// draw preview
					if (appdata->isTile(selectedItemKey))
					{
						path = appdata->getTile(selectedItemKey)->ImagePath;
					}
					if (appdata->isTrain(selectedItemKey))
					{
						path = appdata->getTrain(selectedItemKey)->ImagePath;
					}
					if (path != "")
					{
						graphics->DrawImage(appdata->getImageFromPath(path),
							(X - 1) * userdata->tileSize,
							(Y - 1) * userdata->tileSize,
							userdata->tileSize, userdata->tileSize); //Draws all tiles in the tile map
					}
				}

				graphics->DrawRectangle(penRed, (X - 1) * userdata->tileSize, (Y - 1) * userdata->tileSize, userdata->tileSize, userdata->tileSize);

			}
		}
	}
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {

		Int32 passedTicks = Environment::TickCount - lastTc;
		lastTc = Environment::TickCount;
		double passedTime = passedTicks / 1000.0;
			
		for each (Train^ train in userdata->trainList)
		{
			train->Tick(passedTime, userdata->map);
		}

		panel1->Invalidate();

		if (SelectedTrain != nullptr && trackbarinuse == 0)
			if (SelectedTrain->SpeedLimit == SelectedTrain->MaximumSpeed)
				trackBar2->Value = SelectedTrain->MaximumSpeed * 10;
		//else
			//trackBar2->Value = SelectedTrain->CurrentSpeed * 10; 
		static int count = 0;
		count += 60 * passedTime;
		if (count >= 60)
		{
			count = 0;
			textBox1->AppendText(L"Framerate: " + 1 / passedTime + "\r\n");
		}

	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

		userdata->trainList->Remove(SelectedTrain);
		updateTrainList(userdata, appdata, listBox1);
		if (listBox1->Items->Count < 1)
			listBox1->Text = "Liste der vorhandenen Züge";


	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		for each (Train^ train in userdata->trainList)
		{
			if (train->Name != nullptr) {
				train->SpeedLimit = 0;

			}
		}
		if (listBox1->Items->Count > 0 && (listBox1->Items[0]->ToString() != "Liste der vorhandenen Züge")) {
			CheckMessageBox();
			textBox1->AppendText(L"Alle Züge wurden gestoppt!\r\n");
		}
		else {
			CheckMessageBox();
			textBox1->AppendText(L"Keine Züge vorhanden!\r\n");
		}

		//SelectedTrain->SpeedLimit = 0;
	}
	private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {

		if (SelectedTrain != nullptr)
			SelectedTrain->SpeedLimit = trackBar2->Value / 10;
	}
	private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (SelectedTrain != nullptr) {
			if (radioButton4->Checked == true) {
				SelectedTrain->DrivesForward = 0;
				//SelectedTrain->MaximumSpeed = -30;
			}
			else {
				SelectedTrain->DrivesForward = 1;
				//SelectedTrain->MaximumSpeed *= -1;
			}
			SelectedTrain->SwitchDirection(); //Change the train's direction by 180 degrees
			Rail^ currentRail = dynamic_cast<Rail^>(SelectedTrain->Tile);
			if (currentRail != nullptr) {
				if (currentRail->EndDirections == Directions::NorthSouth || currentRail->EndDirections == Directions::WestEast) {
					SelectedTrain->TileProgress = 4 - SelectedTrain->TileProgress;
				}
				else {
					SelectedTrain->TileProgress = 3.57079632679 - SelectedTrain->TileProgress;
				}
			}
		}
	}
	private: System::Void trackBar2_MouseEnter(System::Object^  sender, System::EventArgs^  e) {

		trackbarinuse = 1;
	}
	private: System::Void trackBar2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {

		trackbarinuse = 0;
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

		if (listBox1->Items->Count == 1 && (listBox1->Items[0]->ToString() != "Liste der vorhandenen Züge")) {
			SelectedTI = 0;   // If there is no train there yet
		}
		else if (listBox1->Items->Count > 1) {
			SelectedTI = listBox1->SelectedIndex;
		}
		else {
			listBox1->Text = "Liste der vorhandenen Züge";
			return;
		}

		if (SelectedTI > -1)
		{
			SelectedTrain = userdata->trainList[SelectedTI];
			trackBar2->Maximum = SelectedTrain->MaximumSpeed * 10;
			trackBar2->Value = SelectedTrain->CurrentSpeed * 10;


			if (SelectedTrain->DrivesForward == 1)   // Forward and backward Direction 
				radioButton2->Checked = true;
			else
				radioButton4->Checked = true;
		}

	}
	private: System::Void speichernToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		saveFileDialog1->DefaultExt = L".mpd";
		saveFileDialog1->AddExtension;
		saveFileDialog1->Filter = L"Map-Datei (*.mpd)|*.mpd";

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			System::IO::FileStream^ fs = System::IO::File::Create(saveFileDialog1->FileName);
			BinaryFormatter^ bf = gcnew BinaryFormatter();
			if (userdata != nullptr) {
				bf->Serialize(fs, userdata);
			}
			fs->Close();
			CheckMessageBox();
			textBox1->AppendText(L"Schienennetz wurde erfolgreich gespeichert!\r\n");
		}


	}
	private: System::Void ladenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		openFileDialog1->FileName = "";
		openFileDialog1->DefaultExt = L".mpd";
		openFileDialog1->AddExtension;
		openFileDialog1->Filter = L"Map-Datei (*.mpd)|*.mpd";

		try {
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				System::IO::FileStream^ fs = System::IO::File::OpenRead(openFileDialog1->FileName);
				BinaryFormatter^ bf = gcnew BinaryFormatter();
				userdata = (Userdata^)bf->Deserialize(fs);
				fs->Close();
				panel1->Invalidate();
				updateTrainList(userdata, appdata, listBox1);
				CheckMessageBox();
				textBox1->AppendText(L"Schienennetz wurde erfolgreich geladen!\r\n");
			}
		}
		catch (Exception^ ex)
		{
			textBox1->AppendText(L"Ungültiges Format/Datei fehlerhaft!");
		}

	}
	private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (Math::Abs(e->X - xWhenMiddleButtonPressed) < 10 && Math::Abs(e->Y - yWhenMiddleButtonPressed) < 10) return; //Don't move when the user just tried to delete		
		int deltaX = e->X - x;
		int deltaY = e->Y - y;
		x = e->X;
		y = e->Y;
		if (e->Button == System::Windows::Forms::MouseButtons::Middle)
		{
			CoordinateOffset.X -= deltaX;
			CoordinateOffset.Y -= deltaY;

			if (CoordinateOffset.X < 0) CoordinateOffset.X = 0;
			if (CoordinateOffset.Y < 0) CoordinateOffset.Y = 0;
			if (CoordinateOffset.X > userdata->map->Width * userdata->tileSize) CoordinateOffset.X = userdata->map->Width * userdata->tileSize;
			if (CoordinateOffset.Y > userdata->map->Height * userdata->tileSize) CoordinateOffset.Y = userdata->map->Height * userdata->tileSize;
		}
	}
	private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int X = CalcTileCoord(e->X + CoordinateOffset.X);	//Calculates the logical tile coordinates the user clicks on
		int Y = CalcTileCoord(e->Y + CoordinateOffset.Y);
		if (e->Button == System::Windows::Forms::MouseButtons::Middle)
		{
			// delete tile if not moved
			if (Math::Abs(e->X - xWhenMiddleButtonPressed) < 15 && Math::Abs(e->Y - yWhenMiddleButtonPressed) < 15)
			{
				if (userdata->map->GetTile(X, Y) != nullptr) {
					TileObject^ obj = userdata->map->GetTile(X, Y);
					userdata->map->DeleteTile(obj, X, Y);
					panel1->Invalidate();
				}
			}
		}
	}
	private: System::Void panel1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		mouseOverPanel = true;
	}
	private: System::Void panel1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		mouseOverPanel = false;
	}
	private: System::Void panel1_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
		int oldTileSize = userdata->tileSize;
		int value = (e->Delta) / 10;
		int smallesTileSize = 56; // Zoomed out
		int biggestTileSize = 180; // Zoomed in
	   // value = 0;
		// Zoom to
		int zoomToX = 0;
		// int zoomToX = CoordinateOffset.X;
		int zoomToY = 0;
		// int zoomToY = CoordinateOffset.Y;


		 // Zoom out
		if (value < 0)
		{
			if (userdata->tileSize > smallesTileSize)
			{
				userdata->tileSize += value;
			}
			if (userdata->tileSize < smallesTileSize) // Check if tileSize too small
			{
				userdata->tileSize = smallesTileSize;
			}
			CoordinateOffset.X = zoomToX * userdata->tileSize / oldTileSize;
			CoordinateOffset.Y = zoomToY * userdata->tileSize / oldTileSize;

		}
		// Zoom in
		else
		{
			if (userdata->tileSize < biggestTileSize)
			{
				userdata->tileSize += value;
			}
			if (userdata->tileSize > biggestTileSize) // Check if tileSize too big
			{
				userdata->tileSize = biggestTileSize;
			}
			CoordinateOffset.X = zoomToX * userdata->tileSize / oldTileSize;
			CoordinateOffset.Y = zoomToY * userdata->tileSize / oldTileSize;

		}
		for each (Train^ tr in userdata->trainList)
		{
			tr->TileSize = userdata->tileSize;
		}
	}
	};
}