#pragma once
#include "CListaCuerdasLianas.h"
#include "CFondoLianas.h"
#include "CFondoOceano.h"
#include "CFondoBatalla.h"
#include "CTarzan.h"
#include "CListaCocodrilos.h"
#include "CListaNativos.h"
#include "CAnimalesSelva.h"

class CControladora
{
	CListaCuerdasLianas* lista;
	CFondoLiana* fondo;
	CTarzan* tarzan;
	//oceano
	CListaCocodrilos* listacocodrilos;
	CFondoOceano* fondoOceano;	
	CTarzan* tarzanNadador;
	//vida tarzan 
	int vidas;
	int semillas;
	int chitas;
	int animales;
	int tiempo;
	//batalla
	CListaNativos* listaNativos;
	CFondoBatalla* fondoBatalla;
	CTarzan* tarzanBatalla;
	CAnimalesSelva* animalesSelva;
public:
	CControladora();
	~CControladora();

	void moverCuerdasLiana();
	void saltarTarzan();
	void desplazarCuerdasLiana();
	void dibujarCuerdasLianas(Graphics^ gr);
	int gettiempo();
	void settiempo(int tiempo);
	void avanzartiempo();

	void dibujarTarzan(Graphics^ gr, Bitmap^ bmpTarzan);
	void dibujarTarzanNadando(Graphics^ gr, Bitmap^ bmpTarzanNadando);
	void dibujarTarzanBatalla(Graphics^ gr, Bitmap^ bmpTarzanBatalla);

	void dibujarFondoLianas(Graphics^ gr, Bitmap^ bmpFondoLiana);
	void dibujarFondoOceano(Graphics^ gr, Bitmap^ bmpFondoOceano);
	void dibujarFondoBatalla(Graphics^ gr, Bitmap^ bmpFondoBatalla);

	CTarzan* gettarzan();
	CTarzan* gettarzanBatalla();
	void validarSiTarzanSePegaALiana();
	void tarzanColgarDeLiana();
	void dibujarVidasLianas(Graphics^ gr);
	void vidasLianas();
	bool tarzanPierdeJuego();
	//nivel de oceano 
	void tarzanNadar(Keys tecla_presionada);
	void agregarBurbuja(CBurbujaOceano* burbuja);
	void moverBurbujas();
	void dibujarBurbujas(Graphics^ gr);
	void agregarCocodrilo(CCocodrilo* c);
	void moverCocodrilos();
	void dibujarCocodrilos(Graphics^ gr, Bitmap^ bmp);
	void validarSiTarzanChocaCocodrilo();
	void validarCuchilloMataCocodrilo();
	void disminuirVidas();
	void dibujarVidas(Graphics^ gr);
	void ataqueCuchillo();
	void ocultaCuchillo();
	//batalla
	void agregarNativo(CNativo* nativo);
	void moverNativos();
	void dibujarNativos(Graphics^ gr, Bitmap^ bmp);

	void avanzarTarzanBatalla();
	void retrocederTarzanBatalla();
	void dibujarLanzas(Graphics^ gr, Bitmap^ bmp);
	void validarLanzaMataNativo();
	void dibujarInstruccionesBatalla(Graphics^ gr);
	bool validarTarzanEncuentraJane();
	void validarTarzanColisionaNativo();
	void comerSemilla();
	void llamarAChita(Graphics^ gr, Bitmap^ bmp);
	void efectuarCuracionChita();
	void llamarAnimales();
	void moverAnimalesSelva();
	void dibujarAnimalesSelva(Graphics^ gr, Bitmap^ bmp);
	void validarAnimalesConNativos();
	CAnimalesSelva* getanimalesSelva();
	void setanimalesSelva(CAnimalesSelva* animalesSelva);
	CTarzan* gettarzanNadador();
	void settarzanNadador(CTarzan* tarzanNadador);
private:

};

