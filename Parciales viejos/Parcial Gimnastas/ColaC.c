#include "ColaC.h"


void iniciaC(ColaC* c) {
    c->pri = c->ult = -1;
}

void poneC(ColaC* c, tElementoC x) {
    int nuevoUlt = (c->ult + 1) % MAX;

    if (nuevoUlt == c->pri)
        return;

    if (c->pri == -1)
        c->pri = 0;

    c->datos[nuevoUlt] = x;
    c->ult = nuevoUlt;

}
void sacaC(ColaC* c, tElementoC *x) {
    int nuevoPri;

    if (c->pri == -1)
        return;

    nuevoPri = (c->pri + 1) % MAX;

    *x = c->datos[c->pri];

    if (c->pri == c->ult)
        c->pri = c->ult = -1;
    else
        c->pri = nuevoPri;
}

tElementoC consultaC(ColaC c) {
    if (c.pri != -1)
        return c.datos[c.pri];

    return 0;
}
int vaciaC(ColaC c) {
    return c.pri == -1;
}
