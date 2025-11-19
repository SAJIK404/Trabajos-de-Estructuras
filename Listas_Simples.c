// Algoritmo que crea lista simple

//funciones incluidas en el codigo hasta el momento
// *  insertarValorInicio
// *  insertarValorFinal
// *  eliminarPrimero
// *  eliminarUltimo
// *  imprimirLista
// *  buscar
// *  eliminarValor
// *  insertarAntesDeValor
// *  insertarDespuesDeValor
// *  eleiminarAntesDeValor
// *  eliminarDespuesDeValor

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

// INICIO FUNCION insertarValorFinal
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
// FIN FUNCION insertarValorFinal

// INICIO FUNCION imprimirLista
void imprimirLista(Nodo *cabeza){
    Nodo *actual = cabeza;

    printf("Lista: ");
    while (actual != NULL){
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}
// FIN FUNCION imprimirLista

// INICIO FUNCION eliminarPrimero
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
// FIN FUNCION eliminarPrimero

// INICIO FUNCION eliminarUltimo
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
// FIN INICIO eliminarUltimo

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

// INICIO FUNCION eliminarValor
void eliminarValor(Nodo **cabeza, int valor){
    // Caso 1: Lista vacía
    if (*cabeza == NULL){
        printf("La lista está vacía. No se pudo eliminar %d.\n", valor);
        return;
    }

    // Caso 2: El nodo a eliminar es la cabeza
    Nodo *actual = *cabeza;
    if (actual->dato == valor){
        *cabeza = actual->siguiente;
        printf("Eliminando nodo cabeza con valor %d.\n", valor);
        free(actual);
        return;
    }

    // Caso 3: El nodo está en medio o al final de la lista
    Nodo *previo = NULL;
    while (actual != NULL && actual->dato != valor){
        previo = actual;
        actual = actual->siguiente;
    }

    // Si 'actual' es NULL, significa que el valor no se encontró
    if (actual == NULL){
        printf("Valor %d NO encontrado en la lista.\n", valor);
        return;
    }

    // El nodo a eliminar es 'actual'.
    // Desvinculamos el nodo 'actual' de la lista.
    previo->siguiente = actual->siguiente;

    printf("Eliminando nodo con valor %d.\n", valor);
    free(actual); // Liberamos la memoria del nodo.
}
// FIN FUNCION eliminarValor

// INICIO FUNCION insertarAntesDeValor
void insertarAntesDeValor(Nodo **cabeza, int nuevoValor, int valorReferencia){
    // 1. Crear el nuevo nodo
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevoNodo){
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    nuevoNodo->dato = nuevoValor;

    // Caso A: La lista está vacía
    if (*cabeza == NULL){
        printf("Lista vacía. No se puede insertar %d antes de %d.\n", nuevoValor, valorReferencia);
        free(nuevoNodo);
        return;
    }

    // Caso B: Insertar antes de la CABEZA
    if ((*cabeza)->dato == valorReferencia){
        nuevoNodo->siguiente = *cabeza;
        *cabeza = nuevoNodo;
        printf("Insertado %d antes del nodo cabeza con valor %d.\n", nuevoValor, valorReferencia);
        return;
    }

    // Caso C: Buscar el nodo previo al valor de referencia
    Nodo *actual = *cabeza;
    Nodo *previo = NULL;

    // Recorrer hasta que el siguiente nodo tenga el valor de referencia, 
    // o hasta llegar al final de la lista.
    while (actual != NULL && actual->dato != valorReferencia){
        previo = actual;
        actual = actual->siguiente;
    }

    // Caso D: Valor de referencia NO encontrado
    if (actual == NULL){
        printf("Valor de referencia %d NO encontrado en la lista. No se pudo insertar %d.\n", valorReferencia, nuevoValor);
        free(nuevoNodo);
        return;
    }

    // Caso E: Inserción en medio o al final
    // 'actual' es el nodo con valorReferencia. 'previo' es el nodo justo antes.
    nuevoNodo->siguiente = actual;
    previo->siguiente = nuevoNodo;
    
    printf("Insertado %d antes de %d.\n", nuevoValor, valorReferencia);
}
// FIN FUNCION insertarAntesDeValor

// INICIO FUNCION insertarDespuesDeValor
void insertarDespuesDeValor(Nodo **cabeza, int nuevoValor, int valorReferencia){
    // 1. Crear el nuevo nodo
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevoNodo){
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    nuevoNodo->dato = nuevoValor;

    // Caso A: La lista está vacía
    if (*cabeza == NULL){
        printf("Lista vacía. No se puede insertar %d después de %d.\n", nuevoValor, valorReferencia);
        free(nuevoNodo);
        return;
    }

    // Caso B: Buscar el nodo de referencia
    Nodo *actual = *cabeza;
    
    // Recorrer hasta encontrar el nodo con valorReferencia, o hasta llegar al final.
    while (actual != NULL && actual->dato != valorReferencia){
        actual = actual->siguiente;
    }

    // Caso C: Valor de referencia NO encontrado
    if (actual == NULL){
        printf("Valor de referencia %d NO encontrado en la lista. No se pudo insertar %d.\n", valorReferencia, nuevoValor);
        free(nuevoNodo);
        return;
    }

    // Caso D: Inserción después del nodo encontrado
    // 'actual' es el nodo de referencia.
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
    
    printf("Insertado %d después de %d.\n", nuevoValor, valorReferencia);
}
// FIN FUNCION insertarDespuesDeValor

// INICIO FUNCION eliminarAntesDeValor
void eliminarAntesDeValor(Nodo **cabeza, int valorReferencia){
    // Caso 1: Lista vacía o solo un nodo (no se puede eliminar 'antes' de nada)
    if (*cabeza == NULL || (*cabeza)->siguiente == NULL){
        printf("No se puede eliminar un nodo antes de %d (lista vacía o con un solo nodo).\n", valorReferencia);
        return;
    }

    // Caso 2: El nodo a eliminar es la CABEZA (el valor de referencia es el segundo nodo)
    if ((*cabeza)->siguiente->dato == valorReferencia){
        Nodo *temp = *cabeza;
        *cabeza = (*cabeza)->siguiente; // La nueva cabeza es el nodo de referencia
        
        printf("Eliminando nodo cabeza (antes de %d) con valor %d.\n", valorReferencia, temp->dato);
        free(temp);
        return;
    }

    // Caso 3: Buscar el nodo PREVIO al nodo a eliminar
    // Necesitamos tres punteros: 
    // - previo_al_eliminado (2 nodos antes de valorReferencia)
    // - a_eliminar (1 nodo antes de valorReferencia)
    // - actual (el nodo con valorReferencia)

    Nodo *previo_al_eliminado = *cabeza;
    // Buscamos el nodo que está dos posiciones antes de valorReferencia
    while (previo_al_eliminado->siguiente->siguiente != NULL && previo_al_eliminado->siguiente->siguiente->dato != valorReferencia){
        previo_al_eliminado = previo_al_eliminado->siguiente;
    }

    // Valor de referencia NO encontrado o solo queda un nodo antes de él (ya manejado en Caso 2)
    if (previo_al_eliminado->siguiente->siguiente == NULL){
        printf("No se encontró el nodo de referencia %d, o no hay un nodo antes de él.\n", valorReferencia);
        return;
    }

    // Caso 4: Eliminación en medio de la lista
    Nodo *a_eliminar = previo_al_eliminado->siguiente;
    
    // Saltamos el nodo a eliminar
    previo_al_eliminado->siguiente = a_eliminar->siguiente;
    
    printf("Eliminando nodo con valor %d (antes de %d).\n", a_eliminar->dato, valorReferencia);
    free(a_eliminar);
}
// FIN FUNCION eliminarAntesDeValor

// INICIO FUNCION eliminarDespuesDeValor
void eliminarDespuesDeValor(Nodo **cabeza, int valorReferencia){
    // Caso 1: Lista vacía
    if (*cabeza == NULL){
        printf("La lista está vacía.\n");
        return;
    }

    // Caso 2: Buscar el nodo de referencia
    Nodo *referencia = *cabeza;
    
    // Recorrer hasta encontrar el nodo con valorReferencia
    while (referencia != NULL && referencia->dato != valorReferencia){
        referencia = referencia->siguiente;
    }

    // Caso 3: Valor de referencia NO encontrado
    if (referencia == NULL){
        printf("Valor de referencia %d NO encontrado en la lista.\n", valorReferencia);
        return;
    }

    // Caso 4: No hay un nodo después del nodo de referencia
    if (referencia->siguiente == NULL){
        printf("No hay un nodo después de %d para eliminar.\n", valorReferencia);
        return;
    }

    // Caso 5: Eliminación
    Nodo *a_eliminar = referencia->siguiente;
    
    // Saltamos el nodo a eliminar
    referencia->siguiente = a_eliminar->siguiente;

    printf("Eliminando nodo con valor %d (después de %d).\n", a_eliminar->dato, valorReferencia);
    free(a_eliminar);
}
// FIN FUNCION eliminarDespuesDeValor

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
