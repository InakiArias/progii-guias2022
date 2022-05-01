#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodito {
char fecha[9];
float imp;
struct nodito * sig;} nodito;
typedef nodito * SubLista;
typedef struct nodoC {
int numC;
float cred, deuda;
struct nodoC * sig;
SubLista sub;} nodoC;
typedef nodoC * TListaC;

void insertaNoditoOrd(SubLista* sub, char* fecha, float imp) {
    SubLista ant, act, aux;
    aux = (SubLista) malloc(sizeof(nodito));
    strcpy(aux->fecha, fecha);
    aux->imp = imp;
    if (*sub == NULL || strcmp(fecha, (*sub)->fecha) < 0) {
        aux->sig = *sub;
        *sub = aux;
    }
    else {
        act = *sub;
        while (act != NULL && strcmp(fecha, aux->fecha) > 0) {
            ant = act;
            act = act->sig;
        }
        ant->sig = aux;
        aux->sig = act;
    }
}

void insertaPago(TListaC l, int numCli, char* fecha, float imp) {
    TListaC auxC = l;

    while (l != NULL && numCli > l->numC)
        auxC = auxC->sig;

    insertaNoditoOrd(&auxC->sub, fecha, imp);
    auxC->deuda -= imp;
}

void eliminaPago(TListaC l, int numCli, char* fecha) {
    SubLista ant, act, aux;

    while (l != NULL && numCli > l->numC)
        l = l->sig;

    if (l == NULL || numCli != l->numC)
        return; //No se encontro el cliente

    act = l->sub;

    while (act != NULL && strcmp(fecha, act->fecha) < 0) {
        ant = act;
        act = act->sig;
    }

    if (act != NULL && strcmp(fecha, act->fecha) == 0) {
        aux = act;

        l->deuda += act->imp;

        if (act == l->sub) {
            l->sub = act->sig;
        }
        else {
            ant->sig = act->sig;
        }

        free(aux);
    }
}

void eliminaCliente(TListaC* l, int numC) {
    TListaC act, ant;
    SubLista aux;

    act = *l;

    while (act != NULL && numC > act->numC) {
        ant = act;
        act = act->sig;
    }

    if (act != NULL && numC == act->numC) {
        while (act->sub != NULL) {
            aux = act->sub;
            act->sub = act->sub->sig;
            free(aux);
        }

        if (act == *l)
            *l = act->sig;
        else
            ant->sig = act->sig;

        free(act);
    }
}

void eliminaClientesSinDeuda(TListaC* l) {
    TListaC actC, antC, auxC;
    SubLista auxS;
    actC = *l;

    while (actC != NULL){
        if (actC->deuda == 0) {
            while (actC->sub != NULL) {
                auxS = actC->sub;
                actC->sub = actC->sub->sig;
                free(auxS);
            }

            if (actC == *l)
                *l = actC->sig;
            else
                antC->sig = actC->sig;

            auxC = actC;
            actC = actC->sig;
            free(auxC);

        }
        else {
            antC = actC;
            actC = actC->sig;
        }
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
