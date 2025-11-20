#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo


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
    Nodo *lista1 = NULL;
    eliminarDespuesDeValor(&lista, 666);
    return 0;