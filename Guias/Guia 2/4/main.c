#include <stdio.h>
#include <stdlib.h>

void ingresaN(int* n);
void creaEIngresaArreglo(float** arr, int n);
void muestraArreglo(float* arr, int n);
void destruyeArreglo(float** arr, int* n);

int main()
{
    float* arr;
    int n;

    ingresaN(&n);
    creaEIngresaArreglo(&arr, n);
    muestraArreglo(arr, n);
    destruyeArreglo(&arr, &n);
    muestraArreglo(arr, n);

    return 0;
}

void ingresaN(int* n) {
    printf("Ingrese n: ");
    scanf("%d", n);
}

void creaEIngresaArreglo(float** arr, int n) {
    *arr = malloc(sizeof(**arr) * n);

    for (int i = 0; i < n; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%f", *arr + i);
    }
}

void muestraArreglo(float* arr, int n) {
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Numero %d: %g\n", i + 1, *(arr + i));
    }

    printf("\n");
}

void destruyeArreglo(float** arr, int* n) {
    free(*arr);
    *arr = NULL;
    *n = 0;
}
