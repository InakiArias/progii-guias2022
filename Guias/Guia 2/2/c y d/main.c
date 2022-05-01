#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INICIAL -9999999
#define COLUMNAS 5
#define FILAS 4

int minimo(int mat[][COLUMNAS], int i, int j, int m) {
    if (i == -1)
        return mat[0][0];
    else {
        int min;

        if (j == -1)
            min = minimo(mat, i - 1, m - 1, m);
        else
            min = minimo(mat, i, j - 1, m);

        return mat[i][j] < min ? mat[i][j] : min;
    }
}

void maximos(int mat[][COLUMNAS], int vec[], int i, int j, int m, int max) {
    if (i > -1) {
        if (j == -1) {
            vec[i] = max;
            maximos(mat, vec, i - 1, m - 1, m, MAX_INICIAL);
        }
        else {
            if (mat[i][j] > max)
                max = mat[i][j];

            maximos(mat, vec, i, j - 1, m, max);
        }
    }
}

int main() {
    int mat[FILAS][COLUMNAS], n = FILAS, m = COLUMNAS;
    int vec[FILAS];

    int i, o;

    srand(time(NULL));
    for(o = 0; o<FILAS; o++)
        for(i = 0; i<COLUMNAS; i++)
            mat[o][i] = rand() % 1000 + 300;

    printf("%d", minimo(mat, n - 1, m - 1, m));

    maximos(mat, vec, n - 1, m - 1, m, MAX_INICIAL);

    return 0;
}
