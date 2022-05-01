#include <stdio.h>
#include <stdlib.h>
#include "Texto.h"

int main()
{
    Texto t = crear("Hola");
    destruir(&t);
    destruir(&t);

    t = crear("Chau");
    puts(texto(t));
    putc(caracterEn(t, 0), stdout);
    puts("");

    Texto concatenado = concatena(crear("Hola"), crear("Chau"));
    puts(texto(concatenado));

    destruir(&t);
    concatenado = concatena(t, crear("Chau"));
    puts(texto(concatenado));

    Texto areemplazar = crear("asdasda");
    Texto reemplazado = reemplazar(areemplazar, 'a', 'e');
    puts(texto(reemplazado));

    Texto sub = subTexto(reemplazado, 3, 12);
    puts(texto(sub));

    Texto pre = crear("asd");
    printf("%d\n", comienzaCon(areemplazar, pre));

    Texto su = crear("sda");
    printf("%d\n", terminaCon(areemplazar, su));


    return 0;
}
