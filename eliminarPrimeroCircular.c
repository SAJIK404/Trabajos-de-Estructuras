#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION eliminarPrimeroCircular
void eliminarPrimeroCircular(Nodo **cabeza) {
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    
    Nodo *a_eliminar = *cabeza;

    // Caso: Solo hay un nodo
    if ((*cabeza)->siguiente == *cabeza) {
        printf("Eliminando único nodo con valor %d.\n", a_eliminar->dato);
        *cabeza = NULL;
        free(a_eliminar);
        return;
    }

    // Caso: Múltiples nodos
    Nodo *ultimo = *cabeza;
    // Encontrar el último nodo
    while (ultimo->siguiente != *cabeza) {
        ultimo = ultimo->siguiente;
    }
    
    *cabeza = (*cabeza)->siguiente; // La nueva cabeza es el segundo nodo
    ultimo->siguiente = *cabeza;    // El último nodo enlaza a la nueva cabeza
    
    printf("Eliminando primer nodo con valor %d.\n", a_eliminar->dato);
    free(a_eliminar);
}
// FIN FUNCION eliminarPrimeroCircular

int main(){
    Nodo *lista = NULL;
    eliminarPrimeroCircular(&lista);
    return 0;
}
