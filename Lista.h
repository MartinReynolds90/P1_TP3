#pragma once

#include "iostream"
#include "Nodo.h"
#include "Vagon.h"
#include "stdlib.h"

using namespace std;

class Lista {
private:
	Nodo* primer_v;
	Nodo* ultimo_v;
public:
	Lista();
	void agregar_nodo(Vagon*);
	void recorrer_lista(float,float);
	//void eliminar_nodo(Vagon*);
	void quitar_nodo();


};

