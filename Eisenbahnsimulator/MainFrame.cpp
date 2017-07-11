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

int Eisenbahnsimulator::MainFrame::CalcTileCoord(int pixCoord)
{
	int X = 1;
	while (true) {
		if (pixCoord < X * userdata->tileSize) {
			return X;
		}
		X++;
	}
}

void Eisenbahnsimulator::MainFrame::CheckMessageBox()
{
	if (textBox1->Text == "MessageBox/Konsole")
		textBox1->Clear();
		
}


