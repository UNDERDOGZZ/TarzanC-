#pragma once
#include "CONSTANTES.h"
using namespace System::Drawing;
using namespace System;
using namespace std;
using namespace System::Windows::Forms;
class CImagen
{
public:
	CImagen();
	CImagen(char* nombre,
		short ancho,
		short alto,
		short posX,
		short posY,
		short dx,
		short dy);
	char* getnombre	();
	short getancho	();
	short getalto	();
	short getposX	();
	short getposY	();
	short getdx		();
	short getdy		();

	void setnombre	(char* nombre	);
	void setancho	(short ancho	);
	void setalto	(short alto		);
	void setposX	(short posX		);
	void setposY	(short posY		);
	void setdx		(short dx		);
	void setdy		(short dy		);

protected:
	char* nombre;
	short ancho;
	short alto;
	short posX;
	short posY;
	short dx;
	short dy;
};

CImagen::CImagen() {
	nombre = new char[10];
	ancho = 0;
	alto = 0;
	posX = 0;
	posY = 0;
	dx = 0;
	dy = 0;
}
CImagen::CImagen(char* nombre,
	short ancho,
	short alto,
	short posX,
	short posY,
	short dx,
	short dy) {
	this->nombre = nombre;
	this->ancho = ancho;
	this->alto = alto;
	this->posX = posX;
	this->posY = posY;
	this->dx = dx;
	this->dy = dy;
}
char* CImagen::getnombre(){ return nombre; }
short CImagen::getancho(){ return ancho; }
short CImagen::getalto(){ return alto; }
short CImagen::getposX(){ return posX; }
short CImagen::getposY(){ return posY; }
short CImagen::getdx(){ return dx; }
short CImagen::getdy(){ return dy; }

void CImagen::setnombre(char* nombre){ this->nombre = nombre; }
void CImagen::setancho(short ancho){ this->ancho = ancho; }
void CImagen::setalto(short alto){ this->alto = alto; }
void CImagen::setposX(short posX){ this->posX = posX; }
void CImagen::setposY(short posY){ this->posY = posY; }
void CImagen::setdx(short dx){ this->dx = dx; }
void CImagen::setdy(short dy){ this->dy = dy; }