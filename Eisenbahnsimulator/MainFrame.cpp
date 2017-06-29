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

int Eisenbahnsimulator::MainFrame::CalcTileCoord(int pixCoord)
{
	int X = 1;
	while (true) {
		if (pixCoord < X * TileSize) {
			return X;
		}
		X++;
	}	
}
