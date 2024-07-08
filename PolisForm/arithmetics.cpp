#include "arithmetics.h"

using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);
	PolisForm::arithmetics form;
	Application::Run(% form);
}