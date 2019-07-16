#pragma once
#include "CControladora.h"
#include "FrmJuego.h"
#include "FrmOceano.h"
#include "FrmBatalla.h"
namespace TF_Progra2_Guevara_Tairaku {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class FrmMenu : public System::Windows::Forms::Form
	{
		CControladora* controlador;
	public:
		FrmMenu(void)
		{
			InitializeComponent();
		}
	protected:
		~FrmMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button2;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;


	private: System::Windows::Forms::TextBox^  textBox1;
	private:
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMenu::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Red;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(250, 314);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(166, 28);
			this->button2->TabIndex = 3;
			this->button2->Text = L"CONTRARELOJ";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FrmMenu::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DeepPink;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(36, 314);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(167, 28);
			this->button1->TabIndex = 2;
			this->button1->Text = L"INICIAR JUEGO";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FrmMenu::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(454, 363);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::ForestGreen;
			this->textBox1->ForeColor = System::Drawing::Color::Yellow;
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(240, 45);
			this->textBox1->TabIndex = 7;
			this->textBox1->Text = L"By:\r\nTairaku Nako, Jose Enrique - u201618878\r\nGuevara Aparicio, Ricardo Alfredo -"
				L" u201618078";
			// 
			// FrmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(453, 361);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FrmMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu";
			this->Load += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FrmMenu_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 controlador = new CControladora();

				 FrmJuego^ juegoLianas = gcnew FrmJuego();
				 juegoLianas->control = this->controlador;
				 juegoLianas->ShowDialog();
				 delete juegoLianas;

				 FrmOceano^ oceano = gcnew FrmOceano();
				 oceano->control = this->controlador;
				 oceano->ShowDialog();
				 delete oceano;

				 FrmBatalla^ batalla = gcnew FrmBatalla();
				 batalla->control = this->controlador;
				 batalla->ShowDialog();
				 delete batalla;
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 controlador = new CControladora();

				 controlador->settiempo(60);//tiempo a 30 segundos

				 FrmJuego^ juegoLianas = gcnew FrmJuego();
				 juegoLianas->control = this->controlador;
				 juegoLianas->ShowDialog();
				 delete juegoLianas;

				 FrmOceano^ oceano = gcnew FrmOceano();
				 oceano->control = this->controlador;
				 oceano->ShowDialog();
				 delete oceano;

				 FrmBatalla^ batalla = gcnew FrmBatalla();
				 batalla->control = this->controlador;
				 batalla->ShowDialog();
				 delete batalla;
	}
	};
}
