#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "PilaD.h"

#define ERROR -6666

typedef PilaD TPila;

int esOperador(char c) {
    switch(c) {
        case '+':
        case '-':
        case '*':
        case '/': return 1;
        default: return 0;
    }
}

float cuenta(float n1, float n2, char operador) {
    switch(operador) {
        case '+': return n1 + n2;
        case '-': return n1 - n2;
        case '*': return n1 * n2;
        case '/': return n1 / n2; //No contempla division por cero
    }
    return ERROR; //No es necesario, solo evita la advertencia
}

float postfija(char operacion[]) {
    TPila p = iniciaPD();
    int i = 0;
    float resultado, n1, n2;
    char c;

    while (operacion[i]) {
        c = operacion[i];

        if (isdigit(c))
            ponePD(&p, c - '0');
        else if (esOperador(c)) {
            if (vaciaPD(p))
                return ERROR;
            else
                n2 = sacaPD(&p);

            if (vaciaPD(p))
                return ERROR;
            else
                n1 = sacaPD(&p);

            ponePD(&p, cuenta(n1, n2, c));
        }
        else
            return ERROR;

        i++;
    }

    resultado = sacaPD(&p);

    if (!vaciaPD(p))
        return ERROR;

    return resultado;

}


int main()
{
    printf("%g", postfija("512+4/+3-"));

    return 0;
}
