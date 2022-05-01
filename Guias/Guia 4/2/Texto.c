#include <stdlib.h>
#include "Texto.h"


Texto crear(char* cadena) {
    Texto texto;
    int i = 0;

    while (cadena[i] != '\0')
        i++;

    texto.largo = i;
    texto.texto = malloc(sizeof(char) * (i + 1));

    for (i = 0; i <= texto.largo; i++) {
        texto.texto[i] = cadena[i];
    }

    return texto;
}

void destruir(Texto *texto) {
    if (texto->texto != NULL) {
        free(texto->texto);
        texto->texto = NULL;
        texto->largo = 0;
    }
}

char* texto(Texto texto) {
    return texto.texto;
}

int largo(Texto texto) {
    return texto.largo;
}

char caracterEn(Texto texto, unsigned int indice) {
    if (indice >= texto.largo)
        return '\0';
    else
        return texto.texto[indice];
}

Texto concatena(Texto texto1, Texto texto2) {
    char* cadena = malloc(sizeof(char) * (texto1.largo + texto2.largo + 1));

    int i = 0, j;

    for (j = 0; j < texto1.largo; j++) {
        cadena[i] = texto1.texto[j];
        i++;
    }

    for (j = 0; j < texto2.largo; j++) {
        cadena[i] = texto2.texto[j];
        i++;
    }

    cadena[i] = '\0';

    Texto res = crear(cadena);
    free(cadena);

    return res;
}

Texto reemplazar(Texto texto, char caracter, char nuevoCaracter) {
    char* cadena = malloc(sizeof(char) * (texto.largo + 1));

    int i;

    for (i = 0; i < texto.largo; i++) {
        if (texto.texto[i] == caracter)
            cadena[i] = nuevoCaracter;
        else
            cadena[i] = texto.texto[i];
    }

    cadena[i] = '\0';

    Texto res = crear(cadena);
    free(cadena);

    return res;
}

Texto subTexto(Texto texto, unsigned int desde, unsigned int hasta) {
    if (desde >= hasta || desde >= texto.largo)
        return crear("");

    if (hasta > texto.largo)
        hasta = texto.largo;

    char* cadena = malloc(sizeof(char) * (hasta - desde + 1));

    int i = 0, j;

    for (j = desde; j < hasta; j++) {
        cadena[i] = texto.texto[j];
        i++;
    }

    cadena[i] = '\0';

    Texto res = crear(cadena);
    free(cadena);

    return res;
}

int comienzaCon(Texto texto, Texto prefijo) {
    if (prefijo.largo > texto.largo)
        return 0;

    int i;

    for (i = 0; i < prefijo.largo; i++) {
        if (texto.texto[i] != prefijo.texto[i])
            return 0;
    }

    return 1;
}

int terminaCon(Texto texto, Texto sufijo) {
    if (sufijo.largo > texto.largo)
        return 0;

    int i;
    int j;
    int limite = texto.largo - sufijo.largo;

    for (i = texto.largo - 1, j = sufijo.largo - 1; i >= limite; i--, j--) {
        if (texto.texto[i] != sufijo.texto[j])
            return 0;
    }

    return 1;
}
