#include "AgendaContactos.h"
#include <stdio.h>
#include <string.h>

AgendaContacto iniciaAgenda() {
    AgendaContacto a;
    a.cant = 0;

    return a;
}

void agregarContacto(Contacto c, AgendaContacto *a) {
    if (a->cant == MAX_CONTACTOS) {
        //Manejar error.
        return;
    }

    int i = 0, j;

    while (i < a->cant && strcmp(c.nombre, a->lista[i].nombre) > 0)
        i++;

    for (j = a->cant; j > i; j--) {
        a->lista[j] = a->lista[j - 1];
    }

    a->lista[i] = c;
    a->cant++;
}

void listarAgenda(AgendaContacto a) {
    puts("");

    int i;

    for (i = 0; i < a.cant; i++) {
        printf("Contacto %d | %s: %s\n", i + 1, a.lista[i].nombre, a.lista[i].numero);
    }

    puts("");
}

int buscaIndice(char* nombre, AgendaContacto *a, int izq, int der) {
    if (izq > der)
        return -1;

    int medio = (izq + der) / 2;

    int comparacion = strcmp(nombre, a->lista[medio].nombre);

    if (comparacion == 0)
        return medio;
    else if (comparacion < 0)
        return buscaIndice(nombre, a, izq, medio - 1);
    else
        return buscaIndice(nombre, a, medio + 1, der);
}

int indiceDe(char* nombre, AgendaContacto a) {
    return buscaIndice(nombre, &a, 0, a.cant - 1);
}

Contacto busca(char* nombre, AgendaContacto a) {
    int indice = indiceDe(nombre, a);

    if (indice == -1) {
        //Manejar error.
    }
    else
        return a.lista[indice];
}
