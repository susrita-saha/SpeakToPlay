#pragma once
#include "stdlib.h"
#include "string.h"
#include"Pause.h"
#include"math.h"
#include"stdio.h"
#include"GlobalFunction.h"
namespace SpeakToPlay {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SelectLanguage
	/// </summary>
	
	public ref class SelectLanguage : public System::Windows::Forms::Form
	{

		
	public:
		SelectLanguage(void)
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
		~SelectLanguage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lbl_speakhindi;
	protected: 
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btn_hindi;
	private: System::Windows::Forms::Label^  lbl_englisgsongs;
	private: System::Windows::Forms::Label^  lbl_speakenglish;
	private: System::Windows::Forms::Label^  lbl_hindisongs;
	private: System::Windows::Forms::Button^  btn_english;
	private: System::Windows::Forms::Label^  lbl_speak;
	private: System::Windows::Forms::ListBox^  lst_guide;
	private: System::Windows::Forms::Button^  btn_recording;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lbl_music;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Label^  lbl_speaktospeech;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
    

	


	
public: System::Media::SoundPlayer^ player;
	private: System::Windows::Forms::Button^  button1;
	public: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SelectLanguage::typeid));
			this->lbl_speakhindi = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btn_hindi = (gcnew System::Windows::Forms::Button());
			this->lbl_englisgsongs = (gcnew System::Windows::Forms::Label());
			this->lbl_speakenglish = (gcnew System::Windows::Forms::Label());
			this->lbl_hindisongs = (gcnew System::Windows::Forms::Label());
			this->btn_english = (gcnew System::Windows::Forms::Button());
			this->lbl_speak = (gcnew System::Windows::Forms::Label());
			this->lst_guide = (gcnew System::Windows::Forms::ListBox());
			this->btn_recording = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_music = (gcnew System::Windows::Forms::Label());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->lbl_speaktospeech = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbl_speakhindi
			// 
			this->lbl_speakhindi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_speakhindi->Location = System::Drawing::Point(152, 73);
			this->lbl_speakhindi->Name = L"lbl_speakhindi";
			this->lbl_speakhindi->Size = System::Drawing::Size(74, 38);
			this->lbl_speakhindi->TabIndex = 0;
			this->lbl_speakhindi->Text = L"Speak";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Teal;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->lbl_speakhindi);
			this->panel1->Controls->Add(this->btn_hindi);
			this->panel1->Controls->Add(this->lbl_englisgsongs);
			this->panel1->Controls->Add(this->lbl_speakenglish);
			this->panel1->Controls->Add(this->lbl_hindisongs);
			this->panel1->Controls->Add(this->btn_english);
			this->panel1->Location = System::Drawing::Point(-95, 38);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(648, 412);
			this->panel1->TabIndex = 8;
			// 
			// btn_hindi
			// 
			this->btn_hindi->Location = System::Drawing::Point(0, 0);
			this->btn_hindi->Name = L"btn_hindi";
			this->btn_hindi->Size = System::Drawing::Size(75, 23);
			this->btn_hindi->TabIndex = 1;
			// 
			// lbl_englisgsongs
			// 
			this->lbl_englisgsongs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_englisgsongs->Location = System::Drawing::Point(410, 198);
			this->lbl_englisgsongs->Name = L"lbl_englisgsongs";
			this->lbl_englisgsongs->Size = System::Drawing::Size(198, 34);
			this->lbl_englisgsongs->TabIndex = 5;
			this->lbl_englisgsongs->Text = L"to play english songs.";
			// 
			// lbl_speakenglish
			// 
			this->lbl_speakenglish->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_speakenglish->Location = System::Drawing::Point(151, 209);
			this->lbl_speakenglish->Name = L"lbl_speakenglish";
			this->lbl_speakenglish->Size = System::Drawing::Size(75, 23);
			this->lbl_speakenglish->TabIndex = 6;
			this->lbl_speakenglish->Text = L"Speak";
			// 
			// lbl_hindisongs
			// 
			this->lbl_hindisongs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbl_hindisongs->Location = System::Drawing::Point(410, 73);
			this->lbl_hindisongs->Name = L"lbl_hindisongs";
			this->lbl_hindisongs->Size = System::Drawing::Size(172, 38);
			this->lbl_hindisongs->TabIndex = 4;
			this->lbl_hindisongs->Text = L"to play hindi songs";
			// 
			// btn_english
			// 
			this->btn_english->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_english->Location = System::Drawing::Point(262, 191);
			this->btn_english->Name = L"btn_english";
			this->btn_english->Size = System::Drawing::Size(104, 41);
			this->btn_english->TabIndex = 3;
			this->btn_english->Text = L"ENGLISH";
			this->btn_english->UseVisualStyleBackColor = true;
			// 
			// lbl_speak
			// 
			this->lbl_speak->BackColor = System::Drawing::Color::Teal;
			this->lbl_speak->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lbl_speak.Image")));
			this->lbl_speak->Location = System::Drawing::Point(245, 9);
			this->lbl_speak->Name = L"lbl_speak";
			this->lbl_speak->Size = System::Drawing::Size(56, 48);
			this->lbl_speak->TabIndex = 12;
			// 
			// lst_guide
			// 
			this->lst_guide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lst_guide->FormattingEnabled = true;
			this->lst_guide->HorizontalScrollbar = true;
			this->lst_guide->ItemHeight = 24;
			this->lst_guide->Items->AddRange(gcnew cli::array< System::Object^  >(13) {L"Guidelines", L"", L"1] Speak \'HELP\' for ", 
				L"help option", L"", L"2] Speak \'HOME\' to ", L"navigate to Home screen.", L"", L"3] Speak  \'BACK\'  to ", L" navigate to previous screen.", 
				L"", L"4] Speak  \'QUIT/EXIT\' to ", L"close Application."});
			this->lst_guide->Location = System::Drawing::Point(3, 0);
			this->lst_guide->Name = L"lst_guide";
			this->lst_guide->ScrollAlwaysVisible = true;
			this->lst_guide->Size = System::Drawing::Size(254, 412);
			this->lst_guide->TabIndex = 0;
			// 
			// btn_recording
			// 
			this->btn_recording->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn_recording.Image")));
			this->btn_recording->Location = System::Drawing::Point(597, 333);
			this->btn_recording->Margin = System::Windows::Forms::Padding(0);
			this->btn_recording->Name = L"btn_recording";
			this->btn_recording->Size = System::Drawing::Size(41, 53);
			this->btn_recording->TabIndex = 7;
			this->btn_recording->UseVisualStyleBackColor = true;
			this->btn_recording->Click += gcnew System::EventHandler(this, &SelectLanguage::btn_recording_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Teal;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(-4, 1);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(918, 56);
			this->label2->TabIndex = 11;
			this->label2->Text = L"SPEAK TO PLAY";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_music
			// 
			this->lbl_music->BackColor = System::Drawing::Color::Teal;
			this->lbl_music->ForeColor = System::Drawing::SystemColors::Control;
			this->lbl_music->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lbl_music.Image")));
			this->lbl_music->Location = System::Drawing::Point(623, 9);
			this->lbl_music->Name = L"lbl_music";
			this->lbl_music->Size = System::Drawing::Size(39, 44);
			this->lbl_music->TabIndex = 13;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Location = System::Drawing::Point(-17, 78);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::Color::Azure;
			this->splitContainer1->Panel1->Controls->Add(this->panel1);
			this->splitContainer1->Panel1->Controls->Add(this->btn_recording);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SelectLanguage::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->AutoScroll = true;
			this->splitContainer1->Panel2->AutoScrollMargin = System::Drawing::Size(1, 1);
			this->splitContainer1->Panel2->Controls->Add(this->lst_guide);
			this->splitContainer1->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SelectLanguage::splitContainer1_Panel2_Paint);
			this->splitContainer1->Size = System::Drawing::Size(940, 414);
			this->splitContainer1->SplitterDistance = 671;
			this->splitContainer1->TabIndex = 9;
			// 
			// lbl_speaktospeech
			// 
			this->lbl_speaktospeech->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 26.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_speaktospeech->Location = System::Drawing::Point(-17, 1);
			this->lbl_speaktospeech->Name = L"lbl_speaktospeech";
			this->lbl_speaktospeech->Size = System::Drawing::Size(893, 56);
			this->lbl_speaktospeech->TabIndex = 10;
			this->lbl_speaktospeech->Text = L"SPEAK TO SPEECH";
			this->lbl_speaktospeech->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(443, 116);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Teal;
			this->label3->ForeColor = System::Drawing::SystemColors::Control;
			this->label3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"label3.Image")));
			this->label3->Location = System::Drawing::Point(613, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 41);
			this->label3->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(262, 70);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 41);
			this->button1->TabIndex = 7;
			this->button1->Text = L"HINDI";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// SelectLanguage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(907, 492);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lbl_speak);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lbl_music);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->lbl_speaktospeech);
			this->Controls->Add(this->label1);
			this->Name = L"SelectLanguage";
			this->Text = L"SelectLanguage";
			this->Load += gcnew System::EventHandler(this, &SelectLanguage::SelectLanguage_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SelectLanguage::SelectLanguage_KeyDown);
			this->panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
