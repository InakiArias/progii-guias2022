#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
#include "ColaC.h"

void muestraPila(TPila* p) {
    TElementoP ayn;

    while (!vaciaP(*p)) {
        sacaP(p, &ayn);
        puts(ayn);
    }
}

void maximo(ColaC* c, int* max) {
    int actual;

    if (vaciaC(*c))
        *max = -9999;
    else {
        sacaC(c, &actual);
        maximo(c, max);
        poneC(c, actual);
        if (actual > *max)
            *max = actual;
    }
}

void maximos(TLista l, TPila* p) {
    int max;
    TLista aux = l;

    iniciaP(p);

    while (l != NULL) {
        maximo(&l->cola, &max);
        poneP(p, max);
        l = l->sig;
    }


}

int main()
{
    ColaC c1, c2, c3;

    iniciaC(&c1);
    iniciaC(&c2);
    iniciaC(&c3);
    poneC(&c1, 3);
    poneC(&c1, 7);
    poneC(&c1, 6);

    int max;
    maximo(&c1, &max);
    maximo(&c1, &max);
    maximo(&c1, &max);
    printf("%d\n", max);



    return 0;
}
