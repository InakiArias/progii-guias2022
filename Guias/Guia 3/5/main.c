#include <stdio.h>
#include <stdlib.h>

int esSimetrica(float mat[][50], int i, int j) { //Recorriendo el triangulo inferior
    if (i == 0)
        return 1;
    if (mat[i][j] != mat[j][i])
        return 0;
    if (j == 0)
        return esSimetrica(mat, i - 1, i - 2);

    return esSimetrica(mat, i, j - 1);
}

int main()
{
    float mat[50][50] = { {1, 2, 3, 4}, {2, 1, 5, 6}, {3, 5, 1, 7}, {4, 6, 7, 1} };
    int n = 4;

    puts(esSimetrica(mat, n - 1, n - 2) ? "True" : "False");

    return 0;
}

//1 2 3 4
//2 1 5 6
//3 5 1 7
//4 6 7 1 Simetrica
