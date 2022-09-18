#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

typedef struct nodo {
    int dato;
    struct nodo* sig;
} nodo;

typedef nodo* TListaC;

void inserta(TListaC* l, int dato) {
    TListaC aux;

    if (*l == NULL) {
        *l = (TListaC) malloc(sizeof(nodo));
        (*l)->dato = dato;
        (*l)->sig = *l;
    }
    else {
        aux = (TListaC) malloc(sizeof(nodo));
        aux->dato = dato;

        aux->sig = (*l)->sig;
        (*l)->sig = aux;
    }
}

void muestra(TListaC l) {
    TListaC aux;

    if (l != NULL) {
        aux = l;

        do {
            printf("%d\n", aux->dato);
            aux = aux->sig;
        } while (aux != l);
    }

    puts("");
}

void elimina(TListaC l, TPila* p) {
    TListaC act, ant;
    int pos;
    TElementoP x;

    if (l != NULL) {
        act = l->sig;
        ant = l;
        pos = 2;

        iniciaP(p);

        while (act != l) {
            if (act->dato < ant->dato) {
                x.nro = act->dato;
                x.pos = pos;
                poneP(p, x);

                ant->sig = act->sig;
                free(act);
                act = ant->sig;
            }
            else {
                ant = act;
                act = act->sig;
            }

            pos++;
        }

    }
}

int main()
{
    TListaC l = NULL;
    TPila p;

    inserta(&l, 1);
    inserta(&l, 52);
    inserta(&l, 43);
    inserta(&l, 355);
    inserta(&l, 2);

    muestra(l);

    elimina(l, &p);

    muestra(l);

    return 0;
}
