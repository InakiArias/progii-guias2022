#include <stdio.h>
#include <stdlib.h>

int sumaArchivoEnteros(const char* rutaArch) {
    FILE *arch = fopen(rutaArch, "r");

    if (arch == NULL)
        return -999;

    int num, suma = 0;

    fscanf(arch, "%d", &num);

    while (!feof(arch)) {
        suma += num;
        fscanf(arch, "%d", &num);
        printf("%d ", num);
    }

    return suma;
}

int main()
{
    printf("%d", sumaArchivoEnteros("datos.txt"));
    return 0;
}
