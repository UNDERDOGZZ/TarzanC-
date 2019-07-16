#pragma once
#include "CFigura.h"
class CFondoLiana : public CFigura
{
public:
	CFondoLiana(short ancho, short alto, short posX, short posY, short dx, short dy);
	~CFondoLiana();
	void mover();
	void dibujar(Graphics^ gr, Bitmap^ bmp);
private:
	
};

CFondoLiana::CFondoLiana(short ancho, short alto, short posX, short posY, short dx, short dy)
:CFigura(ancho, alto, posX, posY, dx, dy){

}
CFondoLiana::~CFondoLiana(){}
void CFondoLiana::mover() {

}
void CFondoLiana::dibujar(Graphics^ gr, Bitmap^ imgFondo) {
	Rectangle OrigenF = Rectangle(0, 0, imgFondo->Width, imgFondo->Height);
	Rectangle DestinoF = Rectangle(0, 0,
		(int)gr->VisibleClipBounds.Width, (int)gr->VisibleClipBounds.Height);
	gr->DrawImage(imgFondo, DestinoF, OrigenF, GraphicsUnit::Pixel);
}