CControladora::CControladora(){
	lista = new CListaCuerdasLianas();
	fondo = new CFondoLiana(LARGO_FORMULARIO, ALTO_FORMULARIO, 0, 0, 15, 15);
	tarzan = new CTarzan(LARGO_TARZAN, ALTO_TARZAN, 575, 225, 10, 10, 0, 45, 40, 0, 0);
	//nivel oceano
	listacocodrilos = new CListaCocodrilos();
	fondoOceano = new CFondoOceano(LARGO_FORMULARIO, ALTO_FORMULARIO, 0, 0, 15, 0);
	tarzanNadador = new CTarzan(LARGO_TARZAN_NADANDO, ALTO_TARZAN_NADANDO, 820, 400, 15, 15, 0, 45, 40, 0, 0);
	//batalla
	listaNativos = new CListaNativos();
	fondoBatalla = new CFondoBatalla(LARGO_FORMULARIO, ALTO_FORMULARIO, 0, 0, 0, 0);
	tarzanBatalla = new CTarzan(LARGO_TARZAN_BATALLA, ALTO_TARZAN_BATALLA, 820, ALTO_FORMULARIO / 2 - ALTO_TARZAN_BATALLA, 5, 0, 0, 45, 40, 0, 0);
	animalesSelva = new CAnimalesSelva(LARGO_ANIMALES_SELVA, ALTO_ANIMALES_SELVA, tarzanBatalla->getposX(), tarzanBatalla->getposY(), 10, 0);
	tarzanBatalla->setestado(7);
	vidas = 10;
	semillas = 5;
	chitas = 5;
	animales = 2;
	tiempo = 0;
}
CControladora::~CControladora(){}

void CControladora::moverCuerdasLiana(){ lista->moverCuerdaLiana(); }
void CControladora::saltarTarzan(){ tarzan->mover(); }
void CControladora::desplazarCuerdasLiana(){ lista->desplazarCuerdasLiana(); }
void CControladora::dibujarCuerdasLianas(Graphics^ gr){ lista->dibujar(gr); }
int CControladora::gettiempo(){ return tiempo; }
void CControladora::settiempo(int tiempo){ this->tiempo = tiempo; }
void CControladora::avanzartiempo(){ tiempo--; }

void CControladora::dibujarTarzan(Graphics^ gr, Bitmap^ bmpTarzan){ tarzan->dibujar(gr, bmpTarzan); }
void CControladora::dibujarTarzanNadando(Graphics^ gr, Bitmap^ bmpTarzanNadando){ tarzanNadador->dibujar(gr, bmpTarzanNadando); }
void CControladora::dibujarTarzanBatalla(Graphics^ gr, Bitmap^ bmpTarzanBatalla){ tarzanBatalla->dibujarEnBatalla(gr, bmpTarzanBatalla); }

void CControladora::dibujarFondoLianas(Graphics^ gr, Bitmap^ bmpFondoLiana){ fondo->dibujar(gr, bmpFondoLiana); }
void CControladora::dibujarFondoOceano(Graphics^ gr, Bitmap^ bmpFondoOceano){ fondoOceano->dibujar(gr, bmpFondoOceano); }
void CControladora::dibujarFondoBatalla(Graphics^ gr, Bitmap^ bmpFondoBatalla){ fondoBatalla->dibujar(gr, bmpFondoBatalla); }

