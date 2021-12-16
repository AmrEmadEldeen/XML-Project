#pragma once

namespace XmlParser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for About
	/// </summary>
	public ref class About : public System::Windows::Forms::Form
	{
	public:
		About(void)
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
		~About()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ Aboutbox;
	protected:
	private: System::Windows::Forms::Button^ button1;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(About::typeid));
			this->Aboutbox = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Aboutbox
			// 
			this->Aboutbox->BackColor = System::Drawing::Color::RosyBrown;
			this->Aboutbox->Cursor = System::Windows::Forms::Cursors::Cross;
			this->Aboutbox->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Aboutbox->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->Aboutbox->Location = System::Drawing::Point(12, 12);
			this->Aboutbox->Name = L"Aboutbox";
			this->Aboutbox->ReadOnly = true;
			this->Aboutbox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Aboutbox->Size = System::Drawing::Size(406, 284);
			this->Aboutbox->TabIndex = 0;
			this->Aboutbox->Text = resources->GetString(L"Aboutbox.Text");
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(169, 302);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 30);
			this->button1->TabIndex = 1;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &About::button1_Click);
			// 
			// About
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(430, 344);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Aboutbox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"About";
			this->Text = L"About";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Form::Close();
	}
	};
}
