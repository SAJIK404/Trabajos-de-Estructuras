#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION eliminarUltimoCircular
void eliminarUltimoCircular(Nodo **cabeza) {
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    // Caso: un solo nodo
    if ((*cabeza)->siguiente == *cabeza) {
        printf("Eliminando único nodo con valor %d.\n", (*cabeza)->dato);
        free(*cabeza);
        *cabeza = NULL;
        return;
    }

    // Encontrar penúltimo (actual) tal que actual->siguiente es el último
    Nodo *actual = *cabeza;
    while (actual->siguiente->siguiente != *cabeza) {
        actual = actual->siguiente;
    }

    Nodo *a_eliminar = actual->siguiente; // último nodo
    actual->siguiente = *cabeza; // cerrar el círculo
    printf("Eliminando último nodo con valor %d.\n", a_eliminar->dato);
    free(a_eliminar);
}
// FIN FUNCION eliminarUltimoCircular
