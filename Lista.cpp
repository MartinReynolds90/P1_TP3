#include "Lista.h"

Lista::Lista() {
    primer_v = NULL;

}

void Lista::agregar_nodo(Vagon *v) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = v;

    Nodo* aux1 = primer_v;
    Nodo* aux2 = NULL;
    
    while ((aux1 != NULL) && (aux1->dato->get_num() <= v->get_num())) {//ordena los vagones a medida que ingresan
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

    while (actual != NULL) {
        actual->dato->set_position(x,y);
        x = x - 55;
        actual = actual->siguiente;
    }

}

void Lista::quitar_nodo() {
    Nodo* borrar = new Nodo();
    borrar = primer_v;
    primer_v = primer_v->siguiente;
    borrar->siguiente = NULL;
    borrar->dato->set_position(0, 0);
    delete borrar;
}

/*void Lista::eliminar_nodo(Vagon* elim) {
    
        Nodo* borrar;
        borrar = primer_v;
        Nodo* anterior = NULL;

        
        cout << "numero del elemento que quiero borrar >>> " << elim->get_num() << endl;
        while ((borrar != NULL) && (borrar->dato != elim)) {
            anterior = borrar;
            borrar = borrar->siguiente;
        }
        if (borrar == NULL) {
            if (primer_v == NULL)cout << "lista vacia" << endl;
            else { cout << "el elemento no esta en la lista " << endl; }
        }
        else if (primer_v == borrar) {
            primer_v = borrar->siguiente;
            delete borrar;
        }
        else {
            anterior->siguiente = borrar->siguiente;
            borrar->dato->set_position(0, 0);
            delete borrar;
        }
    
}*/