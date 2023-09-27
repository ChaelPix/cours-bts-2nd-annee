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
	private: System::Windows::Forms::Label^ label14;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ lbButton6;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed14;
	private: System::Windows::Forms::Label^ label13;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ lbButton5;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed13;
	private: System::Windows::Forms::Label^ label12;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ lbButton4;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed12;
	private: System::Windows::Forms::Label^ label11;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ lbButton3;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed11;
	private: System::Windows::Forms::Label^ label15;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ lbButton7;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ lbButton8;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed15;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed17;
	private: System::Windows::Forms::Label^ label16;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ lbButton9;
	private: System::Windows::Forms::Label^ label17;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed16;










































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
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lbButton3 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->lbLed11 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->lbButton4 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->lbLed12 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->lbButton5 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->lbLed13 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->lbButton6 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->lbLed14 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->lbButton7 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->lbLed15 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->lbButton8 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->lbLed16 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->lbButton9 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->lbLed17 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
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
			this->panel_Vannes->Controls->Add(this->label14);
			this->panel_Vannes->Controls->Add(this->lbButton6);
			this->panel_Vannes->Controls->Add(this->lbLed14);
			this->panel_Vannes->Controls->Add(this->label13);
			this->panel_Vannes->Controls->Add(this->lbButton5);
			this->panel_Vannes->Controls->Add(this->lbLed13);
			this->panel_Vannes->Controls->Add(this->label12);
			this->panel_Vannes->Controls->Add(this->lbButton4);
			this->panel_Vannes->Controls->Add(this->lbLed12);
			this->panel_Vannes->Controls->Add(this->label11);
			this->panel_Vannes->Controls->Add(this->label3);
			this->panel_Vannes->Controls->Add(this->lbButton3);
			this->panel_Vannes->Controls->Add(this->lbLed11);
			this->panel_Vannes->Location = System::Drawing::Point(644, 101);
			this->panel_Vannes->Name = L"panel_Vannes";
			this->panel_Vannes->Size = System::Drawing::Size(822, 423);
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
			this->panel_poids->Location = System::Drawing::Point(644, 530);
			this->panel_poids->Name = L"panel_poids";
			this->panel_poids->Size = System::Drawing::Size(392, 302);
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
			this->panel_malaxeur->Controls->Add(this->label15);
			this->panel_malaxeur->Controls->Add(this->label6);
			this->panel_malaxeur->Controls->Add(this->lbButton7);
			this->panel_malaxeur->Controls->Add(this->lbButton8);
			this->panel_malaxeur->Controls->Add(this->lbLed15);
			this->panel_malaxeur->Controls->Add(this->lbLed17);
			this->panel_malaxeur->Controls->Add(this->label16);
			this->panel_malaxeur->Controls->Add(this->lbButton9);
			this->panel_malaxeur->Controls->Add(this->label17);
			this->panel_malaxeur->Controls->Add(this->lbLed16);
			this->panel_malaxeur->Location = System::Drawing::Point(1042, 530);
			this->panel_malaxeur->Name = L"panel_malaxeur";
			this->panel_malaxeur->Size = System::Drawing::Size(424, 302);
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
			this->lbLed6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbLed6->Label = L"Pvc Base";
			this->lbLed6->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed6->LedColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbLed6->LedSize = System::Drawing::SizeF(60, 60);
			this->lbLed6->Location = System::Drawing::Point(87, 56);
			this->lbLed6->Name = L"lbLed6";
			this->lbLed6->Renderer = nullptr;
			this->lbLed6->Size = System::Drawing::Size(114, 137);
			this->lbLed6->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed6->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed6->TabIndex = 19;
			// 
			// lbLed7
			// 
			this->lbLed7->BackColor = System::Drawing::Color::Transparent;
			this->lbLed7->BlinkInterval = 500;
			this->lbLed7->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbLed7->Label = L"Plastifiant";
			this->lbLed7->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed7->LedColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbLed7->LedSize = System::Drawing::SizeF(60, 60);
			this->lbLed7->Location = System::Drawing::Point(236, 56);
			this->lbLed7->Name = L"lbLed7";
			this->lbLed7->Renderer = nullptr;
			this->lbLed7->Size = System::Drawing::Size(114, 137);
			this->lbLed7->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed7->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed7->TabIndex = 20;
			// 
			// lbLed8
			// 
			this->lbLed8->BackColor = System::Drawing::Color::Transparent;
			this->lbLed8->BlinkInterval = 500;
			this->lbLed8->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbLed8->Label = L"Lubrifiant";
			this->lbLed8->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed8->LedColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbLed8->LedSize = System::Drawing::SizeF(60, 60);
			this->lbLed8->Location = System::Drawing::Point(386, 56);
			this->lbLed8->Name = L"lbLed8";
			this->lbLed8->Renderer = nullptr;
			this->lbLed8->Size = System::Drawing::Size(114, 137);
			this->lbLed8->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
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
			this->lbLed9->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
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
			this->lbLed10->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed10->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed10->TabIndex = 23;
			// 
			// label11
			// 
			this->label11->CausesValidation = false;
			this->label11->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::PaleTurquoise;
			this->label11->Location = System::Drawing::Point(140, 294);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(89, 66);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Bouton Pvc Base";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbButton3
			// 
			this->lbButton3->BackColor = System::Drawing::Color::Transparent;
			this->lbButton3->ButtonColor = System::Drawing::Color::Turquoise;
			this->lbButton3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbButton3->Label = L"";
			this->lbButton3->Location = System::Drawing::Point(123, 171);
			this->lbButton3->Name = L"lbButton3";
			this->lbButton3->Renderer = nullptr;
			this->lbButton3->RepeatInterval = 100;
			this->lbButton3->RepeatState = false;
			this->lbButton3->Size = System::Drawing::Size(120, 120);
			this->lbButton3->StartRepeatInterval = 500;
			this->lbButton3->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->lbButton3->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->lbButton3->TabIndex = 19;
			// 
			// lbLed11
			// 
			this->lbLed11->BackColor = System::Drawing::Color::Transparent;
			this->lbLed11->BlinkInterval = 500;
			this->lbLed11->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed11->Label = L"";
			this->lbLed11->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed11->LedColor = System::Drawing::Color::Red;
			this->lbLed11->LedSize = System::Drawing::SizeF(20, 20);
			this->lbLed11->Location = System::Drawing::Point(145, 90);
			this->lbLed11->Name = L"lbLed11";
			this->lbLed11->Renderer = nullptr;
			this->lbLed11->Size = System::Drawing::Size(75, 75);
			this->lbLed11->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed11->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed11->TabIndex = 21;
			// 
			// label12
			// 
			this->label12->CausesValidation = false;
			this->label12->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::PaleTurquoise;
			this->label12->Location = System::Drawing::Point(249, 294);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(120, 66);
			this->label12->TabIndex = 23;
			this->label12->Text = L"Bouton Pvc Base Fd";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbButton4
			// 
			this->lbButton4->BackColor = System::Drawing::Color::Transparent;
			this->lbButton4->ButtonColor = System::Drawing::Color::Turquoise;
			this->lbButton4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbButton4->Label = L"";
			this->lbButton4->Location = System::Drawing::Point(249, 171);
			this->lbButton4->Name = L"lbButton4";
			this->lbButton4->Renderer = nullptr;
			this->lbButton4->RepeatInterval = 100;
			this->lbButton4->RepeatState = false;
			this->lbButton4->Size = System::Drawing::Size(120, 120);
			this->lbButton4->StartRepeatInterval = 500;
			this->lbButton4->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->lbButton4->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->lbButton4->TabIndex = 22;
			// 
			// lbLed12
			// 
			this->lbLed12->BackColor = System::Drawing::Color::Transparent;
			this->lbLed12->BlinkInterval = 500;
			this->lbLed12->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed12->Label = L"";
			this->lbLed12->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed12->LedColor = System::Drawing::Color::Red;
			this->lbLed12->LedSize = System::Drawing::SizeF(20, 20);
			this->lbLed12->Location = System::Drawing::Point(271, 90);
			this->lbLed12->Name = L"lbLed12";
			this->lbLed12->Renderer = nullptr;
			this->lbLed12->Size = System::Drawing::Size(75, 75);
			this->lbLed12->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed12->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed12->TabIndex = 24;
			// 
			// label13
			// 
			this->label13->CausesValidation = false;
			this->label13->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::PaleTurquoise;
			this->label13->Location = System::Drawing::Point(408, 294);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(120, 66);
			this->label13->TabIndex = 26;
			this->label13->Text = L"Bouton Plastifiant";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbButton5
			// 
			this->lbButton5->BackColor = System::Drawing::Color::Transparent;
			this->lbButton5->ButtonColor = System::Drawing::Color::SkyBlue;
			this->lbButton5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbButton5->Label = L"";
			this->lbButton5->Location = System::Drawing::Point(408, 171);
			this->lbButton5->Name = L"lbButton5";
			this->lbButton5->Renderer = nullptr;
			this->lbButton5->RepeatInterval = 100;
			this->lbButton5->RepeatState = false;
			this->lbButton5->Size = System::Drawing::Size(120, 120);
			this->lbButton5->StartRepeatInterval = 500;
			this->lbButton5->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->lbButton5->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->lbButton5->TabIndex = 25;
			// 
			// lbLed13
			// 
			this->lbLed13->BackColor = System::Drawing::Color::Transparent;
			this->lbLed13->BlinkInterval = 500;
			this->lbLed13->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed13->Label = L"";
			this->lbLed13->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed13->LedColor = System::Drawing::Color::Red;
			this->lbLed13->LedSize = System::Drawing::SizeF(20, 20);
			this->lbLed13->Location = System::Drawing::Point(430, 90);
			this->lbLed13->Name = L"lbLed13";
			this->lbLed13->Renderer = nullptr;
			this->lbLed13->Size = System::Drawing::Size(75, 75);
			this->lbLed13->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed13->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed13->TabIndex = 27;
			// 
			// label14
			// 
			this->label14->CausesValidation = false;
			this->label14->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::PaleTurquoise;
			this->label14->Location = System::Drawing::Point(567, 294);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(120, 66);
			this->label14->TabIndex = 29;
			this->label14->Text = L"Bouton Lubrifiant";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbButton6
			// 
			this->lbButton6->BackColor = System::Drawing::Color::Transparent;
			this->lbButton6->ButtonColor = System::Drawing::Color::DodgerBlue;
			this->lbButton6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbButton6->Label = L"";
			this->lbButton6->Location = System::Drawing::Point(567, 171);
			this->lbButton6->Name = L"lbButton6";
			this->lbButton6->Renderer = nullptr;
			this->lbButton6->RepeatInterval = 100;
			this->lbButton6->RepeatState = false;
			this->lbButton6->Size = System::Drawing::Size(120, 120);
			this->lbButton6->StartRepeatInterval = 500;
			this->lbButton6->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->lbButton6->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->lbButton6->TabIndex = 28;
			// 
			// lbLed14
			// 
			this->lbLed14->BackColor = System::Drawing::Color::Transparent;
			this->lbLed14->BlinkInterval = 500;
			this->lbLed14->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed14->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed14->Label = L"";
			this->lbLed14->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed14->LedColor = System::Drawing::Color::Red;
			this->lbLed14->LedSize = System::Drawing::SizeF(20, 20);
			this->lbLed14->Location = System::Drawing::Point(589, 90);
			this->lbLed14->Name = L"lbLed14";
			this->lbLed14->Renderer = nullptr;
			this->lbLed14->Size = System::Drawing::Size(75, 75);
			this->lbLed14->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed14->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed14->TabIndex = 30;
			// 
			// label15
			// 
			this->label15->CausesValidation = false;
			this->label15->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::YellowGreen;
			this->label15->Location = System::Drawing::Point(284, 232);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(120, 66);
			this->label15->TabIndex = 38;
			this->label15->Text = L"Bouton Évacuation";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbButton7
			// 
			this->lbButton7->BackColor = System::Drawing::Color::Transparent;
			this->lbButton7->ButtonColor = System::Drawing::Color::DarkGreen;
			this->lbButton7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbButton7->Label = L"";
			this->lbButton7->Location = System::Drawing::Point(284, 106);
			this->lbButton7->Name = L"lbButton7";
			this->lbButton7->Renderer = nullptr;
			this->lbButton7->RepeatInterval = 100;
			this->lbButton7->RepeatState = false;
			this->lbButton7->Size = System::Drawing::Size(120, 120);
			this->lbButton7->StartRepeatInterval = 500;
			this->lbButton7->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->lbButton7->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->lbButton7->TabIndex = 37;
			// 
			// lbLed15
			// 
			this->lbLed15->BackColor = System::Drawing::Color::Transparent;
			this->lbLed15->BlinkInterval = 500;
			this->lbLed15->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed15->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed15->Label = L"";
			this->lbLed15->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed15->LedColor = System::Drawing::Color::Red;
			this->lbLed15->LedSize = System::Drawing::SizeF(20, 20);
			this->lbLed15->Location = System::Drawing::Point(306, 27);
			this->lbLed15->Name = L"lbLed15";
			this->lbLed15->Renderer = nullptr;
			this->lbLed15->Size = System::Drawing::Size(75, 75);
			this->lbLed15->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed15->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed15->TabIndex = 39;
			// 
			// label16
			// 
			this->label16->CausesValidation = false;
			this->label16->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::YellowGreen;
			this->label16->Location = System::Drawing::Point(158, 232);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(120, 66);
			this->label16->TabIndex = 35;
			this->label16->Text = L"Bouton Vidange";
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbButton8
			// 
			this->lbButton8->BackColor = System::Drawing::Color::Transparent;
			this->lbButton8->ButtonColor = System::Drawing::Color::Lime;
			this->lbButton8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbButton8->Label = L"";
			this->lbButton8->Location = System::Drawing::Point(158, 109);
			this->lbButton8->Name = L"lbButton8";
			this->lbButton8->Renderer = nullptr;
			this->lbButton8->RepeatInterval = 100;
			this->lbButton8->RepeatState = false;
			this->lbButton8->Size = System::Drawing::Size(120, 120);
			this->lbButton8->StartRepeatInterval = 500;
			this->lbButton8->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->lbButton8->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->lbButton8->TabIndex = 34;
			// 
			// lbLed16
			// 
			this->lbLed16->BackColor = System::Drawing::Color::Transparent;
			this->lbLed16->BlinkInterval = 500;
			this->lbLed16->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed16->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed16->Label = L"";
			this->lbLed16->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed16->LedColor = System::Drawing::Color::Red;
			this->lbLed16->LedSize = System::Drawing::SizeF(20, 20);
			this->lbLed16->Location = System::Drawing::Point(181, 27);
			this->lbLed16->Name = L"lbLed16";
			this->lbLed16->Renderer = nullptr;
			this->lbLed16->Size = System::Drawing::Size(75, 75);
			this->lbLed16->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed16->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed16->TabIndex = 36;
			// 
			// label17
			// 
			this->label17->CausesValidation = false;
			this->label17->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::YellowGreen;
			this->label17->Location = System::Drawing::Point(32, 232);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(120, 66);
			this->label17->TabIndex = 32;
			this->label17->Text = L"Bouton Malaxeur";
			this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbButton9
			// 
			this->lbButton9->BackColor = System::Drawing::Color::Transparent;
			this->lbButton9->ButtonColor = System::Drawing::Color::Silver;
			this->lbButton9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbButton9->Label = L"";
			this->lbButton9->Location = System::Drawing::Point(32, 109);
			this->lbButton9->Name = L"lbButton9";
			this->lbButton9->Renderer = nullptr;
			this->lbButton9->RepeatInterval = 100;
			this->lbButton9->RepeatState = false;
			this->lbButton9->Size = System::Drawing::Size(120, 120);
			this->lbButton9->StartRepeatInterval = 500;
			this->lbButton9->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->lbButton9->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->lbButton9->TabIndex = 31;
			// 
			// lbLed17
			// 
			this->lbLed17->BackColor = System::Drawing::Color::Transparent;
			this->lbLed17->BlinkInterval = 500;
			this->lbLed17->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLed17->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lbLed17->Label = L"";
			this->lbLed17->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed17->LedColor = System::Drawing::Color::Red;
			this->lbLed17->LedSize = System::Drawing::SizeF(20, 20);
			this->lbLed17->Location = System::Drawing::Point(56, 27);
			this->lbLed17->Name = L"lbLed17";
			this->lbLed17->Renderer = nullptr;
			this->lbLed17->Size = System::Drawing::Size(75, 75);
			this->lbLed17->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed17->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed17->TabIndex = 33;
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
