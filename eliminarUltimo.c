#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION eliminarUltimo
void eliminarUltimo(Nodo **cabeza){
    if (*cabeza == NULL){
        printf("La lista está vacía.\n");
        return;
    }

    if ((*cabeza)->siguiente == NULL){
        printf("Eliminando único nodo con valor %d.\n", (*cabeza)->dato);
        free(*cabeza);
        *cabeza = NULL;
        return;
    }

    Nodo *actual = *cabeza;
    while (actual->siguiente->siguiente != NULL){
        actual = actual->siguiente;
    }

    printf("Eliminando último nodo con valor %d.\n", actual->siguiente->dato);
    free(actual->siguiente);
    actual->siguiente = NULL;
}
// FIN INICIO eliminarUltimo

int main(){
    Nodo *lista1 = NULL;
    eliminarUltimo(&lista1);
    return 0;
}