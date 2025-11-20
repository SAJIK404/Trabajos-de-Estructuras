#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION insertarInicioCircular
void insertarInicioCircular(Nodo **cabeza, int valor) {
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    nuevoNodo->dato = valor;

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
        printf("Insertado %d al inicio (primer nodo, circular).\n", valor);
        return;
    }

    // Encontrar el último nodo para mantener el círculo
    Nodo *ultimo = *cabeza;
    while (ultimo->siguiente != *cabeza) {
        ultimo = ultimo->siguiente;
    }

    nuevoNodo->siguiente = *cabeza;
    ultimo->siguiente = nuevoNodo;
    *cabeza = nuevoNodo;

    printf("Insertado %d al inicio (circular).\n", valor);
}
// FIN FUNCION insertarInicioCircular