#pragma once
#include "Toolbox.h"
#include "Train.h"
#include "Decoration.h"
#include "TrainStop.h"
#include "RailSwitch.h"
#include "Map.h"
#include "NewDialog.h"
#include "Rail.h"
#include "BetterPanel.h"
#include "SignalRail.h"

namespace Eisenbahnsimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainFrame : public System::Windows::Forms::Form
	{
		


	public:
		MainFrame(void)
		{
			InitializeComponent();

			toolbox(listView1, ComboToolbox, imageListSchienen, imageListSignale, imageListHaltepunkte, imageListUmgebung, imageListZuege, imageListAlle, Schienen, Signale, Haltepunkte, Umgebung, Zuege, Alle);
			updateToolbox(listView1, ComboToolbox, imageListSchienen, imageListSignale, imageListHaltepunkte, imageListUmgebung, imageListZuege, imageListAlle, Schienen, Signale, Haltepunkte, Umgebung, Zuege, Alle);
			
			
			//
			//TODO: Add the constructor code here
			//
			Trains = gcnew List<Train^>();
			TileSize = 128;
			selectedItem = -1;
			static_cast<BetterPanel^>(panel1)->SetStyle(ControlStyles::AllPaintingInWmPaint, true);
			static_cast<BetterPanel^>(panel1)->SetStyle(ControlStyles::DoubleBuffer, true);
			
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

	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^ ComboToolbox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  trackBar2;

	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBox5;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  überToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  einstellungenToolStripMenuItem;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::Timer^  timer;
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
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->ComboToolbox = (gcnew System::Windows::Forms::ComboBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
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
			this->menuStrip1->Size = System::Drawing::Size(1426, 24);
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
			this->dateiToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->dateiToolStripMenuItem->Text = L"Datei";
			// 
			// neuToolStripMenuItem
			// 
			this->neuToolStripMenuItem->Name = L"neuToolStripMenuItem";
			this->neuToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->neuToolStripMenuItem->Text = L"Neu";
			this->neuToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFrame::neuToolStripMenuItem_Click);
			// 
			// speichernToolStripMenuItem
			// 
			this->speichernToolStripMenuItem->Name = L"speichernToolStripMenuItem";
			this->speichernToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->speichernToolStripMenuItem->Text = L"Speichern";
			// 
			// ladenToolStripMenuItem
			// 
			this->ladenToolStripMenuItem->Name = L"ladenToolStripMenuItem";
			this->ladenToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->ladenToolStripMenuItem->Text = L"Laden";
			// 
			// schließenToolStripMenuItem
			// 
			this->schließenToolStripMenuItem->Name = L"schließenToolStripMenuItem";
			this->schließenToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->schließenToolStripMenuItem->Text = L"Schließen";
			this->schließenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFrame::schließenToolStripMenuItem_Click);
			// 
			// ansichtToolStripMenuItem
			// 
			this->ansichtToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->einstellungenToolStripMenuItem });
			this->ansichtToolStripMenuItem->Name = L"ansichtToolStripMenuItem";
			this->ansichtToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			this->ansichtToolStripMenuItem->Text = L"Bearbeiten";
			this->ansichtToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFrame::ansichtToolStripMenuItem_Click);
			// 
			// einstellungenToolStripMenuItem
			// 
			this->einstellungenToolStripMenuItem->Name = L"einstellungenToolStripMenuItem";
			this->einstellungenToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->einstellungenToolStripMenuItem->Text = L"Einstellungen";
			// 
			// hilfeToolStripMenuItem
			// 
			this->hilfeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->überToolStripMenuItem });
			this->hilfeToolStripMenuItem->Name = L"hilfeToolStripMenuItem";
			this->hilfeToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->hilfeToolStripMenuItem->Text = L"Hilfe";
			// 
			// überToolStripMenuItem
			// 
			this->überToolStripMenuItem->Name = L"überToolStripMenuItem";
			this->überToolStripMenuItem->Size = System::Drawing::Size(108, 22);
			this->überToolStripMenuItem->Text = L"Über...";
			this->überToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainFrame::überToolStripMenuItem_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->Controls->Add(this->groupBox5);
			this->panel1->Location = System::Drawing::Point(222, 28);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1195, 543);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainFrame::panel1_Paint);
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainFrame::panel1_MouseDown);
			// 
			// groupBox5
			// 
			this->groupBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->groupBox5->Location = System::Drawing::Point(963, 388);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(229, 152);
			this->groupBox5->TabIndex = 0;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Ausgewähltes Objekt bearbeiten";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->groupBox1->Controls->Add(this->ComboToolbox);
			this->groupBox1->Controls->Add(this->listView1);
			this->groupBox1->Location = System::Drawing::Point(13, 28);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(201, 569);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Elemente";
			// 
			// ComboToolbox
			// 
			this->ComboToolbox->FormattingEnabled = true;
			this->ComboToolbox->Location = System::Drawing::Point(6, 19);
			this->ComboToolbox->Margin = System::Windows::Forms::Padding(2);
			this->ComboToolbox->Name = L"ComboToolbox";
			this->ComboToolbox->Size = System::Drawing::Size(191, 21);
			this->ComboToolbox->TabIndex = 1;
			this->ComboToolbox->DropDownClosed += gcnew System::EventHandler(this, &MainFrame::ComboToolbox_DropDownClosed);
			// 
			// listView1
			// 
			this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->listView1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView1->Location = System::Drawing::Point(5, 42);
			this->listView1->Margin = System::Windows::Forms::Padding(2);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(192, 522);
			this->listView1->TabIndex = 0;
			this->listView1->TileSize = System::Drawing::Size(168, 60);
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Tile;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainFrame::listView1_SelectedIndexChanged);
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
			this->groupBox3->Location = System::Drawing::Point(220, 603);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(201, 172);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Ausgewählter Zug";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(123, 83);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(71, 17);
			this->radioButton4->TabIndex = 6;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"rückwärts";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(10, 83);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(65, 17);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"vorwärts";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->button4->Location = System::Drawing::Point(10, 113);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(185, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Zug entfernen";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->Location = System::Drawing::Point(9, 142);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(185, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Stop";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Geschwindigkeit";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(6, 21);
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(188, 45);
			this->trackBar2->TabIndex = 1;
			// 
			// comboBox2
			// 
			this->comboBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(222, 577);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(200, 21);
			this->comboBox2->TabIndex = 6;
			this->comboBox2->Text = L"Auswahl Zug";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(427, 575);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(991, 201);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = L"MessageBox/Konsole";
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Liste der vorhandenen Züge" });
			this->listBox1->Location = System::Drawing::Point(13, 603);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(201, 173);
			this->listBox1->TabIndex = 9;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MainFrame::timer_Tick);
			// 
			// MainFrame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1426, 782);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(603, 493);
			this->Name = L"MainFrame";
			this->ShowIcon = false;
			this->Text = L"Eisenbahnsimulator";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		ImageList^ imageListSchienen = gcnew ImageList;
		ImageList^ imageListSignale = gcnew ImageList;
		ImageList^ imageListHaltepunkte = gcnew ImageList;
		ImageList^ imageListUmgebung = gcnew ImageList;
		ImageList^ imageListZuege = gcnew ImageList;
		ImageList^ imageListAlle = gcnew ImageList;
		array<ListViewItem^>^Schienen = gcnew array<ListViewItem^>(6);
		array<ListViewItem^>^Signale = gcnew array<ListViewItem^>(14);
		array<ListViewItem^>^Haltepunkte = gcnew array<ListViewItem^>(2);
		array<ListViewItem^>^Umgebung = gcnew array<ListViewItem^>(4);
		array<ListViewItem^>^Zuege = gcnew array<ListViewItem^>(3);
		array<ListViewItem^>^Alle = gcnew array<ListViewItem^>(29);
		int selectedItem;	//Number of selected toolbox item
		List<Train^>^ Trains;	//Trains on the grid
		int TileSize;	//Size of a tile in pixels
		Map^ TileMap;	//Contains all Tile objects
		int CalcTileCoord(int pixCoord); //Calculates tile coordinate out of pixel coordinate
		void AddTrain(TrainType tt, int xi, int yi);

		
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void ansichtToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void neuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//Open the NewDialog and create a map with the returned size
		::DialogResult confirmResult;
		if (TileMap != nullptr) {

			confirmResult = MessageBox::Show(L"Wollen Sie die bisherige Arbeitsfläche überschreiben?", L"Bestätigen", MessageBoxButtons::YesNo);
			
		}
		if (confirmResult != ::DialogResult::No) {
			NewDialog^ newD = gcnew NewDialog();
			if (newD->ShowDialog(this) == ::DialogResult::OK) { //User pressed OK
				int xCoord;
				int yCoord;
				if (!(int::TryParse(newD->XText, xCoord) && (int::TryParse(newD->YText, yCoord)))) { //Checks if both texts can be converted into Ints
					MessageBox::Show(L"Bitte geben sie nur ganze Zahlen ein.");
				}
				else if (xCoord <= 0 || yCoord <= 0) {
					MessageBox::Show(L"Beide Zahlen müssen größer als 0 sein.");
				}
				else {
					TileMap = gcnew Map(yCoord, xCoord); //Create new Map
					panel1->Invalidate(); //Draw main map
				}
			}
		}
	}
	private: System::Void schließenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void überToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		MessageBox::Show(L"Eisenbahnsimulator\nVersion 1.0.0\nCopyright by Samuel Dressel, Hannes Krumbiegel, Johannes Bley und Florian Köhler");

	}


