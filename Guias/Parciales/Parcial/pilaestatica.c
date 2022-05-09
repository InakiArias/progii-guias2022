#include <stdio.h>
#include "pila.h"

void iniciaP(tPila *p){
    (*p).tope = -1;
}

void poneP(tPila *p, tElementop x){
    if ((*p).tope != MAX-1)
        (*p).datos[++((*p).tope)] = x;
}

void sacaP(tPila *p, tElementop *x){
    if ((*p).tope != -1)
        *x = (*p).datos[((*p).tope)--];
}

tElementop consultaP(tPila p){
    if (p.tope != -1)
        return p.datos[p.tope];
}

int vaciaP(tPila p){
    return (p.tope == -1);
}
