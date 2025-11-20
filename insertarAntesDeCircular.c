#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION insertarAntesDeCircular
void insertarAntesDeCircular(Nodo **cabeza, int referencia, int valor) {
    if (*cabeza == NULL) {
        printf("La lista está vacía. No se puede insertar antes de %d.\n", referencia);
        return;
    }

    Nodo *actual = *cabeza;
    Nodo *previo = NULL;
    int encontrado = 0;

    // Buscar el nodo con dato == referencia y su previo
    do {
        if (actual->dato == referencia) {
            encontrado = 1;
            break;
        }
        previo = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    if (!encontrado) {
        printf("Referencia %d NO encontrada. No se realizó la inserción.\n", referencia);
        return;
    }

    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    nuevoNodo->dato = valor;

    // Si el nodo encontrado es la cabeza, debemos colocar el nuevo nodo
    // antes de la cabeza y actualizar *cabeza
    if (actual == *cabeza) {
        // Encontrar el último para actualizar su enlace
        Nodo *ultimo = *cabeza;
        while (ultimo->siguiente != *cabeza) {
            ultimo = ultimo->siguiente;
        }
        nuevoNodo->siguiente = *cabeza;
        ultimo->siguiente = nuevoNodo;
        *cabeza = nuevoNodo;
    } else {
        // Inserción normal entre previo y actual
        previo->siguiente = nuevoNodo;
        nuevoNodo->siguiente = actual;
    }

    printf("Insertado %d ANTES de %d (circular).\n", valor, referencia);
}
// FIN FUNCION insertarAntesDeCircular

int main(){
    Nodo *lista = NULL;
    insertarAntesDeCircular(&lista, 999, 666);
    return 0;
}