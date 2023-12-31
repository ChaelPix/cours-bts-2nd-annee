#pragma once

#include "BdDPVC.h"
#include "Personnel.h"
#include "OrdreFabrication.h"
#include "EsMelangeur.h"
#include <msclr/marshal.h>
#include <Windows.h>
#include <thread>
namespace Winforms_PignatFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Description r�sum�e de AppCore
	/// </summary>
	public ref class AppCore : public System::Windows::Forms::Form
	{
		CEsMelangeur^ pignat = gcnew CEsMelangeur;
		System::Windows::Forms::Form^ parentForm;

		CPersonnel* operateur;

	private: System::Windows::Forms::Timer^ pignatUpdateTimer;
	private: System::Windows::Forms::Timer^ finCycleTimer;
	private: System::Windows::Forms::Label^ txt_tousOrdresOk;


		   bool isOn = false;
	public:
		AppCore(System::Windows::Forms::Form^ parentForm, CPersonnel* operateur)
		{
			this->parentForm = parentForm;

			this->operateur = operateur;
			InitializeComponent();
			bdd->connecter();
			InitPignat();
			InitbackgroundImages();
			table_InfosOF->Visible = false;
			txt_InfosOF->Visible = false;
			btn_lancerFabrication->Visible = false;
			UpdateREFOF();
			isOn = true;

			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AppCore::OnFormClosed);
		}
