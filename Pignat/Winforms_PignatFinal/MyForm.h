#pragma once

#include "BdDPVC.h"
#include "Personnel.h"
#include <msclr/marshal.h>
#include "AppCore.h"

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
			incorrectTxt->Text = "";
			InitbackgroundImages();
		}
#pragma region useless
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
	private: System::Windows::Forms::Button^ loginButton;
	protected:

	protected:



	private: System::Windows::Forms::PictureBox^ pignatImg;
	private: System::Windows::Forms::TextBox^ passwordTextBox;





	private: System::Windows::Forms::Timer^ BackgroundTimer;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ AnimTimer;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ incorrectTxt;

	private: System::Windows::Forms::PictureBox^ backgroundImage;
	private: System::Windows::Forms::Label^ label3;






	private: System::ComponentModel::IContainer^ components;





	protected:

	protected:



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
#pragma endregion

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
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->pignatImg = (gcnew System::Windows::Forms::PictureBox());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BackgroundTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->AnimTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->incorrectTxt = (gcnew System::Windows::Forms::Label());
			this->backgroundImage = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pignatImg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
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
			this->loginTextBox->Location = System::Drawing::Point(67, 296);
			this->loginTextBox->MaxLength = 20;
			this->loginTextBox->Name = L"loginTextBox";
			this->loginTextBox->Size = System::Drawing::Size(307, 40);
			this->loginTextBox->TabIndex = 0;
			this->loginTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->loginTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::TextBox_KeyDown);
			this->loginTextBox->MouseEnter += gcnew System::EventHandler(this, &MyForm::TextBox_MouseEnter);
			this->loginTextBox->MouseLeave += gcnew System::EventHandler(this, &MyForm::TextBox_MouseLeave);
			// 
			// loginButton
			// 
			this->loginButton->BackColor = System::Drawing::Color::White;
			this->loginButton->CausesValidation = false;
			this->loginButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->loginButton->FlatAppearance->BorderSize = 0;
			this->loginButton->Font = (gcnew System::Drawing::Font(L"Cambria", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginButton->ForeColor = System::Drawing::Color::Black;
			this->loginButton->Location = System::Drawing::Point(146, 575);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(138, 38);
			this->loginButton->TabIndex = 2;
			this->loginButton->Text = L"Connexion";
			this->loginButton->UseVisualStyleBackColor = false;
			this->loginButton->Click += gcnew System::EventHandler(this, &MyForm::loginButton_Click);
			this->loginButton->MouseEnter += gcnew System::EventHandler(this, &MyForm::Control_MouseEnter);
			this->loginButton->MouseLeave += gcnew System::EventHandler(this, &MyForm::Control_MouseLeave);
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
			this->pignatImg->TabIndex = 3;
			this->pignatImg->TabStop = false;
			this->pignatImg->MouseEnter += gcnew System::EventHandler(this, &MyForm::Control_MouseEnter);
			this->pignatImg->MouseLeave += gcnew System::EventHandler(this, &MyForm::Control_MouseLeave);
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->BackColor = System::Drawing::Color::White;
			this->passwordTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Cambria", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordTextBox->ForeColor = System::Drawing::Color::Black;
			this->passwordTextBox->Location = System::Drawing::Point(67, 417);
			this->passwordTextBox->MaxLength = 20;
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->PasswordChar = '*';
			this->passwordTextBox->Size = System::Drawing::Size(307, 40);
			this->passwordTextBox->TabIndex = 1;
			this->passwordTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->passwordTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::TextBox_KeyDown);
			this->passwordTextBox->MouseEnter += gcnew System::EventHandler(this, &MyForm::TextBox_MouseEnter);
			this->passwordTextBox->MouseLeave += gcnew System::EventHandler(this, &MyForm::TextBox_MouseLeave);
			// 
			// BackgroundTimer
			// 
			this->BackgroundTimer->Enabled = true;
			this->BackgroundTimer->Tick += gcnew System::EventHandler(this, &MyForm::BackgroundTimer_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(67, 231);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(43, 49);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &MyForm::Control_MouseEnter);
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &MyForm::Control_MouseLeave);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(130, 231);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(259, 49);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Identifiant";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// AnimTimer
			// 
			this->AnimTimer->Interval = 5;
			this->AnimTimer->Tick += gcnew System::EventHandler(this, &MyForm::AnimTimer_Tick);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(67, 354);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(43, 49);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 8;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseEnter += gcnew System::EventHandler(this, &MyForm::Control_MouseEnter);
			this->pictureBox2->MouseLeave += gcnew System::EventHandler(this, &MyForm::Control_MouseLeave);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(130, 354);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(259, 49);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Mot de Passe";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// incorrectTxt
			// 
			this->incorrectTxt->BackColor = System::Drawing::Color::Transparent;
			this->incorrectTxt->Font = (gcnew System::Drawing::Font(L"Cambria", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->incorrectTxt->ForeColor = System::Drawing::Color::Red;
			this->incorrectTxt->Location = System::Drawing::Point(27, 505);
			this->incorrectTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->incorrectTxt->Name = L"incorrectTxt";
			this->incorrectTxt->Size = System::Drawing::Size(386, 67);
			this->incorrectTxt->TabIndex = 10;
			this->incorrectTxt->Text = L"Identifiant ou mot de passe incorrect !";
			this->incorrectTxt->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// backgroundImage
			// 
			this->backgroundImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backgroundImage.BackgroundImage")));
			this->backgroundImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->backgroundImage->Location = System::Drawing::Point(1, -17);
			this->backgroundImage->Name = L"backgroundImage";
			this->backgroundImage->Size = System::Drawing::Size(1233, 701);
			this->backgroundImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->backgroundImage->TabIndex = 5;
			this->backgroundImage->TabStop = false;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(11, 645);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(259, 27);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Par Beaujard Tra�an - 2023";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1215, 681);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->incorrectTxt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->pignatImg);
			this->Controls->Add(this->loginButton);
			this->Controls->Add(this->loginTextBox);
			this->Controls->Add(this->backgroundImage);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Page d\'Authentifaction";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pignatImg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundImage))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		std::string ConvertStringToStdString(String^ input)
		{
			msclr::interop::marshal_context context;
			const char* converted = context.marshal_as<const char*>(input);
			std::string result(converted);
			return result;
		}

		/**********-------------Login------------**********/

		CBdDPVC^ bdd = gcnew CBdDPVC;

		void tryLogin()
		{
			if (!bdd->connecter())
			{
				incorrectTxt->Text = "Erreur connexion BDD";
				return;
			}
			String^ login = loginTextBox->Text;
			String^ password = passwordTextBox->Text;

			std::string login_s = ConvertStringToStdString(login);
			std::string password_s = ConvertStringToStdString(password);
			CPersonnel personnel(login_s, password_s, CPersonnel::Qualite::INCONNU);

			if (bdd->estUnOperateurAutorise(personnel))
			{
				incorrectTxt->Text = "";

				this->Enabled = false;
				this->Visible = false;
				AppCore^ form2 = gcnew AppCore(this, &personnel);
				form2->ShowDialog();

				//this->Hide(); // Cachez le formulaire actuel
				//AppCore^ form2 = gcnew AppCore(this, &personnel);
				//form2->StartPosition = FormStartPosition::Manual; // D�finir la position de d�part sur Manuelle
				//form2->Location = this->Location;
				//form2->ShowDialog();
			}
			else
			{
				incorrectTxt->Text = "Identifiant ou mot de passe incorrect";
				//MessageBox::Show("Identifiant ou mot de passe incorrect");
			}	
		}

		/**********-------------Text Boxes------------**********/
		System::Collections::Generic::Dictionary<Control^, float>^ originalFontSizes = gcnew System::Collections::Generic::Dictionary<Control^, float>();

private: System::Void TextBox_MouseEnter(System::Object^ sender, System::EventArgs^ e)
{
	TextBox^ txtBox = dynamic_cast<TextBox^>(sender);
	if (!txtBox) return;

	// Si la taille de police originale n'est pas d�j� stock�e, stockez-la.
	if (!originalFontSizes->ContainsKey(txtBox))
	{
		originalFontSizes[txtBox] = txtBox->Font->Size;
	}

	txtBox->BackColor = Color::LightGray;
	txtBox->Font = gcnew System::Drawing::Font(txtBox->Font->FontFamily, txtBox->Font->Size * 1.2);
}

private: System::Void TextBox_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	TextBox^ txtBox = dynamic_cast<TextBox^>(sender);
	if (!txtBox) return;

	float originalSize;
	if (originalFontSizes->TryGetValue(txtBox, originalSize))
	{
		txtBox->BackColor = Color::White;
		txtBox->Font = gcnew System::Drawing::Font(txtBox->Font->FontFamily, originalSize);
	}
	txtBox->SelectionLength = 0;
	this->Focus();
	
}

private: System::Void TextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	   {
		   if (e->KeyCode == Keys::Enter)
		   {
			   if (loginTextBox->Text != "" && passwordTextBox->Text != "")
				   tryLogin();
		   }
	   }




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
	int currentImageIndex = 0;
	int imageIndexStep = 1;
	int timeBreak = 0;
	int glowMaxBreak = 10;


	private: void InitbackgroundImages()
	{
		backgroundImages = gcnew cli::array<Bitmap^>(21);

		for (int i = 0; i < backgroundImages->Length; i++)
		{
			//backgroundImages[i] = gcnew Bitmap(String::Format("C:/Users/traia/OneDrive/Documents/GitHub/cours-bts-2nd-annee/Winforms_PignatFinal/Release/ressources/animated_background/Layer {0}.jpg", i * 2));
			backgroundImages[i] = gcnew Bitmap(String::Format("ressources/animated_background/Layer {0}.jpg", i * 2));
		}


	}

	private: System::Void BackgroundTimer_Tick(System::Object^ sender, System::EventArgs^ e) {

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


		   /*---------------BACKGROUND IMAGE-------------------*/
private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e) {
	incorrectTxt->Text = "Clique";
	tryLogin();
}

};
}
