#include "Lista.h"

Lista::Lista() {
    primer_v = NULL;

}

void Lista::agregar_nodo(Vagon *v) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = v;
    Nodo* aux1 = primer_v;
    Nodo* aux2 = NULL;
    
    while ((aux1 != NULL) && (aux1->dato->get_num() <= v->get_num())) {//ordena los vagones al ingresar a la lista
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (primer_v == aux1) {
        primer_v = nuevo_nodo;
    }
    else {
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
}

void Lista::recorrer_lista(float x,float y) {
    Nodo* actual = new Nodo();
    actual = primer_v;

    while (actual != NULL) {//mientras recorre la lista le pasa a cada vagon una posicion en x menor al anterior
        actual->dato->set_position(x,y);
        x = x - 55;
        actual = actual->siguiente;
    }

}

void Lista::quitar_nodo() {//borra el primer nodo de la lista
    if (primer_v == NULL)cout << "lista vacia" << endl;
    else {
        Nodo* borrar = new Nodo();
        borrar = primer_v;
  
        primer_v = primer_v->siguiente;
        borrar->siguiente = NULL;
        borrar->dato->set_position(0,-80);
        delete borrar;
    }
}

bool Lista::lista_vacia() {//avisa si la lista esta vacia o no
    bool vacia;
    if (primer_v == NULL) {
        vacia = true;
    }
    else {
        vacia = false;
    }
    return vacia;
}

