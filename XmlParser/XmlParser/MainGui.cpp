#include "MainGui.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	XmlParser::MainGui frm;
	Application::Run(% frm);
}
