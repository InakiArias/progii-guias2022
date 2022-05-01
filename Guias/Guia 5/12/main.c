#include <stdio.h>
#include <stdlib.h>
#include "ColaC.h"

int main()
{
    ColaC c;
    iniciaC(&c);
    tElementoC num;

    for (int i = 1; i < 15; i++) {
        poneC(&c, i * 10);
    }

    for (int i = 0; i < 5; i++) {
        sacaC(&c, &num);
    }

    for (int i = 1; i < 50; i++) {
        poneC(&c, i * 100);
    }


    return 0;
}
