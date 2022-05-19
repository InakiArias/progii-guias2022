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

int sumaCondicion(TArbol a, int nivel, int nivelAct) {
    if (a == NULL)
        return 0;
    else {
        nivelAct++;

        if (nivelAct == nivel)
            if ((a->izq == NULL && a->der != NULL) || (a->der == NULL && a->izq != NULL))
                return a->dato;
            else
                return 0;
        else if (nivelAct < nivel)
            return sumaCondicion(a->izq, nivel, nivelAct) + sumaCondicion(a->der, nivel, nivelAct);
        else
            return 0;
    }
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

    printf("%d\n", sumaCondicion(n1, 4, 0));

    return 0;
}
