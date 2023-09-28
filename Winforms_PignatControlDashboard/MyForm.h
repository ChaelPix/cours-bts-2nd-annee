#pragma once

#include "EsMelangeur.h"

namespace Winforms_PignatControlDashboard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace LBSoft::IndustrialCtrls::Base;
	using namespace LBSoft::IndustrialCtrls::Buttons;
	using namespace LBSoft::IndustrialCtrls::Leds;
	using namespace LBSoft::IndustrialCtrls::Knobs;
	using namespace LBSoft::IndustrialCtrls::Meters;
	using namespace LBSoft::IndustrialCtrls::Utils;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		CEsMelangeur^ pignat = gcnew CEsMelangeur();

	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			pignat->initEsMelangeur();
			pignat->majSorties();
			pignat->lireEntrees();

			MajEntreeUI();
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
	private: System::Windows::Forms::Button^ btn_Fermer;





	private: System::Windows::Forms::Label^ txt_Poids;
	private: System::Windows::Forms::Label^ txt_ManuelAuto;
	private: LBSoft::IndustrialCtrls::Meters::LBAnalogMeter^ meter_AutoManuel;


	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_Marche;



	private: System::Windows::Forms::Label^ label10;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ btn_Voyant;

	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_Voyant;










	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_CapteurR3;



	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_CapteurR2;

	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_CapteurR1;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_CapteurBas;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_CapteurHaut;




	private: System::Windows::Forms::Label^ label14;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ btn_vanne4;

	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_vanne4;

	private: System::Windows::Forms::Label^ label13;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ btn_vanne3;

	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_vanne3;

	private: System::Windows::Forms::Label^ label12;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ btn_vanne2;

	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_vanne2;

	private: System::Windows::Forms::Label^ label11;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ btn_vanne1;

	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_vanne1;

	private: System::Windows::Forms::Label^ label15;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ btn_evacuation;

	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ btn_vidange;

	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_evacuation;

	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_malaxeur;

	private: System::Windows::Forms::Label^ label16;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ btn_malaxeur;

	private: System::Windows::Forms::Label^ label17;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_vidange;
	private: System::Windows::Forms::Timer^ timer;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ led_Arret;





	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		bool vanne1, vanne2, vanne3, vanne4, vidange, malaxeur, evacuation, voyantRouge;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel_Commandes = (gcnew System::Windows::Forms::Panel());
			this->led_Arret = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->led_Voyant = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->btn_Voyant = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->txt_ManuelAuto = (gcnew System::Windows::Forms::Label());
			this->meter_AutoManuel = (gcnew LBSoft::IndustrialCtrls::Meters::LBAnalogMeter());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->led_Marche = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->panel_Vannes = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->btn_vanne4 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->led_vanne4 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->btn_vanne3 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->led_vanne3 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->btn_vanne2 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->led_vanne2 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btn_vanne1 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->led_vanne1 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->panel_reservoirs = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->led_CapteurR1 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->led_CapteurR3 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->led_CapteurR2 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->panel_poids = (gcnew System::Windows::Forms::Panel());
			this->txt_Poids = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel_malaxeur = (gcnew System::Windows::Forms::Panel());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btn_evacuation = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->btn_vidange = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->led_evacuation = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->led_malaxeur = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->btn_malaxeur = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->led_vidange = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->panel_cuve = (gcnew System::Windows::Forms::Panel());
			this->led_CapteurBas = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->led_CapteurHaut = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->btn_Fermer = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
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
			this->pictureBox3->Location = System::Drawing::Point(8, 8);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(56, 55);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(68, 8);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(698, 55);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Pignat - Tableau de Commandes";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel_Commandes
			// 
			this->panel_Commandes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_Commandes->Controls->Add(this->led_Arret);
			this->panel_Commandes->Controls->Add(this->led_Voyant);
			this->panel_Commandes->Controls->Add(this->label10);
			this->panel_Commandes->Controls->Add(this->btn_Voyant);
			this->panel_Commandes->Controls->Add(this->txt_ManuelAuto);
			this->panel_Commandes->Controls->Add(this->meter_AutoManuel);
			this->panel_Commandes->Controls->Add(this->label2);
			this->panel_Commandes->Controls->Add(this->led_Marche);
			this->panel_Commandes->Location = System::Drawing::Point(8, 67);
			this->panel_Commandes->Margin = System::Windows::Forms::Padding(2);
			this->panel_Commandes->Name = L"panel_Commandes";
			this->panel_Commandes->Size = System::Drawing::Size(417, 205);
			this->panel_Commandes->TabIndex = 5;
			this->panel_Commandes->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_Commandes->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// led_Arret
			// 
			this->led_Arret->BackColor = System::Drawing::Color::Transparent;
			this->led_Arret->BlinkInterval = 500;
			this->led_Arret->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_Arret->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->led_Arret->Label = L"Arrêt";
			this->led_Arret->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_Arret->LedColor = System::Drawing::Color::Red;
			this->led_Arret->LedSize = System::Drawing::SizeF(60, 60);
			this->led_Arret->Location = System::Drawing::Point(150, 112);
			this->led_Arret->Margin = System::Windows::Forms::Padding(2);
			this->led_Arret->Name = L"led_Arret";
			this->led_Arret->Renderer = nullptr;
			this->led_Arret->Size = System::Drawing::Size(76, 91);
			this->led_Arret->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_Arret->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_Arret->TabIndex = 17;
			// 
			// led_Voyant
			// 
			this->led_Voyant->BackColor = System::Drawing::Color::Transparent;
			this->led_Voyant->BlinkInterval = 500;
			this->led_Voyant->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_Voyant->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->led_Voyant->Label = L"";
			this->led_Voyant->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_Voyant->LedColor = System::Drawing::Color::Red;
			this->led_Voyant->LedSize = System::Drawing::SizeF(20, 20);
			this->led_Voyant->Location = System::Drawing::Point(268, 14);
			this->led_Voyant->Margin = System::Windows::Forms::Padding(2);
			this->led_Voyant->Name = L"led_Voyant";
			this->led_Voyant->Renderer = nullptr;
			this->led_Voyant->Size = System::Drawing::Size(50, 50);
			this->led_Voyant->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_Voyant->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_Voyant->TabIndex = 16;
			// 
			// label10
			// 
			this->label10->CausesValidation = false;
			this->label10->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label10->Location = System::Drawing::Point(265, 150);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(59, 44);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Bouton Voyant";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_Voyant
			// 
			this->btn_Voyant->BackColor = System::Drawing::Color::Transparent;
			this->btn_Voyant->ButtonColor = System::Drawing::Color::Red;
			this->btn_Voyant->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_Voyant->Label = L"";
			this->btn_Voyant->Location = System::Drawing::Point(253, 68);
			this->btn_Voyant->Margin = System::Windows::Forms::Padding(2);
			this->btn_Voyant->Name = L"btn_Voyant";
			this->btn_Voyant->Renderer = nullptr;
			this->btn_Voyant->RepeatInterval = 100;
			this->btn_Voyant->RepeatState = false;
			this->btn_Voyant->Size = System::Drawing::Size(80, 80);
			this->btn_Voyant->StartRepeatInterval = 500;
			this->btn_Voyant->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->btn_Voyant->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->btn_Voyant->TabIndex = 12;
			this->btn_Voyant->Click += gcnew System::EventHandler(this, &MyForm::btn_Voyant_Click);
			// 
			// txt_ManuelAuto
			// 
			this->txt_ManuelAuto->CausesValidation = false;
			this->txt_ManuelAuto->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_ManuelAuto->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->txt_ManuelAuto->Location = System::Drawing::Point(63, 150);
			this->txt_ManuelAuto->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->txt_ManuelAuto->Name = L"txt_ManuelAuto";
			this->txt_ManuelAuto->Size = System::Drawing::Size(59, 44);
			this->txt_ManuelAuto->TabIndex = 9;
			this->txt_ManuelAuto->Text = L"Mode Manuel";
			this->txt_ManuelAuto->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// meter_AutoManuel
			// 
			this->meter_AutoManuel->BackColor = System::Drawing::Color::Transparent;
			this->meter_AutoManuel->BodyColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->meter_AutoManuel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->meter_AutoManuel->Location = System::Drawing::Point(51, 65);
			this->meter_AutoManuel->Margin = System::Windows::Forms::Padding(2);
			this->meter_AutoManuel->MaxValue = 3;
			this->meter_AutoManuel->MeterStyle = LBSoft::IndustrialCtrls::Meters::LBAnalogMeter::AnalogMeterStyle::Circular;
			this->meter_AutoManuel->MinValue = 0;
			this->meter_AutoManuel->Name = L"meter_AutoManuel";
			this->meter_AutoManuel->NeedleColor = System::Drawing::Color::White;
			this->meter_AutoManuel->Renderer = nullptr;
			this->meter_AutoManuel->ScaleColor = System::Drawing::Color::White;
			this->meter_AutoManuel->ScaleDivisions = 0;
			this->meter_AutoManuel->ScaleSubDivisions = 0;
			this->meter_AutoManuel->Size = System::Drawing::Size(83, 83);
			this->meter_AutoManuel->TabIndex = 7;
			this->meter_AutoManuel->Value = 1;
			this->meter_AutoManuel->ViewGlass = false;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(9, 9);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(252, 26);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Commandes du Panneau";
			// 
			// led_Marche
			// 
			this->led_Marche->BackColor = System::Drawing::Color::Transparent;
			this->led_Marche->BlinkInterval = 500;
			this->led_Marche->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_Marche->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->led_Marche->Label = L"Marche";
			this->led_Marche->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_Marche->LedColor = System::Drawing::Color::Lime;
			this->led_Marche->LedSize = System::Drawing::SizeF(60, 60);
			this->led_Marche->Location = System::Drawing::Point(150, 9);
			this->led_Marche->Margin = System::Windows::Forms::Padding(2);
			this->led_Marche->Name = L"led_Marche";
			this->led_Marche->Renderer = nullptr;
			this->led_Marche->Size = System::Drawing::Size(76, 105);
			this->led_Marche->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_Marche->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_Marche->TabIndex = 14;
			// 
			// panel_Vannes
			// 
			this->panel_Vannes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_Vannes->Controls->Add(this->label14);
			this->panel_Vannes->Controls->Add(this->btn_vanne4);
			this->panel_Vannes->Controls->Add(this->led_vanne4);
			this->panel_Vannes->Controls->Add(this->label13);
			this->panel_Vannes->Controls->Add(this->btn_vanne3);
			this->panel_Vannes->Controls->Add(this->led_vanne3);
			this->panel_Vannes->Controls->Add(this->label12);
			this->panel_Vannes->Controls->Add(this->btn_vanne2);
			this->panel_Vannes->Controls->Add(this->led_vanne2);
			this->panel_Vannes->Controls->Add(this->label11);
			this->panel_Vannes->Controls->Add(this->label3);
			this->panel_Vannes->Controls->Add(this->btn_vanne1);
			this->panel_Vannes->Controls->Add(this->led_vanne1);
			this->panel_Vannes->Location = System::Drawing::Point(429, 67);
			this->panel_Vannes->Margin = System::Windows::Forms::Padding(2);
			this->panel_Vannes->Name = L"panel_Vannes";
			this->panel_Vannes->Size = System::Drawing::Size(548, 282);
			this->panel_Vannes->TabIndex = 8;
			this->panel_Vannes->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_Vannes->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// label14
			// 
			this->label14->CausesValidation = false;
			this->label14->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::PaleTurquoise;
			this->label14->Location = System::Drawing::Point(378, 196);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(80, 44);
			this->label14->TabIndex = 29;
			this->label14->Text = L"Bouton Lubrifiant";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_vanne4
			// 
			this->btn_vanne4->BackColor = System::Drawing::Color::Transparent;
			this->btn_vanne4->ButtonColor = System::Drawing::Color::DodgerBlue;
			this->btn_vanne4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_vanne4->Label = L"";
			this->btn_vanne4->Location = System::Drawing::Point(378, 114);
			this->btn_vanne4->Margin = System::Windows::Forms::Padding(2);
			this->btn_vanne4->Name = L"btn_vanne4";
			this->btn_vanne4->Renderer = nullptr;
			this->btn_vanne4->RepeatInterval = 100;
			this->btn_vanne4->RepeatState = false;
			this->btn_vanne4->Size = System::Drawing::Size(80, 80);
			this->btn_vanne4->StartRepeatInterval = 500;
			this->btn_vanne4->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->btn_vanne4->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->btn_vanne4->TabIndex = 28;
			this->btn_vanne4->Click += gcnew System::EventHandler(this, &MyForm::btn_vanne4_Click);
			// 
			// led_vanne4
			// 
			this->led_vanne4->BackColor = System::Drawing::Color::Transparent;
			this->led_vanne4->BlinkInterval = 500;
			this->led_vanne4->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_vanne4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->led_vanne4->Label = L"";
			this->led_vanne4->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_vanne4->LedColor = System::Drawing::Color::Red;
			this->led_vanne4->LedSize = System::Drawing::SizeF(20, 20);
			this->led_vanne4->Location = System::Drawing::Point(393, 60);
			this->led_vanne4->Margin = System::Windows::Forms::Padding(2);
			this->led_vanne4->Name = L"led_vanne4";
			this->led_vanne4->Renderer = nullptr;
			this->led_vanne4->Size = System::Drawing::Size(50, 50);
			this->led_vanne4->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_vanne4->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_vanne4->TabIndex = 30;
			// 
			// label13
			// 
			this->label13->CausesValidation = false;
			this->label13->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::PaleTurquoise;
			this->label13->Location = System::Drawing::Point(272, 196);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(80, 44);
			this->label13->TabIndex = 26;
			this->label13->Text = L"Bouton Plastifiant";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_vanne3
			// 
			this->btn_vanne3->BackColor = System::Drawing::Color::Transparent;
			this->btn_vanne3->ButtonColor = System::Drawing::Color::SkyBlue;
			this->btn_vanne3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_vanne3->Label = L"";
			this->btn_vanne3->Location = System::Drawing::Point(272, 114);
			this->btn_vanne3->Margin = System::Windows::Forms::Padding(2);
			this->btn_vanne3->Name = L"btn_vanne3";
			this->btn_vanne3->Renderer = nullptr;
			this->btn_vanne3->RepeatInterval = 100;
			this->btn_vanne3->RepeatState = false;
			this->btn_vanne3->Size = System::Drawing::Size(80, 80);
			this->btn_vanne3->StartRepeatInterval = 500;
			this->btn_vanne3->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->btn_vanne3->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->btn_vanne3->TabIndex = 25;
			this->btn_vanne3->Click += gcnew System::EventHandler(this, &MyForm::btn_vanne3_Click);
			// 
			// led_vanne3
			// 
			this->led_vanne3->BackColor = System::Drawing::Color::Transparent;
			this->led_vanne3->BlinkInterval = 500;
			this->led_vanne3->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_vanne3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->led_vanne3->Label = L"";
			this->led_vanne3->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_vanne3->LedColor = System::Drawing::Color::Red;
			this->led_vanne3->LedSize = System::Drawing::SizeF(20, 20);
			this->led_vanne3->Location = System::Drawing::Point(287, 60);
			this->led_vanne3->Margin = System::Windows::Forms::Padding(2);
			this->led_vanne3->Name = L"led_vanne3";
			this->led_vanne3->Renderer = nullptr;
			this->led_vanne3->Size = System::Drawing::Size(50, 50);
			this->led_vanne3->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_vanne3->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_vanne3->TabIndex = 27;
			// 
			// label12
			// 
			this->label12->CausesValidation = false;
			this->label12->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::PaleTurquoise;
			this->label12->Location = System::Drawing::Point(166, 196);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(80, 44);
			this->label12->TabIndex = 23;
			this->label12->Text = L"Bouton Pvc Base Fd";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_vanne2
			// 
			this->btn_vanne2->BackColor = System::Drawing::Color::Transparent;
			this->btn_vanne2->ButtonColor = System::Drawing::Color::Turquoise;
			this->btn_vanne2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_vanne2->Label = L"";
			this->btn_vanne2->Location = System::Drawing::Point(166, 114);
			this->btn_vanne2->Margin = System::Windows::Forms::Padding(2);
			this->btn_vanne2->Name = L"btn_vanne2";
			this->btn_vanne2->Renderer = nullptr;
			this->btn_vanne2->RepeatInterval = 100;
			this->btn_vanne2->RepeatState = false;
			this->btn_vanne2->Size = System::Drawing::Size(80, 80);
			this->btn_vanne2->StartRepeatInterval = 500;
			this->btn_vanne2->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->btn_vanne2->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->btn_vanne2->TabIndex = 22;
			this->btn_vanne2->Click += gcnew System::EventHandler(this, &MyForm::btn_vanne2_Click);
			// 
			// led_vanne2
			// 
			this->led_vanne2->BackColor = System::Drawing::Color::Transparent;
			this->led_vanne2->BlinkInterval = 500;
			this->led_vanne2->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_vanne2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->led_vanne2->Label = L"";
			this->led_vanne2->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_vanne2->LedColor = System::Drawing::Color::Red;
			this->led_vanne2->LedSize = System::Drawing::SizeF(20, 20);
			this->led_vanne2->Location = System::Drawing::Point(181, 60);
			this->led_vanne2->Margin = System::Windows::Forms::Padding(2);
			this->led_vanne2->Name = L"led_vanne2";
			this->led_vanne2->Renderer = nullptr;
			this->led_vanne2->Size = System::Drawing::Size(50, 50);
			this->led_vanne2->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_vanne2->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_vanne2->TabIndex = 24;
			// 
			// label11
			// 
			this->label11->CausesValidation = false;
			this->label11->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::PaleTurquoise;
			this->label11->Location = System::Drawing::Point(93, 196);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(59, 44);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Bouton Pvc Base";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::Control;
			this->label3->Location = System::Drawing::Point(9, 9);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(252, 26);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Vannes de Réservoirs";
			// 
			// btn_vanne1
			// 
			this->btn_vanne1->BackColor = System::Drawing::Color::Transparent;
			this->btn_vanne1->ButtonColor = System::Drawing::Color::Turquoise;
			this->btn_vanne1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_vanne1->Label = L"";
			this->btn_vanne1->Location = System::Drawing::Point(82, 114);
			this->btn_vanne1->Margin = System::Windows::Forms::Padding(2);
			this->btn_vanne1->Name = L"btn_vanne1";
			this->btn_vanne1->Renderer = nullptr;
			this->btn_vanne1->RepeatInterval = 100;
			this->btn_vanne1->RepeatState = false;
			this->btn_vanne1->Size = System::Drawing::Size(80, 80);
			this->btn_vanne1->StartRepeatInterval = 500;
			this->btn_vanne1->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->btn_vanne1->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->btn_vanne1->TabIndex = 19;
			this->btn_vanne1->Click += gcnew System::EventHandler(this, &MyForm::btn_vanne1_Click);
			// 
			// led_vanne1
			// 
			this->led_vanne1->BackColor = System::Drawing::Color::Transparent;
			this->led_vanne1->BlinkInterval = 500;
			this->led_vanne1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_vanne1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->led_vanne1->Label = L"";
			this->led_vanne1->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_vanne1->LedColor = System::Drawing::Color::Red;
			this->led_vanne1->LedSize = System::Drawing::SizeF(20, 20);
			this->led_vanne1->Location = System::Drawing::Point(97, 60);
			this->led_vanne1->Margin = System::Windows::Forms::Padding(2);
			this->led_vanne1->Name = L"led_vanne1";
			this->led_vanne1->Renderer = nullptr;
			this->led_vanne1->Size = System::Drawing::Size(50, 50);
			this->led_vanne1->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_vanne1->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_vanne1->TabIndex = 21;
			// 
			// panel_reservoirs
			// 
			this->panel_reservoirs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_reservoirs->Controls->Add(this->label4);
			this->panel_reservoirs->Controls->Add(this->led_CapteurR1);
			this->panel_reservoirs->Controls->Add(this->led_CapteurR3);
			this->panel_reservoirs->Controls->Add(this->led_CapteurR2);
			this->panel_reservoirs->Location = System::Drawing::Point(8, 277);
			this->panel_reservoirs->Margin = System::Windows::Forms::Padding(2);
			this->panel_reservoirs->Name = L"panel_reservoirs";
			this->panel_reservoirs->Size = System::Drawing::Size(417, 145);
			this->panel_reservoirs->TabIndex = 9;
			this->panel_reservoirs->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_reservoirs->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(9, 9);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(252, 26);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Capteurs des Réservoirs";
			// 
			// led_CapteurR1
			// 
			this->led_CapteurR1->BackColor = System::Drawing::Color::Transparent;
			this->led_CapteurR1->BlinkInterval = 500;
			this->led_CapteurR1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_CapteurR1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->led_CapteurR1->Label = L"Pvc Base";
			this->led_CapteurR1->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_CapteurR1->LedColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->led_CapteurR1->LedSize = System::Drawing::SizeF(60, 60);
			this->led_CapteurR1->Location = System::Drawing::Point(58, 37);
			this->led_CapteurR1->Margin = System::Windows::Forms::Padding(2);
			this->led_CapteurR1->Name = L"led_CapteurR1";
			this->led_CapteurR1->Renderer = nullptr;
			this->led_CapteurR1->Size = System::Drawing::Size(76, 91);
			this->led_CapteurR1->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_CapteurR1->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_CapteurR1->TabIndex = 19;
			// 
			// led_CapteurR3
			// 
			this->led_CapteurR3->BackColor = System::Drawing::Color::Transparent;
			this->led_CapteurR3->BlinkInterval = 500;
			this->led_CapteurR3->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_CapteurR3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->led_CapteurR3->Label = L"Lubrifiant";
			this->led_CapteurR3->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_CapteurR3->LedColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->led_CapteurR3->LedSize = System::Drawing::SizeF(60, 60);
			this->led_CapteurR3->Location = System::Drawing::Point(257, 37);
			this->led_CapteurR3->Margin = System::Windows::Forms::Padding(2);
			this->led_CapteurR3->Name = L"led_CapteurR3";
			this->led_CapteurR3->Renderer = nullptr;
			this->led_CapteurR3->Size = System::Drawing::Size(76, 91);
			this->led_CapteurR3->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_CapteurR3->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_CapteurR3->TabIndex = 21;
			// 
			// led_CapteurR2
			// 
			this->led_CapteurR2->BackColor = System::Drawing::Color::Transparent;
			this->led_CapteurR2->BlinkInterval = 500;
			this->led_CapteurR2->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_CapteurR2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->led_CapteurR2->Label = L"Plastifiant";
			this->led_CapteurR2->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_CapteurR2->LedColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->led_CapteurR2->LedSize = System::Drawing::SizeF(60, 60);
			this->led_CapteurR2->Location = System::Drawing::Point(157, 37);
			this->led_CapteurR2->Margin = System::Windows::Forms::Padding(2);
			this->led_CapteurR2->Name = L"led_CapteurR2";
			this->led_CapteurR2->Renderer = nullptr;
			this->led_CapteurR2->Size = System::Drawing::Size(76, 91);
			this->led_CapteurR2->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_CapteurR2->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_CapteurR2->TabIndex = 20;
			// 
			// panel_poids
			// 
			this->panel_poids->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_poids->Controls->Add(this->txt_Poids);
			this->panel_poids->Controls->Add(this->label5);
			this->panel_poids->Location = System::Drawing::Point(429, 353);
			this->panel_poids->Margin = System::Windows::Forms::Padding(2);
			this->panel_poids->Name = L"panel_poids";
			this->panel_poids->Size = System::Drawing::Size(261, 201);
			this->panel_poids->TabIndex = 10;
			this->panel_poids->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_poids->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// txt_Poids
			// 
			this->txt_Poids->CausesValidation = false;
			this->txt_Poids->Font = (gcnew System::Drawing::Font(L"Georgia", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Poids->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->txt_Poids->Location = System::Drawing::Point(7, 71);
			this->txt_Poids->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->txt_Poids->Name = L"txt_Poids";
			this->txt_Poids->Size = System::Drawing::Size(252, 61);
			this->txt_Poids->TabIndex = 7;
			this->txt_Poids->Text = L"658 g";
			this->txt_Poids->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::Control;
			this->label5->Location = System::Drawing::Point(9, 9);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(252, 26);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Poids";
			// 
			// panel_malaxeur
			// 
			this->panel_malaxeur->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_malaxeur->Controls->Add(this->label15);
			this->panel_malaxeur->Controls->Add(this->label6);
			this->panel_malaxeur->Controls->Add(this->btn_evacuation);
			this->panel_malaxeur->Controls->Add(this->btn_vidange);
			this->panel_malaxeur->Controls->Add(this->led_evacuation);
			this->panel_malaxeur->Controls->Add(this->led_malaxeur);
			this->panel_malaxeur->Controls->Add(this->label16);
			this->panel_malaxeur->Controls->Add(this->btn_malaxeur);
			this->panel_malaxeur->Controls->Add(this->label17);
			this->panel_malaxeur->Controls->Add(this->led_vidange);
			this->panel_malaxeur->Location = System::Drawing::Point(695, 353);
			this->panel_malaxeur->Margin = System::Windows::Forms::Padding(2);
			this->panel_malaxeur->Name = L"panel_malaxeur";
			this->panel_malaxeur->Size = System::Drawing::Size(283, 201);
			this->panel_malaxeur->TabIndex = 11;
			this->panel_malaxeur->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_malaxeur->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// label15
			// 
			this->label15->CausesValidation = false;
			this->label15->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::YellowGreen;
			this->label15->Location = System::Drawing::Point(181, 155);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(98, 44);
			this->label15->TabIndex = 38;
			this->label15->Text = L"Bouton Évacuation";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::Control;
			this->label6->Location = System::Drawing::Point(9, 9);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(252, 26);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Équipements du Malaxeur";
			// 
			// btn_evacuation
			// 
			this->btn_evacuation->BackColor = System::Drawing::Color::Transparent;
			this->btn_evacuation->ButtonColor = System::Drawing::Color::DarkGreen;
			this->btn_evacuation->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_evacuation->Label = L"";
			this->btn_evacuation->Location = System::Drawing::Point(189, 71);
			this->btn_evacuation->Margin = System::Windows::Forms::Padding(2);
			this->btn_evacuation->Name = L"btn_evacuation";
			this->btn_evacuation->Renderer = nullptr;
			this->btn_evacuation->RepeatInterval = 100;
			this->btn_evacuation->RepeatState = false;
			this->btn_evacuation->Size = System::Drawing::Size(80, 80);
			this->btn_evacuation->StartRepeatInterval = 500;
			this->btn_evacuation->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->btn_evacuation->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->btn_evacuation->TabIndex = 37;
			this->btn_evacuation->Click += gcnew System::EventHandler(this, &MyForm::btn_evacuation_Click);
			// 
			// btn_vidange
			// 
			this->btn_vidange->BackColor = System::Drawing::Color::Transparent;
			this->btn_vidange->ButtonColor = System::Drawing::Color::Lime;
			this->btn_vidange->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_vidange->Label = L"";
			this->btn_vidange->Location = System::Drawing::Point(105, 73);
			this->btn_vidange->Margin = System::Windows::Forms::Padding(2);
			this->btn_vidange->Name = L"btn_vidange";
			this->btn_vidange->Renderer = nullptr;
			this->btn_vidange->RepeatInterval = 100;
			this->btn_vidange->RepeatState = false;
			this->btn_vidange->Size = System::Drawing::Size(80, 80);
			this->btn_vidange->StartRepeatInterval = 500;
			this->btn_vidange->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->btn_vidange->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->btn_vidange->TabIndex = 34;
			this->btn_vidange->Click += gcnew System::EventHandler(this, &MyForm::btn_vidange_Click);
			// 
			// led_evacuation
			// 
			this->led_evacuation->BackColor = System::Drawing::Color::Transparent;
			this->led_evacuation->BlinkInterval = 500;
			this->led_evacuation->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_evacuation->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->led_evacuation->Label = L"";
			this->led_evacuation->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_evacuation->LedColor = System::Drawing::Color::Red;
			this->led_evacuation->LedSize = System::Drawing::SizeF(20, 20);
			this->led_evacuation->Location = System::Drawing::Point(204, 18);
			this->led_evacuation->Margin = System::Windows::Forms::Padding(2);
			this->led_evacuation->Name = L"led_evacuation";
			this->led_evacuation->Renderer = nullptr;
			this->led_evacuation->Size = System::Drawing::Size(50, 50);
			this->led_evacuation->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_evacuation->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_evacuation->TabIndex = 39;
			// 
			// led_malaxeur
			// 
			this->led_malaxeur->BackColor = System::Drawing::Color::Transparent;
			this->led_malaxeur->BlinkInterval = 500;
			this->led_malaxeur->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_malaxeur->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->led_malaxeur->Label = L"";
			this->led_malaxeur->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_malaxeur->LedColor = System::Drawing::Color::Red;
			this->led_malaxeur->LedSize = System::Drawing::SizeF(20, 20);
			this->led_malaxeur->Location = System::Drawing::Point(37, 18);
			this->led_malaxeur->Margin = System::Windows::Forms::Padding(2);
			this->led_malaxeur->Name = L"led_malaxeur";
			this->led_malaxeur->Renderer = nullptr;
			this->led_malaxeur->Size = System::Drawing::Size(50, 50);
			this->led_malaxeur->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_malaxeur->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_malaxeur->TabIndex = 33;
			// 
			// label16
			// 
			this->label16->CausesValidation = false;
			this->label16->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::YellowGreen;
			this->label16->Location = System::Drawing::Point(105, 155);
			this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(80, 44);
			this->label16->TabIndex = 35;
			this->label16->Text = L"Bouton Vidange";
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_malaxeur
			// 
			this->btn_malaxeur->BackColor = System::Drawing::Color::Transparent;
			this->btn_malaxeur->ButtonColor = System::Drawing::Color::Silver;
			this->btn_malaxeur->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_malaxeur->Label = L"";
			this->btn_malaxeur->Location = System::Drawing::Point(21, 73);
			this->btn_malaxeur->Margin = System::Windows::Forms::Padding(2);
			this->btn_malaxeur->Name = L"btn_malaxeur";
			this->btn_malaxeur->Renderer = nullptr;
			this->btn_malaxeur->RepeatInterval = 100;
			this->btn_malaxeur->RepeatState = false;
			this->btn_malaxeur->Size = System::Drawing::Size(80, 80);
			this->btn_malaxeur->StartRepeatInterval = 500;
			this->btn_malaxeur->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->btn_malaxeur->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->btn_malaxeur->TabIndex = 31;
			this->btn_malaxeur->Click += gcnew System::EventHandler(this, &MyForm::btn_malaxeur_Click);
			// 
			// label17
			// 
			this->label17->CausesValidation = false;
			this->label17->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::YellowGreen;
			this->label17->Location = System::Drawing::Point(21, 155);
			this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(80, 44);
			this->label17->TabIndex = 32;
			this->label17->Text = L"Bouton Malaxeur";
			this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// led_vidange
			// 
			this->led_vidange->BackColor = System::Drawing::Color::Transparent;
			this->led_vidange->BlinkInterval = 500;
			this->led_vidange->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_vidange->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->led_vidange->Label = L"";
			this->led_vidange->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_vidange->LedColor = System::Drawing::Color::Red;
			this->led_vidange->LedSize = System::Drawing::SizeF(20, 20);
			this->led_vidange->Location = System::Drawing::Point(121, 18);
			this->led_vidange->Margin = System::Windows::Forms::Padding(2);
			this->led_vidange->Name = L"led_vidange";
			this->led_vidange->Renderer = nullptr;
			this->led_vidange->Size = System::Drawing::Size(50, 50);
			this->led_vidange->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_vidange->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_vidange->TabIndex = 36;
			// 
			// panel_cuve
			// 
			this->panel_cuve->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->panel_cuve->Controls->Add(this->led_CapteurBas);
			this->panel_cuve->Controls->Add(this->label7);
			this->panel_cuve->Controls->Add(this->led_CapteurHaut);
			this->panel_cuve->Location = System::Drawing::Point(8, 426);
			this->panel_cuve->Margin = System::Windows::Forms::Padding(2);
			this->panel_cuve->Name = L"panel_cuve";
			this->panel_cuve->Size = System::Drawing::Size(417, 129);
			this->panel_cuve->TabIndex = 10;
			this->panel_cuve->MouseEnter += gcnew System::EventHandler(this, &MyForm::panelEnter);
			this->panel_cuve->MouseLeave += gcnew System::EventHandler(this, &MyForm::panelExit);
			// 
			// led_CapteurBas
			// 
			this->led_CapteurBas->BackColor = System::Drawing::Color::Transparent;
			this->led_CapteurBas->BlinkInterval = 500;
			this->led_CapteurBas->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_CapteurBas->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->led_CapteurBas->Label = L"Capteur Bas";
			this->led_CapteurBas->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_CapteurBas->LedColor = System::Drawing::Color::Yellow;
			this->led_CapteurBas->LedSize = System::Drawing::SizeF(60, 60);
			this->led_CapteurBas->Location = System::Drawing::Point(91, 29);
			this->led_CapteurBas->Margin = System::Windows::Forms::Padding(2);
			this->led_CapteurBas->Name = L"led_CapteurBas";
			this->led_CapteurBas->Renderer = nullptr;
			this->led_CapteurBas->Size = System::Drawing::Size(101, 91);
			this->led_CapteurBas->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_CapteurBas->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_CapteurBas->TabIndex = 22;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::Control;
			this->label7->Location = System::Drawing::Point(9, 9);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(406, 26);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Capteurs de la Cuve de Refroidissement";
			// 
			// led_CapteurHaut
			// 
			this->led_CapteurHaut->BackColor = System::Drawing::Color::Transparent;
			this->led_CapteurHaut->BlinkInterval = 500;
			this->led_CapteurHaut->Font = (gcnew System::Drawing::Font(L"Poor Richard", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->led_CapteurHaut->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->led_CapteurHaut->Label = L"Capteur Haut";
			this->led_CapteurHaut->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->led_CapteurHaut->LedColor = System::Drawing::Color::Yellow;
			this->led_CapteurHaut->LedSize = System::Drawing::SizeF(60, 60);
			this->led_CapteurHaut->Location = System::Drawing::Point(196, 29);
			this->led_CapteurHaut->Margin = System::Windows::Forms::Padding(2);
			this->led_CapteurHaut->Name = L"led_CapteurHaut";
			this->led_CapteurHaut->Renderer = nullptr;
			this->led_CapteurHaut->Size = System::Drawing::Size(122, 91);
			this->led_CapteurHaut->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->led_CapteurHaut->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->led_CapteurHaut->TabIndex = 23;
			// 
			// btn_Fermer
			// 
			this->btn_Fermer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_Fermer->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_Fermer->Font = (gcnew System::Drawing::Font(L"Poor Richard", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Fermer->ForeColor = System::Drawing::SystemColors::Control;
			this->btn_Fermer->Location = System::Drawing::Point(876, 12);
			this->btn_Fermer->Margin = System::Windows::Forms::Padding(2);
			this->btn_Fermer->Name = L"btn_Fermer";
			this->btn_Fermer->Size = System::Drawing::Size(101, 44);
			this->btn_Fermer->TabIndex = 12;
			this->btn_Fermer->Text = L"Fermer";
			this->btn_Fermer->UseVisualStyleBackColor = false;
			this->btn_Fermer->Click += gcnew System::EventHandler(this, &MyForm::btn_Fermer_Click);
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 50;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(985, 563);
			this->Controls->Add(this->btn_Fermer);
			this->Controls->Add(this->panel_cuve);
			this->Controls->Add(this->panel_malaxeur);
			this->Controls->Add(this->panel_poids);
			this->Controls->Add(this->panel_reservoirs);
			this->Controls->Add(this->panel_Vannes);
			this->Controls->Add(this->panel_Commandes);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox3);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
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


		void MajEntreeUI()
		{
			int poids = pignat->getPoids();
			txt_Poids->Text = poids.ToString() + " g";

			pignat->getCapteurBasR1() ? led_CapteurR1->State = LBLed::LedState::On : led_CapteurR1->State = LBLed::LedState::Off;
			pignat->getCapteurBasR2() ? led_CapteurR2->State = LBLed::LedState::On : led_CapteurR2->State = LBLed::LedState::Off;
			pignat->getCapteurBasR3() ? led_CapteurR3->State = LBLed::LedState::On : led_CapteurR3->State = LBLed::LedState::Off;

			pignat->getCapteurNiveauBas() ? led_CapteurBas->State = LBLed::LedState::On : led_CapteurBas->State = LBLed::LedState::Off;
			pignat->getCapteurNiveauHaut() ? led_CapteurHaut->State = LBLed::LedState::On : led_CapteurHaut->State = LBLed::LedState::Off;

			pignat->getMarche() ? led_Marche->State = LBLed::LedState::On : led_Marche->State = LBLed::LedState::Off;
			pignat->getArret() ? led_Arret->State = LBLed::LedState::On : led_Arret->State = LBLed::LedState::Off;


			if (!pignat->getManuelAuto())
			{
				meter_AutoManuel->Value = 1;
				txt_ManuelAuto->Text = "Mode Auto";
			}
			else
			{
				meter_AutoManuel->Value = 2;
				txt_ManuelAuto->Text = "Mode Manuel";
			}

		}




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

	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		pignat->lireEntrees();
		MajEntreeUI();
		pignat->majSorties();
	}

	private: System::Void btn_Fermer_Click(System::Object^ sender, System::EventArgs^ e) {
		pignat->fermerEsMelangeur();
		Application::Exit();
	}


	private: System::Void btn_Voyant_Click(System::Object^ sender, System::EventArgs^ e) {

		voyantRouge = !voyantRouge;
		voyantRouge ? led_Voyant->State = LBLed::LedState::On : led_Voyant->State = LBLed::LedState::Off;
		pignat->setVoyantRouge(voyantRouge);
	}
	private: System::Void btn_vanne1_Click(System::Object^ sender, System::EventArgs^ e) {
		vanne1 = !vanne1;
		vanne1 ? led_vanne1->State = LBLed::LedState::On : led_vanne1->State = LBLed::LedState::Off;
		pignat->setVannePVCBase(vanne1);
	}
	private: System::Void btn_vanne2_Click(System::Object^ sender, System::EventArgs^ e) {
		vanne2 = !vanne2;
		vanne2 ? led_vanne2->State = LBLed::LedState::On : led_vanne2->State = LBLed::LedState::Off;
		pignat->setVannePVCBaseFD(vanne2);
	}
	private: System::Void btn_vanne3_Click(System::Object^ sender, System::EventArgs^ e) {
		vanne3 = !vanne3;
		vanne3 ? led_vanne3->State = LBLed::LedState::On : led_vanne3->State = LBLed::LedState::Off;
		pignat->setVannePlastifiant(vanne3);
	}
	private: System::Void btn_vanne4_Click(System::Object^ sender, System::EventArgs^ e) {
		vanne4 = !vanne4;
		vanne4 ? led_vanne4->State = LBLed::LedState::On : led_vanne4->State = LBLed::LedState::Off;
		pignat->setVanneLubrifiant(vanne4);
	}
	private: System::Void btn_malaxeur_Click(System::Object^ sender, System::EventArgs^ e) {
		malaxeur = !malaxeur;
		malaxeur ? led_malaxeur->State = LBLed::LedState::On : led_malaxeur->State = LBLed::LedState::Off;
		pignat->setMalaxeur(malaxeur);
	}
	private: System::Void btn_vidange_Click(System::Object^ sender, System::EventArgs^ e) {
		vidange = !vidange;
		vidange ? led_vidange->State = LBLed::LedState::On : led_vidange->State = LBLed::LedState::Off;
		pignat->setVanneVidange(vidange);
	}
	private: System::Void btn_evacuation_Click(System::Object^ sender, System::EventArgs^ e) {
		evacuation = !evacuation;
		evacuation ? led_evacuation->State = LBLed::LedState::On : led_evacuation->State = LBLed::LedState::Off;
		pignat->setEvacuation(evacuation);
	}

};
}
