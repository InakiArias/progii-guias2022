#include "Pila.h"
#include <stdlib.h>

void iniciaP(TPila* p) {
    *p = NULL;
}

void poneP(TPila* p, TElementoP x) {
    TPila n = (TPila) malloc(sizeof(nodop));
    n->dato = x;
    n->sig = *p;
    *p = n;
}

void sacaP(TPila* p, TElementoP* x) {
    if (!vaciaP(*p)) {
        TPila n = *p;
        *x = n->dato;
        *p = n->sig;
        free(n);
    }

}

TElementoP consultaP(TPila p) {
    if (!vaciaP(p)) {
        return p->dato;
    }

    return 0;
}

int vaciaP(TPila p) {
    return p == NULL;
}
