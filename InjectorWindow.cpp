#include "InjectorWindow.h"
#pragma warning(push)
#pragma warning( disable : 4829 )

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
		wchar_t Buffer[1024];
		wchar_t CurrentProc[1024];
		AllocConsole();
		SetConsoleTitle("Debug Console");
		freopen_s(&f, "CONOUT$", "w", stdout);
		ComboBoxItemDelegate NewComboItem;

		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry))
		{
			ProcessComboBox->BeginUpdate();
			do
			{
				i++;
				//For debug
				StringCbPrintfA((STRSAFE_LPSTR)Buffer, sizeof(Buffer), "%d. %08X %s\n", i, procEntry.th32ProcessID, procEntry.szExeFile);
				//
				//StringCbPrintfA((STRSAFE_LPSTR)CurrentProc, sizeof(CurrentProc), "%s", procEntry.szExeFile);
				NewComboItem.setItem(procEntry.szExeFile);
				if (ProcessComboBox->Items->Contains(NewComboItem.getItem())){}
				else ProcessComboBox->Items->Add(NewComboItem.getItem());
				//System::Windows::Forms::MessageBox(NULL, *(char*)procEntry.szExeFile, "Logs", MB_OK);
				std::cout << (STRSAFE_LPSTR)Buffer;
				NewComboItem.clear();
				//std::cout << NewComboItem.getItem();
			} while (Process32Next(hSnap, &procEntry));
			ProcessComboBox->EndUpdate();
		}
	}
	CloseHandle(hSnap);
}
#pragma warning(pop)