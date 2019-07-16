#pragma once
#include "CControladora.h"
namespace TF_Progra2_Guevara_Tairaku {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class FrmBatalla : public System::Windows::Forms::Form
	{
		Bitmap^ bmpTarzanBatalla;
		Bitmap^ bmpLanza;
		Bitmap^ bmpNativo;
		Bitmap^ bmpJane;
		Bitmap^ bmpChita;
		Bitmap^ bmpAnimales;
		Graphics^ gr;
		int tiempoChita;
		bool chitaVisible;
	public:
		CControladora* control;
		FrmBatalla(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			//control = new CControladora();
			bmpTarzanBatalla = gcnew Bitmap("tarzan_batalla.png");
			bmpLanza = gcnew Bitmap("lanza.png");
			bmpJane = gcnew Bitmap("jane.png");
			bmpNativo = gcnew Bitmap("nativo.png");
			bmpChita = gcnew Bitmap("chita.png");
			bmpAnimales = gcnew Bitmap("animales_selva.png");
			bmpNativo->MakeTransparent(bmpNativo->GetPixel(0, 0));
			bmpTarzanBatalla->MakeTransparent();
			bmpJane->MakeTransparent();
			bmpChita->MakeTransparent();
			tiempoChita = 30;//30ms
			chitaVisible = false;
		}
		void terminarJuego(){
			timer1->Enabled = false;
			timerAgregarNativos->Enabled = false;
			MessageBox::Show("Ganaste! Has rescatado a Jane");
			this->Close();
		}
	protected:
		~FrmBatalla()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::Windows::Forms::Timer^  timerCronometro;
	private: System::Windows::Forms::Timer^  timerAgregarNativos;
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
			this->timerCronometro = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerAgregarNativos = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmBatalla::timer1_Tick);
			// 
			// timerCronometro
			// 
			this->timerCronometro->Interval = 1000;
			this->timerCronometro->Tick += gcnew System::EventHandler(this, &FrmBatalla::timerCronometro_Tick);
			// 
			// timerAgregarNativos
			// 
			this->timerAgregarNativos->Enabled = true;
			this->timerAgregarNativos->Interval = 800;
			this->timerAgregarNativos->Tick += gcnew System::EventHandler(this, &FrmBatalla::timerAgregarNativos_Tick);
			// 
			// FrmBatalla
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1182, 653);
			this->Name = L"FrmBatalla";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmBatalla";
			this->Load += gcnew System::EventHandler(this, &FrmBatalla::FrmBatalla_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmBatalla::FrmBatalla_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmBatalla_Load(System::Object^  sender, System::EventArgs^  e) {
				 if (control->gettiempo() > 0){//solo si se puso un tiempo a la variable tiempo activo el timer de cronometro
					 timerCronometro->Enabled = true;
				 }
	}
	private: System::Void FrmBatalla_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if (e->KeyCode == Keys::Right){
					 control->retrocederTarzanBatalla();
					 control->gettarzanBatalla()->setestadoY(1);
					 control->gettarzanBatalla()->retrocederSpriteTarzan();
				 }
				 else if (e->KeyCode == Keys::Left){
					 control->avanzarTarzanBatalla();
					 control->gettarzanBatalla()->setestadoY(0);
					 control->gettarzanBatalla()->avanzarSpriteTarzan();
				 }
				 else if (e->KeyCode == Keys::Space){
					 control->gettarzanBatalla()->setestadoY(0);
					 control->gettarzanBatalla()->avanzarSpriteTarzan();
					 control->gettarzanBatalla()->lanzarLanza();
				 }
				 else if (e->KeyCode == Keys::C){
					 control->comerSemilla();
				 }
				 else if (e->KeyCode == Keys::L){
					 chitaVisible = true;
					 control->efectuarCuracionChita();
				 }
				 else if (e->KeyCode == Keys::A){
					 control->setanimalesSelva(new CAnimalesSelva(LARGO_ANIMALES_SELVA, ALTO_ANIMALES_SELVA, control->gettarzanBatalla()->getposX(), control->gettarzanBatalla()->getposY(), 10, 0));
					 control->llamarAnimales();
				 }
				 
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 control->dibujarFondoBatalla(gr, bmpJane);
				 control->dibujarTarzanBatalla(gr, bmpTarzanBatalla);

				 control->moverNativos();
				 control->dibujarNativos(gr, bmpNativo);

				 control->dibujarLanzas(gr, bmpLanza);
				 control->validarLanzaMataNativo();
				 control->validarTarzanColisionaNativo();

				 control->moverAnimalesSelva();
				 control->dibujarAnimalesSelva(gr, bmpAnimales);
				 control->validarAnimalesConNativos();

				 control->dibujarInstruccionesBatalla(gr);

				 if (control->validarTarzanEncuentraJane()){
					 terminarJuego();
				 }
				 if (chitaVisible == true){
					 control->llamarAChita(gr, bmpChita);
					 tiempoChita--;
					 if (tiempoChita <= 0)
						 chitaVisible = false;
				 }

				 if (control->tarzanPierdeJuego() == true){
					 exit(0);
				 }
				 
	}
	private: System::Void timerCronometro_Tick(System::Object^  sender, System::EventArgs^  e) {
				 control->avanzartiempo();
				 if (control->gettiempo() == 0){
					 timer1->Enabled = false;
					 timerCronometro->Enabled = false;
					 timerAgregarNativos->Enabled = false;
					 MessageBox::Show("Se acabó el tiempo, perdiste!");
					 exit(0);
				 }
				 this->Text = "Tiempo restante: " + (control->gettiempo());
	}
	private: System::Void timerAgregarNativos_Tick(System::Object^  sender, System::EventArgs^  e) {
				 Random^ r = gcnew Random();
				 int dx = r->Next(20, 30);//desplazamiento de cada nativo aleatorio
				 control->agregarNativo(new CNativo(LARGO_NATIVO, ALTO_NATIVO, 0, ALTO_FORMULARIO / 2 - ALTO_NATIVO + 10, dx, 0));
	}
	};
}
