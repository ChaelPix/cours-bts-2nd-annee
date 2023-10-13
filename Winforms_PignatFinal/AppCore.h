#pragma once

namespace Winforms_PignatFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de AppCore
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
		}

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

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:

	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AppCore::typeid));
			this->pignatImg = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pignatImg))->BeginInit();
			this->SuspendLayout();
			// 
			// pignatImg
			// 
			this->pignatImg->BackColor = System::Drawing::Color::Transparent;
			this->pignatImg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pignatImg.Image")));
			this->pignatImg->Location = System::Drawing::Point(59, 56);
			this->pignatImg->Margin = System::Windows::Forms::Padding(2);
			this->pignatImg->Name = L"pignatImg";
			this->pignatImg->Size = System::Drawing::Size(330, 81);
			this->pignatImg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pignatImg->TabIndex = 4;
			this->pignatImg->TabStop = false;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(74, 209);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(374, 49);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Liste des Ordres de Fabrication";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(115, 261);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(274, 21);
			this->comboBox1->TabIndex = 9;
			// 
			// AppCore
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1218, 685);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pignatImg);
			this->Name = L"AppCore";
			this->Text = L"AppCore";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pignatImg))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
