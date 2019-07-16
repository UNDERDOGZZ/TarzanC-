#pragma once
#include "CFigura.h"
class CNativo : public CFigura
{
public:
	CNativo(short ancho, short alto, short posX, short posY, short dx, short dy);
	~CNativo();
	void dibujar(Graphics^ gr, Bitmap^ bmp);
	void mover();
	bool gettocado();
	void settocado(bool tocado);

	bool geteliminado();
	void seteliminado(bool eliminado);
private:
	int estado;
	bool eliminado;
	bool tocado;
};

CNativo::CNativo(short ancho, short alto, short posX, short posY, short dx, short dy)
:CFigura(ancho, alto, posX, posY, dx, dy){
	this->ancho = ancho;
	this->alto = alto;
	this->posX = posX;
	this->posY = posY;
	this->dx = dx;
	this->dy = dy;
	estado = 0;
	eliminado = tocado = false;
}
CNativo::~CNativo(){}
void CNativo::dibujar(Graphics^ gr, Bitmap^ bmp){
	Rectangle rFuente = Rectangle(estado * ancho, 0, ancho, alto);
	Rectangle rDestino = Rectangle(posX, posY, ancho, alto);
	gr->DrawImage(bmp, rDestino, rFuente, GraphicsUnit::Pixel);

	estado++;
	if (estado == 8) estado = 0;
}
void CNativo::mover(){ posX += dx; }
bool CNativo::gettocado(){ return tocado; }
void CNativo::settocado(bool tocado){ this->tocado = tocado; }

bool CNativo::geteliminado(){ return eliminado; }
void CNativo::seteliminado(bool eliminado){ this->eliminado = eliminado; }