#pragma once
#include "Includes.hpp"
#include "Core.hpp"
#include "ComboBoxItemDelegate.hpp"

namespace GreatInjector {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Сводка для InjectorWindow
	/// </summary>
	public ref class InjectorWindow : public System::Windows::Forms::Form
	{
	public:
		InjectorWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		void FillComboBox();


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~InjectorWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ DLLTextBox;
	private: System::Windows::Forms::Button^ InjectButton;
	private: System::Windows::Forms::ComboBox^ ProcessComboBox;
	private: System::Windows::Forms::Button^ FolderBrowserButton;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::MessageBox^ SuccessMessage;
	private: System::Windows::Forms::MessageBox^ ErrorMessage;

	//Переменные класса






	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InjectorWindow::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->DLLTextBox = (gcnew System::Windows::Forms::TextBox());
			this->InjectButton = (gcnew System::Windows::Forms::Button());
			this->ProcessComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->FolderBrowserButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(62, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(281, 251);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(15, 302);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(177, 22);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Название процесса";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(44, 340);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 22);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Путь к DLL";
			// 
			// DLLTextBox
			// 
			this->DLLTextBox->Location = System::Drawing::Point(198, 340);
			this->DLLTextBox->Name = L"DLLTextBox";
			this->DLLTextBox->Size = System::Drawing::Size(145, 20);
			this->DLLTextBox->TabIndex = 2;
			// 
			// InjectButton
			// 
			this->InjectButton->Location = System::Drawing::Point(159, 376);
			this->InjectButton->Name = L"InjectButton";
			this->InjectButton->Size = System::Drawing::Size(75, 23);
			this->InjectButton->TabIndex = 3;
			this->InjectButton->Text = L"Внедрить";
			this->InjectButton->UseVisualStyleBackColor = true;
			this->InjectButton->Click += gcnew System::EventHandler(this, &InjectorWindow::InjectButton_Click);
			// 
			// ProcessComboBox
			// 
			this->ProcessComboBox->FormattingEnabled = true;
			this->ProcessComboBox->Location = System::Drawing::Point(198, 302);
			this->ProcessComboBox->Name = L"ProcessComboBox";
			this->ProcessComboBox->Size = System::Drawing::Size(176, 21);
			this->ProcessComboBox->Sorted = true;
			this->ProcessComboBox->TabIndex = 4;
			// 
			// FolderBrowserButton
			// 
			this->FolderBrowserButton->Location = System::Drawing::Point(349, 338);
			this->FolderBrowserButton->Name = L"FolderBrowserButton";
			this->FolderBrowserButton->Size = System::Drawing::Size(25, 23);
			this->FolderBrowserButton->TabIndex = 5;
			this->FolderBrowserButton->Text = L"...";
			this->FolderBrowserButton->UseVisualStyleBackColor = true;
			this->FolderBrowserButton->Click += gcnew System::EventHandler(this, &InjectorWindow::FolderBrowserButton_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"File.dll";
			// 
			// InjectorWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(387, 405);
			this->Controls->Add(this->FolderBrowserButton);
			this->Controls->Add(this->ProcessComboBox);
			this->Controls->Add(this->InjectButton);
			this->Controls->Add(this->DLLTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"InjectorWindow";
			this->Text = L"The Great Injector v 0.3";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: char* StringToChar(System::String^ string)
		{
			return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
		}
		private: System::Void InjectButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			String^ Path = DLLTextBox->Text;
			String^ Proc = ProcessComboBox->Text;
			DWORD procId = 0;
			while (!procId)
			{
				procId = Core::GetProcId(StringToChar(Proc));
				Sleep(50);
			}
			HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

			if (hProc && hProc != INVALID_HANDLE_VALUE)
			{
				void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE); //Выделяем дополнительную память в процессе (External)
																										  //Аргументы: 1. Прцесс, в котором происходит выделение
																										  //2. Указатель на начальный адрес
																										  //3. Размер выделяемой области памяти в байтах.
																										  //4. Тип выделения памяти
																										  //5. Тип защиты памяти (на чтение и изменение)
																										  //!! Мы не помещаем сому DLL в процесс, а размещаем путь к DLL !!

				if (loc)																				  // Выделение не должно быть пустым
				{
					WriteProcessMemory(hProc, loc, StringToChar(Path), strlen(StringToChar(Path)) + 1, 0);
					std::cout << StringToChar(Path) << std::endl;
					std::cout << strlen(StringToChar(Path)) + 1 << std::endl;
				}

				HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);	//Создаем поток внутри процесса, который вызывает библиотеку
																													//Путь к который был задан в процесс заранее

				if (hThread)
				{
					CloseHandle(hThread);
				}
			}
			else
			{
				ErrorMessage->Show("Что-то пошло не так!",
								   "Error",
								   MessageBoxButtons::OK,
								   MessageBoxIcon::Error,
								   MessageBoxDefaultButton::Button1,
								   MessageBoxOptions::DefaultDesktopOnly);
			}
			if (hProc)
			{
				CloseHandle(hProc);
			}
			SuccessMessage->Show("Внедрение DLL успешно выполнено",
								 "Success",
								 MessageBoxButtons::OK,
								 MessageBoxIcon::Information,
								 MessageBoxDefaultButton::Button1,
								 MessageBoxOptions::DefaultDesktopOnly);
		}
		private: System::Void FolderBrowserButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			openFileDialog1->Filter = "DLL библиотека (*.dll)|*.dll|Все файлы (*.*)|*.*";
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				DLLTextBox->Text = openFileDialog1->FileName;
			}
		}
	};
}
