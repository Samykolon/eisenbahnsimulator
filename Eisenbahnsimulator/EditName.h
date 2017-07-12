#pragma once


namespace Eisenbahnsimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung f・ EditName
	/// </summary>
	public ref class EditName : public System::Windows::Forms::Form
	{
	public:

		property String^ Name;
		EditName(void)
		{
			InitializeComponent();
			
			//
			//TODO: Konstruktorcode hier hinzuf・en.
			//
		}
		EditName(String^ _name)
		{
			InitializeComponent();
			Name = _name;
			textBox1->Text = Name;

		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~EditName()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(259, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &EditName::textBox1_TextChanged);
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &EditName::textBox1_KeyDown);
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->Location = System::Drawing::Point(13, 40);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(259, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Name ändern";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// EditName
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 75);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->KeyPreview = true;
			this->MinimizeBox = false;
			this->Name = L"EditName";
			this->ShowIcon = false;
			this->Text = L"Zugname ändern";
			this->Load += gcnew System::EventHandler(this, &EditName::EditName_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		Name = textBox1->Text;

	}
	private: System::Void EditName_Load(System::Object^  sender, System::EventArgs^  e) {

		Point^ _point = gcnew System::Drawing::Point(Cursor->Position.X, Cursor->Position.Y);
		Top = _point->Y;
		Left = _point->X;
	}
	private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		if (e->KeyCode == Keys::Enter) {
			button1->PerformClick();
		}

	}
};
}