CTarzan* CControladora::gettarzan(){ return tarzan; }
CTarzan* CControladora::gettarzanBatalla(){ return tarzanBatalla; }
void CControladora::validarSiTarzanSePegaALiana(){
	vector<CuerdaLiana*> lianas = lista->getlista();
	//creo un rectangulo que representa a tarzan
	Rectangle rTarzan = Rectangle(tarzan->getPosXSalto(), tarzan->getPosYSalto(), tarzan->getancho(), tarzan->getalto());
	for (int i = 0; i < lianas.size(); i++){
		//si tarzan ya esta colgado de una liana, evito esa liana
		if (tarzan->getlianaDondeCuelgo() != nullptr){
			if (lianas[i] == tarzan->getlianaDondeCuelgo())
				continue;
		}
		//creo un rectangulo que representa a la liana
		Rectangle rLiana = Rectangle(lianas[i]->getPosxLiana(), lianas[i]->getposY(), lianas[i]->getAnchoLiana(), lianas[i]->getAltoLiana());
		//pregunto si tarzan colisiona con la liana
		if (rLiana.IntersectsWith(rTarzan)){
			//seteo las coordenadas xy de tarzan 
			tarzan->actualizarPosicionTarzan();
			tarzan->setlianaDondeCuelgo(lianas[i]);
			tarzan->detenerSalto();
		}
	}
}
void CControladora::tarzanColgarDeLiana(){
	tarzan->colgarDeLiana();
}
void CControladora::dibujarVidasLianas(Graphics^ gr){ gr->DrawString("Vidas: " + vidas, gcnew Font("Arial", 20), Brushes::Black, 0, 0); }
void CControladora::vidasLianas(){//disminuyo las vidas si caigo de las lianas
	if (tarzan->getvidasRestar() < 0){
		vidas--;
		tarzan->vidasRestasCero();
	}
}
bool CControladora::tarzanPierdeJuego(){
	return vidas <= 0;
}
//nivel de oceano 
void CControladora::tarzanNadar(Keys tecla_presionada){
	if (tecla_presionada == Keys::Right){
		tarzanNadador->nadarDerecha();
	}
	else if (tecla_presionada == Keys::Left){
		tarzanNadador->nadarIzquierda();
	}
	else if (tecla_presionada == Keys::Up){
		tarzanNadador->nadarArriba();
	}
	else if (tecla_presionada == Keys::Down){
		tarzanNadador->nadarAbajo();
	}
}
void CControladora::agregarBurbuja(CBurbujaOceano* burbuja){ fondoOceano->agregarBurbuja(burbuja); }
void CControladora::moverBurbujas(){ fondoOceano->moverBurbujas(); }
void CControladora::dibujarBurbujas(Graphics^ gr){ fondoOceano->dibujarBurbujas(gr); }
void CControladora::agregarCocodrilo(CCocodrilo* c) { listacocodrilos->agregarCocodrilos(c); }
void CControladora::moverCocodrilos() { listacocodrilos->moverCocodrilos(); }
void CControladora::dibujarCocodrilos(Graphics^ gr, Bitmap^ bmp) { listacocodrilos->dibujar(gr, bmp); }
void CControladora::validarSiTarzanChocaCocodrilo(){
	vector<CCocodrilo*> listaCoco = listacocodrilos->getlista();
	//creo un rectangulo que representa a tarzan
	Rectangle rTarzan = Rectangle(tarzanNadador->getposX(), tarzanNadador->getposY(), tarzanNadador->getancho(), tarzanNadador->getalto());
	for (int i = 0; i < listaCoco.size(); i++){
		//creo un rectangulo que representa a cocodrilo
		Rectangle rCoco = Rectangle(listaCoco[i]->getposX(), listaCoco[i]->getposY(), listaCoco[i]->getancho(), listaCoco[i]->getalto());
		//pregunto si tarzan colisiona con cocodrilo y ademas si no lo he tocado previamente
		if (rCoco.IntersectsWith(rTarzan) && listaCoco[i]->gettocado() == false && listaCoco[i]->geteliminado() == false){
			//disminuyo vidas
			disminuirVidas();
			listaCoco[i]->settocado(true);
		}
	}
}
void CControladora::validarCuchilloMataCocodrilo(){
	vector<CCocodrilo*> listaCoco = listacocodrilos->getlista();
	//creo un rectangulo que representa al cuchillo
	CCuchilloTarzan* cu = tarzanNadador->getcuchillo();
	Rectangle rCuchillo = Rectangle(cu->getposX(), cu->getposY(), cu->getancho(), cu->getalto());
	for (int i = 0; i < listaCoco.size(); i++){
		//creo un rectangulo que representa a cocodrilo
		Rectangle rCoco = Rectangle(listaCoco[i]->getposX(), listaCoco[i]->getposY(), listaCoco[i]->getancho(), listaCoco[i]->getalto());
		//pregunto si cuchillo colisiona con cocodrilo, ademas si no lo he tocado previamente y si esta visible el cuchillo
		if (rCoco.IntersectsWith(rCuchillo) &&
			listaCoco[i]->geteliminado() == false &&
			cu->getvisible()){
			//elimino cocodrilos
			listaCoco[i]->settocado(true);
			listaCoco[i]->seteliminado(true);
			break;//dejo de buscar cocodrilos
		}
	}
	//elimino los cocodrilos cuyo eliminado fue seteado en true
	listacocodrilos->eliminarCocodrilos();
}
void CControladora::disminuirVidas(){ vidas--; }
void CControladora::dibujarVidas(Graphics^ gr){ gr->DrawString("Vidas: " + vidas + " | (A)Atacar | (S)Ocultar | (C)Semillas: " + semillas, gcnew Font("Arial", 20), Brushes::Black, 0, 0); }
void CControladora::ataqueCuchillo(){ tarzanNadador->getcuchillo()->setvisible(true); }
void CControladora::ocultaCuchillo(){ tarzanNadador->getcuchillo()->setvisible(false); }
//batalla
void CControladora::agregarNativo(CNativo* nativo){ listaNativos->agregarNativo(nativo); }
void CControladora::moverNativos(){ listaNativos->moverNativos(); }
void CControladora::dibujarNativos(Graphics^ gr, Bitmap^ bmp){ listaNativos->dibujarNativos(gr, bmp); }

