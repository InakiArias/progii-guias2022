#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50

void carga(char rutaArch[], int* arr[], int* n);
void muestra(int* arr[], int n);
void libera(int* arr[], int* n);

int main()
{
    int* arr[MAX_N];
    int n;

    carga("datos.txt", arr, &n);
    muestra(arr, n);
    libera(arr, &n);

    return 0;
}

void carga(char rutaArch[], int* arr[], int* n) {
    *n = 0;
    int aux;

    FILE* arch = fopen(rutaArch, "r");

    if (arch == NULL)
        return;

    while (fscanf(arch, "%d", &aux) == 1) {
        arr[*n] = malloc(sizeof(int));
        *arr[*n] = aux;

        (*n)++;
    }
}

void muestra(int* arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        //if (*arr[i] > 0)
        printf("%d\n", *arr[i]);
    }

    printf("\n");
}

void libera(int* arr[], int* n) {
    int i;

    for (i = 0; i < *n; i++) {
        free(arr[i]);
    }

    *n = 0;
}
