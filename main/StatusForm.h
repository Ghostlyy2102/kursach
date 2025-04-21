#pragma once

namespace TaxiManager {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class StatusForm : public System::Windows::Forms::Form
    {
    public:
        StatusForm(bool currentStatus)
        {
            InitializeComponent();
            radioFree->Checked = currentStatus;
            radioBusy->Checked = !currentStatus;
        }

        bool GetNewStatus() { return radioFree->Checked; }

    protected:
        ~StatusForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::RadioButton^ radioFree;
        System::Windows::Forms::RadioButton^ radioBusy;
        System::Windows::Forms::Button^ btnOK;
        System::Windows::Forms::Button^ btnCancel;

        void InitializeComponent(void)
        {
            this->radioFree = (gcnew System::Windows::Forms::RadioButton());
            this->radioBusy = (gcnew System::Windows::Forms::RadioButton());
            this->btnOK = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();

            // radioFree
            this->radioFree->AutoSize = true;
            this->radioFree->Location = System::Drawing::Point(20, 20);
            this->radioFree->Name = L"radioFree";
            this->radioFree->Size = System::Drawing::Size(72, 17);
            this->radioFree->TabIndex = 0;
            this->radioFree->TabStop = true;
            this->radioFree->Text = L"Свободен";
            this->radioFree->UseVisualStyleBackColor = true;

            // radioBusy
            this->radioBusy->AutoSize = true;
            this->radioBusy->Location = System::Drawing::Point(20, 50);
            this->radioBusy->Name = L"radioBusy";
            this->radioBusy->Size = System::Drawing::Size(83, 17);
            this->radioBusy->TabIndex = 1;
            this->radioBusy->TabStop = true;
            this->radioBusy->Text = L"На вызове";
            this->radioBusy->UseVisualStyleBackColor = true;

            // btnOK
            this->btnOK->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->btnOK->Location = System::Drawing::Point(20, 90);
            this->btnOK->Name = L"btnOK";
            this->btnOK->Size = System::Drawing::Size(90, 30);
            this->btnOK->TabIndex = 2;
            this->btnOK->Text = L"OK";
            this->btnOK->UseVisualStyleBackColor = true;

            // btnCancel
            this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->btnCancel->Location = System::Drawing::Point(120, 90);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(90, 30);
            this->btnCancel->TabIndex = 3;
            this->btnCancel->Text = L"Отмена";
            this->btnCancel->UseVisualStyleBackColor = true;

            // StatusForm
            this->AcceptButton = this->btnOK;
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->CancelButton = this->btnCancel;
            this->ClientSize = System::Drawing::Size(234, 141);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnOK);
            this->Controls->Add(this->radioBusy);
            this->Controls->Add(this->radioFree);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"StatusForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Изменить статус такси";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
    };
}
