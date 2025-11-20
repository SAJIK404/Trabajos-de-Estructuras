#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION insertarValorFinal
void insertarValorFinal(Nodo **cabeza, int valor){
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevoNodo){
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }

    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL){
        *cabeza = nuevoNodo;
        printf("Insertado %d al final (primer nodo).\n", valor);
        return;
    }

    Nodo *actual = *cabeza;
    while (actual->siguiente != NULL){
        actual = actual->siguiente;
    }

    actual->siguiente = nuevoNodo;
    printf("Insertado %d al final.\n", valor);
}
// FIN FUNCION insertarValorFinal

int main(){
    Nodo *lista1 = NULL;
    insertarValorFinal(&lista1, 666);
    return 0;