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

void a_rec(int grafo[MAX][MAX], int arr[], int i, int j, int m) {
    if (i > -1) {
        if (j == -1) {
            arr[i] = 0;
            a_rec(grafo, arr, i - 1, m - 1, m);
        }
        else {
            a_rec(grafo, arr, i, j - 1, m);
            if (grafo[i][j] != 0)
                arr[i] += grafo[i][j];
        }
    }
}

void a(int grafo[MAX][MAX], int arr[], int n) {
    a_rec(grafo, arr, n - 1, n - 1, n);
}

void b_rec(int digrafo[MAX][MAX], int i, int j, int n, int suma, int sumaAnt, int* mayor) {
    if (j > -1) {
        if (i == -1) {
            if (suma > sumaAnt) {
                *mayor = j;
                b_rec(digrafo, n - 1, j - 1, n, 0, suma, mayor);
            }
            else
                b_rec(digrafo, n - 1, j - 1, n, 0, sumaAnt, mayor);
        }
        else
            b_rec(digrafo, i - 1, j, n, suma + digrafo[i][j], sumaAnt, mayor);
    }

}

void b(int digrafo[MAX][MAX], int arr[], int n, int* mayor) {
    *mayor = -1;
    b_rec(digrafo, n - 1, n - 1, n, 0, 0, mayor);
}

int main()
{
    int grafo[MAX][MAX] = {{0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0}}, n = 4;
    int arr[MAX];


    a(grafo, arr, n);
    return 0;
}
