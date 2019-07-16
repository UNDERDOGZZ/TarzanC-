#pragma once
#include "CImagen.h"
class CBurbujaOceano : public CImagen
{
public:
	CBurbujaOceano(short ancho, short alto, short posX, short posY, short dx, short dy);
	~CBurbujaOceano();
	void dibujar(Graphics^ gr);
	void mover();
private:

};

CBurbujaOceano::CBurbujaOceano(short ancho, short alto, short posX, short posY, short dx, short dy){
	this->ancho = ancho;
	this->alto = alto;
	this->posX = posX;
	this->posY = posY;
	this->dx = dx;
	this->dy = dy;
}
CBurbujaOceano::~CBurbujaOceano(){}
void CBurbujaOceano::dibujar(Graphics^ gr){
	gr->FillEllipse(Brushes::Blue, posX, posY, ancho, alto);
	gr->DrawEllipse(Pens::White, posX, posY, ancho, alto);
	gr->FillEllipse(Brushes::White, posX + 4, posY + 4, ancho / 3, alto / 3);
}
void CBurbujaOceano::mover(){
	posX += dx;
}