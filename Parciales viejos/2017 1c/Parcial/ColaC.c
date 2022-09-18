#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ColaC.h"

Cola iniciaC() {
    Cola c;
    c.pri = c.ult = -1;
    return c;
}

int vaciaC(Cola c) {
    return c.pri == -1;
}

void poneC(Cola *c, char x[CAD_FECHA]) {
    if (c->pri == -1) {
        c->pri = c->ult = 0;
        c->datos[0] = x;
        return;
    }

    int nuevoUlt = (c->ult + 1) % TAM_COLA;

    if (nuevoUlt != c->pri) {
        c->ult = nuevoUlt;
        strcpy(c->datos[nuevoUlt], x);
    }
}

void consultaC(Cola c, char x[CAD_FECHA]) {
    if (c.pri != -1)
        strcpy(x, c.datos[c.pri]);
}

void sacaC(Cola *c, char x[CAD_FECHA]) {
    if (c->pri != -1) {
        int nuevoPri = (c->pri + 1) % TAM_COLA;
        strcpy(x, c->datos[c->pri]);

        if (c->pri == c->ult) {
            c->pri = c->ult = -1;
        }
        else {
            c->pri = nuevoPri;
        }
    }
}
