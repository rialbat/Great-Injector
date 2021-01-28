#include "InjectorWindow.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GreatInjector::InjectorWindow form;
	form.FillComboBox();
	Application::Run(% form);
}

void GreatInjector::InjectorWindow::FillComboBox()
{
	//throw gcnew System::NotImplementedException();
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		FILE* f;
		int i = 0;
		TCHAR Buffer[1024];
		AllocConsole();
		freopen_s(&f, "CONOUT$", "w", stdout);

		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry))
		{
			GreatInjector::InjectorWindow::ProcessComboBox->BeginUpdate();
			do
			{
				i++;
				StringCbPrintfA((STRSAFE_LPSTR)Buffer, sizeof(Buffer), "%08X %S\n", procEntry.th32ProcessID, procEntry.szExeFile);
				GreatInjector::InjectorWindow::ProcessComboBox->Items->Add(i.ToString() + (wchar_t)Buffer);
				//System::Windows::Forms::MessageBox(NULL, *(char*)procEntry.szExeFile, "Logs", MB_OK);
				std::cout << (STRSAFE_LPSTR)Buffer;
			} while (Process32Next(hSnap, &procEntry));
			
			GreatInjector::InjectorWindow::ProcessComboBox->EndUpdate();
		}
	}
	CloseHandle(hSnap);
}