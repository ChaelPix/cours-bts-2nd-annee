#pragma once

namespace Winforms_PignatFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ loginTextBox;
	protected:

	protected:


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ backgroundImage;

	private: System::Windows::Forms::Timer^ BackgroundTimer;
	private: System::Windows::Forms::PictureBox^ test0;

	private: System::Windows::Forms::PictureBox^ test2;
	private: System::Windows::Forms::PictureBox^ test3;

	private: System::ComponentModel::IContainer^ components;





	protected:

	protected:



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->loginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->backgroundImage = (gcnew System::Windows::Forms::PictureBox());
			this->BackgroundTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->test0 = (gcnew System::Windows::Forms::PictureBox());
			this->test2 = (gcnew System::Windows::Forms::PictureBox());
			this->test3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test3))->BeginInit();
			this->SuspendLayout();
			// 
			// loginTextBox
			// 
			this->loginTextBox->BackColor = System::Drawing::Color::White;
			this->loginTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->loginTextBox->Font = (gcnew System::Drawing::Font(L"Cambria", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginTextBox->ForeColor = System::Drawing::Color::Black;
			this->loginTextBox->Location = System::Drawing::Point(67, 296);
			this->loginTextBox->MaxLength = 20;
			this->loginTextBox->Name = L"loginTextBox";
			this->loginTextBox->Size = System::Drawing::Size(307, 40);
			this->loginTextBox->TabIndex = 0;
			this->loginTextBox->Text = L" op123";
			this->loginTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->loginTextBox->MouseEnter += gcnew System::EventHandler(this, &MyForm::LoginAreaMouseEnter);
			this->loginTextBox->MouseLeave += gcnew System::EventHandler(this, &MyForm::LoginAreaMouseExit);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->CausesValidation = false;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::DimGray;
			this->button1->Location = System::Drawing::Point(146, 575);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(138, 38);
			this->button1->TabIndex = 2;
			this->button1->Text = L"S\'identifier";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(25, 42);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(417, 132);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(67, 417);
			this->textBox1->MaxLength = 20;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(307, 40);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L" op123";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// backgroundImage
			// 
			this->backgroundImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backgroundImage.Image")));
			this->backgroundImage->Location = System::Drawing::Point(-4, -3);
			this->backgroundImage->Name = L"backgroundImage";
			this->backgroundImage->Size = System::Drawing::Size(1219, 686);
			this->backgroundImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->backgroundImage->TabIndex = 5;
			this->backgroundImage->TabStop = false;
			// 
			// BackgroundTimer
			// 
			this->BackgroundTimer->Enabled = true;
			this->BackgroundTimer->Interval = 50;
			this->BackgroundTimer->Tick += gcnew System::EventHandler(this, &MyForm::BackgroundTimer_Tick);
			// 
			// test0
			// 
			this->test0->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"test0.Image")));
			this->test0->Location = System::Drawing::Point(12, 638);
			this->test0->Name = L"test0";
			this->test0->Size = System::Drawing::Size(43, 31);
			this->test0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->test0->TabIndex = 6;
			this->test0->TabStop = false;
			// 
			// test2
			// 
			this->test2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"test2.Image")));
			this->test2->Location = System::Drawing::Point(12, 582);
			this->test2->Name = L"test2";
			this->test2->Size = System::Drawing::Size(43, 31);
			this->test2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->test2->TabIndex = 8;
			this->test2->TabStop = false;
			// 
			// test3
			// 
			this->test3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"test3.Image")));
			this->test3->Location = System::Drawing::Point(12, 527);
			this->test3->Name = L"test3";
			this->test3->Size = System::Drawing::Size(43, 31);
			this->test3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->test3->TabIndex = 9;
			this->test3->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1215, 681);
			this->Controls->Add(this->test3);
			this->Controls->Add(this->test2);
			this->Controls->Add(this->test0);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->loginTextBox);
			this->Controls->Add(this->backgroundImage);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Pignat";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		/**********-------------Login------------**********/
		void LoginAreaMouseEnter(System::Object^ sender, System::EventArgs^ e)
		{
			loginTextBox->BackColor = Color::Cyan;
		
		}

		void LoginAreaMouseExit(System::Object^ sender, System::EventArgs^ e)
		{
			loginTextBox->BackColor = Color::White;
		}




		int actualImg = 0;

	private: System::Void BackgroundTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		actualImg = (actualImg + 1) % 3;



		switch (actualImg)
		{
		case 0:
			backgroundImage->Image = test0->Image;
			break;

		case 1:
			backgroundImage->Image = test2->Image;
			break;

		case 2:
			backgroundImage->Image = test3->Image;
			break;
		}

	}

};
}
