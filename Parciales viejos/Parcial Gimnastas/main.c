#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ColaC.h"

typedef struct nodito {
    int puntaje;
    struct nodito* sig;
} nodito;

typedef nodito* Sublista;

typedef struct nodo {
    char codGim[9], codNac[5], codDic[4];
    Sublista puntuaciones;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

typedef struct nodoD {
    char codGim[9];
    float puntajeFinal;
    int cantIntentos;
    ColaC intentos;
    struct nodoD* sig, *ant;
} nodoD;

typedef nodoD* PNodo;

typedef struct {
    PNodo pri, ult;
} TListaDoble;

float calculaPuntajeFinal(Sublista s) {
    int suma, cant;
    suma = cant = 0;
    
    while (s != NULL) {
        cant++;
        suma += s->puntaje;
        s = s->sig;
    }
    
    return (float) suma / cant;
}

void insertarIntento(char* codGim, float puntajeFinal, TListaDoble* l) {
    PNodo act, aux;
    
    if (l->pri == NULL || strcmp(codGim, l->pri->codGim) < 0) {
        aux = (PNodo) malloc(sizeof(nodoD));
        strcpy(aux->codGim, codGim);
        aux->puntajeFinal = puntajeFinal;
        aux->cantIntentos = 1;
        iniciaC(&aux->intentos);
        poneC(&aux->intentos, puntajeFinal);
        
        if (l->pri == NULL)
            l->ult = aux;
        else 
            l->pri->ant = aux;
            
        aux->ant = NULL;
        aux->sig = l->pri;
        l->pri = aux;
    }
    else if (strcmp(codGim, l->pri->codGim) == 0) {
        if (puntajeFinal > l->pri->puntajeFinal)
            l->pri->puntajeFinal = puntajeFinal;
        
        l->pri->cantIntentos++;
        poneC(&l->pri->intentos, puntajeFinal);
    }
    else if (strcmp(codGim, l->ult->codGim) == 0) {
        if (puntajeFinal > l->ult->puntajeFinal)
            l->ult->puntajeFinal = puntajeFinal;
        
        l->ult->cantIntentos++;
        poneC(&l->ult->intentos, puntajeFinal);
    }
    else if (strcmp(codGim, l->ult->codGim) > 0) {
        aux = (PNodo) malloc(sizeof(nodoD));
        strcpy(aux->codGim, codGim);
        aux->puntajeFinal = puntajeFinal;
        aux->cantIntentos = 1;
        iniciaC(&aux->intentos);
        poneC(&aux->intentos, puntajeFinal);
        
        aux->sig = NULL;
        aux->ant = l->ult;
        l->ult->sig = aux;
        l->ult = aux;
    }
    else {
        act = l->pri;
        
        while (strcmp(codGim, act->codGim) > 0)
            act = act->sig;
            
        if (strcmp(codGim, act->codGim) == 0) {
            if (puntajeFinal > act->puntajeFinal)
                act->puntajeFinal = puntajeFinal;
        
            act->cantIntentos++;
            poneC(&act->intentos, puntajeFinal);
        }
        else {
            aux = (PNodo) malloc(sizeof(nodoD));
            strcpy(aux->codGim, codGim);
            aux->puntajeFinal = puntajeFinal;
            aux->cantIntentos = 1;
            iniciaC(&aux->intentos);
            poneC(&aux->intentos, puntajeFinal);
            
            aux->sig = act;
            aux->ant = act->ant;
            act->ant->sig = aux;
            act->ant = aux;
        
        }
    }
}

void generarListaDoble(TLista lista, TListaDoble* listaDoble) {
    int suma, cant;
    float puntajeFinal;
    
    suma = cant = 0;
    
    while (lista != NULL) {
        puntajeFinal = calculaPuntajeFinal(lista->puntuaciones);
        cant++;
        suma += puntajeFinal;
        insertarIntento(lista->codGim, puntajeFinal, listaDoble);
        lista = lista->sig;
    }
    
    //Muestra promedios
}

int main()
{
    TListaDoble listaDoble = {NULL, NULL};
    TLista lista = NULL;
    
    generarListaDoble(lista, &listaDoble);

    return 0;
}
