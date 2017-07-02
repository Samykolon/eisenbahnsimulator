#pragma once
public ref class BetterPanel : public System::Windows::Forms::Panel
{
public:
	void SetStyle(System::Windows::Forms::ControlStyles flag, System::Boolean value)
	{
		System::Windows::Forms::Control::SetStyle(flag, value);
	}
};