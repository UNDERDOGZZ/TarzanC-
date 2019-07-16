#pragma once
#include "CFigura.h"
class CAnimalesSelva : public CFigura
{
public:
	CAnimalesSelva(short ancho, short alto, short posX, short posY, short dx, short dy);
	~CAnimalesSelva();
	void dibujar(Graphics^ gr, Bitmap^ bmp);
	void mover();
	bool getvisible();
	void setvisible(bool visible);
private:
	bool visible;
};

CAnimalesSelva::CAnimalesSelva(short ancho, short alto, short posX, short posY, short dx, short dy)
:CFigura(ancho, alto, posX, posY, dx, dy){
	this->ancho = ancho;
	this->alto = alto;
	this->posX = posX;
	this->posY = posY;
	this->dx = dx;
	this->dy = dy;
	visible = false;
}
CAnimalesSelva::~CAnimalesSelva(){}
void CAnimalesSelva::dibujar(Graphics^ gr, Bitmap^ bmp){
	Rectangle rFuente = Rectangle(0, 0, ancho, alto);
	Rectangle rDestino = Rectangle(posX, posY, ancho, alto);
	gr->DrawImage(bmp, rDestino, rFuente, GraphicsUnit::Pixel);
}
void CAnimalesSelva::mover(){ posX -= dx; }
bool CAnimalesSelva::getvisible(){ return visible; }
void CAnimalesSelva::setvisible(bool visible){ this->visible = visible; }