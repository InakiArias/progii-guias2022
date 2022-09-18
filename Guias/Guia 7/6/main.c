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

void nivelMasLarga(TArbol a, char empiezaCon, int largoMax, int nivelActual, int* resultado) {
    int largo;

    if (a != NULL) {
        nivelActual++;

        if (a->dato[0] == empiezaCon) {
            largo = strlen(a->dato);

            if (largo > largoMax) {
                largoMax = largo;
                *resultado = nivelActual;
            }
        }

        nivelMasLarga(a->izq, empiezaCon, largoMax, nivelActual, resultado);
        nivelMasLarga(a->der, empiezaCon, largoMax, nivelActual, resultado);
    }
}

//nivelMasLarga(arbol, 'A', 0, 0, &resultado);

int main()
{
    TArbol n1, n2, n3, n4, n5, n6, n7;
    int resultado;

    creaNodo("Hola", &n1);
    creaNodo("Adios", &n2);
    creaNodo("Holaa", &n3);
    creaNodo("asadsad", &n4);
    creaNodo("rtyrtyrty", &n5);
    creaNodo("Adioss", &n6);
    creaNodo("Holi", &n7);

    n1->izq = n2;
    n1->der = n5;
    n2->izq = n3;
    n2->der = n4;
    n5->izq = n6;
    n6->der = n7;

    preorden(n1);


    nivelMasLarga(n1, 'A', 0, 0, &resultado);
    printf("%d\n", resultado);

    return 0;
}
