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
			InitbackgroundImages();
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
	private: System::Windows::Forms::PictureBox^ pignatImg;

	private: System::Windows::Forms::TextBox^ textBox1;


	private: System::Windows::Forms::Timer^ BackgroundTimer;
	private: System::Windows::Forms::PictureBox^ backgroundImage;
	private: System::Windows::Forms::Timer^ pignatTimer;





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
			this->pignatImg = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->BackgroundTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundImage = (gcnew System::Windows::Forms::PictureBox());
			this->pignatTimer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pignatImg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundImage))->BeginInit();
			this->SuspendLayout();
			// 
			// loginTextBox
			// 
			this->loginTextBox->BackColor = System::Drawing::Color::White;
			this->loginTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->loginTextBox->Font = (gcnew System::Drawing::Font(L"Cambria", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginTextBox->ForeColor = System::Drawing::Color::Black;
			this->loginTextBox->Location = System::Drawing::Point(100, 455);
			this->loginTextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->loginTextBox->MaxLength = 20;
			this->loginTextBox->Name = L"loginTextBox";
			this->loginTextBox->Size = System::Drawing::Size(460, 59);
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
			this->button1->Location = System::Drawing::Point(219, 885);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(207, 58);
			this->button1->TabIndex = 2;
			this->button1->Text = L"S\'identifier";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// pignatImg
			// 
			this->pignatImg->BackColor = System::Drawing::Color::Transparent;
			this->pignatImg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pignatImg.Image")));
			this->pignatImg->Location = System::Drawing::Point(89, 86);
			this->pignatImg->Name = L"pignatImg";
			this->pignatImg->Size = System::Drawing::Size(495, 125);
			this->pignatImg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pignatImg->TabIndex = 3;
			this->pignatImg->TabStop = false;
			this->pignatImg->MouseEnter += gcnew System::EventHandler(this, &MyForm::pignatImg_MouseEnter);
			this->pignatImg->MouseLeave += gcnew System::EventHandler(this, &MyForm::pignatImg_MouseLeave);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(100, 642);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->MaxLength = 20;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(460, 59);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L" op123";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// BackgroundTimer
			// 
			this->BackgroundTimer->Enabled = true;
			this->BackgroundTimer->Tick += gcnew System::EventHandler(this, &MyForm::BackgroundTimer_Tick);
			// 
			// backgroundImage
			// 
			this->backgroundImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backgroundImage.BackgroundImage")));
			this->backgroundImage->Location = System::Drawing::Point(-6, -5);
			this->backgroundImage->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->backgroundImage->Name = L"backgroundImage";
			this->backgroundImage->Size = System::Drawing::Size(1828, 1055);
			this->backgroundImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->backgroundImage->TabIndex = 5;
			this->backgroundImage->TabStop = false;
			// 
			// pignatTimer
			// 
			this->pignatTimer->Interval = 5;
			this->pignatTimer->Tick += gcnew System::EventHandler(this, &MyForm::pignatTimer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1822, 1048);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pignatImg);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->loginTextBox);
			this->Controls->Add(this->backgroundImage);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Pignat";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pignatImg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundImage))->EndInit();
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




		cli::array<Bitmap^>^ backgroundImages;
		int currentImageIndex = 0;
		int imageIndexStep = 1;
		int timeBreak = 0;
		int glowMaxBreak = 5;

	private:

		/*---------------PIGNAT IMAGE-------------------*/
		bool isExpanding = false;
		System::Drawing::Size originalPignatSize;
		System::Drawing::Point originalPignatLocation;

	private: System::Void pignatImg_MouseEnter(System::Object^ sender, System::EventArgs^ e) {


		this->originalPignatSize = pignatImg->Size;
		this->originalPignatLocation = pignatImg->Location;

		isExpanding = true;
		pignatTimer->Enabled = true;
		return;

		int newWidth = static_cast<int>(pignatImg->Width * 1.2);
		int newHeight = static_cast<int>(pignatImg->Height * 1.2);

		int newX = originalPignatLocation.X - (newWidth - originalPignatSize.Width) / 2;
		int newY = originalPignatLocation.Y - (newHeight - originalPignatSize.Height) / 2;

		pignatImg->Size = System::Drawing::Size(newWidth, newHeight);
		pignatImg->Location = System::Drawing::Point(newX, newY);
	}

	private: System::Void pignatImg_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		isExpanding = false;
		pignatTimer->Enabled = true;
		return;

		pignatImg->Size = this->originalPignatSize;
		pignatImg->Location = System::Drawing::Point(originalPignatLocation);
	}

private: System::Void pignatTimer_Tick(System::Object^ sender, System::EventArgs^ e) {


	double scale;

	if (isExpanding)
	{
		// V�rifier si la taille actuelle est inf�rieure � la taille maximale souhait�e
		if (pignatImg->Width < originalPignatSize.Width * 1.2)
			scale = 1.05; 
		else
		{
			this->pignatTimer->Stop(); 
			return;
		}
	}
	else
	{
		if (pignatImg->Width > originalPignatSize.Width)
			scale = 0.95;  
		else
		{
			pignatImg->Size = this->originalPignatSize;  
			pignatImg->Location = this->originalPignatLocation; 
			this->pignatTimer->Stop(); 
			return;
		}
	}

	int newWidth = static_cast<int>(pignatImg->Width * scale);
	int newHeight = static_cast<int>(pignatImg->Height * scale);

	int newX = originalPignatLocation.X - (newWidth - originalPignatSize.Width) / 2;
	int newY = originalPignatLocation.Y - (newHeight - originalPignatSize.Height) / 2;

	pignatImg->Size = System::Drawing::Size(newWidth, newHeight);
	pignatImg->Location = System::Drawing::Point(newX, newY);
}



	 /*---------------BACKGROUND IMAGE-------------------*/
		void InitbackgroundImages()
		{
			backgroundImages = gcnew cli::array<Bitmap^>(21);

			for (int i = 0; i < backgroundImages->Length; i++)
			{
				backgroundImages[i] = gcnew Bitmap(String::Format("C:/Users/traia/OneDrive/Documents/GitHub/cours-bts-2nd-annee/Winforms_PignatFinal/Release/ressources/animated_background/Layer {0}.jpg", i * 2));
			}


		}

		System::Void BackgroundTimer_Tick(System::Object^ sender, System::EventArgs^ e) {

			currentImageIndex += imageIndexStep;
			if (currentImageIndex == 0)
				imageIndexStep = 1;
			else if (currentImageIndex == backgroundImages->Length - 1)
			{
				timeBreak++;

				if (timeBreak >= glowMaxBreak)
				{
					imageIndexStep = -1;
					timeBreak = 0;
				}
				else
					imageIndexStep = 0;
			}

			backgroundImage->Image = backgroundImages[currentImageIndex];
		}





	
};
}
