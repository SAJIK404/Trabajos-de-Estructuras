#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION imprimirLista
void imprimirLista(Nodo *cabeza){
    Nodo *actual = cabeza;

    printf("Lista: ");
    while (actual != NULL){
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}
// FIN FUNCION imprimirLista

int main(){
    Nodo *lista1 = NULL;
    imprimirLista(&lista1);
    return 0;
}