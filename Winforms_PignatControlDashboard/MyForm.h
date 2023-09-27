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
			this->panel_Commandes->Controls->Add(this->lbLed1);
			this->panel_Commandes->Controls->Add(this->label10);
			this->panel_Commandes->Controls->Add(this->lbButton2);
			this->panel_Commandes->Controls->Add(this->label9);
			this->panel_Commandes->Controls->Add(this->lbButton1);
			this->panel_Commandes->Controls->Add(this->label8);
			this->panel_Commandes->Controls->Add(this->lbAnalogMeter1);
			this->panel_Commandes->Controls->Add(this->label2);
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
			this->lbLed1->LedSize = System::Drawing::SizeF(50, 50);
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
			this->panel_cuve->Controls->Add(this->label7);
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
