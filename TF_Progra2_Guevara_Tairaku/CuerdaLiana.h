#pragma once
#include "CImagen.h"
class CuerdaLiana : public CImagen
{
public:
	CuerdaLiana(short posX, short posY,
		float desplazamientoAngulo, short hipotenusa);
	~CuerdaLiana();
	void mover();
	void dibuja(Graphics^ gr);
	void desplazar();
	short getDesplazamientoParaTarzan();
	short getAnchoLiana();
	short getAltoLiana();
	short getPosxLiana();
private:
	short Posx2, Posy2;
	short hipotenusa;
	float angulo;
	float anguloInicial, anguloFinal;
	float desplazamientoAngulo;
	float desfase;
};

CuerdaLiana::CuerdaLiana(short posX, short posY,
	float desplazamientoAngulo, short hipotenusa) {
	this->posX = posX;
	this->posY = posY;
	this->hipotenusa = hipotenusa;
	this->desplazamientoAngulo = desplazamientoAngulo;
	this->dx = DX_DESPLAZAMIENTO_LIANA;
	this->desfase = 0;

	float PI = 3.14159;
	angulo = PI / 6;
	anguloInicial = angulo;
	anguloFinal = -anguloInicial;
	//coordenadas iniciales del final del pendulo
	float distx = (hipotenusa*Math::Sin(angulo));
	Posx2 = posX + distx;
	float disty = (hipotenusa*Math::Cos(angulo));
	Posy2 = posY + disty;
}
CuerdaLiana::~CuerdaLiana() {}
void CuerdaLiana::mover() {
	angulo += desplazamientoAngulo;
	float distx = (hipotenusa*Math::Sin(angulo));

	desfase = Posx2;
	Posx2 = posX + distx;
	desfase -= Posx2;

	float disty = (hipotenusa*Math::Cos(angulo));
	Posy2 = posY + disty;
	if (angulo <= anguloFinal || angulo >= anguloInicial) desplazamientoAngulo *= -1;
}
void CuerdaLiana::dibuja(Graphics^ gr) {
	Pen^ lapiz = gcnew Pen(Color::Brown, 7);
	gr->DrawLine(lapiz, posX, posY, Posx2, Posy2);
	gr->DrawString(getAnchoLiana()+"", gcnew Font("Arial",10), Brushes::Black, posX, posY);
	gr->DrawRectangle(Pens::Black, getPosxLiana(), posY, getAnchoLiana(), getAltoLiana());
}
void CuerdaLiana::desplazar(){
	posX += dx;
}
short CuerdaLiana::getDesplazamientoParaTarzan(){ return desfase*-1; }
short CuerdaLiana::getAnchoLiana(){ return Posx2 - posX < 0 ? (Posx2 - posX)*-1 : Posx2 - posX; }
short CuerdaLiana::getAltoLiana(){ return Posy2 - posY; }
short CuerdaLiana::getPosxLiana(){ return posX < Posx2 ? posX : Posx2; }