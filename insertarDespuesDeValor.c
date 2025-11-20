#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION insertarDespuesDeValor
void insertarDespuesDeValor(Nodo **cabeza, int nuevoValor, int valorReferencia){
    // 1. Crear el nuevo nodo
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevoNodo){
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    nuevoNodo->dato = nuevoValor;

    // Caso A: La lista está vacía
    if (*cabeza == NULL){
        printf("Lista vacía. No se puede insertar %d después de %d.\n", nuevoValor, valorReferencia);
        free(nuevoNodo);
        return;
    }

    // Caso B: Buscar el nodo de referencia
    Nodo *actual = *cabeza;
    
    // Recorrer hasta encontrar el nodo con valorReferencia, o hasta llegar al final.
    while (actual != NULL && actual->dato != valorReferencia){
        actual = actual->siguiente;
    }

    // Caso C: Valor de referencia NO encontrado
    if (actual == NULL){
        printf("Valor de referencia %d NO encontrado en la lista. No se pudo insertar %d.\n", valorReferencia, nuevoValor);
        free(nuevoNodo);
        return;
    }

    // Caso D: Inserción después del nodo encontrado
    // 'actual' es el nodo de referencia.
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
    
    printf("Insertado %d después de %d.\n", nuevoValor, valorReferencia);
}
// FIN FUNCION insertarDespuesDeValor

int main(){
    Nodo *lista1 = NULL;
    insertarDespuesDeValor(&lista1, 999, 666);
    return 0;
}