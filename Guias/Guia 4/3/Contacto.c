#include "Contacto.h"
#include <string.h>
#include <stdlib.h>

Contacto nuevoContacto(char* nombre, char* numero) {
    Contacto c;

    //c.nombre = malloc(sizeof(char) * (strlen(nombre) + 1));
    //c.numero = malloc(sizeof(char) * (strlen(numero) + 1));

    //strcpy(c.nombre, nombre);
    //strcpy(c.numero, numero);

    c.nombre = strdup(nombre);
    c.numero = strdup(numero);

    return c;
}

char* nombre(Contacto c) {
    return c.nombre;
}

char* numero(Contacto c) {
    return c.numero;
}
