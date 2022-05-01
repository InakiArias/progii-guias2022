#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
#include "ColaC.h"

void insertaOrdenado(TPila* competidoresOrd, TElementoP insertado) {
    TElementoP aynaux;

    if (vaciaP(*competidoresOrd))
        poneP(competidoresOrd, insertado);
    else {
        sacaP(competidoresOrd, &aynaux);

        if (insertado[0] > aynaux[0]) {
            insertaOrdenado(competidoresOrd, insertado);
            poneP(competidoresOrd, aynaux);
        }
        else {
            poneP(competidoresOrd, aynaux);
            poneP(competidoresOrd, insertado);
        }
    }
}

void cargaPilaCompetidores(ColaC* competidores, TPila* competidoresOrd) {
    tElementoC ayn;

    while (!vaciaC(*competidores)) {
        sacaC(competidores, &ayn);

        insertaOrdenado(competidoresOrd, ayn);
    }
}

void muestraPila(TPila* p) {
    TElementoP ayn;

    while (!vaciaP(*p)) {
        sacaP(p, &ayn);
        puts(ayn);
    }
}

int main()
{
    ColaC competidores;
    TPila competidoresOrd;
    iniciaC(&competidores);
    iniciaP(&competidoresOrd);

    poneC(&competidores, "Arias, Gabriel");
    poneC(&competidores, "Crias, Gabriel");
    poneC(&competidores, "Brias, Gabriel");
    poneC(&competidores, "Erias, Gabriel");
    poneC(&competidores, "Grias, Gabriel");
    poneC(&competidores, "Drias, Gabriel");

    cargaPilaCompetidores(&competidores, &competidoresOrd);

    muestraPila(&competidoresOrd);

    return 0;
}
