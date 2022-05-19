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

void preorden(TArbol a) {
    if (a != NULL) {
        printf("%d\n", a->dato);
        preorden(a->izq);
        preorden(a->der);
    }
}

int sumaMultiplos(TArbol a, int x) {
    if (a == NULL)
        return 0;
    else if (a->dato % x == 0)
        return sumaMultiplos(a->izq, x) + sumaMultiplos(a->der, x) + 1;
    else
        return sumaMultiplos(a->izq, x) + sumaMultiplos(a->der, x);
}

int hojas(TArbol a) {
    if (a == NULL)
        return 0;
    else {
        if (a->izq == NULL && a->der == NULL)
            return 1;
        else
            return hojas(a->izq) + hojas(a->der);
    }
}

int esta(TArbol a, int x) {
    if (a == NULL)
        return 0;
    else
        return a->dato == x || esta(a->izq, x) || esta(a->der, x);
}


int main()
{
    TArbol n1, n2, n3, n4, n5, n6, n7;

    creaNodo(5, &n1);
    creaNodo(8, &n2);
    creaNodo(3, &n3);
    creaNodo(6, &n4);
    creaNodo(4, &n5);
    creaNodo(1, &n6);
    creaNodo(2, &n7);

    n1->izq = n2;
    n1->der = n5;
    n2->izq = n3;
    n2->der = n4;
    n5->izq = n6;
    n6->der = n7;

    printf("%d\n", sumaMultiplos(n1, 3));
    printf("%d\n", hojas(n1));
    printf("%d\n", esta(n1, 3));

    return 0;
}
