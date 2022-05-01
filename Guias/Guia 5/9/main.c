#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int expresionBalanceada(char* expresion) {
    TPila caracteres;
    char car;
    int i = 0;
    iniciaP(&caracteres);

    while (expresion[i] != '\0') {
        car = expresion[i];

        switch(car) {
            case '(':
            case '{':
            case '[':
                poneP(&caracteres, car);
                break;
            case ')':
                if (vaciaP(caracteres) || consultaP(caracteres) != '(')
                    return 0;
                else {
                    sacaP(&caracteres, &car);
                }
                break;
            case ']':
                if (vaciaP(caracteres) || consultaP(caracteres) != '[')
                    return 0;
                else {
                    sacaP(&caracteres, &car);
                }
                break;
            case '}':
                if (vaciaP(caracteres) || consultaP(caracteres) != '{')
                    return 0;
                else {
                    sacaP(&caracteres, &car);
                }
                break;
        }

        i++;
    }

    return vaciaP(caracteres);
}

int main()
{
    char* exp = "[10 + {(23) * (15)}]" ;

    printf("%s: %d", exp, expresionBalanceada(exp));

    return 0;
}
