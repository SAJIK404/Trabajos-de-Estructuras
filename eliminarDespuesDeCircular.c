#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION eliminarDespuesDeCircular
void eliminarDespuesDeCircular(Nodo **cabeza, int referencia) {
    if (*cabeza == NULL) {
        printf("La lista está vacía. No se puede eliminar después de %d.\n", referencia);
        return;
    }

    Nodo *actual = *cabeza;
    int encontrado = 0;

    // Buscar el nodo con dato == referencia
    do {
        if (actual->dato == referencia) {
            encontrado = 1;
            break;
        }
        actual = actual->siguiente;
    } while (actual != *cabeza);

    if (!encontrado) {
        printf("Referencia %d NO encontrada. No se realizó la eliminación.\n", referencia);
        return;
    }

    Nodo *a_eliminar = actual->siguiente;

    // Si solo hay un nodo, no hay "después"
    if (a_eliminar == actual) {
        printf("Solo existe el nodo %d. No hay nodo después para eliminar.\n", referencia);
        return;
    }

    // Si vamos a eliminar la cabeza, actualizar el puntero de cabeza
    if (a_eliminar == *cabeza) {
        // Encontrar el último para recolocar su enlace
        Nodo *ultimo = *cabeza;
        while (ultimo->siguiente != *cabeza) {
            ultimo = ultimo->siguiente;
        }
        *cabeza = a_eliminar->siguiente;
        ultimo->siguiente = *cabeza;
    }

    actual->siguiente = a_eliminar->siguiente;
    printf("Eliminando nodo DESPUÉS de %d con valor %d.\n", referencia, a_eliminar->dato);
    free(a_eliminar);
}
// FIN FUNCION eliminarDespuesDeCircular

