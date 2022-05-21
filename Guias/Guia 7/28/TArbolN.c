#include "TArbolN.h"

int vacio(tArbolN a) {
    return a.posMayor == POS_NULA;
}

int nulo(tPosicion p) {
    return p == POS_NULA;
}

tPosicion hijoMasIzq(tPosicion p, tArbolN a) {
    return a.nodos[p].hMasIzq;
}

tPosicion hermanoDer(tPosicion p, tArbolN a) {
    return a.nodos[p].hnoDer;
}

tElementoAN info(tPosicion p, tArbolN a) {
    return a.nodos[p].dato;
}

int esRaiz(tPosicion p, tArbolN a) {
    int i = 0;

    while (i <= a.posMayor && (!a.nodos[p].activo || (a.nodos[p].hMasIzq != p && a.nodos[p].hnoDer != p)))
        i++;

    return i > a.posMayor;
}

tPosicion raiz(tArbolN a) {
    int i = 0;

    while (!esRaiz(i, a))
        i++;

    return i;
}

tPosicion padre(tPosicion p, tArbolN a) {

}

