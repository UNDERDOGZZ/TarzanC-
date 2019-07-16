#pragma once
#include <vector>
#include "CuerdaLiana.h"
using namespace std;

class CListaCuerdasLianas
{
	
public:
	CListaCuerdasLianas();
	~CListaCuerdasLianas();
	void agregarCuerdasLianasIniciales();
	void agregarCuerdaLiana(CuerdaLiana* c);
	void moverCuerdaLiana();
	void desplazarCuerdasLiana();
	void dibujar(Graphics^ gr);
	vector<CuerdaLiana*> getlista();
private:
	vector<CuerdaLiana*> lista;
};

CListaCuerdasLianas::CListaCuerdasLianas()
{
	agregarCuerdasLianasIniciales();
}

CListaCuerdasLianas::~CListaCuerdasLianas(){}
void CListaCuerdasLianas::agregarCuerdasLianasIniciales() {
	lista.push_back(new CuerdaLiana(100, 100, VELOCIDAD_LIANA_MEDIO, TAMAÑO_LIANA_PEQUEÑO));
	lista.push_back(new CuerdaLiana(300, 100, VELOCIDAD_LIANA_MUY_LENTO, TAMAÑO_LIANA_MUY_PEQUEÑO));
	lista.push_back(new CuerdaLiana(500, 100, VELOCIDAD_LIANA_RAPIDO, TAMAÑO_LIANA_GRANDE));
	lista.push_back(new CuerdaLiana(700, 100, VELOCIDAD_LIANA_LENTO, TAMAÑO_LIANA_MEDIO));
}
void CListaCuerdasLianas::agregarCuerdaLiana(CuerdaLiana* c) {
	lista.push_back(c);
}
void CListaCuerdasLianas::moverCuerdaLiana() {
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->mover();
	}
}
void CListaCuerdasLianas::desplazarCuerdasLiana() {
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->desplazar();
	}
}
void CListaCuerdasLianas::dibujar(Graphics^ gr) {
	for (int i = 0; i < lista.size(); i++) {

		lista[i]->dibuja(gr);
	}
}
vector<CuerdaLiana*> CListaCuerdasLianas::getlista(){ return lista; }