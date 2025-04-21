#pragma once

#include "Taxi.h"
#include "TaxiList.h"
#include "AddForm.h"
#include "EditForm.h"
#include "StatusForm.h"

namespace TaxiManager {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;

    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
            taxiList = gcnew TaxiList();
        }

    protected:
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        TaxiList^ taxiList;

        System::Windows::Forms::ListView^ listView1;
        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::Button^ btnEdit;
        System::Windows::Forms::Button^ btnDelete;
        System::Windows::Forms::Button^ btnStatus;
        System::Windows::Forms::Button^ btnSave;
        System::Windows::Forms::Button^ btnLoad;
        System::Windows::Forms::Button^ btnShowAvailable;
        System::Windows::Forms::Button^ btnShowBusy;
        System::Windows::Forms::Button^ btnShowAll;
        System::Windows::Forms::Button^ btnAddBefore;
        System::Windows::Forms::Button^ btnAddAfter;


        void InitializeComponent(void)
        {
            this->listView1 = (gcnew System::Windows::Forms::ListView());
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnEdit = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->btnStatus = (gcnew System::Windows::Forms::Button());
            this->btnSave = (gcnew System::Windows::Forms::Button());
            this->btnLoad = (gcnew System::Windows::Forms::Button());
            this->btnShowAvailable = (gcnew System::Windows::Forms::Button());
            this->btnShowBusy = (gcnew System::Windows::Forms::Button());
            this->btnShowAll = (gcnew System::Windows::Forms::Button());
            this->btnAddBefore = (gcnew System::Windows::Forms::Button());
            this->btnAddAfter = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // listView1
            // 
            this->listView1->FullRowSelect = true;
            this->listView1->GridLines = true;
            this->listView1->HideSelection = false;
            this->listView1->Location = System::Drawing::Point(12, 12);
            this->listView1->Name = L"listView1";
            this->listView1->Size = System::Drawing::Size(663, 300);
            this->listView1->TabIndex = 0;
            this->listView1->UseCompatibleStateImageBehavior = false;
            this->listView1->View = System::Windows::Forms::View::Details;
            // 
            // btnAdd
            // 
            this->btnAdd->Location = System::Drawing::Point(12, 318);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(100, 30);
            this->btnAdd->TabIndex = 1;
            this->btnAdd->Text = L"Äîáàâèòü";
            this->btnAdd->UseVisualStyleBackColor = true;
            this->btnAdd->Click += gcnew System::EventHandler(this, &MainForm::btnAdd_Click);
            // 
            // btnEdit
            // 
            this->btnEdit->Location = System::Drawing::Point(118, 318);
            this->btnEdit->Name = L"btnEdit";
            this->btnEdit->Size = System::Drawing::Size(100, 30);
            this->btnEdit->TabIndex = 2;
            this->btnEdit->Text = L"Èçìåíèòü";
            this->btnEdit->UseVisualStyleBackColor = true;
            this->btnEdit->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
            // 
            // btnDelete
            // 
            this->btnDelete->Location = System::Drawing::Point(224, 318);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(100, 30);
            this->btnDelete->TabIndex = 3;
            this->btnDelete->Text = L"Óäàëèòü";
            this->btnDelete->UseVisualStyleBackColor = true;
            this->btnDelete->Click += gcnew System::EventHandler(this, &MainForm::btnDelete_Click);
            // 
            // btnStatus
            // 
            this->btnStatus->Location = System::Drawing::Point(330, 318);
            this->btnStatus->Name = L"btnStatus";
            this->btnStatus->Size = System::Drawing::Size(131, 30);
            this->btnStatus->TabIndex = 4;
            this->btnStatus->Text = L"Èçìåíèòü ñòàòóñ";
            this->btnStatus->UseVisualStyleBackColor = true;
            this->btnStatus->Click += gcnew System::EventHandler(this, &MainForm::btnStatus_Click);
            // 
            // btnSave
            // 
            this->btnSave->Location = System::Drawing::Point(31, 354);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(100, 30);
            this->btnSave->TabIndex = 5;
            this->btnSave->Text = L"Ñîõðàíèòü";
            this->btnSave->UseVisualStyleBackColor = true;
            this->btnSave->Click += gcnew System::EventHandler(this, &MainForm::btnSave_Click);
            // 
            // btnLoad
            // 
            this->btnLoad->Location = System::Drawing::Point(137, 354);
            this->btnLoad->Name = L"btnLoad";
            this->btnLoad->Size = System::Drawing::Size(100, 30);
            this->btnLoad->TabIndex = 6;
            this->btnLoad->Text = L"Çàãðóçèòü";
            this->btnLoad->UseVisualStyleBackColor = true;
            this->btnLoad->Click += gcnew System::EventHandler(this, &MainForm::btnLoad_Click);
            // 
            // btnShowAvailable
            // 
            this->btnShowAvailable->Location = System::Drawing::Point(243, 354);
            this->btnShowAvailable->Name = L"btnShowAvailable";
            this->btnShowAvailable->Size = System::Drawing::Size(130, 30);
            this->btnShowAvailable->TabIndex = 7;
            this->btnShowAvailable->Text = L"Ïîêàçàòü ñâîáîäíûå";
            this->btnShowAvailable->UseVisualStyleBackColor = true;
            this->btnShowAvailable->Click += gcnew System::EventHandler(this, &MainForm::btnShowAvailable_Click);
            // 
            // btnShowBusy
            // 
            this->btnShowBusy->Location = System::Drawing::Point(379, 354);
            this->btnShowBusy->Name = L"btnShowBusy";
            this->btnShowBusy->Size = System::Drawing::Size(150, 30);
            this->btnShowBusy->TabIndex = 8;
            this->btnShowBusy->Text = L"Ïîêàçàòü çàíÿòûå";
            this->btnShowBusy->UseVisualStyleBackColor = true;
            this->btnShowBusy->Click += gcnew System::EventHandler(this, &MainForm::btnShowBusy_Click);
            // 
            // btnShowAll
            // 
            this->btnShowAll->Location = System::Drawing::Point(535, 354);
            this->btnShowAll->Name = L"btnShowAll";
            this->btnShowAll->Size = System::Drawing::Size(103, 30);
            this->btnShowAll->TabIndex = 9;
            this->btnShowAll->Text = L"Ïîêàçàòü âñå";
            this->btnShowAll->UseVisualStyleBackColor = true;
            this->btnShowAll->Click += gcnew System::EventHandler(this, &MainForm::btnShowAll_Click);
            // 
            // btnAddBefore
            // 
            this->btnAddBefore->Location = System::Drawing::Point(573, 318);
            this->btnAddBefore->Name = L"btnAddBefore";
            this->btnAddBefore->Size = System::Drawing::Size(100, 30);
            this->btnAddBefore->TabIndex = 10;
            this->btnAddBefore->Text = L"Äîáàâèòü ïåðåä";
            this->btnAddBefore->UseVisualStyleBackColor = true;
            this->btnAddBefore->Click += gcnew System::EventHandler(this, &MainForm::btnAddBefore_Click);
            // 
            // btnAddAfter
            // 
            this->btnAddAfter->Location = System::Drawing::Point(467, 318);
            this->btnAddAfter->Name = L"btnAddAfter";
            this->btnAddAfter->Size = System::Drawing::Size(100, 30);
            this->btnAddAfter->TabIndex = 11;
            this->btnAddAfter->Text = L"Äîáàâèòü ïîñëå";
            this->btnAddAfter->UseVisualStyleBackColor = true;
            this->btnAddAfter->Click += gcnew System::EventHandler(this, &MainForm::btnAddAfter_Click);
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(685, 411);
            this->Controls->Add(this->btnAddAfter);
            this->Controls->Add(this->btnAddBefore);
            this->Controls->Add(this->btnShowAll);
            this->Controls->Add(this->btnShowBusy);
            this->Controls->Add(this->btnShowAvailable);
            this->Controls->Add(this->btnLoad);
            this->Controls->Add(this->btnSave);
            this->Controls->Add(this->btnStatus);
            this->Controls->Add(this->btnDelete);
            this->Controls->Add(this->btnEdit);
            this->Controls->Add(this->btnAdd);
            this->Controls->Add(this->listView1);
            this->Name = L"MainForm";
            this->Text = L"Óïðàâëåíèå òàêñè";
            this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
            this->ResumeLayout(false);

        }

    private:
        
        System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
            listView1->Columns->Add("Íîìåð", 100);
            listView1->Columns->Add("Ìàðêà", 150);
            listView1->Columns->Add("Âîäèòåëü", 200);
            listView1->Columns->Add("Ñòàòóñ", 100);
            listView1->View = View::Details;
            listView1->FullRowSelect = true;
            listView1->GridLines = true;

            taxiList->UpdateListView(listView1);
        }

        System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
            AddForm^ addForm = gcnew AddForm();
            if (addForm->ShowDialog() == Windows::Forms::DialogResult::OK) {
                if (taxiList->FindTaxi(addForm->GetNumber()) != nullptr) {
                    MessageBox::Show("Òàêñè ñ òàêèì íîìåðîì óæå ñóùåñòâóåò!", "Îøèáêà",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                taxiList->AddToEnd(
                    addForm->GetNumber(),
                    addForm->GetBrand(),
                    addForm->GetDriverName(),
                    addForm->GetStatus()
                );
                taxiList->UpdateListView(listView1);
            }
        }

        System::Void btnAddBefore_Click(System::Object^ sender, System::EventArgs^ e) {
            if (listView1->SelectedItems->Count == 0) {
                MessageBox::Show("Âûáåðèòå òàêñè, ïåðåä êîòîðûì íóæíî äîáàâèòü íîâîå", "Îøèáêà",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            AddForm^ addForm = gcnew AddForm();
            if (addForm->ShowDialog() == Windows::Forms::DialogResult::OK) {
                String^ targetNumber = listView1->SelectedItems[0]->Text;

                if (taxiList->FindTaxi(addForm->GetNumber()) != nullptr) {
                    MessageBox::Show("Òàêñè ñ òàêèì íîìåðîì óæå ñóùåñòâóåò!", "Îøèáêà",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                taxiList->InsertBefore(
                    targetNumber,
                    addForm->GetNumber(),
                    addForm->GetBrand(),
                    addForm->GetDriverName(),
                    addForm->GetStatus()
                );
                taxiList->UpdateListView(listView1);
            }
        }

        System::Void btnAddAfter_Click(System::Object^ sender, System::EventArgs^ e) {
            if (listView1->SelectedItems->Count == 0) {
                MessageBox::Show("Âûáåðèòå òàêñè, ïîñëå êîòîðîãî íóæíî äîáàâèòü íîâîå", "Îøèáêà",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            AddForm^ addForm = gcnew AddForm();
            if (addForm->ShowDialog() == Windows::Forms::DialogResult::OK) {
                String^ targetNumber = listView1->SelectedItems[0]->Text;

                if (taxiList->FindTaxi(addForm->GetNumber()) != nullptr) {
                    MessageBox::Show("Òàêñè ñ òàêèì íîìåðîì óæå ñóùåñòâóåò!", "Îøèáêà",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                taxiList->InsertAfter(
                    targetNumber,
                    addForm->GetNumber(),
                    addForm->GetBrand(),
                    addForm->GetDriverName(),
                    addForm->GetStatus()
                );
                taxiList->UpdateListView(listView1);
            }
        }

        System::Void btnEdit_Click(System::Object^ sender, System::EventArgs^ e) {
            if (listView1->SelectedItems->Count == 0) {
                MessageBox::Show("Âûáåðèòå òàêñè äëÿ ðåäàêòèðîâàíèÿ", "Îøèáêà",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }



            String^ number = listView1->SelectedItems[0]->Text;
            Taxi^ taxi = taxiList->FindTaxi(number);

            EditForm^ editForm = gcnew EditForm(
                taxi->number, taxi->brand, taxi->driverName, taxi->isAvailable);

            if (editForm->ShowDialog() == Windows::Forms::DialogResult::OK) {
                taxi->brand = editForm->GetBrand();
                taxi->driverName = editForm->GetDriverName();
                taxiList->UpdateListView(listView1);
            }
        }

        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
            if (listView1->SelectedItems->Count == 0) {
                MessageBox::Show("Âûáåðèòå òàêñè äëÿ óäàëåíèÿ", "Îøèáêà",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            if (MessageBox::Show("Âû óâåðåíû, ÷òî õîòèòå óäàëèòü âûáðàííîå òàêñè?",
                "Ïîäòâåðæäåíèå", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
                String^ number = listView1->SelectedItems[0]->Text;
                taxiList->RemoveTaxi(number);
                taxiList->UpdateListView(listView1);
            }
        }

        System::Void btnStatus_Click(System::Object^ sender, System::EventArgs^ e) {
            if (listView1->SelectedItems->Count == 0) {
                MessageBox::Show("Âûáåðèòå òàêñè äëÿ èçìåíåíèÿ ñòàòóñà", "Îøèáêà",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            String^ number = listView1->SelectedItems[0]->Text;
            Taxi^ taxi = taxiList->FindTaxi(number);

            StatusForm^ statusForm = gcnew StatusForm(taxi->isAvailable);
            if (statusForm->ShowDialog() == Windows::Forms::DialogResult::OK) {
                taxi->isAvailable = statusForm->GetNewStatus();
                taxiList->UpdateListView(listView1);
            }
        }

        System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
            SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
            saveDialog->Filter = "Text files (*.txt)|*.txt";
            saveDialog->Title = "Ñîõðàíèòü äàííûå òàêñè";

            if (saveDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
                try {
                    taxiList->SaveToFile(saveDialog->FileName);
                    MessageBox::Show("Äàííûå óñïåøíî ñîõðàíåíû", "Óñïåõ",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Îøèáêà ïðè ñîõðàíåíèè: " + ex->Message, "Îøèáêà",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
        }

        System::Void btnLoad_Click(System::Object^ sender, System::EventArgs^ e) {
            OpenFileDialog^ openDialog = gcnew OpenFileDialog();
            openDialog->Filter = "Text files (*.txt)|*.txt";
            openDialog->Title = "Çàãðóçèòü äàííûå òàêñè";

            if (openDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
                try {
                    taxiList->LoadFromFile(openDialog->FileName);
                    taxiList->UpdateListView(listView1);
                    MessageBox::Show("Äàííûå óñïåøíî çàãðóæåíû", "Óñïåõ",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Îøèáêà ïðè çàãðóçêå: " + ex->Message, "Îøèáêà",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
        }

        System::Void btnShowAvailable_Click(System::Object^ sender, System::EventArgs^ e) {
            taxiList->GetTaxisByStatus(true, listView1);
        }

        System::Void btnShowBusy_Click(System::Object^ sender, System::EventArgs^ e) {
            taxiList->GetTaxisByStatus(false, listView1);
        }

        System::Void btnShowAll_Click(System::Object^ sender, System::EventArgs^ e) {
            taxiList->UpdateListView(listView1);
        }

        
    };
}
