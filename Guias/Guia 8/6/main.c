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

int gradoSalida(TLista liAdy[MAX], int vert, int n) {
    TLista aux = liAdy[vert];
    int res = 0;

    while (aux != NULL) {
        res++;
        aux = aux->sig;
    }

    return res;
}

int gradoEntrada(TLista liAdy[MAX], int vert, int n) {
    TLista aux;
    int res = 0;

    for (int i = 0; i < n; i++) {
        aux = liAdy[i];

        while (aux != NULL) {
            if (aux->dato == vert)
                res++;

            aux = aux->sig;
        }
    }

    return res;

}

int main()
{
    TLista liAdy[MAX];
    int n;

    carga(liAdy, &n);

    printf("%d\n", gradoEntrada(liAdy, 0, n));

    return 0;
}