private: System::Void ComboToolbox_DropDownClosed(System::Object^  sender, System::EventArgs^  e) {
	
	updateToolbox(listView1, ComboToolbox, imageListSchienen, imageListSignale, imageListHaltepunkte, imageListUmgebung, imageListZuege, imageListAlle, Schienen, Signale, Haltepunkte, Umgebung, Zuege, Alle);
		

}

	private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (TileMap != nullptr) { //Checks if the user has created a TileMap

		int X = CalcTileCoord(e->X);	//Calculates Tile coordinates the user clicks on
		int Y = CalcTileCoord(e->Y);

			//Places tiles based on toolbox choice
			if (selectedItem != -1) { //TODO: Better solution for numbers, because right now you get confused - enum? + continue
				switch (selectedItem) {

				case 10:
					TileMap->SetTile(gcnew Rail(X, Y, Directions::WestEast)); //Vertical rail
					break;
				case 11:
					TileMap->SetTile(gcnew Rail(X, Y, Directions::SouthNorth)); //Horizontal rail
					break;
				case 12:
					TileMap->SetTile(gcnew Rail(X, Y, Directions::WestNorth)); //Turns
					break;
				case 13:
					TileMap->SetTile(gcnew Rail(X, Y, Directions::NorthEast));
					break;
				case 14:
					TileMap->SetTile(gcnew Rail(X, Y, Directions::SouthEast));
					break;
				case 15:
					TileMap->SetTile(gcnew Rail(X, Y, Directions::WestSouth));
					break;
				case 20:
					TileMap->SetTile(gcnew SignalRail(X, Y, Directions::WestEast, 3, 3)); //Vertical rail
					break;
				case 21:
					TileMap->SetTile(gcnew SignalRail(X, Y, Directions::SouthNorth, 3, 3)); //Horizontal rail
					break;
				case 22:
					TileMap->SetTile(gcnew SignalRail(X, Y, Directions::WestNorth, 3, 3)); //Turns
					break;
				case 23:
					TileMap->SetTile(gcnew SignalRail(X, Y, Directions::NorthEast, 3, 3));
					break;
				case 24:
					TileMap->SetTile(gcnew SignalRail(X, Y, Directions::SouthEast, 3, 3));
					break;
				case 25:
					TileMap->SetTile(gcnew SignalRail(X, Y, Directions::WestSouth, 3, 3));
					break;
				case 16:
					TileMap->SetTile(gcnew SignalRail(X, Y, Directions::WestSouth, 3, 3));
				case 50:
					AddTrain(TrainType::SteamEngine, X, Y);
					break;
				case 51:
					AddTrain(TrainType::DieselEngine, X, Y);
					break;
				case 52:
					AddTrain(TrainType::ElectricLocomotive, X, Y);
					break;				
				}
				panel1->Invalidate();
			}
						
			//if (TileMap->GetTile(X, Y) != nullptr) {
			//	MessageBox::Show("X: " + X + ", Y: " + Y + "\n" + (safe_cast<Rail^>(TileMap->GetTile(X, Y))->EndDirections).ToString()); //Debug output
			//}
			
		}
	}

	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	if (listView1->SelectedItems->Count > 0) 
	{
		selectedItem = selectedTBIndex(listView1, ComboToolbox);
	}
	else
		selectedItem = -1;

	}

