#pragma once
#include "SelectLanguage.h"
#include "Train.h"
#include "windows.h"
#include"stdlib.h"

namespace SpeakToPlay {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lbl_welcome;
	protected: 
	private: System::Windows::Forms::Label^  lbl_speak;
	private: System::Windows::Forms::ListBox^  lst_guide;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  lbl_speaktospeech;
	private: System::Windows::Forms::TextBox^  tb_username;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  lbl_username;
	private: System::Windows::Forms::Label^  lbl_music;
	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->lbl_welcome = (gcnew System::Windows::Forms::Label());
			this->lbl_speak = (gcnew System::Windows::Forms::Label());
			this->lst_guide = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lbl_speaktospeech = (gcnew System::Windows::Forms::Label());
			this->tb_username = (gcnew System::Windows::Forms::TextBox());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lbl_username = (gcnew System::Windows::Forms::Label());
			this->lbl_music = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbl_welcome
			// 
			this->lbl_welcome->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_welcome->Location = System::Drawing::Point(3, 18);
			this->lbl_welcome->Name = L"lbl_welcome";
			this->lbl_welcome->Size = System::Drawing::Size(641, 80);
			this->lbl_welcome->TabIndex = 2;
			this->lbl_welcome->Text = L"WELCOME";
			this->lbl_welcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_speak
			// 
			this->lbl_speak->BackColor = System::Drawing::Color::Teal;
			this->lbl_speak->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lbl_speak.Image")));
			this->lbl_speak->Location = System::Drawing::Point(232, 10);
			this->lbl_speak->Name = L"lbl_speak";
			this->lbl_speak->Size = System::Drawing::Size(57, 44);
			this->lbl_speak->TabIndex = 7;
			// 
			// lst_guide
			// 
			this->lst_guide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lst_guide->FormattingEnabled = true;
			this->lst_guide->HorizontalScrollbar = true;
			this->lst_guide->ItemHeight = 24;
			this->lst_guide->Items->AddRange(gcnew cli::array< System::Object^  >(14) {L"Guidelines", L"", L"", L"1] Speak \'HELP\' for help ", 
				L"option", L"", L"2] Speak \'HOME\' to ", L"navigate to Home screen.", L"", L"3] Speak  \'BACK\'  ", L"to  navigate to previous screen.", 
				L"", L"4] Speak  \'QUIT/EXIT\' ", L"to close Application."});
			this->lst_guide->Location = System::Drawing::Point(3, -1);
			this->lst_guide->Name = L"lst_guide";
			this->lst_guide->ScrollAlwaysVisible = true;
			this->lst_guide->Size = System::Drawing::Size(243, 412);
			this->lst_guide->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(172, 131);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 33);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Proceed";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// lbl_speaktospeech
			// 
			this->lbl_speaktospeech->BackColor = System::Drawing::Color::Teal;
			this->lbl_speaktospeech->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 27.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_speaktospeech->Location = System::Drawing::Point(-21, 2);
			this->lbl_speaktospeech->Name = L"lbl_speaktospeech";
			this->lbl_speaktospeech->Size = System::Drawing::Size(918, 56);
			this->lbl_speaktospeech->TabIndex = 6;
			this->lbl_speaktospeech->Text = L"SPEAK TO PLAY";
			this->lbl_speaktospeech->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tb_username
			// 
			this->tb_username->Location = System::Drawing::Point(295, 59);
			this->tb_username->Name = L"tb_username";
			this->tb_username->Size = System::Drawing::Size(100, 22);
			this->tb_username->TabIndex = 1;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Location = System::Drawing::Point(-10, 77);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::Color::Azure;
			this->splitContainer1->Panel1->Controls->Add(this->groupBox1);
			this->splitContainer1->Panel1->Controls->Add(this->lbl_welcome);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->AutoScroll = true;
			this->splitContainer1->Panel2->AutoScrollMargin = System::Drawing::Size(1, 1);
			this->splitContainer1->Panel2->Controls->Add(this->lst_guide);
			this->splitContainer1->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel2_Paint);
			this->splitContainer1->Size = System::Drawing::Size(938, 414);
			this->splitContainer1->SplitterDistance = 657;
			this->splitContainer1->TabIndex = 5;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Black;
			this->groupBox1->Controls->Add(this->panel1);
			this->groupBox1->Location = System::Drawing::Point(72, 81);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(502, 290);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Teal;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->tb_username);
			this->panel1->Controls->Add(this->lbl_username);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(6, 11);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(490, 273);
			this->panel1->TabIndex = 2;
			// 
			// lbl_username
			// 
			this->lbl_username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_username->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lbl_username->Location = System::Drawing::Point(23, 45);
			this->lbl_username->Name = L"lbl_username";
			this->lbl_username->Size = System::Drawing::Size(197, 46);
			this->lbl_username->TabIndex = 0;
			this->lbl_username->Text = L"Enter username";
			this->lbl_username->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_music
			// 
			this->lbl_music->BackColor = System::Drawing::Color::Teal;
			this->lbl_music->ForeColor = System::Drawing::SystemColors::Control;
			this->lbl_music->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lbl_music.Image")));
			this->lbl_music->Location = System::Drawing::Point(595, 10);
			this->lbl_music->Name = L"lbl_music";
			this->lbl_music->Size = System::Drawing::Size(39, 44);
			this->lbl_music->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Teal;
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(595, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 44);
			this->label1->TabIndex = 9;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(907, 492);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbl_speak);
			this->Controls->Add(this->lbl_speaktospeech);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->lbl_music);
			this->Name = L"Form1";
			this->Text = L"HOME";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
private: System::Void splitContainer1_Panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String ^ username =tb_username->Text;
			 if(username=="POOJA" || username=="SALONI" || username=="SANJANA" || username=="SUSRITA" ||username=="")
			 {
				 SelectLanguage^ f2=gcnew SelectLanguage();
				 this->Hide();
				 f2->ShowDialog();
				 
			 }

			 else
			 {
				 if(MessageBox::Show("Do You Want To Train?","Train",MessageBoxButtons::YesNo,MessageBoxIcon::Question)==System::Windows::Forms::DialogResult::Yes)
				 {
					 Train^ t=gcnew Train();
					 //this->Hide();
					 t->ShowDialog();

				 }

				 else
					 Application::Exit();



			 }
		 }
};
}

