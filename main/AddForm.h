#pragma once

namespace TaxiManager {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class AddForm : public System::Windows::Forms::Form
    {
    public:
        AddForm(void)
        {
            InitializeComponent();
        }

        String^ GetNumber() { return txtNumber->Text; }
        String^ GetBrand() { return txtBrand->Text; }
        String^ GetDriverName() { return txtDriver->Text; }
        bool GetStatus() { return chkAvailable->Checked; }

    protected:
        ~AddForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::TextBox^ txtNumber;
        System::Windows::Forms::TextBox^ txtBrand;
        System::Windows::Forms::TextBox^ txtDriver;
        System::Windows::Forms::CheckBox^ chkAvailable;
        System::Windows::Forms::Button^ btnOK;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::Label^ label3;

        void InitializeComponent(void)
        {
            this->txtNumber = (gcnew System::Windows::Forms::TextBox());
            this->txtBrand = (gcnew System::Windows::Forms::TextBox());
            this->txtDriver = (gcnew System::Windows::Forms::TextBox());
            this->chkAvailable = (gcnew System::Windows::Forms::CheckBox());
            this->btnOK = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // txtNumber
            // 
            this->txtNumber->Location = System::Drawing::Point(120, 20);
            this->txtNumber->Name = L"txtNumber";
            this->txtNumber->Size = System::Drawing::Size(200, 20);
            this->txtNumber->TabIndex = 0;
            // 
            // txtBrand
            // 
            this->txtBrand->Location = System::Drawing::Point(120, 50);
            this->txtBrand->Name = L"txtBrand";
            this->txtBrand->Size = System::Drawing::Size(200, 20);
            this->txtBrand->TabIndex = 1;
            // 
            // txtDriver
            // 
            this->txtDriver->Location = System::Drawing::Point(120, 80);
            this->txtDriver->Name = L"txtDriver";
            this->txtDriver->Size = System::Drawing::Size(200, 20);
            this->txtDriver->TabIndex = 2;
            // 
            // chkAvailable
            // 
            this->chkAvailable->AutoSize = true;
            this->chkAvailable->Checked = true;
            this->chkAvailable->CheckState = System::Windows::Forms::CheckState::Checked;
            this->chkAvailable->Location = System::Drawing::Point(120, 110);
            this->chkAvailable->Name = L"chkAvailable";
            this->chkAvailable->Size = System::Drawing::Size(15, 14);
            this->chkAvailable->TabIndex = 3;
            // 
            // btnOK
            // 
            this->btnOK->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->btnOK->Location = System::Drawing::Point(120, 140);
            this->btnOK->Name = L"btnOK";
            this->btnOK->Size = System::Drawing::Size(90, 30);
            this->btnOK->TabIndex = 4;
            this->btnOK->Text = L"OK";
            this->btnOK->UseVisualStyleBackColor = true;
            // 
            // btnCancel
            // 
            this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->btnCancel->Location = System::Drawing::Point(220, 140);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(90, 30);
            this->btnCancel->TabIndex = 5;
            this->btnCancel->Text = L"Отмена";
            this->btnCancel->UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(20, 23);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(44, 13);
            this->label1->TabIndex = 6;
            this->label1->Text = L"Номер:";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(20, 53);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(43, 13);
            this->label2->TabIndex = 7;
            this->label2->Text = L"Марка:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(20, 83);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(58, 13);
            this->label3->TabIndex = 8;
            this->label3->Text = L"Водитель:";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(23, 110);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(44, 13);
            this->label4->TabIndex = 9;
            this->label4->Text = L"Статус:";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(156, 110);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(164, 13);
            this->label5->TabIndex = 10;
            this->label5->Text = L"Да - свободен, нет - на вызове";
            // 
            // AddForm
            // 
            this->AcceptButton = this->btnOK;
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->CancelButton = this->btnCancel;
            this->ClientSize = System::Drawing::Size(344, 186);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnOK);
            this->Controls->Add(this->chkAvailable);
            this->Controls->Add(this->txtDriver);
            this->Controls->Add(this->txtBrand);
            this->Controls->Add(this->txtNumber);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"AddForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Добавить такси";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    };
}
