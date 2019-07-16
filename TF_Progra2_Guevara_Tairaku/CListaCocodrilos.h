#pragma once
#include <vector>
#include "CCocodrilo.h"
using namespace std;

class CListaCocodrilos
{

public:
	CListaCocodrilos();
	~CListaCocodrilos();

	void agregarCocodrilos(CCocodrilo* c);
	void moverCocodrilos();
	void dibujar(Graphics^ gr, Bitmap^ bmp);
	void eliminarCocodrilos();
	vector<CCocodrilo*> getlista();
private:
	vector<CCocodrilo*> lista;
};

CListaCocodrilos::CListaCocodrilos(){}
CListaCocodrilos::~CListaCocodrilos(){}

void CListaCocodrilos::agregarCocodrilos(CCocodrilo* c) {
	lista.push_back(c);
}
void CListaCocodrilos::moverCocodrilos() {
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->mover();
	}
}
void CListaCocodrilos::dibujar(Graphics^ gr, Bitmap^ bmp) {
	for (int i = 0; i < lista.size(); i++) {
		lista[i]->dibujar(gr, bmp);
	}
}
void CListaCocodrilos::eliminarCocodrilos(){
	for (int i = 0; i < lista.size();){
		if (lista[i]->geteliminado()){//si el cocodrilo tiene su atributo eliminado en true
			lista.erase(lista.begin() + i);
		}
		else i++;
	}
}
vector<CCocodrilo*> CListaCocodrilos::getlista(){ return lista; }