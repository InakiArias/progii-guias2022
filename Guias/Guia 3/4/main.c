#include <stdio.h>
#include <stdlib.h>

void ocurrenciasVoid(float mat[][50], int i, int j, int m, int buscado, int *ocurr) {
    if (i == -1) {
        *ocurr = 0;
    }
    else {
        if (j == 0)
            ocurrenciasVoid(mat, i - 1, m - 1, m, buscado, ocurr);
        else
            ocurrenciasVoid(mat, i, j - 1, m, buscado, ocurr);

        if (mat[i][j] == buscado)
            (*ocurr)++;
    }
}

int ocurrenciasInt(float mat[][50], int i, int j, int m, int buscado) {
    if (i == -1) {
        return 0;
    }
    else {
        int nuevaOcurrencia = mat[i][j] == buscado ? 1 : 0;

        if (j == 0)
            return ocurrenciasInt(mat, i - 1, m - 1, m, buscado) + nuevaOcurrencia;
        else
            return ocurrenciasInt(mat, i, j - 1, m, buscado) + nuevaOcurrencia;
    }
}

int main()
{
    float mat[50][50] = { {10, 10, 30}, {40, 40, 10} };
    int n = 2, m = 3, ocurr;

    ocurrenciasVoid(mat, n - 1, m - 1, m, 40, &ocurr);
    printf("Ocurrencias: %d\n", ocurr);

    printf("Ocurrencias: %d", ocurrenciasInt(mat, n - 1, m - 1, m, 10));

    return 0;
}
