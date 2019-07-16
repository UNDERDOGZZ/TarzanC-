#pragma once
#include "CFigura.h"
class CJane : public CFigura
{
public:
	CJane(short ancho, short alto, short posX, short posY, short dx, short dy);
	~CJane();
	void dibujar(Graphics^ gr, Bitmap^ bmp);
	void mover();
private:
};

CJane::CJane(short ancho, short alto, short posX, short posY, short dx, short dy)
:CFigura(ancho, alto, posX, posY, dx, dy){
	this->ancho = ancho;
	this->alto = alto;
	this->posX = posX;
	this->posY = posY;
	this->dx = dx;
	this->dy = dy;
}
CJane::~CJane(){}
void CJane::dibujar(Graphics^ gr, Bitmap^ bmp){
	Rectangle rFuente = Rectangle(0, 0, bmp->Width, bmp->Height);
	Rectangle rDestino = Rectangle(posX, posY, ancho, alto);
	gr->DrawImage(bmp, rDestino, rFuente, GraphicsUnit::Pixel);
}
void CJane::mover(){ }