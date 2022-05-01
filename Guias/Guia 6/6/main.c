#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodito {
    char nombre[30];
    int edad;
    char estado;
    struct nodito* sig;
} nodito;

typedef nodito* Sublista;

typedef struct nodo {
    char nombre[30];
    int puntaje;
    Sublista jugadores;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

void insertaOrd(TLista* l, char nombre[], int puntaje, Sublista jugadores) {
    TLista ant, act = *l, aux;

    aux = (TLista) malloc(sizeof(nodo));
    strcpy(aux->nombre, nombre);
    aux->puntaje = puntaje;
    aux->jugadores = jugadores;

    while (act != NULL && puntaje < act->puntaje) {
        ant = act;
        act = act->sig;
    }

    aux->sig = act;

    if (act == *l)
        *l = aux;
    else
        ant->sig = aux;
}

void datos(TLista* l) {
    TLista aux;
    Sublista auxS;

    auxS = (Sublista) malloc(sizeof(nodito));
    strcpy(auxS->nombre, "Jugador1");
    auxS->edad = 22;
    auxS->estado = 'A';
    auxS->sig = NULL;

    insertaOrd(l, "Equipo1", 15, auxS);
}

void listadoA(TLista l, char letra) {
    Sublista aux;
    int max = 0, actual, total = 0;

    while (l != NULL) {
        actual = 0;
        aux = l->jugadores;

        while (aux != NULL) {
            if (aux->nombre[0] == letra) {
                printf("%s: %s\n", l->nombre, aux->nombre);
                actual++;
            }
            aux = aux->sig;
        }

        total += actual;

        if (actual > max)
            max = actual;

        l = l->sig;
    }

    printf("%d", max);
}

void listadoB(TLista l, int puntaje) {
    Sublista aux;
    float suma;
    int cant;

    while (l != NULL && l->puntaje >= puntaje) {
        suma = 0;
        cant = 0;
        aux = l->jugadores;

        while (aux != NULL) {
            printf("%s: %s %d\n", l->nombre, aux->nombre, aux->edad);
            cant++;
            suma += aux->edad;

            aux = aux->sig;
        }

        if (cant != 0)
            printf("Prom: %g\n", suma / cant);

        l = l->sig;
    }
}

int verifica(TLista l, char nombre[], int puntaje) {
    while (l != NULL && puntaje < l->puntaje)
        l = l->sig;

    while (l != NULL && puntaje == l->puntaje && strcmp(nombre, l->nombre) != 0)
        l = l->sig;

    return l != NULL && puntaje == l->puntaje && strcmp(nombre, l->nombre) == 0;
}

void elimina(Sublista* jugadores) {
    Sublista act = *jugadores, ant, aux;

    while (act != NULL) {
        if (act->estado == 'S') {
            aux = act;

            if (act == *jugadores)
                *jugadores = act->sig;
            else
                ant->sig = act->sig;

            act = act->sig;
            free(aux);
        }
        else {
            ant = act;
            act = act->sig;
        }
    }
}

void eliminaInactivos(TLista l) {
    while (l != NULL) {
        elimina(&l->jugadores);
        l = l->sig;
    }
}

int main()
{
    TLista l = NULL;

    datos(&l);

    return 0;
}