private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) { //Draws everything
	
	if (TileMap != nullptr) { //If a TileMap has been created
		int maxXTile = Math::Min(TileMap->Width, CalcTileCoord(panel1->Width - 2)); //Calculate the number of tiles that need to be drawn on the panel
		int maxYTile = Math::Min(TileMap->Height, CalcTileCoord(panel1->Height - 2));
		Graphics^ g = e->Graphics;
	
		//for (int x = 0; x < maxXTile; x++) //Draw background tiles
		//{
		//	for (int y = 0; y < maxYTile; y++)
		//	{
		//		g->DrawImage(Image::FromFile(L"Rails/grass.png"), x * TileSize, y * TileSize, TileSize, TileSize); //Draw grass

		//	}
		//}

		g->DrawImage(Image::FromFile(L"Rails/grass_background.png"), 0, 0 , 2000, 2000); //Draw grass - what is better?

		
		

		for (int i = 0; i < TileMap->GetCount(); i++)
		{
			TileObject^ toBeDrawn = TileMap->TileAt(i);
			g->DrawImage(Image::FromFile(L"Rails/" + toBeDrawn->ImagePath), (toBeDrawn->X - 1) * TileSize, (toBeDrawn->Y - 1) * TileSize, TileSize, TileSize); //Draws all tiles in the tile map
		}
				
	}
}
private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
	//Signals switch
	//Trains drive

}
};
}