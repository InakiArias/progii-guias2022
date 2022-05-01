#include <stdio.h>
#include <stdlib.h>

typedef float tipoDeDato;

void agregaEntradas(tipoDeDato medidas[], int cantMedidas, const char *rutaArch) {
    FILE *arch = fopen(rutaArch, "ab");
    if (arch == NULL) {
        printf("Error");
        return;
    }

    int i;

    for (i = 0; i < cantMedidas; i++) {
        fwrite(medidas + i, sizeof(tipoDeDato), 1, arch);
    }

    fclose(arch);
}

void lee(const char *rutaArch, tipoDeDato receptorMedidas[]) {
    FILE *arch = fopen(rutaArch, "rb");
    if (arch == NULL) {
        printf("Error");
        return;
    }

    int i = 0;

    fread(receptorMedidas, sizeof(tipoDeDato), 1, arch);

    while (!feof(arch)) {
        i++;
        fread(receptorMedidas + i, sizeof(tipoDeDato), 1, arch);
    }

    fclose(arch);
}

int main()
{
    tipoDeDato medidas[] = {1.3, 4.5, 6.3, 83, 4, 6, 4, 7, 4, 2}, receptorMedidas[50] = {};
    int cantMedidas = 10;

    agregaEntradas(medidas, cantMedidas, "datos.DAT");
    lee("datos.DAT", receptorMedidas);

    for (int i = 0; i < 50; i++) {
        printf("%g\n", receptorMedidas[i]);
    }
    return 0;
}
