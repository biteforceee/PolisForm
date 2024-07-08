#pragma once
#include "ArithmeticExp.h"
#include <string>
#include <msclr\marshal_cppstd.h>

namespace PolisForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;


	Tabl variables;
	string str;
	arithmetic A;
	/// <summary>
	/// Сводка для arithmatics
	/// </summary>
	public ref class arithmetics : public System::Windows::Forms::Form
	{
	public:
		arithmetics(void)
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
		~arithmetics()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ Textres;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label3;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Textres = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 42);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(195, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"введите строку:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(219, 42);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1472, 34);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(21, 108);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(482, 36);
			this->button1->TabIndex = 2;
			this->button1->Text = L"получить таблицу операндов и полиз\r\n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &arithmetics::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(16, 170);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(256, 29);
			this->label2->TabIndex = 4;
			this->label2->Text = L"таблица опрерандов";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(388, 170);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(235, 36);
			this->button2->TabIndex = 5;
			this->button2->Text = L"получить ответ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &arithmetics::button2_Click);
			// 
			// Textres
			// 
			this->Textres->AutoSize = true;
			this->Textres->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Textres->Location = System::Drawing::Point(661, 155);
			this->Textres->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Textres->Name = L"Textres";
			this->Textres->Size = System::Drawing::Size(145, 52);
			this->Textres->TabIndex = 6;
			this->Textres->Text = L"ответ:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Desktop;
			this->dataGridView1->Location = System::Drawing::Point(16, 203);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 4;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.25F));
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->Size = System::Drawing::Size(320, 536);
			this->dataGridView1->TabIndex = 7;
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &arithmetics::dataGridView1_CellValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(528, 93);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 52);
			this->label3->TabIndex = 8;
			this->label3->Text = L"полиз:";
			// 
			// arithmetics
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(1704, 905);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->Textres);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"arithmetics";
			this->Text = L"arithmetics";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		bool is_num(String^ s) {
			int  i = 0;
			int l;
			if (i == 0 && s[i] == '-') { i = 1; }
			if (s->Length > i) {
				l = 0;
				for (int i = 0; i < s->Length; i++) {
					if (s[i] == ',') {
						if (l == 1) { return false; }
						l = 1;
					}
					else {
						if (!Char::IsNumber(s[i])) {
							return false;
						}
					}

				}
			}
			return true;
		}
		void cleardataGrid() {
			dataGridView1->RowCount = 0;
			dataGridView1->ColumnCount = 0;
		}
		void heightdataGrid(int k) {
			if (k > 0) {
				dataGridView1->RowTemplate->Height = 523 / k;
			}

		}
		void addTable(int k) {
			dataGridView1->RowCount = k;
			dataGridView1->ColumnCount = 2;
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		str = msclr::interop::marshal_as<std::string>(textBox1->Text);
		A = arithmetic(str);
		int k = A.GetTablevarials().getCount();
		cleardataGrid();
		heightdataGrid(k);
		addTable(k);
		for (int i = 0; i < k; i++) {
			string m = A.GetTablevarials()[i].getName();
			dataGridView1->Rows[i ]->Cells[0]->Value = gcnew String(m.c_str());
			if (m > "0" && m < "9") {
				dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToDouble(dataGridView1->Rows[i]->Cells[0]->Value);
			}
		}
		string pol = A.GetA().getPol();
		label3->Text = "Полиз: " + gcnew String(pol.c_str());
	}
	private: System::Void dataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int i = dataGridView1->CurrentRow->Index;
		int j = dataGridView1->CurrentCell->ColumnIndex;
		str = msclr::interop::marshal_as<std::string>(textBox1->Text);
		A = arithmetic(str);
		variables = A.GetTablevarials();
		if (j == 0) { dataGridView1->Rows[i]->Cells[j]->Value = gcnew String(variables[i].getName().c_str()); }
		string m = variables[i].getName();
		if (m[0] > '0' && m[0] < '9') { dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(variables[i].getName().c_str()); }
		if (j == 1) {
			float k = 0;
			if (is_num(Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value))) {
				k = Convert::ToDouble(dataGridView1->Rows[i]->Cells[1]->Value);
			}
			A.SetVar(i, k);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < dataGridView1->RowCount; i++) {
			float k = 0;
			if (is_num(Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value))) {
				k = Convert::ToDouble(dataGridView1->Rows[i]->Cells[1]->Value);
			}
			A.SetVar(i, k);
		}
		float result = A.calculate();
		Textres->Text = "Ответ: " + Convert::ToString(result);
	}
};
}