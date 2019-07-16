#pragma once
#include "CControladora.h"
namespace TF_Progra2_Guevara_Tairaku {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class FrmOceano : public System::Windows::Forms::Form
	{
		Bitmap^ bmpTarzanNadando;
		Bitmap^ bmpCocodrilo;
	public:
		CControladora* control;
		FrmOceano(void)
		{
			InitializeComponent();
			bmpTarzanNadando = gcnew Bitmap("tarzan_nadando.png");
			bmpCocodrilo = gcnew Bitmap("cocodrilo.png");
			bmpTarzanNadando->MakeTransparent();
		}
	protected:
		~FrmOceano()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Timer^  timerCronometro;
	private: System::ComponentModel::IContainer^  components;
	private:
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerCronometro = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmOceano::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1500;
			this->timer2->Tick += gcnew System::EventHandler(this, &FrmOceano::timer2_Tick);
			// 
			// timerCronometro
			// 
			this->timerCronometro->Interval = 1000;
			this->timerCronometro->Tick += gcnew System::EventHandler(this, &FrmOceano::timerCronometro_Tick);
			// 
			// FrmOceano
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1182, 653);
			this->Name = L"FrmOceano";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmOceano";
			this->Load += gcnew System::EventHandler(this, &FrmOceano::FrmOceano_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmOceano::FrmOceano_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmOceano_Load(System::Object^  sender, System::EventArgs^  e) {
				 if (control->gettiempo() > 0){//solo si se puso un tiempo a la variable tiempo activo el timer de cronometro
					 timerCronometro->Enabled = true;
				 }
	}
	private: System::Void FrmOceano_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 //controles para nadar
				 control->tarzanNadar(e->KeyCode);
				 //ataque
				 if (e->KeyCode == Keys::A){ control->ataqueCuchillo(); }
				 if (e->KeyCode == Keys::S){ control->ocultaCuchillo(); }
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 Graphics^ gr = this->CreateGraphics();
				 control->dibujarFondoOceano(gr, nullptr);
				 control->dibujarTarzanNadando(gr, bmpTarzanNadando);
				 control->dibujarBurbujas(gr);
				 control->moverBurbujas();

				 control->moverCocodrilos();
				 control->dibujarCocodrilos(gr, bmpCocodrilo);

				 control->validarSiTarzanChocaCocodrilo();
				 control->validarCuchilloMataCocodrilo();
				 control->dibujarVidas(gr);

				 if (control->tarzanPierdeJuego() == true){
					 exit(0);
				 }
				 //si tarzan llega al otro extremo del mar, pasa de nivel
				 if (control->gettarzanNadador()->getposX() <= 0){
					 timer1->Enabled = false;
					 timer2->Enabled = false;
					 MessageBox::Show("Llegaste a la meta! :)");
					 this->Close();
				 }
	}
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
				 //agrego 5 burbujas
				 Random r;
				 for (int i = 0; i < 5; i++){
					 int anchoBurbuja = r.Next(20, 30);
					 int altoBurbuja = r.Next(20, 30);
					 int yAleatorio = r.Next(ALTO_FORMULARIO / 3, ALTO_FORMULARIO);
					 int dxBurbuja = r.Next(20, 50);
					 control->agregarBurbuja(new CBurbujaOceano(anchoBurbuja, altoBurbuja, 0, yAleatorio, dxBurbuja, 0));
				 }
				 //agrego 3 cocodrilos
				 for (int i = 0; i < 2; i++){
					 int yAleatorioCoco = r.Next(ALTO_FORMULARIO / 3, ALTO_FORMULARIO);
					 int dxCocodrilo = r.Next(8, 15);
					 control->agregarCocodrilo(new CCocodrilo(LARGO_COCODRILO, ALTO_COCODRILO, 0, yAleatorioCoco, dxCocodrilo, 0));
				 }
	}
	private: System::Void timerCronometro_Tick(System::Object^  sender, System::EventArgs^  e) {
				 control->avanzartiempo();
				 if (control->gettiempo() == 0){
					 timer1->Enabled = false;
					 timer2->Enabled = false;
					 timerCronometro->Enabled = false;
					 MessageBox::Show("Se acabó el tiempo, perdiste!");
					 exit(0);
				 }
				 this->Text = "Tiempo restante: " + (control->gettiempo());
	}
	};
}
