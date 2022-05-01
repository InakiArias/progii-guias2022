#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

void cargarPila(const char* num, TPila* pila) {
    iniciaP(pila);
    int i = 0;

    while (num[i] != '\0') {
        poneP(pila, num[i]);
        i++;
    }
}

void pilaAString(TPila* pila, char resultado[]) {
    int i = 0;

    while (!vaciaP(*pila)) {
        sacaP(pila, resultado + i);
        i++;
    }

    resultado[i] = '\0';
}

void suma(const char* num1, const char* num2, char resultado[]) {
    TPila p1, p2, psuma;
    char aux1, aux2;
    int n1, n2, acarreo = 0;

    cargarPila(num1, &p1);
    cargarPila(num2, &p2);

    while (!vaciaP(p1) && !vaciaP(p2)) {
        sacaP(&p1, &aux1);
        sacaP(&p2, &aux2);
        n1 = aux1 - '0';
        n2 = aux2 - '0';

        poneP(&psuma, ((n1 + n2 + acarreo) % 10) + '0');

        acarreo = n1 + n2 + acarreo > 9 ? 1 : 0;
    }

    while (!vaciaP(p1)) {
        sacaP(&p1, &aux1);
        n1 = aux1 - '0';

        poneP(&psuma, ((n1 + acarreo) % 10) + '0');

        acarreo = n1 + acarreo > 9 ? 1 : 0;
    }

    while (!vaciaP(p2)) {
        sacaP(&p2, &aux2);
        n2 = aux2 - '0';

        poneP(&psuma, ((n2 + acarreo) % 10) + '0');

        acarreo = n2 + acarreo > 9 ? 1 : 0;
    }

    if (acarreo == 1)
        poneP(&psuma, '1');

    pilaAString(&psuma, resultado);
}

int main()
{
    char resultado[100];
    suma("99999999999999", "101", resultado);
    puts(resultado);

    return 0;
}
