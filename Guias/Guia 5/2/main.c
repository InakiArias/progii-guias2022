#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

void cargarPila(const char* nomArch, TPila* pila) {
    FILE* arch = fopen(nomArch, "r");
    char aux;
    iniciaP(pila);

    while (fscanf(arch, "%c\n", &aux) == 1) {
        poneP(pila, aux);
    }
}

void muestra_rec(TPila* pila) {
    char aux;

    if (!vaciaP(*pila)) {
        sacaP(pila, &aux);
        putc(aux, stdout);
        muestra_rec(pila);
        poneP(pila, aux);
    }
}

void muestra(TPila* pila) {
    puts("");

    muestra_rec(pila);

    puts("");
}

int main()
{
    TPila pila;
    cargarPila("datos.txt", &pila);

    muestra(&pila);
    muestra(&pila);
    muestra(&pila);
    muestra(&pila);
    muestra(&pila);

    return 0;
}
