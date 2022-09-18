#include <stdio.h>
#include <stdlib.h>
#include "ColaC.h"

#define MAX 10
#define INF 999999

void carga(int grafo[MAX][MAX], int* n) {
    FILE *arch = fopen("matriz.txt", "r");
    int i, j;
    fscanf(arch, "%d", n);

    for (i = 0; i < *n; i++)
        for (j = 0; j < *n; j++)
            fscanf(arch, "%d", &grafo[i][j]);

    fclose(arch);
}

void muestra(int m[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", m[i][j]);

        puts("");
    }

    puts("");
}

void iniciaaam(int n, int aam[MAX][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            aam[i][j] = 0;
}

void iniciaccs(int n, int ccs[MAX]) {
    for (int i = 0; i < n; i++)
        ccs[i] = i;
}

void copia(int grafo[MAX][MAX], int n, int aux[MAX][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            aux[i][j] = grafo[i][j];
}

void buscaMin(int aux[MAX][MAX], int n, int* pesomin, int* imin, int* jmin) {
    *pesomin = INF;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (aux[i][j] != 0 && aux[i][j] < *pesomin) {
                *pesomin = aux[i][j];
                *imin = i;
                *jmin = j;
            }

    aux[*imin][*jmin] = INF;
    aux[*jmin][*imin] = INF;
}

void kruskal(int grafo[MAX][MAX], int n, int aam[MAX][MAX]) {
    int ccs[MAX];
    int aux[MAX][MAX];
    int pesomin, imin, jmin, cantAristas = 0, cci, ccj;

    iniciaccs(n, ccs);
    iniciaaam(n, aam);
    copia(grafo, n, aux);

    while (cantAristas < n - 1) {
        buscaMin(aux, n, &pesomin, &imin, &jmin);
        cci = ccs[imin];
        ccj = ccs[jmin];

        if (cci != ccj) {
            aam[imin][jmin] = pesomin;
            aam[jmin][imin] = pesomin;
            cantAristas++;

            for (int k = 0; k < n; k++)
                if (ccs[k] == ccj)
                    ccs[k] = cci;
        }
    }

}

void iniciavisitados(int n, int visitados[MAX]) {
    visitados[0] = 1;

    for (int i = 1; i < n; i++)
        visitados[i] = 0;
}

void prim(int grafo[MAX][MAX], int n, int aam[MAX][MAX]) {
    int visitados[MAX];
    int aux[MAX][MAX];
    int pesomin, imin, jmin, cantAristas = 0, i, j;

    iniciavisitados(n, visitados);
    iniciaaam(n, aam);
    copia(grafo, n, aux);

    while (cantAristas < n - 1) {
        pesomin = INF;

        for (i = 0; i < n; i++) {
            if (visitados[i] == 1) {
                for (j = 0; j < n; j++) {
                    if (visitados[j] == 0 && aux[i][j] != 0 && aux[i][j] < pesomin) {
                        imin = i;
                        jmin = j;
                        pesomin = aux[i][j];
                    }
                }
            }
        }

        aux[imin][jmin] = 0;
        aux[jmin][imin] = 0;
        visitados[jmin] = 1;

        cantAristas++;
        aam[imin][jmin] = pesomin;
        aam[jmin][imin] = pesomin;
    }

}

int main()
{
    int grafo[MAX][MAX], n;
    int aam[MAX][MAX];
    int aam2[MAX][MAX];

    carga(grafo, &n);

    kruskal(grafo, n, aam);

    prim(grafo, n, aam2);

    muestra(grafo, n);

    muestra(aam, n);

    muestra(aam2, n);

    return 0;
}
