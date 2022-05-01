#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    char dato;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

typedef struct nodoD {
    char dato;
    struct nodoD* sig, *ant;
} nodoD;

typedef nodoD* PNodo;

typedef struct {
    PNodo pri, ult;
} TListaD;

void creaLista(char* t, TLista* l) {
    TLista* ptr = l;
    int i = 0;

    while (t[i] != '\0') {
        *ptr = (TLista) malloc(sizeof(nodo));
        (*ptr)->dato = t[i];
        ptr = &(*ptr)->sig;
        i++;
    }

    *ptr = NULL;
}

void muestraLista(TLista l) {
    while (l != NULL) {
        printf("%c", l->dato);
        l = l->sig;
    }

    puts("");
}

void muestraListaDoble(TListaD l) {
    PNodo p = l.pri;

    while (p != NULL) {
        printf("%c", p->dato);
        p = p->sig;
    }

    puts("");
}

void muestraListaDobleReves(TListaD l) {
    PNodo p = l.ult;

    while (p != NULL) {
        printf("%c", p->dato);
        p = p->ant;
    }

    puts("");
}

int palindrome(TListaD l) {
    PNodo izq, der;

    if (l.pri == NULL)
        return 1;
    else {
        izq = l.pri;
        der = l.ult;

        while (izq != der && izq->ant != der && izq->dato == der->dato) {
            izq = izq->sig;
            der = der->ant;
        }

        return izq->dato == der->dato;
    }
}

void copiaDoble(TLista l, TListaD* ld) {
    PNodo aux;

    if (l != NULL) {
        aux = (PNodo) malloc(sizeof(nodoD));
        aux->dato = l->dato;
        aux->ant = NULL;

        ld->pri = aux;

        l = l->sig;

        while (l != NULL) {
            aux->sig = (PNodo) malloc(sizeof(nodoD));
            aux->sig->dato = l->dato;
            aux->sig->ant = aux;

            aux = aux->sig;

            l = l->sig;
        }

        ld->ult = aux;
        aux->sig = NULL;
    }
    else {
        ld->pri = ld->ult = NULL;
    }
}

int main()
{
    TLista l = NULL;
    TListaD ld = {NULL, NULL};

    creaLista("AssA", &l);
    muestraLista(l);

    copiaDoble(l, &ld);
    muestraListaDoble(ld);
    muestraListaDobleReves(ld);

    printf("%d", palindrome(ld));

    return 0;
}
