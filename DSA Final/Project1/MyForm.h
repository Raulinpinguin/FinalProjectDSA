#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#include <msclr\marshal_cppstd.h>
#include "Airport.h"




namespace Project1 {

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
		
		std::map<std::string, Airport*> *airports;
		
		MyForm(std::map<std::string, Airport*> *mapping)
		{
			airports = mapping; // Get reference to the airpots map from main execution 
			


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

		


	private: System::Windows::Forms::TextBox^ page_title;

	private: System::Windows::Forms::TextBox^ instruction_text_2;
	private: System::Windows::Forms::Button^ gen_table_button;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;

	private: System::Windows::Forms::TextBox^ table_title;

	private: System::Windows::Forms::TextBox^ first_place_text;
	private: System::Windows::Forms::TextBox^ third_place_text;
	private: System::Windows::Forms::TextBox^ second_place_text;
	private: System::Windows::Forms::TextBox^ fourth_place_text;
	private: System::Windows::Forms::TextBox^ fifth_place_text;
	private: System::Windows::Forms::TextBox^ sixth_place_text;
	private: System::Windows::Forms::TextBox^ seventh_place_text;
	private: System::Windows::Forms::TextBox^ eigth_place_text;
	private: System::Windows::Forms::TextBox^ ninth_place_text;
	private: System::Windows::Forms::TextBox^ tenth_place_text;
	private: System::Windows::Forms::TextBox^ percent_text_10;
	private: System::Windows::Forms::TextBox^ percent_text_9;
	private: System::Windows::Forms::TextBox^ percent_text_8;
	private: System::Windows::Forms::TextBox^ percent_text_7;
	private: System::Windows::Forms::TextBox^ percent_text_6;
	private: System::Windows::Forms::TextBox^ percent_text_5;
	private: System::Windows::Forms::TextBox^ percent_text_4;
	private: System::Windows::Forms::TextBox^ percent_text_3;
	private: System::Windows::Forms::TextBox^ percent_text_2;
	private: System::Windows::Forms::TextBox^ place_text;
	private: System::Windows::Forms::TextBox^ airline_8;
	private: System::Windows::Forms::TextBox^ airline_6;
	private: System::Windows::Forms::TextBox^ percent_label;
	private: System::Windows::Forms::TextBox^ airline_name_label;
	private: System::Windows::Forms::TextBox^ airline_1;
	private: System::Windows::Forms::TextBox^ airline_2;
	private: System::Windows::Forms::TextBox^ airline_4;
	private: System::Windows::Forms::TextBox^ airline_5;
	private: System::Windows::Forms::TextBox^ airline_7;
	private: System::Windows::Forms::TextBox^ airline_3;
	private: System::Windows::Forms::TextBox^ airline_10;
	private: System::Windows::Forms::TextBox^ airline_9;
	private: System::Windows::Forms::TextBox^ percent_text_1;
	private: System::Windows::Forms::TextBox^ alg_speed_text;
	private: System::Windows::Forms::TextBox^ month_label;
	private: System::Windows::Forms::ComboBox^ month_dropdown;
	private: System::Windows::Forms::ComboBox^ airport_dropdown;
	private: System::Windows::Forms::TextBox^ airport_label;
	private: System::Windows::Forms::ComboBox^ sort_alg_dropdown;
	private: System::Windows::Forms::TextBox^ alg_type_label;
	private: System::Windows::Forms::ComboBox^ delay_type_dropdown;
	private: System::Windows::Forms::TextBox^ delay_type_label;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::ComponentModel::IContainer^ components;





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
			this->components = (gcnew System::ComponentModel::Container());
			this->page_title = (gcnew System::Windows::Forms::TextBox());
			this->instruction_text_2 = (gcnew System::Windows::Forms::TextBox());
			this->gen_table_button = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->percent_text_10 = (gcnew System::Windows::Forms::TextBox());
			this->percent_text_9 = (gcnew System::Windows::Forms::TextBox());
			this->percent_text_8 = (gcnew System::Windows::Forms::TextBox());
			this->percent_text_7 = (gcnew System::Windows::Forms::TextBox());
			this->percent_text_6 = (gcnew System::Windows::Forms::TextBox());
			this->percent_text_5 = (gcnew System::Windows::Forms::TextBox());
			this->percent_text_4 = (gcnew System::Windows::Forms::TextBox());
			this->percent_text_3 = (gcnew System::Windows::Forms::TextBox());
			this->percent_text_2 = (gcnew System::Windows::Forms::TextBox());
			this->place_text = (gcnew System::Windows::Forms::TextBox());
			this->third_place_text = (gcnew System::Windows::Forms::TextBox());
			this->first_place_text = (gcnew System::Windows::Forms::TextBox());
			this->second_place_text = (gcnew System::Windows::Forms::TextBox());
			this->fourth_place_text = (gcnew System::Windows::Forms::TextBox());
			this->fifth_place_text = (gcnew System::Windows::Forms::TextBox());
			this->sixth_place_text = (gcnew System::Windows::Forms::TextBox());
			this->seventh_place_text = (gcnew System::Windows::Forms::TextBox());
			this->eigth_place_text = (gcnew System::Windows::Forms::TextBox());
			this->ninth_place_text = (gcnew System::Windows::Forms::TextBox());
			this->tenth_place_text = (gcnew System::Windows::Forms::TextBox());
			this->percent_label = (gcnew System::Windows::Forms::TextBox());
			this->airline_name_label = (gcnew System::Windows::Forms::TextBox());
			this->airline_1 = (gcnew System::Windows::Forms::TextBox());
			this->airline_2 = (gcnew System::Windows::Forms::TextBox());
			this->airline_7 = (gcnew System::Windows::Forms::TextBox());
			this->percent_text_1 = (gcnew System::Windows::Forms::TextBox());
			this->airline_6 = (gcnew System::Windows::Forms::TextBox());
			this->airline_4 = (gcnew System::Windows::Forms::TextBox());
			this->airline_8 = (gcnew System::Windows::Forms::TextBox());
			this->airline_9 = (gcnew System::Windows::Forms::TextBox());
			this->airline_5 = (gcnew System::Windows::Forms::TextBox());
			this->airline_10 = (gcnew System::Windows::Forms::TextBox());
			this->airline_3 = (gcnew System::Windows::Forms::TextBox());
			this->table_title = (gcnew System::Windows::Forms::TextBox());
			this->alg_speed_text = (gcnew System::Windows::Forms::TextBox());
			this->month_label = (gcnew System::Windows::Forms::TextBox());
			this->month_dropdown = (gcnew System::Windows::Forms::ComboBox());
			this->airport_dropdown = (gcnew System::Windows::Forms::ComboBox());
			this->airport_label = (gcnew System::Windows::Forms::TextBox());
			this->sort_alg_dropdown = (gcnew System::Windows::Forms::ComboBox());
			this->alg_type_label = (gcnew System::Windows::Forms::TextBox());
			this->delay_type_dropdown = (gcnew System::Windows::Forms::ComboBox());
			this->delay_type_label = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// page_title
			// 
			this->page_title->BackColor = System::Drawing::SystemColors::Info;
			this->page_title->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->page_title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->page_title->Location = System::Drawing::Point(2, 12);
			this->page_title->Multiline = true;
			this->page_title->Name = L"page_title";
			this->page_title->ReadOnly = true;
			this->page_title->Size = System::Drawing::Size(677, 40);
			this->page_title->TabIndex = 4;
			this->page_title->Text = L"Selecting the most reliable airline for your trip.";
			this->page_title->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->page_title->TextChanged += gcnew System::EventHandler(this, &MyForm::page_title_TextChanged);
			// 
			// instruction_text_2
			// 
			this->instruction_text_2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->instruction_text_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->instruction_text_2->Location = System::Drawing::Point(12, 188);
			this->instruction_text_2->Multiline = true;
			this->instruction_text_2->Name = L"instruction_text_2";
			this->instruction_text_2->ReadOnly = true;
			this->instruction_text_2->Size = System::Drawing::Size(596, 38);
			this->instruction_text_2->TabIndex = 10;
			this->instruction_text_2->Text = L"Press \"Generate Table\" once ready.";
			this->instruction_text_2->TextChanged += gcnew System::EventHandler(this, &MyForm::instruction_text_2_TextChanged);
			// 
			// gen_table_button
			// 
			this->gen_table_button->BackColor = System::Drawing::SystemColors::Info;
			this->gen_table_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->gen_table_button->Location = System::Drawing::Point(235, 226);
			this->gen_table_button->Name = L"gen_table_button";
			this->gen_table_button->Size = System::Drawing::Size(201, 56);
			this->gen_table_button->TabIndex = 11;
			this->gen_table_button->Text = L"Generate Table";
			this->gen_table_button->UseVisualStyleBackColor = false;
			this->gen_table_button->Click += gcnew System::EventHandler(this, &MyForm::gen_table_button_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				11.76471F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				44.11765F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				44.11765F)));
			this->tableLayoutPanel1->Controls->Add(this->percent_text_10, 2, 10);
			this->tableLayoutPanel1->Controls->Add(this->percent_text_9, 2, 9);
			this->tableLayoutPanel1->Controls->Add(this->percent_text_8, 2, 8);
			this->tableLayoutPanel1->Controls->Add(this->percent_text_7, 2, 7);
			this->tableLayoutPanel1->Controls->Add(this->percent_text_6, 2, 6);
			this->tableLayoutPanel1->Controls->Add(this->percent_text_5, 2, 5);
			this->tableLayoutPanel1->Controls->Add(this->percent_text_4, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->percent_text_3, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->percent_text_2, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->place_text, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->third_place_text, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->first_place_text, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->second_place_text, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->fourth_place_text, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->fifth_place_text, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->sixth_place_text, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->seventh_place_text, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->eigth_place_text, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->ninth_place_text, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->tenth_place_text, 0, 10);
			this->tableLayoutPanel1->Controls->Add(this->percent_label, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->airline_name_label, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->airline_1, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->airline_2, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->airline_7, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->percent_text_1, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->airline_6, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->airline_4, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->airline_8, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->airline_9, 1, 9);
			this->tableLayoutPanel1->Controls->Add(this->airline_5, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->airline_10, 1, 10);
			this->tableLayoutPanel1->Controls->Add(this->airline_3, 1, 3);
			this->tableLayoutPanel1->Location = System::Drawing::Point(39, 379);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 11;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.115645F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.115645F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.115645F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.115645F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.115645F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 8.680272F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.278913F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.115645F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.115645F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.115645F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.115645F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(596, 335);
			this->tableLayoutPanel1->TabIndex = 12;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::tableLayoutPanel1_Paint);
			// 
			// percent_text_10
			// 
			this->percent_text_10->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->percent_text_10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percent_text_10->Location = System::Drawing::Point(335, 303);
			this->percent_text_10->Name = L"percent_text_10";
			this->percent_text_10->ReadOnly = true;
			this->percent_text_10->Size = System::Drawing::Size(258, 24);
			this->percent_text_10->TabIndex = 35;
			this->percent_text_10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// percent_text_9
			// 
			this->percent_text_9->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->percent_text_9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percent_text_9->Location = System::Drawing::Point(335, 273);
			this->percent_text_9->Name = L"percent_text_9";
			this->percent_text_9->ReadOnly = true;
			this->percent_text_9->Size = System::Drawing::Size(258, 24);
			this->percent_text_9->TabIndex = 34;
			this->percent_text_9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// percent_text_8
			// 
			this->percent_text_8->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->percent_text_8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percent_text_8->Location = System::Drawing::Point(335, 243);
			this->percent_text_8->Name = L"percent_text_8";
			this->percent_text_8->ReadOnly = true;
			this->percent_text_8->Size = System::Drawing::Size(258, 24);
			this->percent_text_8->TabIndex = 33;
			this->percent_text_8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// percent_text_7
			// 
			this->percent_text_7->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->percent_text_7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percent_text_7->Location = System::Drawing::Point(335, 213);
			this->percent_text_7->Name = L"percent_text_7";
			this->percent_text_7->ReadOnly = true;
			this->percent_text_7->Size = System::Drawing::Size(258, 24);
			this->percent_text_7->TabIndex = 32;
			this->percent_text_7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// percent_text_6
			// 
			this->percent_text_6->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->percent_text_6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percent_text_6->Location = System::Drawing::Point(335, 182);
			this->percent_text_6->Name = L"percent_text_6";
			this->percent_text_6->ReadOnly = true;
			this->percent_text_6->Size = System::Drawing::Size(258, 24);
			this->percent_text_6->TabIndex = 31;
			this->percent_text_6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// percent_text_5
			// 
			this->percent_text_5->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->percent_text_5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percent_text_5->Location = System::Drawing::Point(335, 153);
			this->percent_text_5->Name = L"percent_text_5";
			this->percent_text_5->Size = System::Drawing::Size(258, 24);
			this->percent_text_5->TabIndex = 30;
			this->percent_text_5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// percent_text_4
			// 
			this->percent_text_4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->percent_text_4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percent_text_4->Location = System::Drawing::Point(335, 123);
			this->percent_text_4->Name = L"percent_text_4";
			this->percent_text_4->ReadOnly = true;
			this->percent_text_4->Size = System::Drawing::Size(258, 24);
			this->percent_text_4->TabIndex = 29;
			this->percent_text_4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->percent_text_4->TextChanged += gcnew System::EventHandler(this, &MyForm::percent_text_4_TextChanged);
			// 
			// percent_text_3
			// 
			this->percent_text_3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->percent_text_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percent_text_3->Location = System::Drawing::Point(335, 93);
			this->percent_text_3->Name = L"percent_text_3";
			this->percent_text_3->ReadOnly = true;
			this->percent_text_3->Size = System::Drawing::Size(258, 24);
			this->percent_text_3->TabIndex = 28;
			this->percent_text_3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->percent_text_3->TextChanged += gcnew System::EventHandler(this, &MyForm::percent_text_3_TextChanged);
			// 
			// percent_text_2
			// 
			this->percent_text_2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->percent_text_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percent_text_2->Location = System::Drawing::Point(335, 63);
			this->percent_text_2->Name = L"percent_text_2";
			this->percent_text_2->ReadOnly = true;
			this->percent_text_2->Size = System::Drawing::Size(258, 24);
			this->percent_text_2->TabIndex = 27;
			this->percent_text_2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->percent_text_2->TextChanged += gcnew System::EventHandler(this, &MyForm::percent_text_2_TextChanged);
			// 
			// place_text
			// 
			this->place_text->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->place_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->place_text->Location = System::Drawing::Point(3, 3);
			this->place_text->Name = L"place_text";
			this->place_text->ReadOnly = true;
			this->place_text->Size = System::Drawing::Size(64, 24);
			this->place_text->TabIndex = 26;
			this->place_text->Text = L"Place";
			this->place_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->place_text->TextChanged += gcnew System::EventHandler(this, &MyForm::place_text_TextChanged);
			// 
			// third_place_text
			// 
			this->third_place_text->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->third_place_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->third_place_text->Location = System::Drawing::Point(3, 93);
			this->third_place_text->Name = L"third_place_text";
			this->third_place_text->ReadOnly = true;
			this->third_place_text->Size = System::Drawing::Size(64, 24);
			this->third_place_text->TabIndex = 9;
			this->third_place_text->Text = L"3.";
			this->third_place_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->third_place_text->TextChanged += gcnew System::EventHandler(this, &MyForm::third_place_text_TextChanged);
			// 
			// first_place_text
			// 
			this->first_place_text->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->first_place_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->first_place_text->Location = System::Drawing::Point(3, 33);
			this->first_place_text->Name = L"first_place_text";
			this->first_place_text->ReadOnly = true;
			this->first_place_text->Size = System::Drawing::Size(64, 24);
			this->first_place_text->TabIndex = 0;
			this->first_place_text->Text = L"1.";
			this->first_place_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->first_place_text->TextChanged += gcnew System::EventHandler(this, &MyForm::first_place_text_TextChanged);
			// 
			// second_place_text
			// 
			this->second_place_text->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->second_place_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->second_place_text->Location = System::Drawing::Point(3, 63);
			this->second_place_text->Name = L"second_place_text";
			this->second_place_text->ReadOnly = true;
			this->second_place_text->Size = System::Drawing::Size(64, 24);
			this->second_place_text->TabIndex = 1;
			this->second_place_text->Text = L"2.";
			this->second_place_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->second_place_text->TextChanged += gcnew System::EventHandler(this, &MyForm::second_place_text_TextChanged);
			// 
			// fourth_place_text
			// 
			this->fourth_place_text->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->fourth_place_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fourth_place_text->Location = System::Drawing::Point(3, 123);
			this->fourth_place_text->Name = L"fourth_place_text";
			this->fourth_place_text->ReadOnly = true;
			this->fourth_place_text->Size = System::Drawing::Size(64, 24);
			this->fourth_place_text->TabIndex = 10;
			this->fourth_place_text->Text = L"4.";
			this->fourth_place_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->fourth_place_text->TextChanged += gcnew System::EventHandler(this, &MyForm::fourth_place_text_TextChanged);
			// 
			// fifth_place_text
			// 
			this->fifth_place_text->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->fifth_place_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fifth_place_text->Location = System::Drawing::Point(3, 153);
			this->fifth_place_text->Name = L"fifth_place_text";
			this->fifth_place_text->ReadOnly = true;
			this->fifth_place_text->Size = System::Drawing::Size(64, 24);
			this->fifth_place_text->TabIndex = 7;
			this->fifth_place_text->Text = L"5.";
			this->fifth_place_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->fifth_place_text->TextChanged += gcnew System::EventHandler(this, &MyForm::fifth_place_text_TextChanged);
			// 
			// sixth_place_text
			// 
			this->sixth_place_text->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->sixth_place_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sixth_place_text->Location = System::Drawing::Point(3, 182);
			this->sixth_place_text->Name = L"sixth_place_text";
			this->sixth_place_text->ReadOnly = true;
			this->sixth_place_text->Size = System::Drawing::Size(64, 24);
			this->sixth_place_text->TabIndex = 5;
			this->sixth_place_text->Text = L"6.";
			this->sixth_place_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->sixth_place_text->TextChanged += gcnew System::EventHandler(this, &MyForm::sixth_place_text_TextChanged);
			// 
			// seventh_place_text
			// 
			this->seventh_place_text->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->seventh_place_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->seventh_place_text->Location = System::Drawing::Point(3, 213);
			this->seventh_place_text->Name = L"seventh_place_text";
			this->seventh_place_text->ReadOnly = true;
			this->seventh_place_text->Size = System::Drawing::Size(64, 24);
			this->seventh_place_text->TabIndex = 3;
			this->seventh_place_text->Text = L"7.";
			this->seventh_place_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->seventh_place_text->TextChanged += gcnew System::EventHandler(this, &MyForm::seventh_place_text_TextChanged);
			// 
			// eigth_place_text
			// 
			this->eigth_place_text->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->eigth_place_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eigth_place_text->Location = System::Drawing::Point(3, 243);
			this->eigth_place_text->Name = L"eigth_place_text";
			this->eigth_place_text->ReadOnly = true;
			this->eigth_place_text->Size = System::Drawing::Size(64, 24);
			this->eigth_place_text->TabIndex = 2;
			this->eigth_place_text->Text = L"8.";
			this->eigth_place_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->eigth_place_text->TextChanged += gcnew System::EventHandler(this, &MyForm::eigth_place_text_TextChanged);
			// 
			// ninth_place_text
			// 
			this->ninth_place_text->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ninth_place_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ninth_place_text->Location = System::Drawing::Point(3, 273);
			this->ninth_place_text->Name = L"ninth_place_text";
			this->ninth_place_text->ReadOnly = true;
			this->ninth_place_text->Size = System::Drawing::Size(64, 24);
			this->ninth_place_text->TabIndex = 11;
			this->ninth_place_text->Text = L"9.";
			this->ninth_place_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->ninth_place_text->TextChanged += gcnew System::EventHandler(this, &MyForm::ninth_place_text_TextChanged);
			// 
			// tenth_place_text
			// 
			this->tenth_place_text->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tenth_place_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tenth_place_text->Location = System::Drawing::Point(3, 303);
			this->tenth_place_text->Name = L"tenth_place_text";
			this->tenth_place_text->ReadOnly = true;
			this->tenth_place_text->Size = System::Drawing::Size(64, 24);
			this->tenth_place_text->TabIndex = 8;
			this->tenth_place_text->Text = L"10.";
			this->tenth_place_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tenth_place_text->TextChanged += gcnew System::EventHandler(this, &MyForm::tenth_place_text_TextChanged);
			// 
			// percent_label
			// 
			this->percent_label->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->percent_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percent_label->Location = System::Drawing::Point(335, 3);
			this->percent_label->Name = L"percent_label";
			this->percent_label->ReadOnly = true;
			this->percent_label->Size = System::Drawing::Size(258, 27);
			this->percent_label->TabIndex = 13;
			this->percent_label->Text = L"On-Time Percentage";
			this->percent_label->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->percent_label->TextChanged += gcnew System::EventHandler(this, &MyForm::percent_label_TextChanged);
			// 
			// airline_name_label
			// 
			this->airline_name_label->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->airline_name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airline_name_label->Location = System::Drawing::Point(73, 3);
			this->airline_name_label->Name = L"airline_name_label";
			this->airline_name_label->ReadOnly = true;
			this->airline_name_label->Size = System::Drawing::Size(256, 27);
			this->airline_name_label->TabIndex = 12;
			this->airline_name_label->Text = L"Airline Name";
			this->airline_name_label->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->airline_name_label->TextChanged += gcnew System::EventHandler(this, &MyForm::airline_name_label_TextChanged);
			// 
			// airline_1
			// 
			this->airline_1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->airline_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airline_1->Location = System::Drawing::Point(73, 33);
			this->airline_1->Name = L"airline_1";
			this->airline_1->ReadOnly = true;
			this->airline_1->Size = System::Drawing::Size(256, 24);
			this->airline_1->TabIndex = 16;
			this->airline_1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->airline_1->TextChanged += gcnew System::EventHandler(this, &MyForm::airline_1_TextChanged);
			// 
			// airline_2
			// 
			this->airline_2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->airline_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airline_2->Location = System::Drawing::Point(73, 63);
			this->airline_2->Name = L"airline_2";
			this->airline_2->ReadOnly = true;
			this->airline_2->Size = System::Drawing::Size(256, 24);
			this->airline_2->TabIndex = 15;
			this->airline_2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->airline_2->TextChanged += gcnew System::EventHandler(this, &MyForm::airline_2_TextChanged);
			// 
			// airline_7
			// 
			this->airline_7->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->airline_7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airline_7->Location = System::Drawing::Point(73, 213);
			this->airline_7->Name = L"airline_7";
			this->airline_7->ReadOnly = true;
			this->airline_7->Size = System::Drawing::Size(256, 24);
			this->airline_7->TabIndex = 21;
			this->airline_7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->airline_7->TextChanged += gcnew System::EventHandler(this, &MyForm::airline_7_TextChanged);
			// 
			// percent_text_1
			// 
			this->percent_text_1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->percent_text_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percent_text_1->Location = System::Drawing::Point(335, 33);
			this->percent_text_1->Name = L"percent_text_1";
			this->percent_text_1->ReadOnly = true;
			this->percent_text_1->Size = System::Drawing::Size(258, 24);
			this->percent_text_1->TabIndex = 25;
			this->percent_text_1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->percent_text_1->TextChanged += gcnew System::EventHandler(this, &MyForm::percent_text_1_TextChanged);
			// 
			// airline_6
			// 
			this->airline_6->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->airline_6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airline_6->Location = System::Drawing::Point(73, 182);
			this->airline_6->Name = L"airline_6";
			this->airline_6->ReadOnly = true;
			this->airline_6->Size = System::Drawing::Size(256, 24);
			this->airline_6->TabIndex = 20;
			this->airline_6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->airline_6->TextChanged += gcnew System::EventHandler(this, &MyForm::airline_6_TextChanged);
			// 
			// airline_4
			// 
			this->airline_4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->airline_4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airline_4->Location = System::Drawing::Point(73, 123);
			this->airline_4->Name = L"airline_4";
			this->airline_4->ReadOnly = true;
			this->airline_4->Size = System::Drawing::Size(256, 24);
			this->airline_4->TabIndex = 18;
			this->airline_4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->airline_4->TextChanged += gcnew System::EventHandler(this, &MyForm::airline_4_TextChanged);
			// 
			// airline_8
			// 
			this->airline_8->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->airline_8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airline_8->Location = System::Drawing::Point(73, 243);
			this->airline_8->Name = L"airline_8";
			this->airline_8->ReadOnly = true;
			this->airline_8->Size = System::Drawing::Size(256, 24);
			this->airline_8->TabIndex = 22;
			this->airline_8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->airline_8->TextChanged += gcnew System::EventHandler(this, &MyForm::airline_8_TextChanged);
			// 
			// airline_9
			// 
			this->airline_9->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->airline_9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airline_9->Location = System::Drawing::Point(73, 273);
			this->airline_9->Name = L"airline_9";
			this->airline_9->ReadOnly = true;
			this->airline_9->Size = System::Drawing::Size(256, 24);
			this->airline_9->TabIndex = 23;
			this->airline_9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->airline_9->TextChanged += gcnew System::EventHandler(this, &MyForm::airline_9_TextChanged);
			// 
			// airline_5
			// 
			this->airline_5->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->airline_5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airline_5->Location = System::Drawing::Point(73, 153);
			this->airline_5->Name = L"airline_5";
			this->airline_5->ReadOnly = true;
			this->airline_5->Size = System::Drawing::Size(256, 24);
			this->airline_5->TabIndex = 19;
			this->airline_5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->airline_5->TextChanged += gcnew System::EventHandler(this, &MyForm::airline_5_TextChanged);
			// 
			// airline_10
			// 
			this->airline_10->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->airline_10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airline_10->Location = System::Drawing::Point(73, 303);
			this->airline_10->Name = L"airline_10";
			this->airline_10->ReadOnly = true;
			this->airline_10->Size = System::Drawing::Size(256, 24);
			this->airline_10->TabIndex = 24;
			this->airline_10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->airline_10->TextChanged += gcnew System::EventHandler(this, &MyForm::airline_10_TextChanged);
			// 
			// airline_3
			// 
			this->airline_3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->airline_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airline_3->Location = System::Drawing::Point(73, 93);
			this->airline_3->Name = L"airline_3";
			this->airline_3->ReadOnly = true;
			this->airline_3->Size = System::Drawing::Size(256, 24);
			this->airline_3->TabIndex = 17;
			this->airline_3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->airline_3->TextChanged += gcnew System::EventHandler(this, &MyForm::airline_3_TextChanged);
			// 
			// table_title
			// 
			this->table_title->BackColor = System::Drawing::SystemColors::Info;
			this->table_title->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->table_title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->table_title->Location = System::Drawing::Point(12, 328);
			this->table_title->Multiline = true;
			this->table_title->Name = L"table_title";
			this->table_title->ReadOnly = true;
			this->table_title->Size = System::Drawing::Size(641, 31);
			this->table_title->TabIndex = 13;
			this->table_title->Text = L"Top 10 Most reliable Airlines at ___ airport in ___:";
			this->table_title->TextChanged += gcnew System::EventHandler(this, &MyForm::table_title_TextChanged_1);
			// 
			// alg_speed_text
			// 
			this->alg_speed_text->BackColor = System::Drawing::SystemColors::Info;
			this->alg_speed_text->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->alg_speed_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->alg_speed_text->Location = System::Drawing::Point(2, 746);
			this->alg_speed_text->Name = L"alg_speed_text";
			this->alg_speed_text->ReadOnly = true;
			this->alg_speed_text->Size = System::Drawing::Size(677, 21);
			this->alg_speed_text->TabIndex = 16;
			this->alg_speed_text->Text = L"Algorithm speed: ";
			// 
			// month_label
			// 
			this->month_label->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->month_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->month_label->Location = System::Drawing::Point(24, 92);
			this->month_label->Multiline = true;
			this->month_label->Name = L"month_label";
			this->month_label->ReadOnly = true;
			this->month_label->Size = System::Drawing::Size(123, 26);
			this->month_label->TabIndex = 17;
			this->month_label->Text = L"Month:";
			// 
			// month_dropdown
			// 
			this->month_dropdown->FormattingEnabled = true;
			this->month_dropdown->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Jan", L"Feb", L"Mar", L"Apr", L"May", L"Jun",
					L"Jul", L"Aug", L"Sep", L"Oct", L"Nov", L"Dec"
			});
			this->month_dropdown->Location = System::Drawing::Point(39, 124);
			this->month_dropdown->Name = L"month_dropdown";
			this->month_dropdown->Size = System::Drawing::Size(62, 24);
			this->month_dropdown->TabIndex = 18;
			// 
			// airport_dropdown
			// 
			this->airport_dropdown->FormattingEnabled = true;
			this->airport_dropdown->Items->AddRange(gcnew cli::array< System::Object^  >(404) {
				L"ABE", L"ABI", L"ABQ", L"ABR", L"ABY",
					L"ACK", L"ACT", L"ACV", L"ACY", L"ADK", L"ADQ", L"AEX", L"AGS", L"AKN", L"ALB", L"ALO", L"AMA", L"ANC", L"APF", L"APN", L"ART",
					L"ASE", L"ATL", L"ATW", L"ATY", L"AUS", L"AVL", L"AVP", L"AZA", L"AZO", L"BDL", L"BET", L"BFF", L"BFL", L"BFM", L"BGM", L"BGR",
					L"BHM", L"BIL", L"BIS", L"BJI", L"BKG", L"BLI", L"BLV", L"BMI", L"BNA", L"BOI", L"BOS", L"BPT", L"BQK", L"BQN", L"BRD", L"BRO",
					L"BRW", L"BTM", L"BTR", L"BTV", L"BUF", L"BUR", L"BWI", L"BZN", L"CAE", L"CAK", L"CBM", L"CDC", L"CDV", L"CEC", L"CGI", L"CHA",
					L"CHO", L"CHS", L"CIC", L"CID", L"CIU", L"CKB", L"CLD", L"CLE", L"CLL", L"CLT", L"CMH", L"CMI", L"CMX", L"CNY", L"COD", L"COS",
					L"COU", L"CPR", L"CRP", L"CRW", L"CSG", L"CVG", L"CWA", L"CYS", L"DAB", L"DAL", L"DAY", L"DBQ", L"DCA", L"DEN", L"DFW", L"DHN",
					L"DIK", L"DLG", L"DLH", L"DRO", L"DRT", L"DSM", L"DTW", L"DUT", L"DVL", L"EAR", L"EAU", L"ECP", L"EFD", L"EGE", L"EKO", L"ELM",
					L"ELP", L"ENV", L"ERI", L"ESC", L"EUG", L"EVV", L"EWN", L"EWR", L"EYW", L"FAI", L"FAR", L"FAT", L"FAY", L"FCA", L"FLG", L"FLL",
					L"FLO", L"FMN", L"FNL", L"FNT", L"FOE", L"FSD", L"FSM", L"FWA", L"GCC", L"GCK", L"GEG", L"GFK", L"GGG", L"GJT", L"GLH", L"GNV",
					L"GPT", L"GRB", L"GRI", L"GRK", L"GRR", L"GSO", L"GSP", L"GST", L"GTF", L"GTR", L"GUC", L"GUM", L"HDN", L"HGR", L"HHH", L"HIB",
					L"HKY", L"HLN", L"HNL", L"HOB", L"HOU", L"HPN", L"HRL", L"HSV", L"HTS", L"HVN", L"HYA", L"HYS", L"IAD", L"IAG", L"IAH", L"ICT",
					L"IDA", L"IFP", L"ILE", L"ILG", L"ILM", L"IMT", L"IND", L"INL", L"IPL", L"ISN", L"ISO", L"ISP", L"ITH", L"ITO", L"IYK", L"JAC",
					L"JAN", L"JAX", L"JFK", L"JLN", L"JMS", L"JNU", L"KOA", L"KTN", L"LAN", L"LAR", L"LAS", L"LAW", L"LAX", L"LBB", L"LBE", L"LBF",
					L"LBL", L"LCH", L"LCK", L"LEX", L"LFT", L"LGA", L"LGB", L"LIH", L"LIT", L"LMT", L"LNK", L"LNY", L"LRD", L"LSE", L"LWB", L"LWS",
					L"LYH", L"MAF", L"MBS", L"MCI", L"MCN", L"MCO", L"MDT", L"MDW", L"MEI", L"MEM", L"MFE", L"MFR", L"MGM", L"MHK", L"MHT", L"MIA",
					L"MKC", L"MKE", L"MKG", L"MKK", L"MLB", L"MLI", L"MLU", L"MMH", L"MOB", L"MOD", L"MOT", L"MQT", L"MRY", L"MSN", L"MSO", L"MSP",
					L"MSY", L"MTH", L"MTJ", L"MVY", L"MWH", L"MYR", L"OAJ", L"OAK", L"OGD", L"OGG", L"OGS", L"OKC", L"OMA", L"OME", L"ONT", L"ORD",
					L"ORF", L"ORH", L"OTH", L"OTZ", L"OWB", L"OXR", L"PAE", L"PAH", L"PBG", L"PBI", L"PDX", L"PFN", L"PGD", L"PGV", L"PHF", L"PHL",
					L"PHX", L"PIA", L"PIB", L"PIE", L"PIH", L"PIR", L"PIT", L"PLN", L"PMD", L"PNS", L"PPG", L"PRC", L"PSC", L"PSE", L"PSG", L"PSM",
					L"PSP", L"PUB", L"PVD", L"PVU", L"PWM", L"RAP", L"RCA", L"RDD", L"RDM", L"RDU", L"RFD", L"RHI", L"RIC", L"RKS", L"RNO", L"ROA",
					L"ROC", L"ROW", L"RST", L"RSW", L"SAF", L"SAN", L"SAT", L"SAV", L"SBA", L"SBN", L"SBP", L"SCC", L"SCE", L"SCK", L"SDF", L"SEA",
					L"SFB", L"SFO", L"SGF", L"SGU", L"SHD", L"SHV", L"SIT", L"SJC", L"SJT", L"SJU", L"SKA", L"SLC", L"SLE", L"SLN", L"SMF", L"SMX",
					L"SNA", L"SOP", L"SPI", L"SPN", L"SPS", L"SRQ", L"STC", L"STL", L"STS", L"STT", L"STX", L"SUN", L"SUX", L"SWF", L"SWO", L"SYR",
					L"TEX", L"TKI", L"TLH", L"TOL", L"TPA", L"TRI", L"TTN", L"TUL", L"TUP", L"TUS", L"TVC", L"TWF", L"TXK", L"TYR", L"TYS", L"UIN",
					L"USA", L"UST", L"UTM", L"VCT", L"VEL", L"VIS", L"VLD", L"VPS", L"WRG", L"WYS", L"XNA", L"YAK", L"YKM", L"YNG", L"YUM"
			});
			this->airport_dropdown->Location = System::Drawing::Point(168, 124);
			this->airport_dropdown->Name = L"airport_dropdown";
			this->airport_dropdown->Size = System::Drawing::Size(62, 24);
			this->airport_dropdown->TabIndex = 20;
			// 
			// airport_label
			// 
			this->airport_label->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->airport_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->airport_label->Location = System::Drawing::Point(153, 92);
			this->airport_label->Multiline = true;
			this->airport_label->Name = L"airport_label";
			this->airport_label->ReadOnly = true;
			this->airport_label->Size = System::Drawing::Size(123, 26);
			this->airport_label->TabIndex = 19;
			this->airport_label->Text = L"Airport:";
			// 
			// sort_alg_dropdown
			// 
			this->sort_alg_dropdown->FormattingEnabled = true;
			this->sort_alg_dropdown->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Quicksort", L"Heapsort" });
			this->sort_alg_dropdown->Location = System::Drawing::Point(297, 124);
			this->sort_alg_dropdown->Name = L"sort_alg_dropdown";
			this->sort_alg_dropdown->Size = System::Drawing::Size(109, 24);
			this->sort_alg_dropdown->TabIndex = 22;
			// 
			// alg_type_label
			// 
			this->alg_type_label->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->alg_type_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->alg_type_label->Location = System::Drawing::Point(282, 92);
			this->alg_type_label->Multiline = true;
			this->alg_type_label->Name = L"alg_type_label";
			this->alg_type_label->ReadOnly = true;
			this->alg_type_label->Size = System::Drawing::Size(184, 26);
			this->alg_type_label->TabIndex = 21;
			this->alg_type_label->Text = L"Sorting Algorithm:";
			// 
			// delay_type_dropdown
			// 
			this->delay_type_dropdown->FormattingEnabled = true;
			this->delay_type_dropdown->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"General (All delays)", L"Carrier fault" });
			this->delay_type_dropdown->Location = System::Drawing::Point(497, 124);
			this->delay_type_dropdown->Name = L"delay_type_dropdown";
			this->delay_type_dropdown->Size = System::Drawing::Size(107, 24);
			this->delay_type_dropdown->TabIndex = 24;
			// 
			// delay_type_label
			// 
			this->delay_type_label->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->delay_type_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delay_type_label->Location = System::Drawing::Point(482, 92);
			this->delay_type_label->Multiline = true;
			this->delay_type_label->Name = L"delay_type_label";
			this->delay_type_label->ReadOnly = true;
			this->delay_type_label->Size = System::Drawing::Size(184, 26);
			this->delay_type_label->TabIndex = 23;
			this->delay_type_label->Text = L"Delay Type:";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(689, 797);
			this->Controls->Add(this->delay_type_dropdown);
			this->Controls->Add(this->delay_type_label);
			this->Controls->Add(this->sort_alg_dropdown);
			this->Controls->Add(this->alg_type_label);
			this->Controls->Add(this->airport_dropdown);
			this->Controls->Add(this->airport_label);
			this->Controls->Add(this->month_dropdown);
			this->Controls->Add(this->month_label);
			this->Controls->Add(this->gen_table_button);
			this->Controls->Add(this->instruction_text_2);
			this->Controls->Add(this->page_title);
			this->Controls->Add(this->alg_speed_text);
			this->Controls->Add(this->table_title);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
	private: System::Void month_dropdown_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void month_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void instruction_text_1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void page_title_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void month_text_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airport_dropdown_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void sort_alg_type_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void sort_alg_dropdown_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void instruction_text_2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void table_title_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void table_title_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void listBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airline_1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airline_2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void place_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airline_name_label_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void percent_label_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void percent_text_1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void first_place_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void second_place_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void percent_text_2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void percent_text_3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airline_3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airline_4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void third_place_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void fourth_place_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void fifth_place_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void sixth_place_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void seventh_place_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void eigth_place_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ninth_place_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tenth_place_text_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airline_10_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airline_9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airline_8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airline_7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airline_5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void airline_6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void percent_text_4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}


		   //Generates the table with new values based on the user selection 
	private: System::Void gen_table_button_Click(System::Object^ sender, System::EventArgs^ e) {

		
		//Check to make sure valid selections have been 
		if (airport_dropdown->Text != "" && month_dropdown->Text != "" && sort_alg_dropdown->Text != "" && delay_type_dropdown->Text != "") {
			
			
			double alg_time = 0.0; // Variable to store the amount of time taken by the sorting algorithm


			this->table_title->Text = "Top 10 Most reliable Airlines at " + airport_dropdown->Text + " airport in " + month_dropdown->Text + " : ";

			//Create mappings to convert dropdown values to usable strings 
			//How to convert was derived from this link: 
			//https://stackoverflow.com/questions/1300718/c-net-convert-systemstring-to-stdstring

			msclr::interop::marshal_context context;
			std::string month = context.marshal_as<std::string>(month_dropdown->Text);
			std::string airport = context.marshal_as<std::string>(airport_dropdown->Text);

			//Create a mapping to convert months to integers 
			std::map<std::string, int> converted_month;
			converted_month["Jan"] = 1;
			converted_month["Feb"] = 2;
			converted_month["Mar"] = 3;
			converted_month["Apr"] = 4;
			converted_month["May"] = 5;
			converted_month["Jun"] = 6;
			converted_month["Jul"] = 7;
			converted_month["Aug"] = 8;
			converted_month["Sep"] = 9;
			converted_month["Oct"] = 10;
			converted_month["Nov"] = 11;
			converted_month["Dec"] = 12;


			//Perform desired sort and store values in a vector 
			//Quicksort General
			std::pair<std::vector<std::string>, std::vector<std::string>> sorted_data;
			if (this->sort_alg_dropdown->Text == "Quicksort" && this->delay_type_dropdown->Text == "General (All delays)") {


				//Get start time 
				std::clock_t start_time = clock();


				//Run the method to sort and return the data 
				sorted_data = (*airports)[airport]->QuicksortByDelayRatio(converted_month[month]);

				//Get end time 
				std::clock_t end_time = clock();


				//Calculate amount of time taken
				alg_time = (double(end_time) - double(start_time)) / double(CLOCKS_PER_SEC);
				this->alg_speed_text->Text = "Algorithm speed: Time taken by Quicksort is " + alg_time.ToString() + " sec";
			} 
			//Heapsort General 
			
			else if (sort_alg_dropdown->Text == "Heapsort" && this->delay_type_dropdown->Text == "General (All delays)") {

				
				//Get start time 
				std::clock_t start_time = clock();
				

				//Run the method to sort and return the data 
				sorted_data = (*airports)[airport]->HeapsortByDelayRatio(converted_month[month]);


				//Get end time 
				std::clock_t end_time = clock();


				//Calculate amount of time taken
				alg_time = (double(end_time) - double(start_time)) / double(CLOCKS_PER_SEC);
				this->alg_speed_text->Text = "Algorithm speed: Time taken by Heapsort is " + alg_time.ToString() + " sec";
			}

			//Quicksort Carrier fault
			else if (sort_alg_dropdown->Text == "Quicksort" && this->delay_type_dropdown->Text == "Carrier fault") {


				//Get start time 
				std::clock_t start_time = clock();

				//Run the method to sort and return the data 
				sorted_data = (*airports)[airport]->QuicksortByAirlineDelayRatio(converted_month[month]);


				//Get end time 
				std::clock_t end_time = clock();


				//Calculate amount of time taken
				alg_time = (double(end_time) - double(start_time)) / double(CLOCKS_PER_SEC);
				this->alg_speed_text->Text = "Algorithm speed: Time taken by Quicksort is " + alg_time.ToString() + " sec";
			}

			//Heapsort Carrier fault
			else if (sort_alg_dropdown->Text == "Heapsort" && this->delay_type_dropdown->Text == "Carrier fault") {


				//Get start time 
				std::clock_t start_time = clock();


				//Run the method to sort and return the data 
				sorted_data = (*airports)[airport]->HeapsortByAirlineDelayRatio(converted_month[month]);
			

				//Get end time 
				std::clock_t end_time = clock();


				//Calculate amount of time taken
				alg_time = (double(end_time) - double(start_time)) / double(CLOCKS_PER_SEC);
				this->alg_speed_text->Text = "Algorithm speed: Time taken by Heapsort is " + alg_time.ToString() + " sec";
			}



			//Update table entries 
			if (sorted_data.first.size() > 0) { //Check to ensure propor size of airline vector 
				this->airline_1->Text = gcnew String((sorted_data.first)[0].data()); // Convert std::string to System::String and change the value in the table
				this->percent_text_1->Text = gcnew String(sorted_data.second[0].data()) + "%"; // Display the percentage for the airline 
			}
			else {
				this->airline_1->Text = "";
				this->percent_text_1->Text = "";
			}
			if (sorted_data.first.size() > 1) {
				this->airline_2->Text = gcnew String((sorted_data.first)[1].data());
				this->percent_text_2->Text = gcnew String(sorted_data.second[1].data()) + "%";
			}
			else {
				this->airline_2->Text = "";
				this->percent_text_2->Text = "";
			}
			if (sorted_data.first.size() > 2) {
				this->airline_3->Text = gcnew String((sorted_data.first)[2].data());
				this->percent_text_3->Text = gcnew String(sorted_data.second[2].data()) + "%";
			}

			else {
				this->airline_3->Text = "";
				this->percent_text_3->Text = "";
			}
			if (sorted_data.first.size() > 3) {
				this->airline_4->Text = gcnew String((sorted_data.first)[3].data());
				this->percent_text_4->Text = gcnew String(sorted_data.second[3].data()) + "%";
			}
			else {
				this->airline_4->Text = "";
				this->percent_text_4->Text = "";
			}
			if (sorted_data.first.size() > 4) {
				this->airline_5->Text = gcnew String((sorted_data.first)[4].data());
				this->percent_text_5->Text = gcnew String(sorted_data.second[4].data()) + "%";
			}
			else {
				this->airline_5->Text = "";
				this->percent_text_5->Text = "";
			}
			if (sorted_data.first.size() > 5) {
				this->airline_6->Text = gcnew String((sorted_data.first)[5].data());
				this->percent_text_6->Text = gcnew String(sorted_data.second[5].data()) + "%";
			}
			else {
				this->airline_6->Text = "";
				this->percent_text_6->Text = "";
			}
			if (sorted_data.first.size() > 6) {
				this->airline_7->Text = gcnew String((sorted_data.first)[6].data());
				this->percent_text_7->Text = gcnew String(sorted_data.second[6].data()) + "%";
			}
			else {
				this->airline_7->Text = "";
				this->percent_text_7->Text = "";
			}
			if (sorted_data.first.size() > 7) {
				this->airline_8->Text = gcnew String((sorted_data.first)[7].data());
				this->percent_text_8->Text = gcnew String(sorted_data.second[7].data()) + "%";
			}
			else {
				this->airline_8->Text = "";
				this->percent_text_8->Text = "";
			}
			if (sorted_data.first.size() > 8) {
				this->airline_9->Text = gcnew String((sorted_data.first)[8].data());
				this->percent_text_9->Text = gcnew String(sorted_data.second[8].data()) + "%";
			}
			else {
				this->airline_9->Text = "";
				this->percent_text_9->Text = "";
			}
			if (sorted_data.first.size() > 9) {
				this->airline_10->Text = gcnew String((sorted_data.first)[9].data());
				this->percent_text_10->Text = gcnew String(sorted_data.second[9].data()) + "%";
			}
			else {
				this->airline_10->Text = "";
				this->percent_text_10->Text = "";
			}



		}

	


	}
	};
}
