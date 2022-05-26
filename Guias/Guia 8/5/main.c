#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void muestra(int m[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", m[i][j]);

        puts("");
    }

    puts("");
}

int gradoEntrada(int digrafo[MAX][MAX], int vertice, int n) {
    int i, res = 0;

    for (i = 0; i < n; i++) {
        if (digrafo[i][vertice] != 0)
            res++;
    }

    return res;
}

int gradoSalida(int digrafo[MAX][MAX], int vertice, int n) {
    int j, res = 0;

    for (j = 0; j < n; j++) {
        if (digrafo[vertice][j] != 0)
            res++;
    }

    return res;
}

int grado(int digrafo[MAX][MAX], int vertice, int n) {
    return gradoEntrada(digrafo, vertice, n) + gradoSalida(digrafo, vertice, n) - digrafo[vertice][vertice];
}

int main()
{
    int digrafo[MAX][MAX] = {{0, 1, 1, 0}, {0, 0, 0, 1}, {1, 1, 0, 0}, {0, 0, 1, 0}}, n = 4;

    muestra(digrafo, n);

    printf("%d\n", gradoEntrada(digrafo, 3, n));
    printf("%d\n", gradoSalida(digrafo, 0, n));

    return 0;
}
