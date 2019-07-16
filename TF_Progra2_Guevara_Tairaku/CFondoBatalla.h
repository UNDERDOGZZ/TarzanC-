#pragma once
#include "CFigura.h"
#include "CJane.h"
class CFondoBatalla : public CFigura
{
public:
	CFondoBatalla(short ancho, short alto, short posX, short posY, short dx, short dy);
	~CFondoBatalla();
	void mover();
	void dibujar(Graphics^ gr, Bitmap^ bmpJane);
	CJane* getjane();
private:
	CJane* jane;
};

CFondoBatalla::CFondoBatalla(short ancho, short alto, short posX, short posY, short dx, short dy)
:CFigura(ancho, alto, posX, posY, dx, dy){
	jane = new CJane(LARGO_JANE, ALTO_JANE, LARGO_FORMULARIO / 5, ALTO_FORMULARIO / 2 - ALTO_JANE, 0, 0);
}
CFondoBatalla::~CFondoBatalla(){}
void CFondoBatalla::mover() {

}
void CFondoBatalla::dibujar(Graphics^ gr, Bitmap^ bmpJane) {
	gr->FillRectangle(Brushes::LightBlue, posX, posY, ancho, alto);
	gr->FillRectangle(Brushes::Green, posX, posY + alto / 2, ancho, alto / 2);
	jane->dibujar(gr, bmpJane);
}
CJane* CFondoBatalla::getjane(){ return jane; }