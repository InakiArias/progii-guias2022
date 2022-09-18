#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define INF 9999

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

void muestra(int m[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", m[i][j]);

        puts("");
    }

    puts("");
}

int alcanzable(int vi, int vj, int digrafo[MAX][MAX], int n) {
    int min = INF, aux, j;

    if (vi == vj)
        return 0;
    else {
        for (j = 0; j < n; j++) {
            if (digrafo[vi][j] != 0) {
                aux = alcanzable(j, vj, digrafo, n) + 1;

                if (aux < min)
                    min = aux;
            }
        }

        return min;
    }


}

int main()
{
    int digrafo[MAX][MAX] = {{0, 1, 1, 0}, {0, 0, 0, 1}, {1, 1, 0, 0}, {0, 0, 1, 0}}, n = 4;

    muestra(digrafo, n);


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d, %d: %d\n", i + 1, j + 1, alcanzable(i, j, digrafo, n));

    return 0;
}
