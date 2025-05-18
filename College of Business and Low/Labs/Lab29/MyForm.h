#pragma once

namespace Lab29 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ открытьФайлToolStripMenuItem;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: Microsoft::VisualBasic::Compatibility::VB6::FileListBox^ fileListBox1;
	private: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer1;
	private: System::Windows::Forms::ToolStripMenuItem^ слудеющийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ проигрыватьToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button5;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьФайлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->слудеющийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->проигрыватьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->fileListBox1 = (gcnew Microsoft::VisualBasic::Compatibility::VB6::FileListBox());
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->файлToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1299, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->открытьФайлToolStripMenuItem,
					this->слудеющийToolStripMenuItem, this->проигрыватьToolStripMenuItem
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// открытьФайлToolStripMenuItem
			// 
			this->открытьФайлToolStripMenuItem->Name = L"открытьФайлToolStripMenuItem";
			this->открытьФайлToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->открытьФайлToolStripMenuItem->Text = L"Открыть файл";
			this->открытьФайлToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::открытьФайлToolStripMenuItem_Click);
			// 
			// слудеющийToolStripMenuItem
			// 
			this->слудеющийToolStripMenuItem->Name = L"слудеющийToolStripMenuItem";
			this->слудеющийToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->слудеющийToolStripMenuItem->Text = L"Следующий";
			this->слудеющийToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::слудеющийToolStripMenuItem_Click);
			// 
			// проигрыватьToolStripMenuItem
			// 
			this->проигрыватьToolStripMenuItem->Name = L"проигрыватьToolStripMenuItem";
			this->проигрыватьToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->проигрыватьToolStripMenuItem->Text = L"Проигрывать";
			this->проигрыватьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::проигрыватьToolStripMenuItem_Click);
			// 
			// fileListBox1
			// 
			this->fileListBox1->FormattingEnabled = true;
			this->fileListBox1->Location = System::Drawing::Point(663, 22);
			this->fileListBox1->Name = L"fileListBox1";
			this->fileListBox1->Pattern = L"*.*";
			this->fileListBox1->Size = System::Drawing::Size(196, 524);
			this->fileListBox1->TabIndex = 1;
			this->fileListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::fileListBox1_SelectedIndexChanged);
			// 
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(13, 28);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(644, 518);
			this->axWindowsMediaPlayer1->TabIndex = 2;
			this->axWindowsMediaPlayer1->StatusChange += gcnew System::EventHandler(this, &MyForm::axWindowsMediaPlayer1_StatusChange);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(865, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(189, 20);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(865, 174);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(422, 269);
			this->textBox2->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(865, 86);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(415, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Генерация рандомного числа";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1060, 28);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(227, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Создание нового массива";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(865, 57);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(422, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Добавления числа в массив";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(872, 112);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"label1";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(865, 145);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(422, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Распечатать имеющиеся в массиве значения";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(868, 477);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 69);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Information";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(7, 44);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(67, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Surname";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(7, 20);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(53, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Name";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(865, 451);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(305, 20);
			this->textBox3->TabIndex = 11;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1176, 449);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(104, 23);
			this->button5->TabIndex = 12;
			this->button5->Text = L"Подсчитать";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1299, 558);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->axWindowsMediaPlayer1);
			this->Controls->Add(this->fileListBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void открытьФайлToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		fileListBox1->Pattern = "*.mp3";
		folderBrowserDialog1->ShowDialog();
		fileListBox1->FileName = folderBrowserDialog1->SelectedPath;
	}
	private: System::Void fileListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		axWindowsMediaPlayer1->URL = folderBrowserDialog1->SelectedPath + "\\" + fileListBox1->SelectedItem->ToString();
	}
	private: System::Void axWindowsMediaPlayer1_StatusChange(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "Проигрывается: " + axWindowsMediaPlayer1->status->ToString();
	}
	private: System::Void слудеющийToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			fileListBox1->SelectedIndex += 1;
		}
		catch (System::ArgumentOutOfRangeException^ e)
		{
			MessageBox::Show("Список закончился.");
		}
		catch (System::Exception^ e)
		{
			MessageBox::Show("Ошибка " + e->Message);
		}
	}
	private: System::Void проигрыватьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			axWindowsMediaPlayer1->Ctlcontrols->play();
		}
		catch (System::Exception^ e)
		{
			MessageBox::Show("Ошибка " + e->Message);
		}
	}
	private:
		int n = 0;
		int* m = nullptr;
		int i = 0;
		int countCHET = 0;
		int countNECHET = 0;
		int count = 0;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Random^ r = gcnew Random();
		int a = 10 + (r->Next()) % (99 - 10 + 1);
		textBox1->Text = a.ToString();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			if (m != nullptr)
			{
				delete[] m;
				m = nullptr;
				n = 0;
				label1->Text = "";
				label1->Text = "Удалён имевшийся массив.";
			}
			this->n = Convert::ToInt32(this->textBox1->Text);
			m = new int[n];
			if (!m)
			{
				MessageBox::Show("Не удаётся создать массив на " + n.ToString() + " элементов.");
				return;
			}
			i = 0;
			label1->Text = "Создан массив на " + n.ToString() + " элементов";
		}
		catch (System::FormatException^ e)
		{
			MessageBox::Show(e->Message);
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			if (i < n && n > 0 && m != nullptr)
			{
				m[i] = Convert::ToInt32(this->textBox1->Text);
				i++;
				label1->Text = "";
				label1->Text = "Заполнен элемент № " + i.ToString() + " из " + n.ToString();
			}
			else
			{
				MessageBox::Show("Массив размерности " + n + " заполнен или не создан.");
			}
		}
		catch (System::FormatException^ e)
		{
			MessageBox::Show(e->Message);
		}
		catch (System::Exception^ e)
		{
			MessageBox::Show(e->Message);
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox2->ReadOnly = true;
		this->textBox2->Clear();
		this->textBox1->Clear();
		for (int j = 0; j < i && j < n; j++)
		{
			this->textBox2->Text += m[j].ToString() + " ";
		}
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "Aleksandr";
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "Zenevich";
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox3->ReadOnly = true;
		this->textBox3->Clear();
		try
		{
			for (int j = 0; j < i && j < n; j++)
			{
				if (m[j] % 2 == 0)
				{
					countCHET++;
					count++;
				}
				else
				{
					countNECHET++;
					count++;
				}
			}
			this->textBox3->Text = countCHET.ToString() + " чётных и " + countNECHET.ToString() + " нечётных чисел, всего: " + count.ToString();
		}
		catch (System::FormatException^ e)
		{
			MessageBox::Show(e->Message);
		}
		catch (System::Exception^ e)
		{
			MessageBox::Show(e->Message);
		}
	}
	};
}
