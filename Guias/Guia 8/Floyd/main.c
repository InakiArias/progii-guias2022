#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define INF 999

void muestra(int m[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%5d ", m[i][j]);

        puts("");
    }

    puts("");
}

void floyd(int digrafo[MAX][MAX], int n, int a[MAX][MAX], int c[MAX][MAX]) {
    int i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i == j) {
                a[i][j] = 0;
                c[i][j] = -1;
            }
            else if (digrafo[i][j] != 0) {
                a[i][j] = digrafo[i][j];
                c[i][j] = -1;
            }
            else {
                a[i][j] = INF;
                c[i][j] = INF;
            }

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (a[i][k] + a[k][j] < a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    c[i][j] = k;
                }

}

void alcance(int a[MAX][MAX], int n, int r[MAX][MAX]) {
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != INF) {
                r[i][j] = 1;
            }
            else {
                r[i][j] = 0;
            }
}

void muestraCamino_rec(int c[MAX][MAX], int v, int w) {
    if (c[v][w] != -1) {
        muestraCamino_rec(c, v, c[v][w]);
        printf(" - %d", c[v][w] + 1);
        muestraCamino_rec(c, c[v][w], w);
    }
}

void muestraCamino(int c[MAX][MAX], int v, int w) {
    printf("%d", v + 1);
    muestraCamino_rec(c, v, w);
    printf(" - %d\n", w + 1);
}

int main()
{
    int digrafo[MAX][MAX] = {{0, 30, 0, 13}, {22, 0, 10, 12}, {0, 25, 0, 0}, {13, 6, 0, 0}}, n = 4;
    int a[MAX][MAX], c[MAX][MAX], r[MAX][MAX], i, j;

    floyd(digrafo, n, a, c);
    alcance(a, n, r);

    printf("Adyacencia:\n\n");
    muestra(digrafo, n);

    printf("A:\n\n");
    muestra(a, n);

    printf("C:\n\n");
    muestra(c, n);

    printf("R:\n\n");
    muestra(r, n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i != j) {
                printf("Camino de %d a %d: ", i + 1, j + 1);
                muestraCamino(c, i, j);
            }


    return 0;
}
