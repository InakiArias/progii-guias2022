#include <stdio.h>
#include <stdlib.h>
#include "TArbolN.h"

int cantNodos(tArbolN a, tPosicion p) { //ej a
    int cuenta;
    tPosicion c;

    if (nulo(p))
        return 0;
    else {
        cuenta = 1;
        c = hijoMasIzq(p, a);

        while (!nulo(c)) {
            cuenta += cantNodos(a, c);
            c = hermanoDer(c, a);
        }

        return cuenta;
    }
}

int cantNodos2(tArbolN a, tPosicion p) {//ej a
    if (nulo(p))
        return 0;
    else
        return cantNodos2(a, hijoMasIzq(p, a)) + cantNodos2(a, hermanoDer(p, a)) + 1;
}

void porcentajePares_rec(tArbolN a, tPosicion p, int* cant, int* suma) {
    if (!nulo(p)) {
        if (info(p, a) % 2 == 0)
            (*suma)++;

        (*cant)++;

        porcentajePares_rec(a, hijoMasIzq(p, a), cant, suma);
        porcentajePares_rec(a, hermanoDer(p, a), cant, suma);
    }
}

void porcentajePares(tArbolN a, float* res) { //ej b
    int cant, suma;
    cant = suma = 0;
    porcentajePares_rec(a, raiz(a), &cant, &suma);

    if (cant > 0)
        *res = (float) suma / cant * 100;
    else
        *res = 0; //??
}

int grado(tArbolN a, tPosicion p) { //ej c
    int gr, grAct, grAux;
    tPosicion c;

    if (nulo(p))
        return 0;
    else {
        grAct = 0;
        gr = 0;

        c = hijoMasIzq(p, a);

        while (!nulo(c)) {
            gr++;
            grAux = grado(a, c);

            if (grAux > grAct)
                grAct = grAux;

            c = hermanoDer(c, a);
        }

        return gr > grAct ? gr : grAct;
    }
}

int cantNodosGradoYNivelImpar(tArbolN a, tPosicion p, int nivel) { //ej d
    int suma, gr;
    tPosicion c;

    if (nulo(p))
        return 0;
    else {
        suma = 0;

        c = hijoMasIzq(p, a);

        while (!nulo(c)) {
            gr++;
            suma += cantNodosGradoYNivelImpar(a, c, nivel + 1);
            c = hermanoDer(c, a);
        }

        if (gr % 2 == 1 && nivel % 2 == 1)
            return suma + 1;

        else
            return suma;
    }
}

int verifica(tArbolN a, tPosicion p) { // ej e
    int gr, cumple;
    tPosicion c;

    if (nulo(p))
        return 1;
    else {
        gr = 0;
        c = hijoMasIzq(p, a);

        while (!nulo(c)) {
            gr++;
            c = hermanoDer(c, a);
        }

        if (gr != info(p, a) && gr > 0)
            return 0;
        else {
            cumple = 1;
            c = hijoMasIzq(p, a);

            while (!nulo(c) && cumple) {
                cumple = verifica(a, c);
                c = hermanoDer(c, a);
            }

            return cumple;
        }
    }
}

void verifica2_rec(tArbolN a, tPosicion p, int* res) {
    int gr;
    tPosicion c;

    if (!nulo(p)) {
        gr = 0;
        c = hijoMasIzq(p, a);

        while (!nulo(c)) {
            gr++;
            c = hermanoDer(c, a);
        }

        if (gr != info(p, a) && gr > 0)
            *res = 0;
        else {
            c = hijoMasIzq(p, a);

            while (!nulo(c) && *res) {
                verifica2_rec(a, c, res);
                c = hermanoDer(c, a);
            }
        }
    }
}

void verifica2(tArbolN a, int* res) { // ej e
    *res = 1;
    verifica2_rec(a, raiz(a), res);
}

void promedio_rec(tArbolN a, tPosicion p, int k, int nivel, int* cant, int* suma) {
    if (!nulo(p)) {
        if (nivel == k) {
            (*cant)++;
            *suma += info(p, a);
            promedio_rec(a, hermanoDer(p, a), k, nivel, cant, suma);
        }
        else if (nivel < k) {
            promedio_rec(a, hijoMasIzq(p, a), k, nivel + 1, cant, suma);
            promedio_rec(a, hermanoDer(p, a), k, nivel, cant, suma);
        }
    }
}

void promedio(tArbolN a, int k, float* res) { //ej f
    int cant, suma;
    cant = suma = 0;

    promedio_rec(a, raiz(a), k, 1, &cant, &suma);

    if (cant > 0)
        *res = (float) suma / cant;
    else
        *res = -666; //??
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
