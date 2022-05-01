#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

void insertaOrdenado(TLista* cabeza, int dato) {
    TLista aux;
    TLista* ptr;

    ptr = cabeza;

    aux = (TLista) malloc(sizeof(nodo));
    aux->dato = dato;

    while (*ptr != NULL && dato > (*ptr)->dato) {
        ptr = &(*ptr)->sig;
    }

    aux->sig = *ptr;
    *ptr = aux;
}

void destruirLista(TLista* cabeza) {
    TLista l, aux;

    l = *cabeza;

    while (l != NULL) {
        aux = l;
        l = l->sig;
        free(aux);
    }

    *cabeza = NULL;
}

void eliminaDato(TLista* cabeza, int dato) {
    TLista aux;
    TLista* ptr;

    ptr = cabeza;

    while (*ptr != NULL) {
        if ((*ptr)->dato == dato) {
            aux = *ptr;
            *ptr = (*ptr)->sig;
            free(aux);
        }
        else {
            ptr = &(*ptr)->sig;
        }
    }
}

void muestraLista(TLista cabeza) {
    TLista aux = cabeza;

    puts("");

    while (aux != NULL) {
        printf("%d\n", aux->dato);
        aux = aux->sig;
    }

    puts("");
}

int main()
{
    TLista lista = NULL;

    insertaOrdenado(&lista, 5);
    insertaOrdenado(&lista, 9);
    insertaOrdenado(&lista, 6);
    insertaOrdenado(&lista, 4);
    insertaOrdenado(&lista, 5);
    insertaOrdenado(&lista, 9);
    insertaOrdenado(&lista, 6);
    insertaOrdenado(&lista, 4);

    muestraLista(lista);

    eliminaDato(&lista, 5);
    eliminaDato(&lista, 4);
    eliminaDato(&lista, 6);


    muestraLista(lista);


    return 0;
}
