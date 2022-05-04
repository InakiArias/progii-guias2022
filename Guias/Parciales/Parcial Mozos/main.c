/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodito {
    int nroMesa, cantComensales;
    struct nodito* sig;
} nodito;

typedef nodito* Sublista;

typedef struct nodo {
    char id[6];
    Sublista mesas;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

void insertaNoditoOrdenado(Sublista* s, int nroMesa, int cantComensales) {
    Sublista ant, aux, act = *s;
    
    while (act != NULL && nroMesa < act->nroMesa) {
        ant = act;
        act = act->sig;
    }
    
    aux = (Sublista) malloc(sizeof(nodito));
    aux->nroMesa = nroMesa;
    aux->cantComensales = cantComensales;
    
    aux->sig = act;
    
    if (act == *s) 
        *s = aux;
    else
        ant->sig = aux;
}

void carga(TLista* l, char* nomArch) {
    FILE* arch = fopen(nomArch, "r");
    TLista aux;
    int i, cantMesas, nroMesa, cantComensales;
    char id[6];
    
    if (arch != NULL) {
        while (fscanf(arch, "%s %d", id, &cantMesas) == 2) {
            aux = (TLista) malloc(sizeof(nodo));
            strcpy(aux->id, id);
            aux->mesas = NULL;
            
            for (i = 0; i < cantMesas; i++) {
                fscanf(arch, "%d %d", &nroMesa, &cantComensales);
                insertaNoditoOrdenado(&aux->mesas, nroMesa, cantComensales);
            }
            
            aux->sig = *l;
            *l = aux;
        }
    }
}

void muestra(TLista l) {
    Sublista aux;
    
    while (l != NULL) {
        puts(l->id);
        
        aux = l->mesas;
        
        while (aux != NULL) {
            printf("%d %d\n", aux->nroMesa, aux->cantComensales);
            aux = aux->sig;
        }
        
        l = l->sig;
    }
}

void cerrar(TLista* l, char* id, int nroMesa) {
    TLista ant, act = *l;
    Sublista antS, actS;
    
    while (act != NULL && strcmp(id, act->id) != 0) {
        ant = act;
        act = act->sig;
    }
    
    if (act != NULL && strcmp(id, act->id) == 0) {
        actS = act->mesas;
        
        while (actS != NULL && nroMesa < actS->nroMesa) {
            antS = actS;
            actS = actS->sig;
        }
        
        if (actS != NULL && nroMesa == actS->nroMesa) {
            if (actS == act->mesas) 
                act->mesas = actS->sig;
            else
                antS->sig = actS->sig;
                
            free(actS);
            
            if (act->mesas == NULL) {
                if (act == *l)
                    *l = act->sig;
                else
                    ant->sig = act->sig;
                    
                free(act);
            }
        }
    }
}

void cuentaListado(Sublista s, int* cantMesas, int* cantUnComensal) {
    *cantMesas = 0;
    *cantUnComensal = 0;
    
    while (s != NULL) {
        if (s->cantComensales == 1)
            (*cantUnComensal)++;
        
        (*cantMesas)++;
        s = s->sig;
    }
}

void listado(TLista l) {
    int cantMesas, cantUnComensal;
    printf("LISTADO DE MOZOS:\n\n");
    printf("Id Mozo\t\t Mesas sin cerrar\t\t Mesas con un solo comensal\n");
    
    while (l != NULL) {
        cuentaListado(l->mesas, &cantMesas, &cantUnComensal);
        
        printf("%6s\t\t%9d\t\t%22d\n", l->id, cantMesas, cantUnComensal);
    
        l = l->sig;
    }
}

int main()
{
    TLista l = NULL;
    
    carga(&l, "Mozos.txt");
    
    cerrar(&l, "Pedro", 39);
    cerrar(&l, "Alejo", 77);
    
    listado(l);

    return 0;
}
