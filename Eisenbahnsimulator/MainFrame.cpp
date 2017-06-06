#include "MainFrame.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Eisenbahnsimulator::MainFrame form;
	Application::Run(%form);
}


void justAfunction()
{
	// This does nothing
}