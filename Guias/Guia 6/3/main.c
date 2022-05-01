#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char dato[20];
    int cant;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

void insertaOrd(TLista* l, char dato[]) {
    TLista* ptr = l;
    TLista aux;

    while (*ptr != NULL && strcmp(dato, (*ptr)->dato) > 0) {
        ptr = &(*ptr)->sig;
    }

    if (*ptr != NULL && strcmp(dato, (*ptr)->dato) == 0) {
        (*ptr)->cant++;
    }
    else {
        aux = (TLista) malloc(sizeof(nodo));
        strcpy(aux->dato, dato);
        aux->cant = 1;

        aux->sig = *ptr;
        *ptr = aux;
    }
}

void crearLista(const char* nomArch, TLista* l) {
    FILE* arch = fopen(nomArch, "r");
    char datoaux[20];

    while (fscanf(arch, "%s\n", datoaux) == 1) {
        insertaOrd(l, datoaux);
    }
}

void muestraLista(TLista l) {
    while (l != NULL) {
        printf("%s: %d\n", l->dato, l->cant);
        l = l->sig;
    }
}

int main()
{
    TLista l = NULL;

    crearLista("datos.txt", &l);
    muestraLista(l);

    return 0;
}
