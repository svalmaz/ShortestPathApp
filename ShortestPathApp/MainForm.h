#pragma once
#include "Graph.h"

namespace ShortestPathApp {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MainForm : public Form {
    public:
        MainForm() {
            InitializeComponent();
        }

    protected:
        ~MainForm() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ calculateButton;
        System::Windows::Forms::TextBox^ startVertex;
        System::Windows::Forms::TextBox^ endVertex;
        System::Windows::Forms::Label^ resultLabel;
        System::Windows::Forms::DataGridView^ adjMatrixGrid;
        System::ComponentModel::Container^ components;

        void InitializeComponent() {
            this->calculateButton = gcnew System::Windows::Forms::Button();
            this->startVertex = gcnew System::Windows::Forms::TextBox();
            this->endVertex = gcnew System::Windows::Forms::TextBox();
            this->resultLabel = gcnew System::Windows::Forms::Label();
            this->adjMatrixGrid = gcnew System::Windows::Forms::DataGridView();

            // Настройка DataGridView для матрицы смежности
            this->adjMatrixGrid->Location = System::Drawing::Point(50, 50);
            this->adjMatrixGrid->Size = System::Drawing::Size(200, 200);
            this->adjMatrixGrid->ColumnCount = 6;  // 5 колонок (вершин), написал 6 тк выйдет конфликт в цикле
            this->adjMatrixGrid->RowCount = 6;     // 5 строк (вершин)

            //обычные нактройки чтобы юзер не мог ничего менять
            this->adjMatrixGrid->AllowUserToAddRows = false;
            this->adjMatrixGrid->AllowUserToDeleteRows = false;

          
            for (int i = 0; i < 5; i++) {
                this->adjMatrixGrid->Columns[i]->Width = 40; 
            }

            // Инициализация значений в ячейках
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    this->adjMatrixGrid->Rows[i]->Cells[j]->Value = "0"; 
                }
            }

          
            this->calculateButton->Location = System::Drawing::Point(300, 150);
            this->calculateButton->Size = System::Drawing::Size(100, 30);
            this->calculateButton->Text = "Calculate";
            this->calculateButton->Click += gcnew System::EventHandler(this, &MainForm::OnCalculateClick);

            // Текстовое поле для начальной вершины
            this->startVertex->Location = System::Drawing::Point(300, 50);
            this->startVertex->Size = System::Drawing::Size(100, 20);

            // Текстовое поле для конечной вершины
            this->endVertex->Location = System::Drawing::Point(300, 100);
            this->endVertex->Size = System::Drawing::Size(100, 20);

           
            this->resultLabel->Location = System::Drawing::Point(50, 300);
            this->resultLabel->AutoSize = true;

            
            this->Controls->Add(this->calculateButton);
            this->Controls->Add(this->startVertex);
            this->Controls->Add(this->endVertex);
            this->Controls->Add(this->resultLabel);
            this->Controls->Add(this->adjMatrixGrid);
            this->Size = System::Drawing::Size(500, 400);
            this->Text = "Shortest Path Calculator";
        }

        // Тут и находим кратчайший путь
        void OnCalculateClick(System::Object^ sender, System::EventArgs^ e) {
            int start, end;
            if (Int32::TryParse(this->startVertex->Text, start) && Int32::TryParse(this->endVertex->Text, end)) {
                // Считывание данных из DataGridView (матрица смежности)
                Graph^ g = gcnew Graph(5); // Пример с 5 вершинами
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        int weight = Convert::ToInt32(this->adjMatrixGrid->Rows[i]->Cells[j]->Value);
                        if (weight != 0) {
                            g->addEdge(i, j, weight); 
                        }
                    }
                }

                // Запуск алгоритма Дейкстры
                array<int>^ path = g->dijkstra(start, end);

                // Формирование строки с результатом
                String^ result = "Shortest path from " + start + " to " + end + ": ";
                for (int i = 0; i < path->Length; i++) {
                    result += path[i] + " ";
                }
                this->resultLabel->Text = result;
            }
            else {
                this->resultLabel->Text = "Please enter valid numeric values.";
            }
        }
    };
}
