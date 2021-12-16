
#include "About.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>

#pragma once

namespace XmlParser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainGui
	/// </summary>
	public ref class MainGui : public System::Windows::Forms::Form
	{
	public:
		MainGui(void)
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
		~MainGui()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ openbutton;
	protected:

	protected:
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ Savebutton;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainGui::typeid));
			this->openbutton = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Savebutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openbutton
			// 
			this->openbutton->Location = System::Drawing::Point(479, 21);
			this->openbutton->Name = L"openbutton";
			this->openbutton->Size = System::Drawing::Size(94, 36);
			this->openbutton->TabIndex = 0;
			this->openbutton->Text = L"Open";
			this->openbutton->UseVisualStyleBackColor = true;
			this->openbutton->Click += gcnew System::EventHandler(this, &MainGui::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 58);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(440, 369);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(6, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 31);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Xml File Selection";
			this->label1->Click += gcnew System::EventHandler(this, &MainGui::label1_Click);
			// 
			// Savebutton
			// 
			this->Savebutton->Location = System::Drawing::Point(479, 391);
			this->Savebutton->Name = L"Savebutton";
			this->Savebutton->Size = System::Drawing::Size(94, 36);
			this->Savebutton->TabIndex = 3;
			this->Savebutton->Text = L"Save";
			this->Savebutton->UseVisualStyleBackColor = true;
			// 
			// MainGui
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(585, 439);
			this->Controls->Add(this->Savebutton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->openbutton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainGui";
			this->Text = L"XmlParser";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		OpenFileDialog^ xmlop = gcnew OpenFileDialog;
		if (xmlop->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			richTextBox1->LoadFile(xmlop->FileName, RichTextBoxStreamType::PlainText);
			//label1->Visible = true;
			label1->Text = "The Original Xml File";

		}
		
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (label1->Text == "Xml File Selection")
		{
			if (MessageBox::Show("Please Select An Xml File", " ", MessageBoxButtons::OKCancel,
				MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
			{
				openbutton->PerformClick();
			}

		}
	}
	
	private: static string tostdstring(System::String^ strobj) {
		using System::Runtime::InteropServices::Marshal;
		System::IntPtr pointer = Marshal::StringToHGlobalAnsi(strobj);
		char* charpointer = reinterpret_cast<char*>(pointer.ToPointer());
		std::string returnString(charpointer, strobj->Length);
		Marshal::FreeHGlobal(pointer);
		return returnString;
	}

	private: static String^ tosysstring(string s) {
		return gcnew String(s.c_str());
	}

};
}
