#pragma once
#include "CFigura.h"
class CCocodrilo : public CFigura
{
public:
	CCocodrilo(short ancho, short alto, short posX, short posY, short dx, short dy);
	~CCocodrilo();
	void dibujar(Graphics^ gr, Bitmap^ bmp);
	void mover();
	bool gettocado();
	void settocado(bool tocado);

	bool geteliminado();
	void seteliminado(bool eliminado);
private:
	int estado;
	bool tocado;
	bool eliminado;
};

CCocodrilo::CCocodrilo(short ancho, short alto, short posX, short posY, short dx, short dy)
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
CCocodrilo::~CCocodrilo(){}
void CCocodrilo::dibujar(Graphics^ gr, Bitmap^ bmp){
	Rectangle rFuente = Rectangle(estado*ancho, 0, ancho, alto);
	Rectangle rDestino = Rectangle(posX, posY, ancho, alto);
	gr->DrawImage(bmp, rDestino, rFuente, GraphicsUnit::Pixel);

	estado++;
	if (estado == 7) estado = 0;
}
void CCocodrilo::mover(){ posX += dx; }
bool CCocodrilo::gettocado(){ return tocado; }
void CCocodrilo::settocado(bool tocado){ this->tocado = tocado; }

bool CCocodrilo::geteliminado(){ return eliminado; }
void CCocodrilo::seteliminado(bool eliminado){ this->eliminado = eliminado; }