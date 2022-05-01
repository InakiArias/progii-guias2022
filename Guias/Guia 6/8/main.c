#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    char dato;
    struct nodo* sig;
} nodo;

typedef nodo* TListaC;

void inserta(TListaC* l, char dato) {
    TListaC aux;
    aux = (TListaC) malloc(sizeof(nodo));
    aux->dato = dato;

    if (*l == NULL) {
        aux->sig = aux;
        *l = aux;
    }
    else {
        aux->sig = (*l)->sig;
        (*l)->sig = aux;
        *l = aux;
    }
}

void insertaPal(TListaC* l, char* pal) {
    int i = 0;

    while (pal[i] != '\0') {
        inserta(l, pal[i]);
        i++;
    }
}

void muestra(TListaC l) {
    TListaC aux;

    if (l != NULL) {
        aux = l->sig;

        do {
           printf("%c", aux->dato);
           aux = aux->sig;
        } while (aux != l->sig);
    }

    puts("");
}

void elimina(TListaC* l, int pos) {
    TListaC aux, ant = *l;
    int i = 0;

    if (*l != NULL) {
        aux = (*l)->sig;

        while (aux != *l && i < pos) {
            ant = aux;
            aux = aux->sig;
            i++;
        }

        if (i == pos) {
            ant->sig = aux->sig;

            if (aux == *l)
                *l = ant;

            free(aux);
        }
    }
}

int main()
{
    TListaC l = NULL;

    insertaPal(&l, "Hola Mundo");
    muestra(l);

    elimina(&l, 3);

    muestra(l);


    return 0;
}
