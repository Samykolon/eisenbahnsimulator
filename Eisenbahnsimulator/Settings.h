#pragma once

namespace Eisenbahnsimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		property String^ Background;
		property Boolean PreviewEnabled;
		Settings(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}
		Settings(String^ _backgroundpath, Boolean _previewenabled)
		{
			InitializeComponent();
			Background = _backgroundpath;
			PreviewEnabled = _previewenabled;

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
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->imagedComboBox1 = (gcnew ComboxExtended::ImagedComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
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
			this->imagedComboBox1->Location = System::Drawing::Point(12, 32);
			this->imagedComboBox1->Name = L"imagedComboBox1";
			this->imagedComboBox1->Size = System::Drawing::Size(208, 21);
			this->imagedComboBox1->TabIndex = 3;
			this->imagedComboBox1->DropDownClosed += gcnew System::EventHandler(this, &Settings::imagedComboBox1_DropDownClosed);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(12, 64);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(208, 58);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Preview ein/aus";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(145, 25);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->radioButton2->Size = System::Drawing::Size(43, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Aus";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(16, 25);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(40, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Ein";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Settings::radioButton1_CheckedChanged);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(232, 261);
			this->Controls->Add(this->groupBox1);
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
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
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

		if (PreviewEnabled == true)
			radioButton1->Checked = true;
		else
			radioButton2->Checked = true;

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
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (radioButton1->Checked == true)
		PreviewEnabled = true;
	else
		PreviewEnabled = false;
}
};
}
