#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION insertarValorInicio  
void insertarValorInicio(Nodo **cabeza, int valor){
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo)); // casting
    
    // Manejo de errores ============
    if (!nuevoNodo){
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    //========================

    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;

    printf("Insertado %d al inicio.\n", valor);
}
// FIN FUNCION insertarValorInicio


int main(){
    Nodo *lista1 = NULL
    Nodo *lista2 = NULL
    insertarValorInicio(*lista1, 666)

    return 0
}
