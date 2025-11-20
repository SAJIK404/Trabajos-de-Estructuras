// Listas circulares

// funciones incluidas en el codigo hasta el momento
// * insertarFinalCircular
// * imprimirListaCircular
// * eliminarPrimeroCircular
// * buscarElementoCircular
// * insertarAntesDeCircular
// * insertarInicioCircular
// * eliminarUltimoCircular
// * eliminarDespuesDeCircular

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

// INICIO FUNCION imprimirListaCircular
void imprimirListaCircular(Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista Circular: VACÍA\n");
        return;
    }
    
    Nodo *actual = cabeza;
    printf("Lista Circular: ");
    
    // Usamos do-while para imprimir al menos el primer elemento
    // y parar cuando volvemos a la cabeza
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza); 
    
    printf("(Vuelve a %d)\n", cabeza->dato);
}
// FIN FUNCION imprimirListaCircular

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

// INICIO FUNCION insertarAntesDeCircular
void insertarAntesDeCircular(Nodo **cabeza, int referencia, int valor) {
    if (*cabeza == NULL) {
        printf("La lista está vacía. No se puede insertar antes de %d.\n", referencia);
        return;
    }

    Nodo *actual = *cabeza;
    Nodo *previo = NULL;
    int encontrado = 0;

    // Buscar el nodo con dato == referencia y su previo
    do {
        if (actual->dato == referencia) {
            encontrado = 1;
            break;
        }
        previo = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    if (!encontrado) {
        printf("Referencia %d NO encontrada. No se realizó la inserción.\n", referencia);
        return;
    }

    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    nuevoNodo->dato = valor;

    // Si el nodo encontrado es la cabeza, debemos colocar el nuevo nodo
    // antes de la cabeza y actualizar *cabeza
    if (actual == *cabeza) {
        // Encontrar el último para actualizar su enlace
        Nodo *ultimo = *cabeza;
        while (ultimo->siguiente != *cabeza) {
            ultimo = ultimo->siguiente;
        }
        nuevoNodo->siguiente = *cabeza;
        ultimo->siguiente = nuevoNodo;
        *cabeza = nuevoNodo;
    } else {
        // Inserción normal entre previo y actual
        previo->siguiente = nuevoNodo;
        nuevoNodo->siguiente = actual;
    }

    printf("Insertado %d ANTES de %d (circular).\n", valor, referencia);
}
// FIN FUNCION insertarAntesDeCircular

// INICIO FUNCION insertarInicioCircular
void insertarInicioCircular(Nodo **cabeza, int valor) {
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    nuevoNodo->dato = valor;

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
        printf("Insertado %d al inicio (primer nodo, circular).\n", valor);
        return;
    }

    // Encontrar el último nodo para mantener el círculo
    Nodo *ultimo = *cabeza;
    while (ultimo->siguiente != *cabeza) {
        ultimo = ultimo->siguiente;
    }

    nuevoNodo->siguiente = *cabeza;
    ultimo->siguiente = nuevoNodo;
    *cabeza = nuevoNodo;

    printf("Insertado %d al inicio (circular).\n", valor);
}
// FIN FUNCION insertarInicioCircular

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

int main() {
    Nodo *lista = NULL;

    printf("CREACIÓN DE LISTA\n");
    insertarFinalCircular(&lista, 10);
    insertarFinalCircular(&lista, 20);
    insertarFinalCircular(&lista, 30);
    insertarFinalCircular(&lista, 40);

    imprimirListaCircular(lista);

    printf("\nBÚSQUEDA\n");
    buscarElementoCircular(lista, 30);
    buscarElementoCircular(lista, 10);

    printf("\nELIMINAR PRIMERO\n");
    eliminarPrimeroCircular(&lista);

    imprimirListaCircular(lista);
    
    printf("\nBÚSQUEDA\n");
    buscarElementoCircular(lista, 40);

    return 0;
}