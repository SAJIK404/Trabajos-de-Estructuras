#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

// INICIO FUNCION buscarElementoCircular
void buscarElementoCircular(Nodo *cabeza, int valor) {
    if (cabeza == NULL) {
        printf("Valor %d NO encontrado (lista vacía).\n", valor);
        return;
    }

    Nodo *previo = NULL;
    Nodo *actual = cabeza;
    int encontrado = 0;

    // Recorre la lista hasta que el nodo actual sea el valor o volvamos a la cabeza
    do {
        if (actual->dato == valor) {
            encontrado = 1;
            break;
        }
        previo = actual;
        actual = actual->siguiente;
    } while (actual != cabeza);
    
    if (encontrado) {
        // Si el elemento encontrado es la cabeza, su antecedente es el último nodo
        if (actual == cabeza) {
            Nodo *ultimo = cabeza;
            while (ultimo->siguiente != cabeza) {
                ultimo = ultimo->siguiente;
            }
            previo = ultimo;
        }

        printf("Elemento %d encontrado.\n", valor);
        printf("  Dirección del Antecedente: %p\n", (void *)previo);
        printf("  Información del Consecuente: %d\n", actual->siguiente->dato);
    } else {
        printf("Valor %d NO encontrado en la lista.\n", valor);
    }
}
// FIN FUNCION buscarElementoCircular

int main(){
    Nodo *lista = NULL;
    buscarElementoCircular(lista, 666);
    return 0;
}
