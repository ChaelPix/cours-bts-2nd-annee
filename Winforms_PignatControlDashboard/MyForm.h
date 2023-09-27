#pragma once

namespace Winforms_PignatControlDashboard {

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


	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel_Commandes;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel_Vannes;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel_reservoirs;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel_poids;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel_malaxeur;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel_cuve;

	private: System::Windows::Forms::Label^ label7;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ txt_PoidsTension;

	private: System::Windows::Forms::Label^ txt_Poids;
	private: System::Windows::Forms::Label^ label8;
	private: LBSoft::IndustrialCtrls::Meters::LBAnalogMeter^ lbAnalogMeter1;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed1;
	private: System::Windows::Forms::Label^ label10;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ lbButton2;
	private: System::Windows::Forms::Label^ label9;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ lbButton1;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed3;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed2;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed4;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed5;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed8;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed7;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed6;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed9;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed10;









































	private: System::ComponentModel::IContainer^ components;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel_Commandes = (gcnew System::Windows::Forms::Panel());
			this->lbLed1 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->lbButton2 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lbButton1 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lbAnalogMeter1 = (gcnew LBSoft::IndustrialCtrls::Meters::LBAnalogMeter());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel_Vannes = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel_reservoirs = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel_poids = (gcnew System::Windows::Forms::Panel());
			this->txt_PoidsTension = (gcnew System::Windows::Forms::Label());
			this->txt_Poids = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel_malaxeur = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel_cuve = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lbLed2 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->lbLed3 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->lbLed4 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->lbLed5 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->lbLed6 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->lbLed7 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->lbLed8 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->lbLed9 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->lbLed10 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel_Commandes->SuspendLayout();
			this->panel_Vannes->SuspendLayout();
			this->panel_reservoirs->SuspendLayout();
			this->panel_poids->SuspendLayout();
			this->panel_malaxeur->SuspendLayout();
			this->panel_cuve->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(12, 12);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(84, 83);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(102, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(536, 83);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Pignat - Tableau de Commandes";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel_Commandes
			// 
			this->panel_Commandes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_Commandes->Controls->Add(this->lbLed3);
			this->panel_Commandes->Controls->Add(this->lbLed1);
			this->panel_Commandes->Controls->Add(this->label10);
			this->panel_Commandes->Controls->Add(this->lbButton2);
			this->panel_Commandes->Controls->Add(this->label9);
			this->panel_Commandes->Controls->Add(this->lbButton1);
			this->panel_Commandes->Controls->Add(this->label8);
			this->panel_Commandes->Controls->Add(this->lbAnalogMeter1);
			this->panel_Commandes->Controls->Add(this->label2);
			this->panel_Commandes->Controls->Add(this->lbLed2);
			this->panel_Commandes->Controls->Add(this->lbLed4);
			this->panel_Commandes->Controls->Add(this->lbLed5);
			this->panel_Commandes->Location = System::Drawing::Point(12, 101);
			this->panel_Commandes->Name = L"panel_Commandes";
			this->panel_Commandes->Size = System::Drawing::Size(626, 308);
			this->panel_Commandes->TabIndex = 5;
			this->panel_Commandes->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_Commandes->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// lbLed1
			// 
			this->lbLed1->BackColor = System::Drawing::Color::Transparent;
			this->lbLed1->BlinkInterval = 500;
			this->lbLed1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed1->Label = L"Voyant";
			this->lbLed1->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed1->LedColor = System::Drawing::Color::Red;
			this->lbLed1->LedSize = System::Drawing::SizeF(60, 60);
			this->lbLed1->Location = System::Drawing::Point(512, 3);
			this->lbLed1->Name = L"lbLed1";
			this->lbLed1->Renderer = nullptr;
			this->lbLed1->Size = System::Drawing::Size(114, 137);
			this->lbLed1->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed1->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed1->TabIndex = 14;
			// 
			// label10
			// 
			this->label10->CausesValidation = false;
			this->label10->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label10->Location = System::Drawing::Point(397, 225);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(89, 66);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Bouton Arret";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbButton2
			// 
			this->lbButton2->BackColor = System::Drawing::Color::Transparent;
			this->lbButton2->ButtonColor = System::Drawing::Color::Red;
			this->lbButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbButton2->Label = L"";
			this->lbButton2->Location = System::Drawing::Point(380, 102);
			this->lbButton2->Name = L"lbButton2";
			this->lbButton2->Renderer = nullptr;
			this->lbButton2->RepeatInterval = 100;
			this->lbButton2->RepeatState = false;
			this->lbButton2->Size = System::Drawing::Size(120, 120);
			this->lbButton2->StartRepeatInterval = 500;
			this->lbButton2->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->lbButton2->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->lbButton2->TabIndex = 12;
			// 
			// label9
			// 
			this->label9->CausesValidation = false;
			this->label9->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label9->Location = System::Drawing::Point(247, 225);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(89, 66);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Bouton Marche";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbButton1
			// 
			this->lbButton1->BackColor = System::Drawing::Color::Transparent;
			this->lbButton1->ButtonColor = System::Drawing::Color::Lime;
			this->lbButton1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbButton1->Label = L"";
			this->lbButton1->Location = System::Drawing::Point(230, 102);
			this->lbButton1->Name = L"lbButton1";
			this->lbButton1->Renderer = nullptr;
			this->lbButton1->RepeatInterval = 100;
			this->lbButton1->RepeatState = false;
			this->lbButton1->Size = System::Drawing::Size(120, 120);
			this->lbButton1->StartRepeatInterval = 500;
			this->lbButton1->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->lbButton1->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->lbButton1->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->CausesValidation = false;
			this->label8->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->label8->Location = System::Drawing::Point(94, 225);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(89, 66);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Mode Manuel";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbAnalogMeter1
			// 
			this->lbAnalogMeter1->BackColor = System::Drawing::Color::Transparent;
			this->lbAnalogMeter1->BodyColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lbAnalogMeter1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbAnalogMeter1->Location = System::Drawing::Point(76, 97);
			this->lbAnalogMeter1->MaxValue = 3;
			this->lbAnalogMeter1->MeterStyle = LBSoft::IndustrialCtrls::Meters::LBAnalogMeter::AnalogMeterStyle::Circular;
			this->lbAnalogMeter1->MinValue = 0;
			this->lbAnalogMeter1->Name = L"lbAnalogMeter1";
			this->lbAnalogMeter1->NeedleColor = System::Drawing::Color::White;
			this->lbAnalogMeter1->Renderer = nullptr;
			this->lbAnalogMeter1->ScaleColor = System::Drawing::Color::White;
			this->lbAnalogMeter1->ScaleDivisions = 0;
			this->lbAnalogMeter1->ScaleSubDivisions = 0;
			this->lbAnalogMeter1->Size = System::Drawing::Size(125, 125);
			this->lbAnalogMeter1->TabIndex = 7;
			this->lbAnalogMeter1->Value = 1;
			this->lbAnalogMeter1->ViewGlass = false;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(14, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(378, 39);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Commandes du Panneau";
			// 
			// panel_Vannes
			// 
			this->panel_Vannes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_Vannes->Controls->Add(this->label3);
			this->panel_Vannes->Location = System::Drawing::Point(644, 101);
			this->panel_Vannes->Name = L"panel_Vannes";
			this->panel_Vannes->Size = System::Drawing::Size(822, 448);
			this->panel_Vannes->TabIndex = 8;
			this->panel_Vannes->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_Vannes->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::Control;
			this->label3->Location = System::Drawing::Point(14, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(378, 39);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Vannes de Réservoirs";
			// 
			// panel_reservoirs
			// 
			this->panel_reservoirs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_reservoirs->Controls->Add(this->label4);
			this->panel_reservoirs->Controls->Add(this->lbLed6);
			this->panel_reservoirs->Controls->Add(this->lbLed8);
			this->panel_reservoirs->Controls->Add(this->lbLed7);
			this->panel_reservoirs->Location = System::Drawing::Point(12, 415);
			this->panel_reservoirs->Name = L"panel_reservoirs";
			this->panel_reservoirs->Size = System::Drawing::Size(626, 218);
			this->panel_reservoirs->TabIndex = 9;
			this->panel_reservoirs->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_reservoirs->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(14, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(378, 39);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Capteurs des Réservoirs";
			// 
			// panel_poids
			// 
			this->panel_poids->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_poids->Controls->Add(this->txt_PoidsTension);
			this->panel_poids->Controls->Add(this->txt_Poids);
			this->panel_poids->Controls->Add(this->label5);
			this->panel_poids->Location = System::Drawing::Point(644, 555);
			this->panel_poids->Name = L"panel_poids";
			this->panel_poids->Size = System::Drawing::Size(392, 277);
			this->panel_poids->TabIndex = 10;
			this->panel_poids->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_poids->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// txt_PoidsTension
			// 
			this->txt_PoidsTension->CausesValidation = false;
			this->txt_PoidsTension->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_PoidsTension->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(198)));
			this->txt_PoidsTension->Location = System::Drawing::Point(7, 178);
			this->txt_PoidsTension->Name = L"txt_PoidsTension";
			this->txt_PoidsTension->Size = System::Drawing::Size(378, 39);
			this->txt_PoidsTension->TabIndex = 8;
			this->txt_PoidsTension->Text = L"0000 mV";
			this->txt_PoidsTension->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_Poids
			// 
			this->txt_Poids->CausesValidation = false;
			this->txt_Poids->Font = (gcnew System::Drawing::Font(L"Georgia", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Poids->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->txt_Poids->Location = System::Drawing::Point(7, 87);
			this->txt_Poids->Name = L"txt_Poids";
			this->txt_Poids->Size = System::Drawing::Size(378, 91);
			this->txt_Poids->TabIndex = 7;
			this->txt_Poids->Text = L"658 g";
			this->txt_Poids->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::Control;
			this->label5->Location = System::Drawing::Point(14, 14);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(378, 39);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Poids";
			// 
			// panel_malaxeur
			// 
			this->panel_malaxeur->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_malaxeur->Controls->Add(this->label6);
			this->panel_malaxeur->Location = System::Drawing::Point(1042, 555);
			this->panel_malaxeur->Name = L"panel_malaxeur";
			this->panel_malaxeur->Size = System::Drawing::Size(424, 277);
			this->panel_malaxeur->TabIndex = 11;
			this->panel_malaxeur->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_malaxeur->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::Control;
			this->label6->Location = System::Drawing::Point(14, 14);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(378, 39);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Équipements du Malaxeur";
			// 
			// panel_cuve
			// 
			this->panel_cuve->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_cuve->Controls->Add(this->lbLed9);
			this->panel_cuve->Controls->Add(this->label7);
			this->panel_cuve->Controls->Add(this->lbLed10);
			this->panel_cuve->Location = System::Drawing::Point(12, 639);
			this->panel_cuve->Name = L"panel_cuve";
			this->panel_cuve->Size = System::Drawing::Size(626, 193);
			this->panel_cuve->TabIndex = 10;
			this->panel_cuve->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_cuve->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::Control;
			this->label7->Location = System::Drawing::Point(14, 14);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(609, 39);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Capteurs de la Cuve de Refroidissement";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(1314, 18);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(152, 66);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Fermer";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// lbLed2
			// 
			this->lbLed2->BackColor = System::Drawing::Color::Transparent;
			this->lbLed2->BlinkInterval = 500;
			this->lbLed2->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed2->Label = L"";
			this->lbLed2->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed2->LedColor = System::Drawing::Color::Red;
			this->lbLed2->LedSize = System::Drawing::SizeF(20, 20);
			this->lbLed2->Location = System::Drawing::Point(252, 21);
			this->lbLed2->Name = L"lbLed2";
			this->lbLed2->Renderer = nullptr;
			this->lbLed2->Size = System::Drawing::Size(75, 75);
			this->lbLed2->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed2->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed2->TabIndex = 15;
			// 
			// lbLed3
			// 
			this->lbLed3->BackColor = System::Drawing::Color::Transparent;
			this->lbLed3->BlinkInterval = 500;
			this->lbLed3->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed3->Label = L"";
			this->lbLed3->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed3->LedColor = System::Drawing::Color::Red;
			this->lbLed3->LedSize = System::Drawing::SizeF(20, 20);
			this->lbLed3->Location = System::Drawing::Point(402, 21);
			this->lbLed3->Name = L"lbLed3";
			this->lbLed3->Renderer = nullptr;
			this->lbLed3->Size = System::Drawing::Size(75, 75);
			this->lbLed3->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed3->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed3->TabIndex = 16;
			// 
			// lbLed4
			// 
			this->lbLed4->BackColor = System::Drawing::Color::Transparent;
			this->lbLed4->BlinkInterval = 500;
			this->lbLed4->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed4->Label = L"";
			this->lbLed4->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed4->LedColor = System::Drawing::Color::Red;
			this->lbLed4->LedSize = System::Drawing::SizeF(20, 20);
			this->lbLed4->Location = System::Drawing::Point(66, 21);
			this->lbLed4->Name = L"lbLed4";
			this->lbLed4->Renderer = nullptr;
			this->lbLed4->Size = System::Drawing::Size(75, 75);
			this->lbLed4->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed4->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed4->TabIndex = 17;
			// 
			// lbLed5
			// 
			this->lbLed5->BackColor = System::Drawing::Color::Transparent;
			this->lbLed5->BlinkInterval = 500;
			this->lbLed5->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed5->Label = L"";
			this->lbLed5->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed5->LedColor = System::Drawing::Color::Red;
			this->lbLed5->LedSize = System::Drawing::SizeF(20, 20);
			this->lbLed5->Location = System::Drawing::Point(135, 21);
			this->lbLed5->Name = L"lbLed5";
			this->lbLed5->Renderer = nullptr;
			this->lbLed5->Size = System::Drawing::Size(75, 75);
			this->lbLed5->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed5->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed5->TabIndex = 18;
			// 
			// lbLed6
			// 
			this->lbLed6->BackColor = System::Drawing::Color::Transparent;
			this->lbLed6->BlinkInterval = 500;
			this->lbLed6->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbLed6->Label = L"Plastifiant";
			this->lbLed6->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed6->LedColor = System::Drawing::Color::SteelBlue;
			this->lbLed6->LedSize = System::Drawing::SizeF(60, 60);
			this->lbLed6->Location = System::Drawing::Point(87, 56);
			this->lbLed6->Name = L"lbLed6";
			this->lbLed6->Renderer = nullptr;
			this->lbLed6->Size = System::Drawing::Size(114, 137);
			this->lbLed6->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::On;
			this->lbLed6->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed6->TabIndex = 19;
			// 
			// lbLed7
			// 
			this->lbLed7->BackColor = System::Drawing::Color::Transparent;
			this->lbLed7->BlinkInterval = 500;
			this->lbLed7->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbLed7->Label = L"Lubrifiant";
			this->lbLed7->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed7->LedColor = System::Drawing::Color::SteelBlue;
			this->lbLed7->LedSize = System::Drawing::SizeF(60, 60);
			this->lbLed7->Location = System::Drawing::Point(236, 56);
			this->lbLed7->Name = L"lbLed7";
			this->lbLed7->Renderer = nullptr;
			this->lbLed7->Size = System::Drawing::Size(114, 137);
			this->lbLed7->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::On;
			this->lbLed7->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed7->TabIndex = 20;
			// 
			// lbLed8
			// 
			this->lbLed8->BackColor = System::Drawing::Color::Transparent;
			this->lbLed8->BlinkInterval = 500;
			this->lbLed8->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbLed8->Label = L"Autre truc";
			this->lbLed8->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed8->LedColor = System::Drawing::Color::SteelBlue;
			this->lbLed8->LedSize = System::Drawing::SizeF(60, 60);
			this->lbLed8->Location = System::Drawing::Point(386, 56);
			this->lbLed8->Name = L"lbLed8";
			this->lbLed8->Renderer = nullptr;
			this->lbLed8->Size = System::Drawing::Size(114, 137);
			this->lbLed8->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::On;
			this->lbLed8->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed8->TabIndex = 21;
			// 
			// lbLed9
			// 
			this->lbLed9->BackColor = System::Drawing::Color::Transparent;
			this->lbLed9->BlinkInterval = 500;
			this->lbLed9->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lbLed9->Label = L"Capteur Bas";
			this->lbLed9->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed9->LedColor = System::Drawing::Color::Yellow;
			this->lbLed9->LedSize = System::Drawing::SizeF(60, 60);
			this->lbLed9->Location = System::Drawing::Point(159, 43);
			this->lbLed9->Name = L"lbLed9";
			this->lbLed9->Renderer = nullptr;
			this->lbLed9->Size = System::Drawing::Size(114, 137);
			this->lbLed9->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::On;
			this->lbLed9->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed9->TabIndex = 22;
			// 
			// lbLed10
			// 
			this->lbLed10->BackColor = System::Drawing::Color::Transparent;
			this->lbLed10->BlinkInterval = 500;
			this->lbLed10->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lbLed10->Label = L"Capteur Haut";
			this->lbLed10->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed10->LedColor = System::Drawing::Color::Yellow;
			this->lbLed10->LedSize = System::Drawing::SizeF(60, 60);
			this->lbLed10->Location = System::Drawing::Point(312, 43);
			this->lbLed10->Name = L"lbLed10";
			this->lbLed10->Renderer = nullptr;
			this->lbLed10->Size = System::Drawing::Size(130, 137);
			this->lbLed10->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::On;
			this->lbLed10->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed10->TabIndex = 23;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(1478, 844);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel_cuve);
			this->Controls->Add(this->panel_malaxeur);
			this->Controls->Add(this->panel_poids);
			this->Controls->Add(this->panel_reservoirs);
			this->Controls->Add(this->panel_Vannes);
			this->Controls->Add(this->panel_Commandes);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox3);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Pignat";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel_Commandes->ResumeLayout(false);
			this->panel_Vannes->ResumeLayout(false);
			this->panel_reservoirs->ResumeLayout(false);
			this->panel_poids->ResumeLayout(false);
			this->panel_malaxeur->ResumeLayout(false);
			this->panel_cuve->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion



	private: System::Void panelEnter(System::Object^ sender, System::EventArgs^ e) {

		/*Panel^ panel = safe_cast<Panel^>(sender);
		panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;*/
	}

	private: System::Void panelExit(System::Object^ sender, System::EventArgs^ e) {

		/*System::Drawing::Point mousePosition = this->PointToClient(System::Windows::Forms::Cursor::Position);
		Panel^ panel = safe_cast<Panel^>(sender);

		System::Drawing::Rectangle panelRect = panel->Bounds;

		if (mousePosition.X < panelRect.Left || mousePosition.X > panelRect.Right || mousePosition.Y < panelRect.Top || mousePosition.Y > panelRect.Bottom) 
			panel->BorderStyle = System::Windows::Forms::BorderStyle::None;

			*/
	}

};
}
