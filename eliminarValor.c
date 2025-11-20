#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION eliminarValor
void eliminarValor(Nodo **cabeza, int valor){
    // Caso 1: Lista vacía
    if (*cabeza == NULL){
        printf("La lista está vacía. No se pudo eliminar %d.\n", valor);
        return;
    }

    // Caso 2: El nodo a eliminar es la cabeza
    Nodo *actual = *cabeza;
    if (actual->dato == valor){
        *cabeza = actual->siguiente;
        printf("Eliminando nodo cabeza con valor %d.\n", valor);
        free(actual);
        return;
    }

    // Caso 3: El nodo está en medio o al final de la lista
    Nodo *previo = NULL;
    while (actual != NULL && actual->dato != valor){
        previo = actual;
        actual = actual->siguiente;
    }

    // Si 'actual' es NULL, significa que el valor no se encontró
    if (actual == NULL){
        printf("Valor %d NO encontrado en la lista.\n", valor);
        return;
    }

    // El nodo a eliminar es 'actual'.
    // Desvinculamos el nodo 'actual' de la lista.
    previo->siguiente = actual->siguiente;

    printf("Eliminando nodo con valor %d.\n", valor);
    free(actual); // Liberamos la memoria del nodo.
}
// FIN FUNCION eliminarValor

int main(){
    Nodo *lista1 = NULL;
    eliminarValor(&lista1, 666);
    return 0;
}