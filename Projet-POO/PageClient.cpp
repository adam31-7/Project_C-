#include "PageClient.h"

using namespace System;

using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GestionClient::PageClient form;
	Application::Run(%form);
}