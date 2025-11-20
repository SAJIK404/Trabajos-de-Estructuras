#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION insertarAntesDeValor
void insertarAntesDeValor(Nodo **cabeza, int nuevoValor, int valorReferencia){
    // 1. Crear el nuevo nodo
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevoNodo){
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    nuevoNodo->dato = nuevoValor;

    // Caso A: La lista está vacía
    if (*cabeza == NULL){
        printf("Lista vacía. No se puede insertar %d antes de %d.\n", nuevoValor, valorReferencia);
        free(nuevoNodo);
        return;
    }

    // Caso B: Insertar antes de la CABEZA
    if ((*cabeza)->dato == valorReferencia){
        nuevoNodo->siguiente = *cabeza;
        *cabeza = nuevoNodo;
        printf("Insertado %d antes del nodo cabeza con valor %d.\n", nuevoValor, valorReferencia);
        return;
    }

    // Caso C: Buscar el nodo previo al valor de referencia
    Nodo *actual = *cabeza;
    Nodo *previo = NULL;

    // Recorrer hasta que el siguiente nodo tenga el valor de referencia, 
    // o hasta llegar al final de la lista.
    while (actual != NULL && actual->dato != valorReferencia){
        previo = actual;
        actual = actual->siguiente;
    }

    // Caso D: Valor de referencia NO encontrado
    if (actual == NULL){
        printf("Valor de referencia %d NO encontrado en la lista. No se pudo insertar %d.\n", valorReferencia, nuevoValor);
        free(nuevoNodo);
        return;
    }

    // Caso E: Inserción en medio o al final
    // 'actual' es el nodo con valorReferencia. 'previo' es el nodo justo antes.
    nuevoNodo->siguiente = actual;
    previo->siguiente = nuevoNodo;
    
    printf("Insertado %d antes de %d.\n", nuevoValor, valorReferencia);
}
// FIN FUNCION insertarAntesDeValor

int main(){
    Nodo *lista1 = NULL;
    insertarAntesDeValor(&lista1, 999, 666);
    return 0;
}