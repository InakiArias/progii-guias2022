#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pila.h"

typedef struct nodo {
    char nombre[21];
    TPila titulos;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

typedef struct nodoC {
    char nombre[21];
    char dni[9];
    float prom;
    int orden;
    struct nodoC* sig;
} nodoC;

typedef nodoC* TListaCircular;

void agregaTitulo(char* nombre, char* dni, float prom, TLista* l) {
    TLista ant, aux, act = *l;
    TElementoP titulo;
    
    strcpy(titulo.dni, dni);
    titulo.prom = prom;
    
    while (act != NULL && strcmp(nombre, act->nombre) > 0) {
        ant = act;
        act = act->sig;
    }
    
    if (act != NULL && strcmp(nombre, act->nombre) == 0) {
        poneP(&act->titulos, titulo);
    }
    else {
        aux = (TLista) malloc(sizeof(nodo));
        strcpy(aux->nombre, nombre);
        iniciaP(&aux->titulos);
        poneP(&aux->titulos, titulo);
        
        aux->sig = act;
        
        if (act == *l) 
            *l = aux;
        else
            ant->sig = aux;
    }
}

void carga(char* nomArch, TLista* l) {
    char nombre[21], dni[9];
    float prom;
    
    FILE* arch = fopen(nomArch, "r");
    
    if (arch != NULL) {
        while (fscanf(arch, "%s %s %f", nombre, dni, &prom) == 3) {
            agregaTitulo(nombre, dni, prom, l);
        }
    }
}

void muestraPila(TPila* p) {
    TElementoP titulo;
    
    if (!vaciaP(*p)) {
        sacaP(p, &titulo);
        printf("%s %g\n", titulo.dni, titulo.prom);
        muestraPila(p);
        poneP(p, titulo);
    }
}

void muestraLista(TLista l) {
    puts("LISTADO FACULTADES:\n");
    
    while (l != NULL) {
        puts(l->nombre);
        muestraPila(&l->titulos);
        puts("");
        l = l->sig;
    }
}

void sacaTituloPila(TPila* p, char* dni, int* elimino, float* prom) {
    TElementoP titulo;
    
    if (vaciaP(*p)) {
        *elimino = 0;
    }
    else {
        sacaP(p, &titulo);
        
        if (strcmp(dni, titulo.dni) == 0) {
            *elimino = 1;
            *prom = titulo.prom;
        }
        else {
            sacaTituloPila(p, dni, elimino, prom);
            poneP(p, titulo);
        }
    }
}

void retiro(char* nombre, char* dni, int* ordenActual, TLista* listaFacus, TListaCircular* listaTitulos, int* completado) {
    TLista ant, act = *listaFacus;
    TListaCircular aux;
    int elimino;
    float prom;
    
    *completado = 0;
    
    while (act != NULL && strcmp(nombre, act->nombre) > 0) {
        ant = act;
        act = act->sig;
    }
    
    if (act != NULL && strcmp(nombre, act->nombre) == 0) {
        sacaTituloPila(&act->titulos, dni, &elimino, &prom);
        
        if (elimino) {
            if (vaciaP(act->titulos)) {
                if (act == *listaFacus)
                    *listaFacus = act->sig;
                else
                    ant->sig = act->sig;
                    
                free(act);
            }
            
            (*ordenActual)++;
            
            aux = (TListaCircular) malloc(sizeof(nodoC));
            strcpy(aux->nombre, nombre);
            strcpy(aux->dni, dni);
            aux->prom = prom;
            aux->orden = *ordenActual;
            
            if (*listaTitulos == NULL) {
                *listaTitulos = aux;
                aux->sig = aux;
            }
            else {
                aux->sig = (*listaTitulos)->sig;
                (*listaTitulos)->sig = aux;
                *listaTitulos = aux;
            }
            
            *completado = 1;
        }
    }
}

void muestraTitulos(TListaCircular titulos, char* nombre) {
    TListaCircular aux, alumnoMejorProm = NULL;
    float mejorProm = 0;
    
    puts("LISTADO TITULOS ENTREGADOS:\n");
    
    if (titulos != NULL) {
        aux = titulos->sig;
        
        do {
            if (strcmp(nombre, aux->nombre) == 0 && aux->prom > mejorProm) {
                mejorProm = aux->prom;
                alumnoMejorProm = aux;
            }
            
            printf("Facultad: %s DNI: %s Promedio: %g Orden Entrega: %d\n", aux->nombre, aux->dni, aux->prom, aux->orden);
            aux = aux->sig;
            
        } while (aux != titulos->sig);
    }
    
    if (alumnoMejorProm != NULL) {
        printf("\nAlumno con mejor promedio de %s:\n", nombre);
        printf("DNI: %s Promedio: %g Orden Entrega: %d\n", alumnoMejorProm->dni, alumnoMejorProm->prom, alumnoMejorProm->orden);
    }
    else {
        printf("\nNo hay alumnos graduados de %s:\n", nombre);
    }
}

void devolucion(char* dni, TListaCircular* lista, int* devuelto) {
    TListaCircular ant, act;
    
    *devuelto = 0;
    
    if (*lista != NULL) {
        ant = *lista;
        act = (*lista)->sig;
        
        while (act != *lista && strcmp(dni, act->dni) != 0) {
            ant = act;
            act = act->sig;
        } 
        
        if (strcmp(dni, act->dni) == 0) {
            ant->sig = act->sig;
            
            if (act == *lista) {
                if (act == ant)
                    *lista = NULL;
                else
                    *lista = ant;
            }
                
            free(act);
            
            *devuelto = 1;
        }
    }
}

int main()
{
    TLista l = NULL;
    TListaCircular titulos = NULL;
    int ordenActual = 0;
    int completado;
    int devuelto;
    
    carga("TITULOS.txt", &l);
    
    retiro("CS_Economicas", "23098765", &ordenActual, &l, &titulos, &completado);
    retiro("CS_Economicas", "98904567", &ordenActual, &l, &titulos, &completado);
    retiro("Ingenieria", "91112345", &ordenActual, &l, &titulos, &completado);
    
    muestraLista(l);
    
    devolucion("91112345", &titulos, &devuelto);
    
    muestraTitulos(titulos, "CS_Economicas");
    
    return 0;
}
