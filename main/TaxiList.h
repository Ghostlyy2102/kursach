#pragma once
#include "Taxi.h"

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

namespace TaxiManager {

    ref class TaxiList {
    private:
        Taxi^ head;
        Taxi^ tail;
        int count;

    public:
        TaxiList() : head(nullptr), tail(nullptr), count(0) {}

        void AddToEnd(String^ num, String^ br, String^ dr, bool avail) {
            Taxi^ newTaxi = gcnew Taxi(num, br, dr, avail);
            if (tail == nullptr) {
                head = tail = newTaxi;
            }
            else {
                tail->next = newTaxi;
                newTaxi->prev = tail;
                tail = newTaxi;
            }
            count++;
        }

        void InsertBefore(String^ targetNumber, String^ num, String^ br, String^ dr, bool avail) {
            Taxi^ target = FindTaxi(targetNumber);
            if (target == nullptr) return;

            Taxi^ newTaxi = gcnew Taxi(num, br, dr, avail);
            newTaxi->next = target;
            newTaxi->prev = target->prev;

            if (target->prev != nullptr) {
                target->prev->next = newTaxi;
            }
            else {
                head = newTaxi;
            }
            target->prev = newTaxi;
            count++;
        }

        void InsertAfter(String^ targetNumber, String^ num, String^ br, String^ dr, bool avail) {
            Taxi^ target = FindTaxi(targetNumber);
            if (target == nullptr) return;

            Taxi^ newTaxi = gcnew Taxi(num, br, dr, avail);
            newTaxi->prev = target;
            newTaxi->next = target->next;

            if (target->next != nullptr) {
                target->next->prev = newTaxi;
            }
            else {
                tail = newTaxi;
            }
            target->next = newTaxi;
            count++;
        }

        bool RemoveTaxi(String^ number) {
            Taxi^ taxi = FindTaxi(number);
            if (taxi == nullptr) return false;

            if (taxi->prev != nullptr) {
                taxi->prev->next = taxi->next;
            }
            else {
                head = taxi->next;
            }

            if (taxi->next != nullptr) {
                taxi->next->prev = taxi->prev;
            }
            else {
                tail = taxi->prev;
            }

            count--;
            return true;
        }

        Taxi^ FindTaxi(String^ number) {
            Taxi^ current = head;
            while (current != nullptr) {
                if (current->number == number) return current;
                current = current->next;
            }
            return nullptr;
        }

        void UpdateListView(System::Windows::Forms::ListView^ listView) {
            listView->Items->Clear();
            Taxi^ current = head;
            while (current != nullptr) {
                ListViewItem^ item = gcnew ListViewItem(current->number);
                item->SubItems->Add(current->brand);
                item->SubItems->Add(current->driverName);
                item->SubItems->Add(current->isAvailable ? "Свободен" : "На вызове");

                if (!current->isAvailable) {
                    item->BackColor = System::Drawing::Color::LightPink;
                }
                else {
                    item->BackColor = System::Drawing::Color::LightGreen;
                }

                listView->Items->Add(item);
                current = current->next;
            }
        }

        void GetTaxisByStatus(bool available, ListView^ listView) {
            listView->Items->Clear();
            Taxi^ current = head;
            while (current != nullptr) {
                if (current->isAvailable == available) {
                    ListViewItem^ item = gcnew ListViewItem(current->number);
                    item->SubItems->Add(current->brand);
                    item->SubItems->Add(current->driverName);
                    item->SubItems->Add(available ? "Свободен" : "На вызове");
                    listView->Items->Add(item);
                    if (!current->isAvailable) {
                        item->BackColor = System::Drawing::Color::LightPink;
                    }
                    else {
                        item->BackColor = System::Drawing::Color::LightGreen;
                    }
                }
                current = current->next;
            }
        }

        void SaveToFile(String^ fileName) {
            StreamWriter^ writer = gcnew StreamWriter(fileName);
            Taxi^ current = head;
            while (current != nullptr) {
                writer->WriteLine("{0},{1},{2},{3}",
                    current->number, current->brand,
                    current->driverName, current->isAvailable);
                current = current->next;
            }
            writer->Close();
        }

        void LoadFromFile(String^ fileName) {
            StreamReader^ reader = gcnew StreamReader(fileName);
            head = tail = nullptr;
            count = 0;

            while (!reader->EndOfStream) {
                String^ line = reader->ReadLine();
                array<String^>^ parts = line->Split(',');
                if (parts->Length == 4) {
                    AddToEnd(parts[0], parts[1], parts[2],
                        Boolean::Parse(parts[3]));
                }
            }
            reader->Close();
        }
    };
}