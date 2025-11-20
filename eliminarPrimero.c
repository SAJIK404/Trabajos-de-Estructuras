


// definicion del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
// fin estructura Nodo


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