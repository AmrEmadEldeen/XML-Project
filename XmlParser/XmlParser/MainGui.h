
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
	private: static string minify(string str) {
		int count = 0;
		for (int i = 0; str[i]; i++)
			if (str[i] != ' ' && str[i] != '\n')
				str[count++] = str[i];
		str[count] = '\0';
		return str;
	}
	
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
void Error_corr(string& S)
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
 {MessageBox::Show("Finish Detection", " ", MessageBoxButtons::OK, MessageBoxIcon::Asterisk); }

}
while (!T.empty())
 {
 MessageBox::Show("<" + tosysstring(T.top()) + ">  with no closed tag", " ", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
 T.pop();
  }
}
};
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
}
