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

void cambiaSignos(TPila* pila) {
    TElementoP aux;
    if (!vaciaP(*pila)) {
        sacaP(pila, &aux);
        cambiaSignos(pila);
        poneP(pila, -aux);
    }
}

void muestra_rec(TPila* pila) {
    TElementoP aux;

    if (!vaciaP(*pila)) {
        sacaP(pila, &aux);
        printf("%d\n", aux);
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
    cambiaSignos(&pila);
    muestra(&pila);

    return 0;
}
