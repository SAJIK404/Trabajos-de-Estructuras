#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION insertarFinalCircular
void insertarFinalCircular(Nodo **cabeza, int valor) {
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    
    // Manejo de errores ============
    if (!nuevoNodo) {
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    //========================

    nuevoNodo->dato = valor;
    
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        // Enlaza el nodo consigo mismo para cerrar el círculo
        nuevoNodo->siguiente = *cabeza; 
        printf("Insertado %d al final (primer nodo, circular).\n", valor);
        return;
    }

    Nodo *actual = *cabeza;
    // Recorrer hasta el último nodo, que es el que apunta a la cabeza
    while (actual->siguiente != *cabeza) {
        actual = actual->siguiente;
    }
    
    // El nuevo nodo apunta a la cabeza (cierra el círculo)
    nuevoNodo->siguiente = *cabeza;
    // El último nodo original apunta al nuevo nodo
    actual->siguiente = nuevoNodo;
    
    printf("Insertado %d al final (circular).\n", valor);
}
// FIN FUNCION insertarFinalCircular

int main(){
    Nodo *lista = NULL;
    insertarFinalCircular(&lista, 666);
    return 0;
}