#pragma region OSEF
	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~AppCore()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pignatImg;
	private: System::Windows::Forms::Label^ txt_OF;


	private: System::Windows::Forms::ListBox^ listOF;


	private: System::Windows::Forms::Timer^ BackgroundTimer;
	private: System::Windows::Forms::Timer^ AnimTimer;
	private: System::Windows::Forms::Label^ txt_InfosOF;


	private: System::Windows::Forms::PictureBox^ pictureBox1;



	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ backgroundImage;
	private: System::Windows::Forms::Button^ btn_lancerFabrication;

	private: System::Windows::Forms::Button^ btn_deconnexion;
	private: System::Windows::Forms::TableLayoutPanel^ table_InfosOF;





	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ txt_quantiteLubrifiant;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ txt_quantitePVC;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ txt_tempsRefroidissement;

	private: System::Windows::Forms::Label^ txt_tempsMelange;

	private: System::Windows::Forms::Label^ txt_quantitePlastifiant;
	private: System::Windows::Forms::Label^ txt_deconnecter;


	private: System::Windows::Forms::Timer^ OfUpdateTimer;


	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AppCore::typeid));
			this->pignatImg = (gcnew System::Windows::Forms::PictureBox());
			this->txt_OF = (gcnew System::Windows::Forms::Label());
			this->listOF = (gcnew System::Windows::Forms::ListBox());
			this->BackgroundTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->AnimTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->txt_InfosOF = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->backgroundImage = (gcnew System::Windows::Forms::PictureBox());
			this->btn_lancerFabrication = (gcnew System::Windows::Forms::Button());
			this->btn_deconnexion = (gcnew System::Windows::Forms::Button());
			this->table_InfosOF = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->txt_tempsRefroidissement = (gcnew System::Windows::Forms::Label());
			this->txt_tempsMelange = (gcnew System::Windows::Forms::Label());
			this->txt_quantitePlastifiant = (gcnew System::Windows::Forms::Label());
			this->txt_quantiteLubrifiant = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txt_quantitePVC = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txt_deconnecter = (gcnew System::Windows::Forms::Label());
			this->OfUpdateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->pignatUpdateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->finCycleTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->txt_tousOrdresOk = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pignatImg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundImage))->BeginInit();
			this->table_InfosOF->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pignatImg
			// 
			this->pignatImg->BackColor = System::Drawing::Color::Transparent;
			this->pignatImg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pignatImg.Image")));
			this->pignatImg->Location = System::Drawing::Point(143, 20);
			this->pignatImg->Margin = System::Windows::Forms::Padding(2);
			this->pignatImg->Name = L"pignatImg";
			this->pignatImg->Size = System::Drawing::Size(297, 57);
			this->pignatImg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pignatImg->TabIndex = 4;
			this->pignatImg->TabStop = false;
			this->pignatImg->MouseEnter += gcnew System::EventHandler(this, &AppCore::Control_MouseEnter);
			this->pignatImg->MouseLeave += gcnew System::EventHandler(this, &AppCore::Control_MouseLeave);
			// 
			// txt_OF
			// 
			this->txt_OF->BackColor = System::Drawing::Color::Transparent;
			this->txt_OF->Font = (gcnew System::Drawing::Font(L"Cambria", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_OF->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->txt_OF->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->txt_OF->Location = System::Drawing::Point(198, 96);
			this->txt_OF->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->txt_OF->Name = L"txt_OF";
			this->txt_OF->Size = System::Drawing::Size(279, 49);
			this->txt_OF->TabIndex = 8;
			this->txt_OF->Text = L"Ordres de Fabrication :";
			this->txt_OF->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// listOF
			// 
			this->listOF->BackColor = System::Drawing::Color::WhiteSmoke;
			this->listOF->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listOF->FormattingEnabled = true;
			this->listOF->ItemHeight = 19;
			this->listOF->Location = System::Drawing::Point(218, 138);
			this->listOF->Margin = System::Windows::Forms::Padding(2);
			this->listOF->Name = L"listOF";
			this->listOF->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listOF->Size = System::Drawing::Size(275, 99);
			this->listOF->TabIndex = 9;
			this->listOF->SelectedIndexChanged += gcnew System::EventHandler(this, &AppCore::listOF_SelectedIndexChanged);
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
			// txt_InfosOF
			// 
			this->txt_InfosOF->BackColor = System::Drawing::Color::Transparent;
			this->txt_InfosOF->Font = (gcnew System::Drawing::Font(L"Cambria", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_InfosOF->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->txt_InfosOF->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->txt_InfosOF->Location = System::Drawing::Point(212, 326);
			this->txt_InfosOF->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->txt_InfosOF->Name = L"txt_InfosOF";
			this->txt_InfosOF->Size = System::Drawing::Size(430, 86);
			this->txt_InfosOF->TabIndex = 11;
			this->txt_InfosOF->Text = L"Infos de $REF_OF_X ($TYPE) :";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(5, 42);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->MaximumSize = System::Drawing::Size(33, 32);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(33, 30);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(5, 79);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox5->MaximumSize = System::Drawing::Size(33, 32);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(33, 30);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 4;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(5, 5);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox4->MaximumSize = System::Drawing::Size(33, 32);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(33, 30);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// backgroundImage
			// 
			this->backgroundImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->backgroundImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backgroundImage.Image")));
			this->backgroundImage->Location = System::Drawing::Point(-1, 0);
			this->backgroundImage->Name = L"backgroundImage";
			this->backgroundImage->Size = System::Drawing::Size(1233, 701);
			this->backgroundImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->backgroundImage->TabIndex = 10;
			this->backgroundImage->TabStop = false;
			// 
			// btn_lancerFabrication
			// 
			this->btn_lancerFabrication->BackColor = System::Drawing::SystemColors::Window;
			this->btn_lancerFabrication->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_lancerFabrication->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_lancerFabrication->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_lancerFabrication->Location = System::Drawing::Point(370, 556);
			this->btn_lancerFabrication->Margin = System::Windows::Forms::Padding(2);
			this->btn_lancerFabrication->Name = L"btn_lancerFabrication";
			this->btn_lancerFabrication->Size = System::Drawing::Size(151, 36);
			this->btn_lancerFabrication->TabIndex = 13;
			this->btn_lancerFabrication->Text = L"Lancer Fabrication";
			this->btn_lancerFabrication->UseVisualStyleBackColor = false;
			this->btn_lancerFabrication->Click += gcnew System::EventHandler(this, &AppCore::LancerCycle);
			this->btn_lancerFabrication->MouseEnter += gcnew System::EventHandler(this, &AppCore::Control_MouseEnter);
			this->btn_lancerFabrication->MouseLeave += gcnew System::EventHandler(this, &AppCore::Control_MouseLeave);
			// 
			// btn_deconnexion
			// 
			this->btn_deconnexion->BackColor = System::Drawing::Color::Transparent;
			this->btn_deconnexion->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_deconnexion.BackgroundImage")));
			this->btn_deconnexion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_deconnexion->FlatAppearance->BorderSize = 0;
			this->btn_deconnexion->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_deconnexion->Font = (gcnew System::Drawing::Font(L"Cambria", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_deconnexion->ForeColor = System::Drawing::Color::Transparent;
			this->btn_deconnexion->Location = System::Drawing::Point(251, 618);
			this->btn_deconnexion->Margin = System::Windows::Forms::Padding(2);
			this->btn_deconnexion->Name = L"btn_deconnexion";
			this->btn_deconnexion->Size = System::Drawing::Size(45, 43);
			this->btn_deconnexion->TabIndex = 14;
			this->btn_deconnexion->UseVisualStyleBackColor = false;
			this->btn_deconnexion->Click += gcnew System::EventHandler(this, &AppCore::btn_deconnexion_Click);
			this->btn_deconnexion->MouseEnter += gcnew System::EventHandler(this, &AppCore::Control_MouseEnter);
			this->btn_deconnexion->MouseLeave += gcnew System::EventHandler(this, &AppCore::Control_MouseLeave);
			// 
			// table_InfosOF
			// 
			this->table_InfosOF->BackColor = System::Drawing::Color::WhiteSmoke;
			this->table_InfosOF->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::OutsetDouble;
			this->table_InfosOF->ColumnCount = 4;
			this->table_InfosOF->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10.13299F)));
			this->table_InfosOF->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				52.63158F)));
			this->table_InfosOF->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				21.80451F)));
			this->table_InfosOF->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.28571F)));
			this->table_InfosOF->Controls->Add(this->txt_tempsRefroidissement, 2, 4);
			this->table_InfosOF->Controls->Add(this->txt_tempsMelange, 2, 3);
			this->table_InfosOF->Controls->Add(this->txt_quantitePlastifiant, 2, 2);
			this->table_InfosOF->Controls->Add(this->txt_quantiteLubrifiant, 2, 1);
			this->table_InfosOF->Controls->Add(this->label9, 3, 0);
			this->table_InfosOF->Controls->Add(this->txt_quantitePVC, 2, 0);
			this->table_InfosOF->Controls->Add(this->pictureBox5, 0, 2);
			this->table_InfosOF->Controls->Add(this->pictureBox4, 0, 0);
			this->table_InfosOF->Controls->Add(this->pictureBox1, 0, 1);
			this->table_InfosOF->Controls->Add(this->pictureBox2, 0, 3);
			this->table_InfosOF->Controls->Add(this->pictureBox3, 0, 4);
			this->table_InfosOF->Controls->Add(this->label3, 1, 0);
			this->table_InfosOF->Controls->Add(this->label4, 1, 1);
			this->table_InfosOF->Controls->Add(this->label5, 1, 2);
			this->table_InfosOF->Controls->Add(this->label6, 1, 3);
			this->table_InfosOF->Controls->Add(this->label7, 1, 4);
			this->table_InfosOF->Controls->Add(this->label10, 3, 1);
			this->table_InfosOF->Controls->Add(this->label11, 3, 2);
			this->table_InfosOF->Controls->Add(this->label12, 3, 3);
			this->table_InfosOF->Controls->Add(this->label13, 3, 4);
			this->table_InfosOF->Location = System::Drawing::Point(235, 360);
			this->table_InfosOF->Margin = System::Windows::Forms::Padding(2);
			this->table_InfosOF->Name = L"table_InfosOF";
			this->table_InfosOF->RowCount = 5;
			this->table_InfosOF->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20.00001F)));
			this->table_InfosOF->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->table_InfosOF->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->table_InfosOF->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->table_InfosOF->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->table_InfosOF->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->table_InfosOF->Size = System::Drawing::Size(407, 192);
			this->table_InfosOF->TabIndex = 15;
			// 
			// txt_tempsRefroidissement
			// 
			this->txt_tempsRefroidissement->Font = (gcnew System::Drawing::Font(L"Cambria", 15.25F, System::Drawing::FontStyle::Bold));
			this->txt_tempsRefroidissement->Location = System::Drawing::Point(260, 151);
			this->txt_tempsRefroidissement->Name = L"txt_tempsRefroidissement";
			this->txt_tempsRefroidissement->Size = System::Drawing::Size(80, 32);
			this->txt_tempsRefroidissement->TabIndex = 21;
			this->txt_tempsRefroidissement->Text = L"00";
			this->txt_tempsRefroidissement->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_tempsMelange
			// 
			this->txt_tempsMelange->Font = (gcnew System::Drawing::Font(L"Cambria", 15.25F, System::Drawing::FontStyle::Bold));
			this->txt_tempsMelange->Location = System::Drawing::Point(260, 114);
			this->txt_tempsMelange->Name = L"txt_tempsMelange";
			this->txt_tempsMelange->Size = System::Drawing::Size(80, 32);
			this->txt_tempsMelange->TabIndex = 20;
			this->txt_tempsMelange->Text = L"00";
			this->txt_tempsMelange->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_quantitePlastifiant
			// 
			this->txt_quantitePlastifiant->Font = (gcnew System::Drawing::Font(L"Cambria", 15.25F, System::Drawing::FontStyle::Bold));
			this->txt_quantitePlastifiant->Location = System::Drawing::Point(260, 77);
			this->txt_quantitePlastifiant->Name = L"txt_quantitePlastifiant";
			this->txt_quantitePlastifiant->Size = System::Drawing::Size(80, 32);
			this->txt_quantitePlastifiant->TabIndex = 19;
			this->txt_quantitePlastifiant->Text = L"000";
			this->txt_quantitePlastifiant->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_quantiteLubrifiant
			// 
			this->txt_quantiteLubrifiant->Font = (gcnew System::Drawing::Font(L"Cambria", 15.25F, System::Drawing::FontStyle::Bold));
			this->txt_quantiteLubrifiant->Location = System::Drawing::Point(260, 40);
			this->txt_quantiteLubrifiant->Name = L"txt_quantiteLubrifiant";
			this->txt_quantiteLubrifiant->Size = System::Drawing::Size(80, 32);
			this->txt_quantiteLubrifiant->TabIndex = 18;
			this->txt_quantiteLubrifiant->Text = L"000";
			this->txt_quantiteLubrifiant->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label9
			// 
			this->label9->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(349, 3);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(33, 32);
			this->label9->TabIndex = 13;
			this->label9->Text = L"g";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_quantitePVC
			// 
			this->txt_quantitePVC->Font = (gcnew System::Drawing::Font(L"Cambria", 15.25F, System::Drawing::FontStyle::Bold));
			this->txt_quantitePVC->Location = System::Drawing::Point(260, 3);
			this->txt_quantitePVC->Name = L"txt_quantitePVC";
			this->txt_quantitePVC->Size = System::Drawing::Size(80, 32);
			this->txt_quantitePVC->TabIndex = 12;
			this->txt_quantitePVC->Text = L"000";
			this->txt_quantitePVC->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(5, 116);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->MaximumSize = System::Drawing::Size(33, 32);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(33, 30);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(5, 153);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox3->MaximumSize = System::Drawing::Size(33, 32);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(33, 32);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(49, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 32);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Base PVC";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(49, 40);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 32);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Lubrifiant";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(49, 77);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 32);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Plastifiant";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(49, 114);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(156, 32);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Temps M�lange";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F));
			this->label7->Location = System::Drawing::Point(49, 151);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(202, 32);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Temps Refroidissement";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label10
			// 
			this->label10->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(349, 40);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(33, 32);
			this->label10->TabIndex = 14;
			this->label10->Text = L"g";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label11
			// 
			this->label11->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(349, 77);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(33, 32);
			this->label11->TabIndex = 15;
			this->label11->Text = L"g";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(349, 114);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(33, 32);
			this->label12->TabIndex = 16;
			this->label12->Text = L"s";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(349, 151);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(33, 32);
			this->label13->TabIndex = 17;
			this->label13->Text = L"s";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_deconnecter
			// 
			this->txt_deconnecter->Font = (gcnew System::Drawing::Font(L"Cambria", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_deconnecter->Location = System::Drawing::Point(227, 644);
			this->txt_deconnecter->Name = L"txt_deconnecter";
			this->txt_deconnecter->Size = System::Drawing::Size(96, 32);
			this->txt_deconnecter->TabIndex = 16;
			this->txt_deconnecter->Text = L"se d�connecter";
			this->txt_deconnecter->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// OfUpdateTimer
			// 
			this->OfUpdateTimer->Enabled = true;
			this->OfUpdateTimer->Interval = 5000;
			this->OfUpdateTimer->Tick += gcnew System::EventHandler(this, &AppCore::OfUpdateTimer_Tick);
			// 
			// pignatUpdateTimer
			// 
			this->pignatUpdateTimer->Interval = 1;
			this->pignatUpdateTimer->Tick += gcnew System::EventHandler(this, &AppCore::majCycleFabrication);
			// 
			// finCycleTimer
			// 
			this->finCycleTimer->Interval = 3500;
			this->finCycleTimer->Tick += gcnew System::EventHandler(this, &AppCore::finCycleTimer_Tick);
			// 
			// txt_tousOrdresOk
			// 
			this->txt_tousOrdresOk->BackColor = System::Drawing::Color::Transparent;
			this->txt_tousOrdresOk->Font = (gcnew System::Drawing::Font(L"Cambria", 10));
			this->txt_tousOrdresOk->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->txt_tousOrdresOk->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->txt_tousOrdresOk->Location = System::Drawing::Point(251, 239);
			this->txt_tousOrdresOk->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->txt_tousOrdresOk->Name = L"txt_tousOrdresOk";
			this->txt_tousOrdresOk->Size = System::Drawing::Size(242, 27);
			this->txt_tousOrdresOk->TabIndex = 17;
			this->txt_tousOrdresOk->Text = L"Tous les ordres sont trait�s !";
			this->txt_tousOrdresOk->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->txt_tousOrdresOk->Visible = false;
			// 
			// AppCore
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1218, 685);
			this->ControlBox = false;
			this->Controls->Add(this->txt_tousOrdresOk);
			this->Controls->Add(this->btn_deconnexion);
			this->Controls->Add(this->txt_deconnecter);
			this->Controls->Add(this->table_InfosOF);
			this->Controls->Add(this->btn_lancerFabrication);
			this->Controls->Add(this->txt_InfosOF);
			this->Controls->Add(this->listOF);
			this->Controls->Add(this->txt_OF);
			this->Controls->Add(this->pignatImg);
			this->Controls->Add(this->backgroundImage);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AppCore";
			this->Text = L"Panneau des Ordres de Fabrication";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pignatImg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundImage))->EndInit();
			this->table_InfosOF->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		std::string ConvertStringToStdString(String^ input)
		{
			msclr::interop::marshal_context context;
			const char* converted = context.marshal_as<const char*>(input);
			std::string result(converted);
			return result;
		}

		

		void InitPignat()
		{
			pignat->initEsMelangeur();
			pignat->majSorties();
		}

		/*---------------Code BDD-------------------*/
		CBdDPVC^ bdd = gcnew CBdDPVC;
		void UpdateREFOF()
		{		
			std::vector<std::string> listeOf_std = bdd->getReferencesOFaTraiter();
			int selectedIndex = listOF->SelectedIndex; // Stockez l'index s�lectionn�
			listOF->Items->Clear();

			for (int i = 0; i < listeOf_std.size(); i++)
			{
				listOF->Items->Add(gcnew String(listeOf_std.at(i).c_str()));
			}

			if (selectedIndex >= 0 && selectedIndex < listOF->Items->Count)
			{
				listOF->SelectedIndex = selectedIndex;
			}
			else
			{
				table_InfosOF->Visible = false;
				txt_InfosOF->Visible = false;
				btn_lancerFabrication->Visible = false;
				listOF->SelectedIndex = -1;
			}
				

			txt_tousOrdresOk->Visible = listOF->Items->Count == 0;
		}
		COrdreFabrication* ordreFabrication;

		private: System::Void listOF_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

			if (listOF->SelectedIndex < 0 || listOF->SelectedIndex >= listOF->Items->Count)
				return;

			String^ refOf = listOF->SelectedItem->ToString();
			std::string refOf_string = ConvertStringToStdString(refOf);


			COrdreFabrication of = bdd->getOrdreFabrication(refOf_string);
			
			ordreFabrication = new COrdreFabrication(of);

			CFormule formule = of.getFormule();

			String^ type = gcnew String(formule.getType().c_str());
			txt_InfosOF->Text = "Infos de " + refOf + " (" + type + ")";

			double quantite = of.getQuantite();
			txt_quantitePVC->Text = "" + quantite * (formule.getPvcBase() );
			txt_quantiteLubrifiant->Text = "" + quantite * (formule.getLubrifiant());
			txt_quantitePlastifiant->Text = "" + quantite * (formule.getPlastifiant());

			txt_tempsMelange->Text = "" + formule.getDureeMalaxage();
			txt_tempsRefroidissement->Text = "" + formule.getDureeRefroidissement();

			table_InfosOF->Visible = true;
			txt_InfosOF->Visible = true;
			btn_lancerFabrication->Visible = true;
		}


			   /*---------------Gestion CYCLE-------------------*/
		enum class Etats { AttenteMarche, VersementPvc, VersementPlastifiant, VersementLubrifiant, Malaxage, Vidange, Refroidissement, Evacuation, Fin };
		Etats nEtat = Etats::AttenteMarche;
		int duree_refroid = 0;
		int duree_malax = 0;
		int differenceToDisablePvcFd = 10;
		bool running = false;
		float masse_pvc_base, masse_plastifiant, masse_lubrifiant, temps_malaxage, temps_refroidissement;

		System::Void LancerCycle(System::Object^ sender, System::EventArgs^ e)
		{
			ShowHideMenu(false);

			Single::TryParse(txt_quantitePVC->Text, masse_pvc_base);
			Single::TryParse(txt_quantiteLubrifiant->Text, masse_lubrifiant);
			Single::TryParse(txt_quantitePlastifiant->Text, masse_plastifiant);

			temps_malaxage = System::Int32::Parse(txt_tempsMelange->Text);
			temps_refroidissement = System::Int32::Parse(txt_tempsRefroidissement->Text);

			nEtat = Etats::AttenteMarche;
			running = true;
			pignatUpdateTimer->Enabled = true;
			OfUpdateTimer->Enabled = false;

			bdd->majEtatEnCours(*ordreFabrication, *operateur);
		}

		System::Void majCycleFabrication(System::Object^ sender, System::EventArgs^ e)
		{
			pignat->lireEntrees();

			switch (nEtat) {
			case Etats::AttenteMarche:
				txt_InfosOF->Text = "Attente Bouton Marche...";

				if (pignat->getMarche())
				{
					pignat->setVoyantRouge(true);
					nEtat = Etats::VersementPvc;
				}
				break;

			case Etats::VersementPvc:
				txt_InfosOF->Text = "Versement Pvc : \n   " + pignat->getPoids() + " / " + masse_pvc_base + "g";

				if ((pignat->getPoids() >= masse_pvc_base))
					nEtat = Etats::VersementPlastifiant;

				break;

			case Etats::VersementPlastifiant:
				txt_InfosOF->Text = "Versement Plastifiant : \n   " + pignat->getPoids() + " / " + (masse_pvc_base + masse_plastifiant) + "g";

				if (pignat->getPoids() >= masse_pvc_base + masse_plastifiant)
					nEtat = Etats::VersementLubrifiant;

				break;

			case Etats::VersementLubrifiant:
				txt_InfosOF->Text = "Versement Lubrifiant : \n   " + pignat->getPoids() + " / " + (masse_pvc_base + masse_plastifiant + masse_lubrifiant) + "g";

				if (pignat->getPoids() >= masse_pvc_base + masse_plastifiant + masse_lubrifiant)
				{
					nEtat = Etats::Malaxage;
					pignatUpdateTimer->Interval = 1000;
				}
				break;

			case Etats::Malaxage:
				txt_InfosOF->Text = "Malaxage : \n   " + duree_malax + " / " + temps_malaxage + "s";

				if (duree_malax >= temps_malaxage)
				{
					nEtat = Etats::Vidange;
					pignatUpdateTimer->Interval = 1;
				}
				
				break;

			case Etats::Vidange:
				txt_InfosOF->Text = "Vidange : \n   Poids Restant : " + pignat->getPoids() + "g";
				
				if (pignat->getPoids() <= 20)
				{
					nEtat = Etats::Refroidissement;
					pignatUpdateTimer->Interval = 1000;
				}
				break;

			case Etats::Refroidissement:
				txt_InfosOF->Text = "Refroidissement : \n   " + duree_refroid + " / " + temps_refroidissement + "s";
				
				if (duree_refroid >= temps_refroidissement)
				{
					nEtat = Etats::Evacuation; 
					pignatUpdateTimer->Interval = 1;
				}
				
				break;

			case Etats::Evacuation:
				txt_InfosOF->Text = "Evacuation du bac...";

				if (!pignat->getCapteurNiveauBas())
				{
					nEtat = Etats::Fin;
				}
				
				break;

			case Etats::Fin:
				txt_InfosOF->Text = "Fin !";
				finCycleTimer->Enabled = true;

			default:
				running = false;
			}

			if (!pignat->getArret())
			{
				nEtat = Etats::Fin;	
			}

			pignat->setVannePVCBase(nEtat == Etats::VersementPvc);
			pignat->setVannePVCBaseFD(nEtat == Etats::VersementPvc && pignat->getPoids() < masse_pvc_base - differenceToDisablePvcFd);
			pignat->setVannePlastifiant(nEtat == Etats::VersementPlastifiant);
			pignat->setVanneLubrifiant(nEtat == Etats::VersementLubrifiant);
			if (nEtat == Etats::Malaxage)
			{
				duree_malax++;
			}
			pignat->setVanneVidange(nEtat == Etats::Vidange);
			if (nEtat == Etats::Refroidissement)
			{
				duree_refroid++;
			}
			pignat->setEvacuation(nEtat == Etats::Evacuation);
			pignat->setMalaxeur(nEtat == Etats::Malaxage || nEtat == Etats::VersementLubrifiant);

			pignat->majSorties();				  
			
		}		

		void FinCycle()
		{
			running = false;
			bdd->majHeureFin(*ordreFabrication);
			UpdateREFOF();
			pignatUpdateTimer->Enabled = false;
			pignat->setVoyantRouge(false);

			ordreFabrication = nullptr;

			listOF->Visible = true;
			txt_OF->Visible = true;
			listOF->SelectedIndex = -1;
			btn_deconnexion->Visible = true;
			txt_deconnecter->Visible = true;	


			OfUpdateTimer->Enabled = true;
		}

		private: System::Void finCycleTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			finCycleTimer->Enabled = false;
			FinCycle();
		}
		void ShowHideMenu(bool action)
		{
			btn_lancerFabrication->Visible = action;
			txt_OF->Visible = action;
			listOF->Visible = action;
			table_InfosOF->Visible = action;
			btn_deconnexion->Visible = action;
			txt_deconnecter->Visible = action;
		}

		/*---------------RESPONSIVE ANIM-------------------*/
#pragma region RESPONSIVE_ANIM
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

#pragma endregion


		/*---------------BACKGROUND IMAGE-------------------*/
#pragma region Background
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

#pragma endregion



private: System::Void btn_deconnexion_Click(System::Object^ sender, System::EventArgs^ e) {
	isOn = false;
	AnimTimer->Enabled = false;
	OfUpdateTimer->Enabled = false;
	
	bdd->deconnecter();
	Sleep(100);
	parentForm->Enabled = true;
	parentForm->Visible = true;
	this->Close();

}
private: System::Void OfUpdateTimer_Tick(System::Object^ sender, System::EventArgs^ e) {

	if(isOn)
		UpdateREFOF();
}

	   void OnFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	   {
		   GC::Collect();
		   GC::WaitForPendingFinalizers();
		   delete this;
	   }



};
}
