#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char apellidoynombre[50];
    char nacionalidad[50];
    int puntaje;
} TipoDeDato;

void agregaEntradas(TipoDeDato datos[], int cantDatos, const char *rutaArch) {
    FILE *arch = fopen(rutaArch, "ab");
    if (arch == NULL) {
        printf("Error");
        return;
    }

    int i;

    for (i = 0; i < cantDatos; i++) {
        fwrite(datos + i, sizeof(TipoDeDato), 1, arch);
    }

    fclose(arch);
}

void lee(const char *rutaArch, TipoDeDato receptorDatos[]) {
    FILE *arch = fopen(rutaArch, "rb");
    if (arch == NULL) {
        printf("Error");
        return;
    }

    int i = 0;

    fread(receptorDatos, sizeof(TipoDeDato), 1, arch);

    while (!feof(arch)) {
        i++;
        fread(receptorDatos + i, sizeof(TipoDeDato), 1, arch);
    }

    fclose(arch);
}

void muestraPosicion(const char* rutaArch, int pos) {
    FILE* arch = fopen(rutaArch, "rb");

    fseek(arch, pos * sizeof(TipoDeDato), SEEK_SET);

    TipoDeDato tenista;
    fread(&tenista, sizeof(TipoDeDato), 1, arch);

    puts(tenista.apellidoynombre);
    puts(tenista.nacionalidad);
    printf("%d", tenista.puntaje);

    fclose(arch);
}

int main()
{
    TipoDeDato datos[3] = { {"Arias", "Arg", 100}, {"Melo", "Br", 60}, {"Davies", "Ing", 40} }, receptorDatos[50] = {};
    int cantDatos = 3;

    agregaEntradas(datos, cantDatos, "datos.DAT");
    muestraPosicion("datos.DAT", 1);

    return 0;
}
