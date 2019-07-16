#pragma once
#include "CFigura.h"
#include "CBurbujaOceano.h"
class CFondoOceano: public CFigura
{
public:
	CFondoOceano(short ancho, short alto, short posX, short posY, short dx, short dy);
	~CFondoOceano();
	void mover();
	void dibujar(Graphics^ gr, Bitmap^ bmp);
	void agregarBurbuja(CBurbujaOceano* burbuja);
	void moverBurbujas();
	void dibujarBurbujas(Graphics^ gr);
private:
	vector<CBurbujaOceano*> burbujas;
};

CFondoOceano::CFondoOceano(short ancho, short alto, short posX, short posY, short dx, short dy)
:CFigura(ancho, alto, posX, posY, dx, dy){

}
CFondoOceano::~CFondoOceano(){}
void CFondoOceano::mover() {

}
void CFondoOceano::dibujar(Graphics^ gr, Bitmap^ bmp) {
	gr->FillRectangle(Brushes::LightBlue, posX, posY, ancho, alto);//cielo
	gr->FillRectangle(Brushes::Blue, posX, posY + (alto / 3), ancho, alto);//oceano
}
void CFondoOceano::agregarBurbuja(CBurbujaOceano* burbuja){
	burbujas.push_back(burbuja);
}
void CFondoOceano::moverBurbujas(){
	for (int i = 0; i < burbujas.size(); i++){
		burbujas[i]->mover();
	}
}
void CFondoOceano::dibujarBurbujas(Graphics^ gr){
	for (int i = 0; i < burbujas.size(); i++){
		burbujas[i]->dibujar(gr);
	}
}