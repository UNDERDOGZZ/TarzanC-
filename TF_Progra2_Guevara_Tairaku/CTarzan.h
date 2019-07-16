#pragma once
#include "CFigura.h"
#include "CuerdaLiana.h"
#include "CCuchilloTarzan.h"
#include "CLanza.h"
class CTarzan : public CFigura
{
public:
	CTarzan(short ancho, short alto, short posX, short posY, short dx, short dy,
		double i, double	angulo, double v0, double desplazamientox, double	desplazamientoy);
	~CTarzan();
	void mover();
	void dibujar(Graphics^ gr, Bitmap^ bmp);
	void dibujarEnBatalla(Graphics^ gr, Bitmap^ bmp);
	void detenerSalto();
	void cambiarAEstadoFrontal();
	void cambiarAEstadoSaltoAdelante();
	void cambiarAEstadoSaltoAtras();
	void actualizarPosicionTarzan();
	void colgarDeLiana();
	double getPosXSalto();
	double getPosYSalto();

	double geti();
	double getangulo();
	double getv0();
	double getdesplazamientox();
	double getdesplazamientoy();
	bool getmover();
	void seti(double i);
	void setangulo(double angulo);
	void setv0(double v0);
	CuerdaLiana* getlianaDondeCuelgo();
	CCuchilloTarzan* getcuchillo();
	void setlianaDondeCuelgo(CuerdaLiana* lianaDondeCuelgo);

	//todo controles de nado
	void nadarArriba();
	void nadarAbajo();
	void nadarIzquierda();
	void nadarDerecha();

	//batalla por jane
	vector<CLanza*> getarrLanzas();
	void lanzarLanza();
	void dibujarLanzas(Graphics^ gr, Bitmap^ bmp);
	void moverLanzas();
	void eliminarLanzas();
	void avanzar();
	void retroceder();
	void setestado(int estado);
	void setestadoY(int estado);
	void avanzarSpriteTarzan();
	void retrocederSpriteTarzan();
	void llamarAChita(Graphics^ gr, Bitmap^ bmp);
	int getvidasRestar();
	void setvidasRestar(int vidasRestar);
	void vidasRestasCero();
private:
	//pos del sprite
	int estadoX;
	int estadoY;
	//variables para hacer mov parabolico
	double i;
	double angulo;
	double v0;
	double desplazamientox;
	double desplazamientoy;
	bool moverr;
	int vidasRestar;
	//liana de la que se colagará tarzan
	CuerdaLiana* lianaDondeCuelgo;
	CCuchilloTarzan* cuchillo;
	vector<CLanza*> arrLanzas;
};

CTarzan::CTarzan(short ancho, short alto, short posX, short posY, short dx, short dy,
	double i, double	angulo, double v0, double desplazamientox, double	desplazamientoy)
	:CFigura(ancho, alto, posX, posY, dx, dy){
	this->estadoX = 0;
	this->estadoY = 0;
	this->i = i;
	this->angulo = angulo;
	this->v0 = v0;
	this->desplazamientox = desplazamientox;
	this->desplazamientoy = desplazamientoy;
	this->moverr = false;
	lianaDondeCuelgo = nullptr;
	vidasRestar = 0;
	cuchillo = new CCuchilloTarzan(30, 20, posX - 30, posY, 0, 0);
}
CTarzan::~CTarzan(){}
void CTarzan::mover() {
	desplazamientox = v0 * cos(angulo) * i;
	desplazamientoy = -0.5 * 9.81 * (i*i) + v0 * sin(angulo) * i;
	i += 0.50;//i = velocidad
}
void CTarzan::dibujar(Graphics^ gr, Bitmap^ bmp) {
	if (posY - desplazamientoy <= ALTO_FORMULARIO - alto){//valido que este dentro del mapa
		Rectangle rDestino = Rectangle(posX - desplazamientox, posY - desplazamientoy, ancho, alto);
		Rectangle rFuente = Rectangle(0, estadoX*alto, ancho, alto);
		gr->DrawImage(bmp, rDestino, rFuente, GraphicsUnit::Pixel);
		//dibujo el cuchillo de tarzan si esta en modo visible
		if (cuchillo->getvisible()) cuchillo->dibujar(gr, bmp);
		this->moverr = true;
	}
	else{
		detenerSalto();
		vidasRestar--;
	}
}
void CTarzan::dibujarEnBatalla(Graphics^ gr, Bitmap^ bmp){
	Rectangle rDestino = Rectangle(posX, posY, ancho, alto);
	Rectangle rFuente = Rectangle(estadoX * ancho, estadoY*alto, ancho, alto);
	gr->DrawImage(bmp, rDestino, rFuente, GraphicsUnit::Pixel);
}
void CTarzan::detenerSalto(){
	desplazamientox = 0;
	desplazamientoy = 0;
	i = 0;
	this->moverr = false;
}

