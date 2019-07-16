#pragma once
#include "CImagen.h"
class CFigura : public CImagen
{
public:
	CFigura(short ancho, short alto, short posX, short posY, short dx, short dy);
	~CFigura();
	virtual void mover() abstract;
	virtual void dibujar(Graphics^ gr,Bitmap^ bmp) abstract;

protected:

};

CFigura::CFigura(short ancho, short alto, short posX, short posY, short dx, short dy){
	this->ancho = ancho;
	this->alto = alto;
	this->posX = posX;
	this->posY = posY;
	this->dx = dx;
	this->dy = dy;
}
CFigura::~CFigura(){}