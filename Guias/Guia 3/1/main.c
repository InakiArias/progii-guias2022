//a) calcular el producto de dos números enteros positivos a partir de sumas sucesivas.
//b) calcular cociente y resto entre dos números enteros positivos a partir de restas sucesivas
//c) hallar el máximo elemento de un vector de enteros (realizar una versión void y otra int)

#include <stdio.h>
#include <stdlib.h>

int funcA(int a, int b) {
    if (b == 0)
        return 0;

    return a + funcA(a, b - 1);
}

void funcB(int a, int b, int *coc, int *res) {
    if (a < b) {
        *res = a;
        *coc = 0;
    }
    else {
        funcB(a - b, b, coc, res);
        (*coc)++;
    }
}

int funcC1(int vec[], int i) {
    if (i == 0)
        return vec[0];

    int max = funcC1(vec, i - 1);

    return vec[i] > max ? vec[i] : max;
}

void funcC2(int vec[], int i, int *max) {
    if (i == 0)
        *max = vec[i];
    else {
        funcC2(vec, i - 1, max);

        if (vec[i] > *max)
            *max = vec[i];
    }
}

int main()
{
    printf("A: %d\n", funcA(8, 9));

    int coc, res;
    funcB(47, 11, &coc, &res);
    printf("Coc: %d Resto: %d\n", coc, res);

    int vec[] = {500, 653, 10, 425, 98}, max;
    printf("Max: %d\n", funcC1(vec, 4));

    funcC2(vec, 4, &max);
    printf("Max: %d\n", max);



    return 0;
}
