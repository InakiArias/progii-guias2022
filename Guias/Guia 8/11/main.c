#include <stdio.h>
#include <stdlib.h>
#include "ColaC.h"
#include "Pila.h"

#define MAX 10

typedef struct nodo {
    int dato;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

void carga(int grafo[MAX][MAX], int* n) {
    FILE *arch = fopen("matriz.txt", "r");
    int i, j;
    fscanf(arch, "%d", n);

    for (i = 0; i < *n; i++)
        for (j = 0; j < *n; j++)
            fscanf(arch, "%d", &grafo[i][j]);

    fclose(arch);
}

int buscaNoVisitado(int visitados[]) {
    int i = 0;

    while (visitados[i] != 0)
        i++;

    return i;
}

void bfs(int grafo[MAX][MAX], int n) {
    int visitados[MAX] = {};
    int cc = 0, cantVisitados = 0, inicial, actual, j;
    ColaC cola;
    iniciaC(&cola);

    while (cantVisitados != n) {
        cc++;

        inicial = buscaNoVisitado(visitados);
        printf("%d\n", inicial + 1);
        poneC(&cola, inicial);
        visitados[inicial] = cc;
        cantVisitados++;

        while (!vaciaC(cola)) {
            sacaC(&cola, &actual);

            for (j = 0; j < n; j++)
                if (grafo[actual][j] != 0 && visitados[j] == 0) {
                    printf("%d\n", j + 1);
                    poneC(&cola, j);
                    visitados[j] = cc;
                    cantVisitados++;
                }
        }
    }
}

void dfs(int grafo[MAX][MAX], int n) {
    int visitados[MAX] = {};
    int cc = 0, cantVisitados = 0, inicial, actual, j;
    TPila pila;
    iniciaP(&pila);

    while (cantVisitados != n) {
        cc++;

        inicial = buscaNoVisitado(visitados);
        printf("%d\n", inicial + 1);
        poneP(&pila, inicial);
        visitados[inicial] = cc;
        cantVisitados++;

        while (cantVisitados != n && !vaciaP(pila)) {
            actual = consultaP(pila);

            j = 0;

            while (grafo[actual][j] == 0 || visitados[j] != 0)
                j++;

            if (j < n) {
                printf("%d\n", j + 1);
                poneP(&pila, j);
                visitados[j] = cc;
                cantVisitados++;
            }
            else
                sacaP(&pila, &j);
        }
    }
}

int cconexas(int grafo[MAX][MAX], int n) {
    int visitados[MAX] = {};
    int cc = 0, cantVisitados = 0, inicial, actual, j;
    ColaC cola;
    iniciaC(&cola);

    while (cantVisitados != n) {
        inicial = buscaNoVisitado(visitados);
        poneC(&cola, inicial);
        cc++;
        visitados[inicial] = cc;
        cantVisitados++;

        while (!vaciaC(cola)) {
            sacaC(&cola, &actual);

            for (j = 0; j < n; j++)
                if (grafo[actual][j] != 0 && visitados[j] == 0) {
                    poneC(&cola, j);
                    visitados[j] = cc;
                    cantVisitados++;
                }
        }
    }

    return cc;
}

int main()
{
    int grafo[MAX][MAX], n;

    carga(grafo, &n);

    bfs(grafo, n);

    printf("CC: %d\n", cconexas(grafo, n));

    dfs(grafo, n);

    return 0;
}
