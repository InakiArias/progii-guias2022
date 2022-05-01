#include <stdio.h>
#include <stdlib.h>
#include "AgendaContactos.h"

int main()
{
    AgendaContacto agenda = iniciaAgenda();

    agregarContacto(nuevoContacto("Iñaki", "2234005566"), &agenda);
    agregarContacto(nuevoContacto("John", "2234456789"), &agenda);
    agregarContacto(nuevoContacto("Lohn", "2234456789"), &agenda);
    agregarContacto(nuevoContacto("Bohn", "2234456789"), &agenda);
    agregarContacto(nuevoContacto("Cohn", "2234456789"), &agenda);
    agregarContacto(nuevoContacto("Fohn", "2234456789"), &agenda);
    agregarContacto(nuevoContacto("Rohn", "2234456789"), &agenda);

    listarAgenda(agenda);

    char* buscado = "John";
    printf("Indice de %s: %d\n", buscado, indiceDe(buscado, agenda));

    Contacto aBuscar = busca(buscado, agenda);
    printf("%s %s\n", nombre(aBuscar), numero(aBuscar));

    return 0;
}
