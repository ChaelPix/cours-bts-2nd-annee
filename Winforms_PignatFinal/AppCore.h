#pragma once

namespace Winforms_PignatFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de AppCore
	/// </summary>
	public ref class AppCore : public System::Windows::Forms::Form
	{
	public:
		AppCore(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			InitbackgroundImages();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~AppCore()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pignatImg;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBox1;

	private: System::Windows::Forms::Timer^ BackgroundTimer;
	private: System::Windows::Forms::Timer^ AnimTimer;
	private: System::Windows::Forms::Label^ label2;




	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ backgroundImage;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;


	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AppCore::typeid));
			this->pignatImg = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->BackgroundTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->AnimTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->backgroundImage = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pignatImg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->SuspendLayout();
			// 
			// pignatImg
			// 
			this->pignatImg->BackColor = System::Drawing::Color::Transparent;
			this->pignatImg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pignatImg.Image")));
			this->pignatImg->Location = System::Drawing::Point(214, 30);
			this->pignatImg->Name = L"pignatImg";
			this->pignatImg->Size = System::Drawing::Size(445, 87);
			this->pignatImg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pignatImg->TabIndex = 4;
			this->pignatImg->TabStop = false;
			this->pignatImg->MouseEnter += gcnew System::EventHandler(this, &AppCore::Control_MouseEnter);
			this->pignatImg->MouseLeave += gcnew System::EventHandler(this, &AppCore::Control_MouseLeave);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label1->Location = System::Drawing::Point(297, 148);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(418, 75);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Ordres de Fabrication :";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 28;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"REF_OF_1", L"REF_OF_1", L"REF_OF_1", L"REF_OF_1",
					L"REF_OF_1", L"REF_OF_1", L"REF_OF_1", L"REF_OF_1"
			});
			this->listBox1->Location = System::Drawing::Point(327, 213);
			this->listBox1->Name = L"listBox1";
			this->listBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listBox1->Size = System::Drawing::Size(410, 172);
			this->listBox1->TabIndex = 9;
			// 
			// BackgroundTimer
			// 
			this->BackgroundTimer->Enabled = true;
			this->BackgroundTimer->Interval = 75;
			this->BackgroundTimer->Tick += gcnew System::EventHandler(this, &AppCore::BackgroundTimer_Tick);
			// 
			// AnimTimer
			// 
			this->AnimTimer->Interval = 5;
			this->AnimTimer->Tick += gcnew System::EventHandler(this, &AppCore::AnimTimer_Tick);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label2->Location = System::Drawing::Point(319, 444);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(418, 75);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Infos de $REF_OF_X :";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(271, 212);
			this->pictureBox1->MaximumSize = System::Drawing::Size(50, 50);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(50, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(375, 318);
			this->pictureBox2->MaximumSize = System::Drawing::Size(50, 50);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(50, 50);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(50, 318);
			this->pictureBox3->MaximumSize = System::Drawing::Size(50, 50);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(50, 50);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->pictureBox5);
			this->panel1->Controls->Add(this->pictureBox4);
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(327, 496);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(665, 281);
			this->panel1->TabIndex = 12;
			// 
			// backgroundImage
			// 
			this->backgroundImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->backgroundImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backgroundImage.Image")));
			this->backgroundImage->Location = System::Drawing::Point(-12, -12);
			this->backgroundImage->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->backgroundImage->Name = L"backgroundImage";
			this->backgroundImage->Size = System::Drawing::Size(1850, 1078);
			this->backgroundImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->backgroundImage->TabIndex = 10;
			this->backgroundImage->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(50, 212);
			this->pictureBox4->MaximumSize = System::Drawing::Size(50, 50);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(50, 50);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(497, 212);
			this->pictureBox5->MaximumSize = System::Drawing::Size(50, 50);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(50, 50);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 4;
			this->pictureBox5->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(553, 811);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(226, 55);
			this->button1->TabIndex = 13;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Red;
			this->button2->Location = System::Drawing::Point(21, 917);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 110);
			this->button2->TabIndex = 14;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Location = System::Drawing::Point(1138, 46);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(665, 370);
			this->panel2->TabIndex = 13;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				99)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				98)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(998, 547);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(366, 295);
			this->tableLayoutPanel1->TabIndex = 15;
			// 
			// AppCore
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1827, 1054);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pignatImg);
			this->Controls->Add(this->backgroundImage);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"AppCore";
			this->Text = L"AppCore";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pignatImg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion



		/*---------------RESPONSIVE ANIM-------------------*/
		bool isExpanding = false;
		Control^ currentAnimatedControl = nullptr;
		System::Collections::Generic::Dictionary<Control^, System::Drawing::Size>^ originalSizes = gcnew System::Collections::Generic::Dictionary<Control^, System::Drawing::Size>();
		System::Collections::Generic::Dictionary<Control^, System::Drawing::Point>^ originalLocations = gcnew System::Collections::Generic::Dictionary<Control^, System::Drawing::Point>();

		private: System::Void Control_MouseEnter(System::Object^ sender, System::EventArgs^ e)
		{
			Control^ ctrl = dynamic_cast<Control^>(sender);
			if (!ctrl) return;

			if (currentAnimatedControl != nullptr)
			{
				AnimTimer->Stop();
				currentAnimatedControl->Size = originalSizes[currentAnimatedControl];
				currentAnimatedControl->Location = originalLocations[currentAnimatedControl];
			}

			this->originalSizes[ctrl] = ctrl->Size;
			this->originalLocations[ctrl] = ctrl->Location;
			currentAnimatedControl = ctrl;

			isExpanding = true;
			AnimTimer->Enabled = true;
		}

		private: System::Void Control_MouseLeave(System::Object^ sender, System::EventArgs^ e)
		{
			Control^ ctrl = dynamic_cast<Control^>(sender);
			if (!ctrl) return;

			isExpanding = false;
			AnimTimer->Enabled = true;
		}

		private: System::Void AnimTimer_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			if (currentAnimatedControl == nullptr) return;

			double scale;
			if (isExpanding)
			{
				if (currentAnimatedControl->Width < originalSizes[currentAnimatedControl].Width * 1.2)
					scale = 1.05;
				else
				{
					this->AnimTimer->Stop();
					return;
				}
			}
			else
			{
				if (currentAnimatedControl->Width > originalSizes[currentAnimatedControl].Width)
					scale = 0.95;
				else
				{
					currentAnimatedControl->Size = this->originalSizes[currentAnimatedControl];
					currentAnimatedControl->Location = this->originalLocations[currentAnimatedControl];
					this->AnimTimer->Stop();
					return;
				}
			}

			int newWidth = static_cast<int>(currentAnimatedControl->Width * scale);
			int newHeight = static_cast<int>(currentAnimatedControl->Height * scale);

			int newX = originalLocations[currentAnimatedControl].X - (newWidth - originalSizes[currentAnimatedControl].Width) / 2;
			int newY = originalLocations[currentAnimatedControl].Y - (newHeight - originalSizes[currentAnimatedControl].Height) / 2;

			currentAnimatedControl->Size = System::Drawing::Size(newWidth, newHeight);
			currentAnimatedControl->Location = System::Drawing::Point(newX, newY);
		}


		/*---------------BACKGROUND IMAGE-------------------*/
		cli::array<Bitmap^>^ backgroundImages;
		const int nbImages = 60;
		int imageIndexStep = 1;
		int currentImageIndex = 0;

	private: void InitbackgroundImages()
	{
		backgroundImages = gcnew cli::array<Bitmap^>(nbImages);

		for (int i = 0; i < backgroundImages->Length; i++)
		{
			//backgroundImages[i] = gcnew Bitmap(String::Format("C:/Users/traia/OneDrive/Documents/GitHub/cours-bts-2nd-annee/Winforms_PignatFinal/Release/ressources/animated_background/Layer {0}.jpg", i * 2));
			backgroundImages[i] = gcnew Bitmap(String::Format("ressources/animated_fluid/Layer {0}.jpg", i+1));
		}

	}

	private: System::Void BackgroundTimer_Tick(System::Object^ sender, System::EventArgs^ e) {

		currentImageIndex += imageIndexStep;
		if (currentImageIndex == 0)
			imageIndexStep = 1;
		else if (currentImageIndex == backgroundImages->Length - 1)
		{
			imageIndexStep = -1;
		}

		backgroundImage->Image = backgroundImages[currentImageIndex];
	}







};
}
