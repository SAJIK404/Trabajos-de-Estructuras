#include <stdio.h>
#include <stdlib.h>

// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo

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

int main(){
    Nodo *lista = NULL;
    imprimirListsCircular(lista);
    return 0;
}
