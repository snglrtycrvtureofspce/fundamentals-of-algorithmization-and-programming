﻿#include "MyForm.h"
#include <Windows.h>

using namespace Lab25;
System::STAThreadAttribute;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

