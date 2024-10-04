#pragma once

namespace Lab28 {

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
			this->Text = "Работа с MS WORD Зеневич Александр Т-091";
			this->textBox1->Multiline = true;
			this->textBox1->TabIndex = 0;
			this->button1->TabIndex = 1;
			this->button2->TabIndex = 2;
			this->button1->Text = "Проверка орфографии";
			this->button2->Text = "Создать документ MS WORD";
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

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;

	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 464);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(286, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(304, 464);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(259, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(551, 20);
			this->textBox1->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(575, 499);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		auto word1 = gcnew Microsoft::Office::Interop::Word::Application();
		word1->Visible = false;
		Object^ t = Type::Missing;
		auto document = word1->Documents->Add(t, t, t, t);
		document->Words->First->InsertBefore(this->textBox1->Text);
		document->CheckSpelling(t, t, t, t, t, t, t, t, t, t, t, t);
	//	String^ correctText = document->Content.Text;
	//	this->textBox1->Text = correctText->Replace("\r", "");
		Boolean* tt = false;
	//	word1->Documents->Close(tt, t, t);
	//	word1->Quit(tt, t, t);
		word1 = nullptr;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			try
			{
				array<String^>^ names = { "Иванов Иван", "Петров Пётр", "Сидоров Сидор", "Антонова Мария", "Вскрытие замков", "Справочная Служба", "Прогноз погоды", "Smith Jack",
				"Рождественский Эдуард Ипполитович", "ЖЭС" };
				array<String^>^ telephones = { "+375(44)353-53-230", "+375(13)333-333-333", "+343(33)223-43-21", "+376(33)342-24-31", "3434333", "324324320", "43434343","44324240", "43434343", "4334343" };
				auto word2 = gcnew Microsoft::Office::Interop::Word::Application();
				word2->Visible = true;
				auto t = Type::Missing;
				auto document2 = word2->Documents->Add(t, t, t, t);
				word2->Selection->TypeText("\t\t\t\tТаблица телефонных номеров");
				System::Object^ t1 = Microsoft::Office::Interop::Word::WdDefaultTableBehavior::wdWord9TableBehavior;
				System::Object^ t2 = Microsoft::Office::Interop::Word::WdAutoFitBehavior::wdAutoFitContent;
				word2->ActiveDocument->Tables->Add(word2->Selection->Range, 10, 2, t1, t2);
				for (int i = 0; i < 10; i++)
				{
					try
					{
						word2->ActiveDocument->Tables[1]->Cell(i + 1, 1)->Range->InsertAfter(names[i]);
						word2->ActiveDocument->Tables[1]->Cell(i + 1, 2)->Range->InsertAfter(telephones[i]);
					}
					catch (System::Runtime::InteropServices::COMException^ e)
					{
						textBox1->Text += i.ToString() + " " + e->Message + "\t";
						i--;
					}
					Object^ t3 = Microsoft::Office::Interop::Word::WdUnits::wdLine;
					Int32^ str10 = 10;
					word2->Selection->MoveDown(t3, str10, t);
					word2->Selection->TypeText("\tВ таблице перечислены номера телефонов и их владельцы\n");
					Object^ fileName = "Lab28.docx";
					word2->ActiveDocument->SaveAs(fileName, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t);
				}
			}
			catch (System::Expection^ e0)
			{
				textBox1->Text += e0->Message + "\t";
			}
	}
	};
}
