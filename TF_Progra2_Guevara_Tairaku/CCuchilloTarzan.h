#pragma once
#include "CFigura.h"
class CCuchilloTarzan: public CFigura
{
public:
	CCuchilloTarzan(short ancho, short alto, short posX, short posY, short dx, short dy);
	~CCuchilloTarzan();
	void dibujar(Graphics^ gr, Bitmap^ bmp);
	void mover();
	bool getvisible();
	void setvisible(bool visible);
private:
	bool visible;
};

CCuchilloTarzan::CCuchilloTarzan(short ancho, short alto, short posX, short posY, short dx, short dy)
:CFigura(ancho, alto, posX, posY, dx, dy){
	this->ancho = ancho;
	this->alto = alto;
	this->posX = posX;
	this->posY = posY;
	this->dx = dx;
	this->dy = dy;
	visible = false;
}
CCuchilloTarzan::~CCuchilloTarzan(){}
void CCuchilloTarzan::dibujar(Graphics^ gr, Bitmap^ bmp){
	//array<Point>^ puntos = { Point(posX, posY), Point(posX + (ancho / 2), posY), Point(posX + (ancho / 2), posY + alto) };
	gr->FillRectangle(Brushes::Brown, posX + (ancho / 2), posY, ancho / 2, alto / 3);
	//gr->FillPolygon(Brushes::Gold, puntos);
}
void CCuchilloTarzan::mover(){  }
bool CCuchilloTarzan::getvisible(){ return visible; }
void CCuchilloTarzan::setvisible(bool visible){ this->visible = visible; }