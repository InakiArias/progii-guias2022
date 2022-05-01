#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

void muestraLista(TLista l) {
    puts("");

    while (l != NULL) {
        printf("%d\n", l->dato);
        l = l->sig;
    }

    puts("");

}

void a(int arr[], int n, TLista* l) {
    int i;
    TLista aux;

    for (i = 0; i < n; i++) {
        aux = (TLista) malloc(sizeof(nodo));
        aux->dato = arr[i];
        aux->sig = *l;
        *l = aux;
    }
}

void b(int arr[], int n, TLista* l) {
    int i;
    TLista* ptr = l;

    for (i = 0; i < n; i++) {
        *ptr = (TLista) malloc(sizeof(nodo));
        (*ptr)->dato = arr[i];
        ptr = &(*ptr)->sig;
    }

    *ptr = NULL;
}

void insertaOrd(TLista* l, int dato) {
    TLista aux;
    TLista* ptr = l;

    aux = (TLista) malloc(sizeof(nodo));
    aux->dato = dato;

    while (*ptr != NULL && dato > (*ptr)->dato) {
        ptr = &(*ptr)->sig;
    }

    aux->sig = *ptr;
    *ptr = aux;
}


void c(int arr[], int n, TLista* l) {
    int i;

    for (i = 0; i < n; i++) {
        insertaOrd(l, arr[i]);
    }
}

void elimina(TLista* l, int pos) {
    TLista aux;
    TLista* ptr = l;
    int i = 0;

    while (*ptr != NULL && i < pos) {
        ptr = &(*ptr)->sig;
        i++;
    }

    if (*ptr != NULL && i == pos) {
        aux = (*ptr);
        *ptr = (*ptr)->sig;
        free(aux);
    }
}

int main()
{
    int arr[] = {1, 5, 9, 3, 5}, n = 5;
    TLista l1, l2, l3;
    l1 = l2 = l3 = NULL;

    a(arr, n, &l1);
    muestraLista(l1);

    b(arr, n, &l2);
    muestraLista(l2);

    c(arr, n, &l3);

    elimina(&l3, 5);
    muestraLista(l3);

    return 0;
}
