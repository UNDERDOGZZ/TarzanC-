#pragma once
#include <vector>
#include "CNativo.h"
using namespace std;

class CListaNativos
{

public:
	CListaNativos();
	~CListaNativos();

	void agregarNativo(CNativo* c);
	void moverNativos();
	void dibujarNativos(Graphics^ gr, Bitmap^ bmp);
	void eliminarNativos();
	vector<CNativo*> getlista();
private:
	vector<CNativo*> lista;
};

CListaNativos::CListaNativos(){}
CListaNativos::~CListaNativos(){}

void CListaNativos::agregarNativo(CNativo* c) {
	lista.push_back(c);
}
void CListaNativos::moverNativos() {
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->mover();
	}
}
void CListaNativos::dibujarNativos(Graphics^ gr, Bitmap^ bmp) {
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->dibujar(gr, bmp);
	}
}
void CListaNativos::eliminarNativos(){
	for (int i = 0; i < lista.size();){
		if (lista[i]->geteliminado()){//si el cocodrilo tiene su atributo eliminado en true
			lista.erase(lista.begin() + i);
		}
		else i++;
	}
}
vector<CNativo*> CListaNativos::getlista(){ return lista; }