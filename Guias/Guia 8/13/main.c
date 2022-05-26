#include <stdio.h>
#include <stdlib.h>
#include "ColaC.h"
#include "Pila.h"

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

void prim(int grafo[MAX][MAX], int n, int aam[MAX][MAX]) {
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

int main()
{
    int grafo[MAX][MAX], n;
    int aam[MAX][MAX];

    carga(grafo, &n);

    prim(grafo, n, aam);

    muestra(grafo, n);

    muestra(aam, n);

    return 0;
}
