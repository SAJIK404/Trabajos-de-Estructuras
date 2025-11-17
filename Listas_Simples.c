#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;


// ==========================
//      INSERTAR INICIO
// ==========================
void insertarValorInicio(Nodo **cabeza, int valor){
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (nuevoNodo == NULL){
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }

    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;

    printf("Insertado %d al inicio.\n", valor);
}


// ==========================
//      INSERTAR FINAL
// ==========================
void insertarValorFinal(Nodo **cabeza, int valor){
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevoNodo){
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }

    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL){
        *cabeza = nuevoNodo;
        printf("Insertado %d al final (primer nodo).\n", valor);
        return;
    }

    Nodo *actual = *cabeza;
    while (actual->siguiente != NULL){
        actual = actual->siguiente;
    }

    actual->siguiente = nuevoNodo;
    printf("Insertado %d al final.\n", valor);
}


// ==========================
//      IMPRIMIR LISTA
// ==========================
void imprimirLista(Nodo *cabeza){
    Nodo *actual = cabeza;

    printf("Lista: ");
    while (actual != NULL){
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}


// ==========================
//      ELIMINAR PRIMERO
// ==========================
void eliminarPrimero(Nodo **cabeza){
    if (*cabeza == NULL){
        printf("La lista está vacía.\n");
        return;
    }

    Nodo *temp = *cabeza;
    *cabeza = (*cabeza)->siguiente;

    printf("Eliminando primer nodo con valor %d.\n", temp->dato);
    free(temp);
}


// ==========================
//      ELIMINAR ÚLTIMO
// ==========================
void eliminarUltimo(Nodo **cabeza){
    if (*cabeza == NULL){
        printf("La lista está vacía.\n");
        return;
    }

    if ((*cabeza)->siguiente == NULL){
        printf("Eliminando único nodo con valor %d.\n", (*cabeza)->dato);
        free(*cabeza);
        *cabeza = NULL;
        return;
    }

    Nodo *actual = *cabeza;
    while (actual->siguiente->siguiente != NULL){
        actual = actual->siguiente;
    }

    printf("Eliminando último nodo con valor %d.\n", actual->siguiente->dato);
    free(actual->siguiente);
    actual->siguiente = NULL;
}


// ==========================
//            BUSCAR
// ==========================
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


// ==========================
//             MAIN
// ==========================
int main(){

    // Crear dos listas independientes
    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;

    // Trabajando con lista1
    insertarValorInicio(&lista1, 10);
    insertarValorInicio(&lista1, 20);
    insertarValorInicio(&lista1, 30);

    imprimirLista(lista1);

    eliminarUltimo(&lista1);
    imprimirLista(lista1);

    insertarValorFinal(&lista1, 777);
    imprimirLista(lista1);

    buscar(lista1, 777);

    // Trabajando con lista2
    insertarValorFinal(&lista2, 1000);
    insertarValorFinal(&lista2, 2000);
    imprimirLista(lista2);

    eliminarPrimero(&lista2);
    imprimirLista(lista2);

    buscar(lista2, 2000);

    return 0;
}
