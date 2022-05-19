#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo *izq, *der;
} nodo;

typedef nodo* TArbol;

void creaNodo(int dato, TArbol* n) {
    *n = (TArbol) malloc(sizeof(nodo));
    (*n)->izq = (*n)->der = NULL;
    (*n)->dato = dato;
}

void inserta(TArbol *a, int x) {
    if (*a == NULL) {
        *a = (TArbol) malloc (sizeof(struct nodo));
        (*a)->dato = x;
        (*a)->der = NULL;
        (*a)->izq = NULL;
    }
    else if (x >(*a)->dato)
        inserta(&(*a)->der, x);
    else
        inserta(&(*a)->izq, x);
}

void inorden(TArbol a) {
    if (a != NULL) {
        inorden(a->izq);
        printf("%d\n", a->dato);
        inorden(a->der);
    }
}

int minimo_rec(TArbol a) {
    if (a->izq == NULL)
        return a->dato;
    else
        return minimo_rec(a->izq);
}

int minimo(TArbol a) {
    if (a == NULL)
        return -999999;
    else
        return minimo_rec(a);
}


int main()
{
    TArbol arbol = NULL;
    int arr[] = {10, 8, 14, 24, 11, 1, 33, 40, 5, 32, 3, 7, 9, 25}, n = 14;

    for (int i = 0; i < n; i++)
        inserta(&arbol, arr[i]);

    printf("%d\n", minimo(arbol));

    return 0;
}
