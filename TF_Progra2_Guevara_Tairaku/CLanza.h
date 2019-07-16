#pragma once
#include "CFigura.h"
class CLanza : public CFigura
{
public:
	CLanza(short ancho, short alto, short posX, short posY, short dx, short dy);
	~CLanza();
	void dibujar(Graphics^ gr, Bitmap^ bmp);
	void mover();
	bool geteliminado();
	void seteliminado(bool eliminado);
private:
	bool eliminado;
};

CLanza::CLanza(short ancho, short alto, short posX, short posY, short dx, short dy)
:CFigura(ancho, alto, posX, posY, dx, dy){
	this->ancho = ancho;
	this->alto = alto;
	this->posX = posX;
	this->posY = posY;
	this->dx = dx;
	this->dy = dy;
	eliminado = false;
}
CLanza::~CLanza(){}
void CLanza::dibujar(Graphics^ gr, Bitmap^ bmp){
	Rectangle rFuente = Rectangle(0, 0, bmp->Width, bmp->Height);
	Rectangle rDestino = Rectangle(posX, posY, ancho, alto);
	gr->DrawImage(bmp, rDestino, rFuente, GraphicsUnit::Pixel);
}
void CLanza::mover(){ posX -= dx; }
bool CLanza::geteliminado(){ return eliminado; }
void CLanza::seteliminado(bool eliminado){ this->eliminado = eliminado; }