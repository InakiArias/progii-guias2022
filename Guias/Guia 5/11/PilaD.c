#include <stdio.h>
#include <stdlib.h>
#include "PilaD.h"

PilaD iniciaPD() {
    nodop *p = NULL;
    return p;
}

int vaciaPD(PilaD p) {
    return (p == NULL);
}

void ponePD(PilaD *p, tElementoPD x) {
    nodop *n = malloc(sizeof(nodop));
    n->dato = x;
    n->sig = *p;
    *p = n;
}

tElementoPD consultaPD(PilaD p) {
    if (p)
        return p->dato;

    return -6666;
}

tElementoPD sacaPD(PilaD *p) {
    if (*p) {
        nodop *n = *p;
        tElementoPD res = n->dato;
        *p = (*p)->sig;
        free(n);
        return res;
    }

    return -6666;

}

