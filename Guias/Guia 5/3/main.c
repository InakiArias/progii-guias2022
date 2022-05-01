#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

void cargarPila(const char* nomArch, TPila* pila) {
    FILE* arch = fopen(nomArch, "r");
    TElementoP aux;
    iniciaP(pila);

    while (fscanf(arch, "%d\n", &aux) == 1) {
        poneP(pila, aux);
    }
}

void muestra_rec(TPila* pila, int n) {
    TElementoP aux;

    if (!vaciaP(*pila) && n > 0) {
        sacaP(pila, &aux);
        printf("%d\n", aux);
        muestra_rec(pila, n - 1);
        poneP(pila, aux);
    }
}

void muestra(TPila* pila, int n) {
    puts("");

    muestra_rec(pila, n);

    puts("");
}

int main()
{
    TPila pila;
    cargarPila("datos.txt", &pila);

    muestra(&pila, 3);
    muestra(&pila, 10);

    return 0;
}
