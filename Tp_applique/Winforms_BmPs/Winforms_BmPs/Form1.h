#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ btn_importer;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btn_importer = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(265, 91);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1434, 841);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::DimGray;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->btn_importer);
			this->panel2->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel2->Location = System::Drawing::Point(-7, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1717, 97);
			this->panel2->TabIndex = 0;
			// 
			// btn_importer
			// 
			this->btn_importer->BackColor = System::Drawing::Color::Transparent;
			this->btn_importer->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_importer->Location = System::Drawing::Point(38, 20);
			this->btn_importer->Name = L"btn_importer";
			this->btn_importer->Size = System::Drawing::Size(270, 45);
			this->btn_importer->TabIndex = 2;
			this->btn_importer->Text = L"Importer";
			this->btn_importer->UseVisualStyleBackColor = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->ClientSize = System::Drawing::Size(1698, 924);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BmPs";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