void CTarzan::cambiarAEstadoFrontal(){ estadoX = 0; }
void CTarzan::cambiarAEstadoSaltoAdelante(){ estadoX = 1; }
void CTarzan::cambiarAEstadoSaltoAtras(){ estadoX = 2; }
void CTarzan::actualizarPosicionTarzan(){
	posX -= desplazamientox;
	posY -= desplazamientoy;
}
void CTarzan::colgarDeLiana(){
	if (lianaDondeCuelgo != nullptr && i == 0){//solo se cuelga en la liana cuando esta en una liana y no esta saltando
		posX += lianaDondeCuelgo->getDesplazamientoParaTarzan();
	}
}

double CTarzan::getPosXSalto(){ return posX - desplazamientox; }
double CTarzan::getPosYSalto(){ return posY - desplazamientoy; }

double CTarzan::geti(){ return i; }
double CTarzan::getangulo(){ return angulo; }
double CTarzan::getv0(){ return v0; }
double CTarzan::getdesplazamientox(){ return desplazamientox; }
double CTarzan::getdesplazamientoy(){ return desplazamientoy; }
bool CTarzan::getmover(){ return moverr; }
void CTarzan::seti(double i){ this->i = i; }
void CTarzan::setangulo(double angulo){ this->angulo = angulo; }
void CTarzan::setv0(double v0){ this->v0 = v0; }
CuerdaLiana* CTarzan::getlianaDondeCuelgo(){ return lianaDondeCuelgo; }
CCuchilloTarzan* CTarzan::getcuchillo(){ return cuchillo; }
void CTarzan::setlianaDondeCuelgo(CuerdaLiana* lianaDondeCuelgo){ this->lianaDondeCuelgo = lianaDondeCuelgo; }

//todo controles de nado
void CTarzan::nadarArriba(){ posY -= dy; cuchillo->setposY(cuchillo->getposY() - dy); }
void CTarzan::nadarAbajo(){ posY += dy; cuchillo->setposY(cuchillo->getposY() + dy); }
void CTarzan::nadarIzquierda(){ posX -= dx; cuchillo->setposX(cuchillo->getposX() - dx); }
void CTarzan::nadarDerecha(){ posX += dx; cuchillo->setposX(cuchillo->getposX() + dx); }

//batalla por jane
vector<CLanza*> CTarzan::getarrLanzas(){ return arrLanzas; }
void CTarzan::lanzarLanza(){
	arrLanzas.push_back(new CLanza(LARGO_CUCHILLO, ALTO_CUCHILLO, posX, posY, 15, 0));
}
void CTarzan::dibujarLanzas(Graphics^ gr, Bitmap^ bmp){
	for (int i = 0; i < arrLanzas.size(); i++){
		arrLanzas[i]->dibujar(gr, bmp);
	}
	moverLanzas();
}
void CTarzan::moverLanzas(){
	for (int i = 0; i < arrLanzas.size(); i++){
		arrLanzas[i]->mover();
	}
}
void CTarzan::eliminarLanzas(){
	for (int i = 0; i < arrLanzas.size();){
		if (arrLanzas[i]->geteliminado()){//si el cocodrilo tiene su atributo eliminado en true
			arrLanzas.erase(arrLanzas.begin() + i);
		}
		else i++;
	}
}
void CTarzan::avanzar(){ posX -= dx; }
void CTarzan::retroceder(){ posX += dx; }
void CTarzan::setestado(int estado){ this->estadoX = estado; }
void CTarzan::setestadoY(int estado){ this->estadoY = estado; }
void CTarzan::avanzarSpriteTarzan(){
	estadoX--;
	if (estadoX < 0)
		estadoX = 7;
}
void CTarzan::retrocederSpriteTarzan(){
	estadoX++;
	if (estadoX > 7)
		estadoX = 0;
}
void CTarzan::llamarAChita(Graphics^ gr, Bitmap^ bmp){
	Rectangle rFuente = Rectangle(0, 0, 25, 25);
	Rectangle rDestino = Rectangle(posX, posY, 25, 25);
	gr->DrawImage(bmp, rDestino, rFuente, GraphicsUnit::Pixel);
}
int CTarzan::getvidasRestar(){ return vidasRestar; }
void CTarzan::setvidasRestar(int vidasRestar){ this->vidasRestar = vidasRestar; }
void CTarzan::vidasRestasCero(){ vidasRestar = 0; }