private: System::Void splitContainer1_Panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
private: System::Void btn_recording_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 char RECMODPATH[] = "\"\"I:\\Academics\\MTECH\\Sem 1\\Speech Processing\\Recording_Module\\", PATH1[500], PATH2[500], PATH3[500], PATH5[800];
 char ROOT_SAVE[] = "I:\\Academics\\MTECH\\Sem 1\\Playlist\\Intermediates\\", PATH_READ[200];
			 FILE *fpFilename;
 			 char word[200]="hindi";//remove once you get the code;
			 int ERR=0;

			 strcpy(PATH1, RECMODPATH);
		strcat(PATH1, "Recording_Module.exe\"");
		strcpy(PATH2, "\"");
		strcat(PATH2, ROOT_SAVE);
		strcat(PATH2, "184101038_100_100.wav\"");
		strcpy(PATH3, "\"");
		strcat(PATH3, ROOT_SAVE);
		strcat(PATH3, "184101038_100_100.txt\"");
		strcpy(PATH5, PATH1);
		strcat(PATH5, " 1 ");
		strcat(PATH5, PATH2);
		strcat(PATH5, " ");
		strcat(PATH5, PATH3);
		//printf("Recording started...");
		system(PATH5);
		//printf("Recording ended...");
			 //char path[]="\"\"C:\\Users\\salon\\Downloads\\Recording_Module\\Recording_Module.exe\" 1 \"C:\\Users\\salon\\Documents\\Visual Studio 2010\\Projects\\SpeakToPlay\\SpeakToPlay\\184101038_100_100.wav\" \"C:\\Users\\salon\\Documents\\Visual Studio 2010\\Projects\\SpeakToPlay\\SpeakToPlay\\184101038_100_100.txt\"\""; //change the Recording module path ,change dcfile path
			 //system(path);

			 //take code to detect word 

			 TestModel();
			 //read answer from file "ANSWER.txt"
			 //write answer to file "ANSWER.txt"
			
	strcpy(PATH_READ, ROOT_SAVE);
	strcat(PATH_READ, "ANSWER.txt");
	ERR = fopen_s(&fpFilename, PATH_READ, "r");//creates file to write cepstral coefficients Ci's in

	if (ERR){
		printf("Error in creating ANSWER.txt file");
		scanf("%c");
		//exit(0);
	}
	fscanf(fpFilename, "%s", &word);
	fclose(fpFilename);
	

			 if(strcmp(word,"hindi")==0)
			 {
				 try
				 {
					player=gcnew System::Media::SoundPlayer();
					player->SoundLocation="I:\\Academics\\MTECH\\Sem 1\\Playlist\\Intermediates\\Udein.wav";

					player->Load();
					player->PlaySync();
					//this->Hide();
					
					//Pause^ p=gcnew Pause();
					 //this->Hide();
					 //p->ShowDialog();

					//player->Stop();
				 }

				 catch(Win32Exception^ ex)
				 {
					 MessageBox::Show(ex->Message);
				 }


			 }

			 else if(strcmp(word,"english")==0)
			 {
				 try
				 {
					player =gcnew System::Media::SoundPlayer();
					player->SoundLocation="I:\\Academics\\MTECH\\Sem 1\\Playlist\\Intermediates\\Sorry.wav";

					player->Load();
					player->Play();
				 }

				 catch(Win32Exception^ ex)
				 {
					 MessageBox::Show(ex->Message);
				 }

			}


		 }

private: System::Void SelectLanguage_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void SelectLanguage_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		 {
			 if(e->KeyCode==Windows::Forms::Keys::Space)
			 {	
				 player->Stop();
			 }


		 }


		
	









};
}
