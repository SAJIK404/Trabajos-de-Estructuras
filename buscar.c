#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo


// INICIO FUNCION buscar
void buscar(Nodo *cabeza, int valor){
    Nodo *actual = cabeza;
    int posicion = 0;

    while (actual != NULL){
        if (actual->dato == valor){
            printf("Valor %d encontrado en la posición %d.\n", valor, posicion);
            return;
        }
        actual = actual->siguiente;
        posicion++;
    }

    printf("Valor %d NO encontrado en la lista.\n", valor);
}
// FIN FUNCION buscar

int main(){
    Nodo *lista1 = NULL;
    buscar(&lista1, 666);
    return 0;
}