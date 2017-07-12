#pragma once

namespace Eisenbahnsimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung f�r Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		property String^ Background;
		Settings(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzuf�gen.
			//
		}
		Settings(String^ _backgroundpath)
		{
			InitializeComponent();
			Background = _backgroundpath;

		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:

	private: System::Windows::Forms::Button^  button1;
	private: ComboxExtended::ImagedComboBox^  imagedComboBox1;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->imagedComboBox1 = (gcnew ComboxExtended::ImagedComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Schienenhintergrund";
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->Location = System::Drawing::Point(15, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(205, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Einstellungen speichern";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// imagedComboBox1
			// 
			this->imagedComboBox1->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawVariable;
			this->imagedComboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->imagedComboBox1->FormattingEnabled = true;
			this->imagedComboBox1->Location = System::Drawing::Point(12, 30);
			this->imagedComboBox1->Name = L"imagedComboBox1";
			this->imagedComboBox1->Size = System::Drawing::Size(208, 21);
			this->imagedComboBox1->TabIndex = 3;
			this->imagedComboBox1->DropDownClosed += gcnew System::EventHandler(this, &Settings::imagedComboBox1_DropDownClosed);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(232, 261);
			this->Controls->Add(this->imagedComboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"Settings";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Einstellungen";
			this->Load += gcnew System::EventHandler(this, &Settings::Settings_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		ComboxExtended::ComboBoxItem^ Gras = (gcnew ComboxExtended::ComboBoxItem("Gras", Image::FromFile(L"Rails/grass_background.png")));
		ComboxExtended::ComboBoxItem^ Dirt = (gcnew ComboxExtended::ComboBoxItem("Dirt", Image::FromFile(L"Rails/dirt_background.png")));
		ComboxExtended::ComboBoxItem^ Stone = (gcnew ComboxExtended::ComboBoxItem("Stone", Image::FromFile(L"Rails/stone_background.png")));
		ComboxExtended::ComboBoxItem^ Snow = (gcnew ComboxExtended::ComboBoxItem("Snow", Image::FromFile(L"Rails/snow_background.png")));
		ComboxExtended::ComboBoxItem^ Sandstone = (gcnew ComboxExtended::ComboBoxItem("Sandstone", Image::FromFile(L"Rails/sandstone_background.png")));

	private: System::Void Settings_Load(System::Object^  sender, System::EventArgs^  e) {

		
		imagedComboBox1->Items->Add(Gras);
		imagedComboBox1->Items->Add(Dirt);
		imagedComboBox1->Items->Add(Stone);
		imagedComboBox1->Items->Add(Snow);
		imagedComboBox1->Items->Add(Sandstone);
		
		try {

			if (Background == L"Rails/grass_background.png")
				imagedComboBox1->SelectedItem = Gras;
			else if (Background == L"Rails/dirt_background.png")
				imagedComboBox1->SelectedItem = Dirt;
			else if (Background == L"Rails/stone_background.png")
				imagedComboBox1->SelectedItem = Stone;
			else if (Background == L"Rails/snow_background.png")
				imagedComboBox1->SelectedItem = Snow;
			else
				imagedComboBox1->SelectedItem = Sandstone;

		}

		catch (Exception^ ex)
		{
			MessageBox::Show(ex->ToString());

		}

	}
private: System::Void imagedComboBox1_DropDownClosed(System::Object^  sender, System::EventArgs^  e) {

	if (imagedComboBox1->SelectedItem == Gras)
		Background = L"Rails/grass_background.png";
	else if (imagedComboBox1->SelectedItem == Dirt)
		Background = L"Rails/dirt_background.png";
	else if (imagedComboBox1->SelectedItem == Stone)
		Background = L"Rails/stone_background.png";
	else if (imagedComboBox1->SelectedItem == Snow)
		Background = L"Rails/snow_background.png";
	else 
		Background = L"Rails/sandstone_background.png";
}
};
}
