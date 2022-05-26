#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct nodo {
    int dato;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

void carga(TLista liAdy[], int* n) {
    TLista aux;

    *n = 4;

    for (int i = 0; i < *n; i++)
        liAdy[i] = NULL;

    aux = malloc(sizeof(nodo));
    aux->dato = 1;
    aux->sig = liAdy[0];
    liAdy[0] = aux;

    aux = malloc(sizeof(nodo));
    aux->dato = 2;
    aux->sig = liAdy[0];
    liAdy[0] = aux;

    aux = malloc(sizeof(nodo));
    aux->dato = 3;
    aux->sig = liAdy[1];
    liAdy[1] = aux;

    aux = malloc(sizeof(nodo));
    aux->dato = 0;
    aux->sig = liAdy[2];
    liAdy[2] = aux;

    aux = malloc(sizeof(nodo));
    aux->dato = 1;
    aux->sig = liAdy[2];
    liAdy[2] = aux;

    aux = malloc(sizeof(nodo));
    aux->dato = 2;
    aux->sig = liAdy[3];
    liAdy[3] = aux;
}

int gradoM(int grafo[MAX][MAX], int vert, int n) {
    int res = 0, i , j;

    for (i = 0; i < vert; i++)
        if (grafo[i][vert] != 0)
            res += grafo[i][vert];

    for (j = vert; j < n; j++)
        if (grafo[vert][j] != 0)
            res += grafo[vert][j];

    return res;
}

int gradoL(TLista liAdy[], int vert, int n) {
    int res = 0;
    TLista aux = liAdy[vert];

    while (aux != NULL) {
        res++;
        aux = aux->sig;
    }

    return res;
}

int main()
{
    int grafo[MAX][MAX] = {{0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0}}, n = 4;


    printf("%d\n", gradoM(grafo, 3, n));

    return 0;
}
