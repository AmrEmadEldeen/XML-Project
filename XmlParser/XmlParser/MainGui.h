#include "About.h"
#include "json_conv.h"
#include <iostream>
#include <fstream>
#include <streambuf>
#include <vector>
#include <string>
#include <stack>
#include <cctype>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <stdlib.h>

#pragma once
namespace XmlParser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace std;
	/// <summary>
	/// Contains the Main User Interface components
	/// </summary>
	public ref class MainGui : public System::Windows::Forms::Form
	{
	public:
		MainGui(void)
		{
			InitializeComponent();

		}
		MainGui(String^ xmldata)
		{
			InitializeComponent();
			richTextBox1->Text = xmldata;
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
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ Savebutton;
	private: System::Windows::Forms::Button^ compressbutton;
	private: System::Windows::Forms::Button^ checkbutton;
	private: System::Windows::Forms::Button^ Jsonbutton;
	private: System::Windows::Forms::Button^ decombutton;
	private: System::Windows::Forms::Button^ Aboutbutton;

	private: System::Windows::Forms::Button^ minifbutton;
	private: System::Windows::Forms::Button^ exitbutton;
	private: System::Windows::Forms::Button^ formatbutton;






	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainGui::typeid));
			this->openbutton = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Savebutton = (gcnew System::Windows::Forms::Button());
			this->compressbutton = (gcnew System::Windows::Forms::Button());
			this->checkbutton = (gcnew System::Windows::Forms::Button());
			this->Jsonbutton = (gcnew System::Windows::Forms::Button());
			this->decombutton = (gcnew System::Windows::Forms::Button());
			this->Aboutbutton = (gcnew System::Windows::Forms::Button());
			this->minifbutton = (gcnew System::Windows::Forms::Button());
			this->exitbutton = (gcnew System::Windows::Forms::Button());
			this->formatbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openbutton
			// 
			this->openbutton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->openbutton->Location = System::Drawing::Point(493, 25);
			this->openbutton->Name = L"openbutton";
			this->openbutton->Size = System::Drawing::Size(80, 28);
			this->openbutton->TabIndex = 0;
			this->openbutton->Text = L"Open";
			this->openbutton->UseVisualStyleBackColor = true;
			this->openbutton->Click += gcnew System::EventHandler(this, &MainGui::openbutton_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::Black;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->ForeColor = System::Drawing::Color::White;
			this->richTextBox1->Location = System::Drawing::Point(12, 52);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(439, 375);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(5, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(224, 37);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Select an Xml File";
			this->label1->Click += gcnew System::EventHandler(this, &MainGui::label1_Click);
			// 
			// Savebutton
			// 
			this->Savebutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Savebutton->Location = System::Drawing::Point(493, 263);
			this->Savebutton->Name = L"Savebutton";
			this->Savebutton->Size = System::Drawing::Size(80, 28);
			this->Savebutton->TabIndex = 3;
			this->Savebutton->Text = L"Save";
			this->Savebutton->UseVisualStyleBackColor = true;
			this->Savebutton->Click += gcnew System::EventHandler(this, &MainGui::Savebutton_Click);
			// 
			// compressbutton
			// 
			this->compressbutton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->compressbutton->FlatAppearance->BorderColor = System::Drawing::SystemColors::ButtonFace;
			this->compressbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->compressbutton->ForeColor = System::Drawing::Color::Black;
			this->compressbutton->Location = System::Drawing::Point(493, 161);
			this->compressbutton->Name = L"compressbutton";
			this->compressbutton->Size = System::Drawing::Size(80, 28);
			this->compressbutton->TabIndex = 4;
			this->compressbutton->Text = L"Compress";
			this->compressbutton->UseVisualStyleBackColor = false;
			this->compressbutton->Click += gcnew System::EventHandler(this, &MainGui::compressbutton_Click);
			// 
			// checkbutton
			// 
			this->checkbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->checkbutton->Location = System::Drawing::Point(493, 93);
			this->checkbutton->Name = L"checkbutton";
			this->checkbutton->Size = System::Drawing::Size(80, 28);
			this->checkbutton->TabIndex = 5;
			this->checkbutton->Text = L"Error Check";
			this->checkbutton->UseVisualStyleBackColor = true;
			this->checkbutton->Click += gcnew System::EventHandler(this, &MainGui::checkbutton_Click);
			// 
			// Jsonbutton
			// 
			this->Jsonbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Jsonbutton->Location = System::Drawing::Point(493, 229);
			this->Jsonbutton->Name = L"Jsonbutton";
			this->Jsonbutton->Size = System::Drawing::Size(80, 28);
			this->Jsonbutton->TabIndex = 6;
			this->Jsonbutton->Text = L"Json Convert";
			this->Jsonbutton->UseVisualStyleBackColor = true;
			this->Jsonbutton->Click += gcnew System::EventHandler(this, &MainGui::Jsonbutton_Click);
			// 
			// decombutton
			// 
			this->decombutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->decombutton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F));
			this->decombutton->Location = System::Drawing::Point(493, 195);
			this->decombutton->Name = L"decombutton";
			this->decombutton->Size = System::Drawing::Size(80, 28);
			this->decombutton->TabIndex = 7;
			this->decombutton->Text = L"Decompress";
			this->decombutton->UseVisualStyleBackColor = true;
			this->decombutton->Click += gcnew System::EventHandler(this, &MainGui::decombutton_Click);
			// 
			// Aboutbutton
			// 
			this->Aboutbutton->Location = System::Drawing::Point(493, 365);
			this->Aboutbutton->Name = L"Aboutbutton";
			this->Aboutbutton->Size = System::Drawing::Size(80, 28);
			this->Aboutbutton->TabIndex = 8;
			this->Aboutbutton->Text = L"About";
			this->Aboutbutton->UseVisualStyleBackColor = true;
			this->Aboutbutton->Click += gcnew System::EventHandler(this, &MainGui::Aboutbutton_Click);
			// 
			// minifbutton
			// 
			this->minifbutton->FlatAppearance->BorderColor = System::Drawing::SystemColors::ButtonFace;
			this->minifbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minifbutton->Location = System::Drawing::Point(493, 127);
			this->minifbutton->Name = L"minifbutton";
			this->minifbutton->Size = System::Drawing::Size(80, 28);
			this->minifbutton->TabIndex = 10;
			this->minifbutton->Text = L"Minify";
			this->minifbutton->UseVisualStyleBackColor = true;
			this->minifbutton->Click += gcnew System::EventHandler(this, &MainGui::minifbutton_Click);
			// 
			// exitbutton
			// 
			this->exitbutton->Location = System::Drawing::Point(493, 399);
			this->exitbutton->Name = L"exitbutton";
			this->exitbutton->Size = System::Drawing::Size(80, 28);
			this->exitbutton->TabIndex = 11;
			this->exitbutton->Text = L"Exit";
			this->exitbutton->UseVisualStyleBackColor = true;
			this->exitbutton->Click += gcnew System::EventHandler(this, &MainGui::exitbutton_Click);
			// 
			// formatbutton
			// 
			this->formatbutton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->formatbutton->Location = System::Drawing::Point(493, 59);
			this->formatbutton->Name = L"formatbutton";
			this->formatbutton->Size = System::Drawing::Size(80, 28);
			this->formatbutton->TabIndex = 12;
			this->formatbutton->Text = L"Format";
			this->formatbutton->UseVisualStyleBackColor = true;
			this->formatbutton->Click += gcnew System::EventHandler(this, &MainGui::formatbutton_Click);
			// 
			// MainGui
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(585, 439);
			this->Controls->Add(this->formatbutton);
			this->Controls->Add(this->exitbutton);
			this->Controls->Add(this->minifbutton);
			this->Controls->Add(this->Aboutbutton);
			this->Controls->Add(this->decombutton);
			this->Controls->Add(this->Jsonbutton);
			this->Controls->Add(this->checkbutton);
			this->Controls->Add(this->compressbutton);
			this->Controls->Add(this->Savebutton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->openbutton);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MainGui";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"XmlParser";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (label1->Text == "Xml File Selection")
		{
			if (MessageBox::Show("Please Select An Xml File", " ", MessageBoxButtons::OKCancel,
				MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
			{
				openbutton->PerformClick();
			}

		}
	}
	private: System::Void openbutton_Click(System::Object^ sender, System::EventArgs^ e) {

		OpenFileDialog^ xmlop = gcnew OpenFileDialog;
		xmlop->Filter = "Xml files|*.xml";
		if (xmlop->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			String^ filename = xmlop->FileName;
			IO::StreamReader^ myXmlFile = gcnew IO::StreamReader(filename);
			String^ content = myXmlFile->ReadToEnd();
			richTextBox1->Text = content;
			myXmlFile->Close();
			label1->Text = "The Original Xml File";

		}
		richTextBox1->Visible = true;
	}

	private: System::Void Savebutton_Click(System::Object^ sender, System::EventArgs^ e) {

		SaveFileDialog^ xmlsv = gcnew SaveFileDialog;
		xmlsv->CreatePrompt = true;
		xmlsv->OverwritePrompt = true;
		xmlsv->FileName = "MyXml";
		xmlsv->Filter = "Xml files|*.xml";
		xmlsv->DefaultExt = "*.xml";
		xmlsv->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments);
		

		if (xmlsv->ShowDialog() == System::Windows::Forms::DialogResult::OK && xmlsv->FileName->Length > 0)
		{
			
			String^ filename = xmlsv->FileName;
			IO::StreamWriter^ myXmlFile = gcnew IO::StreamWriter(filename);
			myXmlFile->WriteLine(richTextBox1->Text);
			myXmlFile->Flush();
			myXmlFile->Close();

			label1->Text = "The Xml File Has Been Saved";
		}
	}
	private: System::Void Aboutbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		About^ about1 = gcnew About;
		about1->ShowDialog();
	}
	private: System::Void checkbutton_Click(System::Object^ sender, System::EventArgs^ e) {

		string S = tostdstring(richTextBox1->Text);
		Error_corr(S);
		label1->Text = "Errors in This Xml Are Detected";
		richTextBox1->ReadOnly = false;
		
	}
	private: System::Void compressbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		//Compression Function
		string s = tostdstring(richTextBox1->Text);
		savecompressedFile("Compressed.dat", Compress(s));
		label1->Text = "The Xml File Has Been Compressed \nand Saved as [Compressed.dat] ";
		richTextBox1->Visible = false;
	}

	private: System::Void minifbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		string s = tostdstring(richTextBox1->Text);
		s = minify(s);
		richTextBox1->Text = tosysstring(s);
		richTextBox1->Visible = true;
		label1->Text = "The Minifyied XML File";
	}

	private: System::Void decombutton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		string s = Decompression(readCompressedFile("Compressed.dat"));
		richTextBox1->Text = tosysstring(s);
		richTextBox1->Visible = true;
		label1->Text = "The XML File Has been Decompressed";
	}

	private: System::Void exitbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Are you Sure You want to Exit", " ", MessageBoxButtons::YesNo,
			MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes){
			Close();
		}
		
	}
	private: System::Void formatbutton_Click(System::Object^ sender, System::EventArgs^ e) {

		string st = tostdstring(richTextBox1->Text);
		vector<string> VecXml;
		unsigned int XmlSize;
		XML_vectorize(st, VecXml, XmlSize);
		string std = formatting(VecXml);
		richTextBox1->Text = tosysstring(std);
		label1->Text = "The XML File Has been Formated";
	}
	private: System::Void Jsonbutton_Click(System::Object^ sender, System::EventArgs^ e) {

		label1->Text = "The XML File Converted Into Json File";
		unsigned int xmlsize;
		string st = tostdstring(richTextBox1->Text);
		vector<string> xmlvec;
		XML_vectorize(st, xmlvec, xmlsize);
		int linesSize = xmlvec.size();
		node* root;
		root = create_tree(xmlvec, linesSize);
		string out;
		iteration(root, out);
		richTextBox1->Text = tosysstring(out);

	}

	// FUNCTIONS PARTITION

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
	private: void Error_corr(string& S)
		   {
			   stack <string> T;
			   stack <string> M;
			   string open = "";
			   string closed = "";
			   string C = "";
			   string K = "";
			   string B = "";

			   for (int i = 0; i < S.length(); i++)
			   {

				   if (S[i] == '<' && S[i + 1] != '/')
				   {
					   i++;
					   while (S[i] != '>')
					   {
						   open += S[i++];
					   }
					   T.push(open);
					   open.clear();
				   }
				   else if (S[i] == '<' && S[i + 1] == '/')
				   {
					   i = i + 2;
					   while (S[i] != '>')
					   {
						   closed += S[i++];
					   }
					   // pop if equal
					   if (closed == T.top())
					   {
						   T.pop();
						   closed.clear();
					   }
					   else {
						   B = T.top();
						   while (!T.empty() && T.top() != closed)
						   {
							   C = T.top();
							   M.push(C);
							   T.pop();
							   C.clear();
						   }
						   if (T.empty())
						   {
							   while (!M.empty())
							   {
								   K = M.top();
								   T.push(K);
								   M.pop();
								   K.clear();
							   }
							   MessageBox::Show("</" + tosysstring(closed) + "> Should be </" + tosysstring(T.top()) + ">", " ", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
							   T.pop();
							   closed.clear();
						   }
						   else if (closed == T.top())
						   {
							   T.pop();
							   while (!M.empty())
							   {
								   MessageBox::Show("<" + tosysstring(M.top()) + ">  with no closed tag", " ", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
								   M.pop();
							   }
							   closed.clear();
						   }
					   }
				   }

			   }
			   if (T.empty())
			   {
				   {MessageBox::Show("Finished Detection", " ", MessageBoxButtons::OK, MessageBoxIcon::Asterisk); }

			   }
			   while (!T.empty())
			   {
				   MessageBox::Show("<" + tosysstring(T.top()) + ">  with no closed tag", " ", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				   T.pop();
			   }
		   }
	//Compression "Encoding" function needs an input string that will be compressed "encoded".
	private: static vector<int> Compress(string input_stream)
	{
		unordered_map <string, int> table;
		for (int i = 0; i <= 255; i++)                     
		{
			string ch = "";                              
			ch += char(i);
			table[ch] = i;                                
		}                                                

		string current = "";                                    
		string next = "";                                     
		current += input_stream[0];                            
		int code = 256;                                          
		vector<int> output_code;                                 
	
		for (unsigned int i = 0; i < input_stream.length(); i++)   
		{
			if (i != input_stream.length() - 1)                   
				next += input_stream[i + 1];                      
		
			if (table.find(current + next) != table.end())    	
			{
				current = current + next;                      
			}
		
			else 											 
			{
				output_code.push_back(table[current]);	   
				table[current + next] = code;			 
				code++;                                
				current = next;                        
			}
			next = "";                                
		}
	
		output_code.push_back(table[current]);
		return output_code;                             
	}

	private: static void savecompressedFile(string f,vector<int> a) 
	{
		ofstream file(f, ios::binary | ios::out);                
	                                                        
		for (unsigned int i = 0; i < a.size(); i++) 
		{
			int num = a[i];
			file.write((char *)&num, sizeof(int));
		}
	
		file.close();
	}

	private: static vector<int> readCompressedFile(string f) 
	{
		ifstream file(f, ios::binary | ios::in);               
	                                                    
		vector<int>b;
	
		while (!file.eof())                                 
		{
			int num;
			file.read((char *)&num, sizeof(int));
			b.push_back(num);
		}
	
		file.close();
		return b;
	}
	private: static string Decompression(vector<int> input_code)
	{
		unordered_map <int, string> table;           
		for (int i = 0; i <= 255; i++) 
		{
			string ch = "";
			ch += char(i);
			table[i] = ch;                          
		}
	
		string Out_string = "";                          
		int old = input_code[0];                 
		int	 n;
		string s = table[old];                    
		string c = "";
		c += s[0];
		cout << s;                               
		int count = 256;                         
	
		for (unsigned int i = 0; i < input_code.size() - 1; i++)     
		{
			n = input_code[i + 1];                                  
		
			if (table.find(n) == table.end())                      
			{
				s = table[old];                                   
				s = s + c;
			}
		
			else                                                  
			{
				s = table[n];                                    
			}
		
			Out_string += s;                                           
			c = "";
			c += s[0];
			table[count] = table[old] + c;                            
			count++;
			old = n;
		}
		return Out_string;
	}
	private: static string minify(string str) {
		int count = 0;
		for (int i = 0; str[i]; i++)
			if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\v' && str[i] != '\b')
				str[count++] = str[i];
		str[count] = '\0';
		return str;
	}
	private: static bool findChar(char x, string y) {
		for (unsigned int i = 0; i < y.length(); i++) {
			if (y[i] == x) {
				return 1;
			}
		}
		return 0;
	}
	private: static string formatting(vector<string> t) {
		int ind = 0;
		int openflag = 0;
		int closeflag = 0;
		string str = "";
		for (unsigned int i = 0; i < t.size(); i++) {
			if (t[i][0] == '<' && (t[i][1] == '?' || t[i][1] == '!')) {
				str += t[i] + "\n";		//print output
			}
			else if (t[i][0] == '<' && !findChar('/', t[i])) {
				openflag++;
				closeflag = 0;
				if (openflag > 1) {
					ind++;
				}
				for (int j = 0; j < ind; j++) {
					str += "    ";		//print tab
				}
				str += t[i] + "\n";	//print output
			}
			else if (t[i][0] == '<' && t[i][1] == '/') {
				closeflag++;
				openflag = 0;
				if (closeflag > 1) {
					ind--;
				}
				for (int j = 0; j < ind; j++) {
					str += "    ";		//print tab
				}
				str += t[i] + "\n";	//print output
			}
			else if (t[i][0] == '<' && findChar('/', t[i])) {
				openflag++;
				closeflag = 0;
				if (openflag > 1) {
					ind++;
				}
				for (int j = 0; j < ind; j++) {
					str += "    ";		//print tab
				}
				str += t[i] + "\n";	//print output
				closeflag++;
				openflag = 0;
				if (closeflag > 1) {
					ind--;
				}
			}
			else {
				for (int j = 0; j < ind; j++) {
					str += "    ";		//print tab
				}
				str += t[i] + "\n";	//print output
			}
		}
		return str;
	}
	private: static void XML_vectorize(string file_data, vector<string> &XML_Vector, unsigned int &XML_Size)
	{

        int str_start;
        int str_end;
        int file_data_index=0;
        XML_Vector.reserve(10000);
        long long vector_capacity = 10000;
        while(file_data[file_data_index] != '\0')
        {
            string line="";

            while( (file_data[file_data_index] == ' ') && (file_data[file_data_index] == '\n' ))
            {
                file_data_index++;
            }

            if(file_data[file_data_index] == '<')
                {
                    str_start = file_data_index;
                    str_end = file_data_index + 1;
                    while(file_data[str_end] != '>' && file_data[str_end] != '\0')
                    {
                        str_end++;
                    }
                    if(file_data[str_end] == '\0')
                    {
                        break;
                    }
                }
                else //normal input(not tags)
                {
                    str_start = file_data_index;
                    str_end = file_data_index+1;
                    while(file_data[str_end] != '<' && file_data[str_end] != '\0' && file_data[str_end] != '\n' )
                    {
                        str_end++;
                    }
                    str_end--; //So we dont take "<" with us
                    if(file_data[str_end] == '\0' )
                    {
                        break;
                    }
                }

            if ( file_data[file_data_index] == '\n'   ) {
                file_data_index ++;
                continue;
            }

            file_data_index = str_end+1;
            XML_Vector.push_back(file_data.substr(str_start, str_end - str_start +1));
            XML_Size++;
            if(XML_Size + 20 > vector_capacity)
            {
                XML_Vector.reserve(vector_capacity + 10000);
                vector_capacity = vector_capacity + 10000;
            }
        }
    }
};
}