void CControladora::avanzarTarzanBatalla(){ tarzanBatalla->avanzar(); }
void CControladora::retrocederTarzanBatalla(){ tarzanBatalla->retroceder(); }
void CControladora::dibujarLanzas(Graphics^ gr, Bitmap^ bmp){ tarzanBatalla->dibujarLanzas(gr, bmp); }
void CControladora::validarLanzaMataNativo(){
	vector<CNativo*> nativos = listaNativos->getlista();
	vector<CLanza*> lanzas = tarzanBatalla->getarrLanzas();

	for (int i = 0; i < nativos.size(); i++){
		//rectangulo que representa al nativo de la actual iteracion
		Rectangle rNativo = Rectangle(nativos[i]->getposX(), nativos[i]->getposY(), nativos[i]->getancho(), nativos[i]->getalto());
		for (int j = 0; j < lanzas.size(); j++){
			//rectangulo que representa a la lanza de la actual iteracion
			Rectangle rLanza = Rectangle(lanzas[j]->getposX(), lanzas[j]->getposY(), lanzas[j]->getancho(), lanzas[j]->getalto());
			if (rLanza.IntersectsWith(rNativo) &&
				lanzas[j]->geteliminado() == false &&
				nativos[i]->geteliminado() == false){//si colisionan y la lanza y el nativo no han colisionado previamente

				lanzas[j]->seteliminado(true);
				nativos[i]->seteliminado(true);
			}
		}
	}

	listaNativos->eliminarNativos();
	tarzanBatalla->eliminarLanzas();
}
void CControladora::dibujarInstruccionesBatalla(Graphics^ gr){
	gr->DrawString("Vidas: " + vidas +
		" | (SPACE)Atacar | (C)Semillas: " +
		semillas + " | (L)Llamar chita: " + chitas +
		" | (A) LLAMAR ANIMALES: " + animales, gcnew Font("Arial", 15), Brushes::Black, 0, 0);
}
bool CControladora::validarTarzanEncuentraJane(){
	Rectangle rTarzan = Rectangle(tarzanBatalla->getposX(), tarzanBatalla->getposY(), tarzanBatalla->getancho(), tarzanBatalla->getalto());
	CJane* jane = fondoBatalla->getjane();
	Rectangle rJane = Rectangle(jane->getposX(), jane->getposY(), jane->getancho(), jane->getalto());
	return rTarzan.IntersectsWith(rJane);
}
void CControladora::validarTarzanColisionaNativo(){
	vector<CNativo*> nativos = listaNativos->getlista();
	//creo un rectangulo que representa a tarzan
	Rectangle rTarzan = Rectangle(tarzanBatalla->getposX(), tarzanBatalla->getposY(), tarzanBatalla->getancho(), tarzanBatalla->getalto());
	for (int i = 0; i < nativos.size(); i++){
		//rectangulo que representa al nativo de la actual iteracion
		Rectangle rNativo = Rectangle(nativos[i]->getposX(), nativos[i]->getposY(), nativos[i]->getancho(), nativos[i]->getalto());
		//pregunto si tarzan colisiona con nativo y ademas si no lo he tocado previamente
		if (rNativo.IntersectsWith(rTarzan) && nativos[i]->gettocado() == false && nativos[i]->geteliminado() == false){
			//disminuyo vidas
			disminuirVidas();
			nativos[i]->settocado(true);
		}
	}
}
void CControladora::comerSemilla(){
	if (semillas > 0){
		semillas--;
		vidas++;
	}
}
void CControladora::llamarAChita(Graphics^ gr, Bitmap^ bmp){
	tarzanBatalla->llamarAChita(gr, bmp);
}
void CControladora::efectuarCuracionChita(){
	if (chitas > 0){
		vidas++;
		chitas--;
	}
}
void CControladora::llamarAnimales(){
	if (animales > 0){
		animalesSelva->setvisible(true);
		animales--;
	}
}
void CControladora::moverAnimalesSelva(){
	if (animalesSelva->getvisible() == true) animalesSelva->mover();
}
void CControladora::dibujarAnimalesSelva(Graphics^ gr, Bitmap^ bmp){
	if (animalesSelva->getvisible() == true) animalesSelva->dibujar(gr, bmp);
}
void CControladora::validarAnimalesConNativos(){
	if (animalesSelva->getvisible() == true){//solo si los animales estan visibles pregunto si colisionan
		vector<CNativo*> nativos = listaNativos->getlista();
		//creo un rectangulo que representa a los animales
		Rectangle rAnimales = Rectangle(animalesSelva->getposX(), animalesSelva->getposY(), animalesSelva->getancho(), animalesSelva->getalto());
		for (int i = 0; i < nativos.size(); i++){
			//rectangulo que representa al nativo de la actual iteracion
			Rectangle rNativo = Rectangle(nativos[i]->getposX(), nativos[i]->getposY(), nativos[i]->getancho(), nativos[i]->getalto());
			//pregunto si tarzan colisiona con nativo y ademas si no lo he tocado previamente
			if (rNativo.IntersectsWith(rAnimales) && nativos[i]->gettocado() == false && nativos[i]->geteliminado() == false){
				//marco como eliminado al nativo
				nativos[i]->seteliminado(true);
			}
		}
		listaNativos->eliminarNativos();
	}
	if (animalesSelva->getposX() <= 0)//si los animales salen de la pantalla
		animalesSelva->setvisible(false);
}
CAnimalesSelva* CControladora::getanimalesSelva(){ return animalesSelva; }
void CControladora::setanimalesSelva(CAnimalesSelva* animalesSelva){ this->animalesSelva = animalesSelva; }
CTarzan* CControladora::gettarzanNadador(){ return tarzanNadador; }
void CControladora::settarzanNadador(CTarzan* tarzanNadador){ this->tarzanNadador = tarzanNadador; }