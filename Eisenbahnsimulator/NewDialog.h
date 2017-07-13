#pragma once

namespace Eisenbahnsimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung f・ NewDialog
	/// </summary>
	public ref class NewDialog : public System::Windows::Forms::Form
	{
	public:
		NewDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzuf・en.
			//
			

		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~NewDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  CreateButton;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  XBox;
	private: System::Windows::Forms::TextBox^  YBox;


	private: System::Windows::Forms::Label^  label2;

	public:
			 String^ XText;
			 String^ YText;
	

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f・ die Designerunterst・zung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge舅dert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->CreateButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->XBox = (gcnew System::Windows::Forms::TextBox());
			this->YBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// CreateButton
			// 
			this->CreateButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->CreateButton->Location = System::Drawing::Point(16, 123);
			this->CreateButton->Margin = System::Windows::Forms::Padding(4);
			this->CreateButton->Name = L"CreateButton";
			this->CreateButton->Size = System::Drawing::Size(100, 28);
			this->CreateButton->TabIndex = 0;
			this->CreateButton->Text = L"Erstellen";
			this->CreateButton->UseVisualStyleBackColor = true;
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->Location = System::Drawing::Point(240, 123);
			this->CancelButton->Margin = System::Windows::Forms::Padding(4);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(100, 28);
			this->CancelButton->TabIndex = 1;
			this->CancelButton->Text = L"Abbrechen";
			this->CancelButton->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 20);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Größe der Arbeitsfläche:";
			// 
			// XBox
			// 
			this->XBox->Location = System::Drawing::Point(16, 76);
			this->XBox->Margin = System::Windows::Forms::Padding(4);
			this->XBox->Name = L"XBox";
			this->XBox->Size = System::Drawing::Size(100, 22);
			this->XBox->TabIndex = 3;
			this->XBox->Text = L"100";
			this->XBox->TextChanged += gcnew System::EventHandler(this, &NewDialog::XBox_TextChanged);
			// 
			// YBox
			// 
			this->YBox->Location = System::Drawing::Point(240, 80);
			this->YBox->Margin = System::Windows::Forms::Padding(4);
			this->YBox->Name = L"YBox";
			this->YBox->Size = System::Drawing::Size(100, 22);
			this->YBox->TabIndex = 4;
			this->YBox->Text = L"100";
			this->YBox->TextChanged += gcnew System::EventHandler(this, &NewDialog::YBox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(172, 80);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"x";
			// 
			// NewDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(353, 172);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->YBox);
			this->Controls->Add(this->XBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->CreateButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"NewDialog";
			this->ShowIcon = false;
			this->Text = L"Neue Strecke anlegen...";
			this->Load += gcnew System::EventHandler(this, &NewDialog::NewDialog_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void XBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	XText = XBox->Text;
}
private: System::Void YBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	YText = YBox->Text;
}
private: System::Void NewDialog_Load(System::Object^  sender, System::EventArgs^  e) {
	XText = XBox->Text;
	YText = YBox->Text;
}
};
}
