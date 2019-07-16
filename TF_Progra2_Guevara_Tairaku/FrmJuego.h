#pragma once
#include "CControladora.h"
namespace TF_Progra2_Guevara_Tairaku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmJuego
	/// </summary>
	public ref class FrmJuego : public System::Windows::Forms::Form
	{
		Graphics^ gr;
		Bitmap^ bmpTarzan;
		Bitmap^ bmpFondo;
		bool estadoSalto = false;
		int xAntesSalto, yAntesSalto;
	public:
		CControladora* control;
		FrmJuego(void)
		{
			InitializeComponent();
			bmpTarzan = gcnew Bitmap("tarzan.png");
			bmpFondo = gcnew Bitmap("jungle1.png");
			bmpTarzan->MakeTransparent();
		}
	protected:
		~FrmJuego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timerCronometro;
	protected:
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timerCronometro = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timerCronometro
			// 
			this->timerCronometro->Interval = 1000;
			this->timerCronometro->Tick += gcnew System::EventHandler(this, &FrmJuego::timerCronometro_Tick);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmJuego::timer1_Tick);
			// 
			// FrmJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1182, 653);
			this->Name = L"FrmJuego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmJuego";
			this->Load += gcnew System::EventHandler(this, &FrmJuego::FrmJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmJuego::FrmJuego_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmJuego_Load(System::Object^  sender, System::EventArgs^  e) {
				 if (control->gettiempo() > 0){//solo si se puso un tiempo a la variable tiempo activo el timer de cronometro
					 timerCronometro->Enabled = true;
				 }
	}
	private: System::Void FrmJuego_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if (e->KeyCode == Keys::Space)
					 estadoSalto = true;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 gr = this->CreateGraphics();
				 control->dibujarFondoLianas(gr, bmpFondo);
				 control->moverCuerdasLiana();

				 if (estadoSalto == true) control->saltarTarzan();

				 control->tarzanColgarDeLiana();
				 control->dibujarCuerdasLianas(gr);
				 control->dibujarTarzan(gr, bmpTarzan);
				 control->dibujarVidasLianas(gr);
				 control->vidasLianas();

				 //valido si tarzan se pega a una liana
				 control->validarSiTarzanSePegaALiana();
				 //si se deja de mover porque choco con una liana, detengo el salto
				 if (control->gettarzan()->getmover() == false) estadoSalto = false;
				 //si tarzan paso el limite inferior del form
				 if (control->gettarzan()->getmover() == false && estadoSalto) estadoSalto = false;

				 //validar si tarzan termina los saltos
				 if (control->gettarzan()->getPosXSalto() <= 0){
					 timer1->Stop();
					 this->Close();
				 }

				 //valido si tarzan sigue vivo
				 if (control->tarzanPierdeJuego() == true){
					 timer1->Enabled = false;
					 MessageBox::Show("Perdiste!");
					 exit(0);
				 }
	}
	private: System::Void timerCronometro_Tick(System::Object^  sender, System::EventArgs^  e) {
				 control->avanzartiempo();

				 if (control->gettiempo() == 0){
					 timer1->Enabled = false;
					 timerCronometro->Enabled = false;
					 MessageBox::Show("Se acabó el tiempo, perdiste!");
					 exit(0);
				 }
				 this->Text = "Tiempo restante: " + (control->gettiempo());
	}
	};
}
