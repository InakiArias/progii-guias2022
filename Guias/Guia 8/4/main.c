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

void transformaAGrafo(int digrafo[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            if (digrafo[i][j] != 0)
                digrafo[j][i] = digrafo[i][j];
    }
}

int main()
{
    int digrafo[MAX][MAX] = {{0, 1, 1, 0}, {0, 0, 0, 1}, {1, 1, 0, 0}, {0, 0, 1, 0}}, n = 4;

    muestra(digrafo, n);

    transformaAGrafo(digrafo, n);

    muestra(digrafo, n);

    return 0;
}
