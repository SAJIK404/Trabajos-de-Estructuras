

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

void insertarFinalCircular(Nodo **cabeza, int valor) {
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        return;
    }
    nuevoNodo->dato = valor;
    
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        nuevoNodo->siguiente = *cabeza; 
        return;
    }

    Nodo *actual = *cabeza;
    while (actual->siguiente != *cabeza) {
        actual = actual->siguiente;
    }

    nuevoNodo->siguiente = *cabeza;
    actual->siguiente = nuevoNodo;
}

void imprimirListaCircular(Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista Circular: VACÍA\n");
        return;
    }
    
    Nodo *actual = cabeza;
    printf("Lista Circular: ");
    int contador = 0;
    
    do {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
        contador++;
        if (contador > 100) break; // Límite de seguridad
    } while (actual != cabeza); 
    
    printf("(Vuelve a %d)\n", cabeza->dato);
}

void eliminarPrimeroCircular(Nodo **cabeza) {
    if (*cabeza == NULL) {
        return;
    }
    
    Nodo *a_eliminar = *cabeza;

    if ((*cabeza)->siguiente == *cabeza) {
        *cabeza = NULL;
        free(a_eliminar);
        return;
    }

    Nodo *ultimo = *cabeza;
    while (ultimo->siguiente != *cabeza) {
        ultimo = ultimo->siguiente;
    }
    
    *cabeza = (*cabeza)->siguiente;
    ultimo->siguiente = *cabeza; 
    
    free(a_eliminar);
}

void buscarElementoCircular(Nodo *cabeza, int valor) {
    if (cabeza == NULL) {
        printf("Búsqueda: Lista vacía.\n");
        return;
    }

    Nodo *previo = NULL;
    Nodo *actual = cabeza;
    int encontrado = 0;

    do {
        if (actual->dato == valor) {
            encontrado = 1;
            break;
        }
        previo = actual;
        actual = actual->siguiente;
    } while (actual != cabeza);
    
    if (encontrado) {
        // El antecedente es 'previo'. Si el nodo encontrado es la cabeza, 
        // el antecedente es el último elemento.
        if (actual == cabeza) {
            Nodo *ultimo = cabeza;
            while (ultimo->siguiente != cabeza) {
                ultimo = ultimo->siguiente;
            }
            previo = ultimo;
        }

        // El consecuente es 'actual->siguiente'.
        printf("Elemento %d encontrado.\n", valor);
        printf("  Dirección del Antecedente: %p\n", (void *)previo);
        printf("  Información del Consecuente: %d\n", actual->siguiente->dato);
    } else {
        printf("Elemento %d NO encontrado en la lista.\n", valor);
    }
}

int main() {
    Nodo *lista = NULL;

    printf("--- 1. Creación y adición (Final) ---\n");
    insertarFinalCircular(&lista, 10);
    insertarFinalCircular(&lista, 20);
    insertarFinalCircular(&lista, 30);
    insertarFinalCircular(&lista, 40);
    imprimirListaCircular(lista);

    printf("\n--- 2. Búsqueda y Antecedente/Consecuente (Buscar 30) ---\n");
    buscarElementoCircular(lista, 30);
    
    printf("\n--- 3. Búsqueda de la Cabeza (Buscar 10) ---\n");
    buscarElementoCircular(lista, 10);

    printf("\n--- 4. Eliminación del Primer Elemento ---\n");
    eliminarPrimeroCircular(&lista);
    imprimirListaCircular(lista);

    printf("\n--- 5. Búsqueda de elemento inexistente ---\n");
    buscarElementoCircular(lista, 99);
    
    return 0;
}
