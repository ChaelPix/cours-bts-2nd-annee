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
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ lbButton1;
	private: LBSoft::IndustrialCtrls::Buttons::LBButton^ lbButton2;

	private: LBSoft::IndustrialCtrls::Meters::LBAnalogMeter^ lbAnalogMeter1;

	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel6;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label2;
	private: LBSoft::IndustrialCtrls::Leds::LBLed^ lbLed1;
	private: LBSoft::IndustrialCtrls::Meters::LBDigitalMeter^ lbDigitalMeter1;
	private: System::Windows::Forms::Panel^ panel7;

















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
			this->lbButton1 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->lbButton2 = (gcnew LBSoft::IndustrialCtrls::Buttons::LBButton());
			this->lbAnalogMeter1 = (gcnew LBSoft::IndustrialCtrls::Meters::LBAnalogMeter());
			this->lbLed2 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lbLed1 = (gcnew LBSoft::IndustrialCtrls::Leds::LBLed());
			this->lbDigitalMeter1 = (gcnew LBSoft::IndustrialCtrls::Meters::LBDigitalMeter());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(19, 12);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(400, 83);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// lbButton1
			// 
			this->lbButton1->BackColor = System::Drawing::Color::Transparent;
			this->lbButton1->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lbButton1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbButton1->Label = L"";
			this->lbButton1->Location = System::Drawing::Point(15, 69);
			this->lbButton1->Name = L"lbButton1";
			this->lbButton1->Renderer = nullptr;
			this->lbButton1->RepeatInterval = 100;
			this->lbButton1->RepeatState = false;
			this->lbButton1->Size = System::Drawing::Size(100, 100);
			this->lbButton1->StartRepeatInterval = 500;
			this->lbButton1->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->lbButton1->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->lbButton1->TabIndex = 4;
			// 
			// lbButton2
			// 
			this->lbButton2->BackColor = System::Drawing::Color::Transparent;
			this->lbButton2->ButtonColor = System::Drawing::Color::Red;
			this->lbButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbButton2->Label = L"";
			this->lbButton2->Location = System::Drawing::Point(10, 69);
			this->lbButton2->Name = L"lbButton2";
			this->lbButton2->Renderer = nullptr;
			this->lbButton2->RepeatInterval = 100;
			this->lbButton2->RepeatState = false;
			this->lbButton2->Size = System::Drawing::Size(100, 100);
			this->lbButton2->StartRepeatInterval = 500;
			this->lbButton2->State = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonState::Normal;
			this->lbButton2->Style = LBSoft::IndustrialCtrls::Buttons::LBButton::ButtonStyle::Circular;
			this->lbButton2->TabIndex = 5;
			// 
			// lbAnalogMeter1
			// 
			this->lbAnalogMeter1->BackColor = System::Drawing::Color::Transparent;
			this->lbAnalogMeter1->BodyColor = System::Drawing::Color::Black;
			this->lbAnalogMeter1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbAnalogMeter1->Location = System::Drawing::Point(10, 70);
			this->lbAnalogMeter1->MaxValue = 3;
			this->lbAnalogMeter1->MeterStyle = LBSoft::IndustrialCtrls::Meters::LBAnalogMeter::AnalogMeterStyle::Circular;
			this->lbAnalogMeter1->MinValue = 0;
			this->lbAnalogMeter1->Name = L"lbAnalogMeter1";
			this->lbAnalogMeter1->NeedleColor = System::Drawing::Color::FloralWhite;
			this->lbAnalogMeter1->Renderer = nullptr;
			this->lbAnalogMeter1->ScaleColor = System::Drawing::Color::White;
			this->lbAnalogMeter1->ScaleDivisions = 0;
			this->lbAnalogMeter1->ScaleSubDivisions = 0;
			this->lbAnalogMeter1->Size = System::Drawing::Size(100, 100);
			this->lbAnalogMeter1->TabIndex = 8;
			this->lbAnalogMeter1->Value = 1;
			this->lbAnalogMeter1->ViewGlass = false;
			// 
			// lbLed2
			// 
			this->lbLed2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->lbLed2->BackColor = System::Drawing::Color::Transparent;
			this->lbLed2->BlinkInterval = 500;
			this->lbLed2->Label = L"";
			this->lbLed2->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed2->LedColor = System::Drawing::Color::Red;
			this->lbLed2->LedSize = System::Drawing::SizeF(50, 50);
			this->lbLed2->Location = System::Drawing::Point(7, 36);
			this->lbLed2->Name = L"lbLed2";
			this->lbLed2->Renderer = nullptr;
			this->lbLed2->Size = System::Drawing::Size(110, 110);
			this->lbLed2->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed2->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed2->TabIndex = 10;
			// 
			// panel1
			// 
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel1->Controls->Add(this->lbDigitalMeter1);
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(-7, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(452, 835);
			this->panel1->TabIndex = 11;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->lbAnalogMeter1);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(31, 539);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(124, 183);
			this->panel2->TabIndex = 12;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(11, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 49);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Auto/\r\nManuel\r\n";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->lbButton1);
			this->panel3->Location = System::Drawing::Point(161, 539);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(124, 183);
			this->panel3->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(11, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 49);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Marche";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4->Controls->Add(this->label3);
			this->panel4->Controls->Add(this->lbButton2);
			this->panel4->Location = System::Drawing::Point(291, 539);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(124, 183);
			this->panel4->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(11, 10);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 49);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Arrêt";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::White;
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel5->Controls->Add(this->label4);
			this->panel5->Controls->Add(this->lbLed2);
			this->panel5->Location = System::Drawing::Point(161, 350);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(124, 183);
			this->panel5->TabIndex = 13;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(11, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 49);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Voyant Rouge";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::White;
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel6->Controls->Add(this->label5);
			this->panel6->Controls->Add(this->lbLed1);
			this->panel6->Location = System::Drawing::Point(291, 350);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(124, 183);
			this->panel6->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(11, 10);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 49);
			this->label5->TabIndex = 5;
			this->label5->Text = L"\?\?\?";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbLed1
			// 
			this->lbLed1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->lbLed1->BackColor = System::Drawing::Color::White;
			this->lbLed1->BlinkInterval = 500;
			this->lbLed1->Label = L"";
			this->lbLed1->LabelPosition = LBSoft::IndustrialCtrls::Leds::LBLed::LedLabelPosition::Top;
			this->lbLed1->LedColor = System::Drawing::Color::Orange;
			this->lbLed1->LedSize = System::Drawing::SizeF(50, 50);
			this->lbLed1->Location = System::Drawing::Point(6, 36);
			this->lbLed1->Name = L"lbLed1";
			this->lbLed1->Renderer = nullptr;
			this->lbLed1->Size = System::Drawing::Size(110, 110);
			this->lbLed1->State = LBSoft::IndustrialCtrls::Leds::LBLed::LedState::Off;
			this->lbLed1->Style = LBSoft::IndustrialCtrls::Leds::LBLed::LedStyle::Circular;
			this->lbLed1->TabIndex = 11;
			// 
			// lbDigitalMeter1
			// 
			this->lbDigitalMeter1->BackColor = System::Drawing::Color::Black;
			this->lbDigitalMeter1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbDigitalMeter1->Cursor = System::Windows::Forms::Cursors::Default;
			this->lbDigitalMeter1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lbDigitalMeter1->Format = L"0000";
			this->lbDigitalMeter1->Location = System::Drawing::Point(67, 167);
			this->lbDigitalMeter1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->lbDigitalMeter1->Name = L"lbDigitalMeter1";
			this->lbDigitalMeter1->Renderer = nullptr;
			this->lbDigitalMeter1->Signed = true;
			this->lbDigitalMeter1->Size = System::Drawing::Size(304, 103);
			this->lbDigitalMeter1->TabIndex = 12;
			this->lbDigitalMeter1->Value = 0;
			// 
			// panel7
			// 
			this->panel7->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(130)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel7->Location = System::Drawing::Point(1212, 0);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(273, 835);
			this->panel7->TabIndex = 14;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(1478, 844);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Pignat Controller";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
