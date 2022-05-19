#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char dato[20];
    struct nodo *izq, *der;
} nodo;

typedef nodo* TArbol;

void creaNodo(char* dato, TArbol* n) {
    *n = (TArbol) malloc(sizeof(nodo));
    (*n)->izq = (*n)->der = NULL;
    strcpy((*n)->dato, dato);
}

void preorden(TArbol a) {
    if (a != NULL) {
        printf("%s\n", a->dato);
        preorden(a->izq);
        preorden(a->der);
    }
}

int profundidad(TArbol a) {
    int profIzq, profDer;

    if (a == NULL)
        return 0;
    else {
        profIzq = profundidad(a->izq) + 1;
        profDer = profundidad(a->der) + 1;
        return profIzq > profDer ? profIzq : profDer;
    }
}

int longitudMasLarga(TArbol a) {
    int largoIzq, largoDer, largoActual;

    if (a == NULL)
        return 0;
    else {
        largoActual = strlen(a->dato);

        largoIzq = longitudMasLarga(a->izq);
        if (largoIzq > largoActual)
            largoActual = largoIzq;

        largoDer = longitudMasLarga(a->der);
        if (largoDer > largoActual)
            largoActual = largoDer;

        return largoActual;
    }
}

int hijosDerechos(TArbol a) {
    if (a == NULL)
        return 0;
    else {
        if (a->der != NULL)
            return hijosDerechos(a->izq) + hijosDerechos(a->der) + 1;
        else
            return hijosDerechos(a->izq);
    }
}

int main()
{
    TArbol n1, n2, n3, n4, n5, n6, n7;

    creaNodo("Hola", &n1);
    creaNodo("Adios", &n2);
    creaNodo("Holaa", &n3);
    creaNodo("Como va", &n4);
    creaNodo("Jejeje", &n5);
    creaNodo("Adios", &n6);
    creaNodo("Holi", &n7);

    n1->izq = n2;
    n1->der = n5;
    n2->izq = n3;
    n2->der = n4;
    n5->izq = n6;
    n6->der = n7;

    preorden(n1);

    printf("%d\n", profundidad(n1));
    printf("%d\n", longitudMasLarga(n1));
    printf("%d\n", hijosDerechos(n1));

    return 0;
}
