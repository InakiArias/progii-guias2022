#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

void carga(int arr[], int n, TLista* l) {
    int i;
    TLista aux;
    
    for (i = 0; i < n; i++) {
        aux = (TLista) malloc(sizeof(nodo));
        aux->dato = arr[i];
        aux->sig = *l;
        *l = aux;
    }
}

void divide(TLista* l, TLista* pares, TLista* impares) {
    TLista ultPares, aux;
    
    while (*l != NULL) {
        aux = (*l)->sig;
        
        if ((*l)->dato % 2 != 0) {
            (*l)->sig = *impares;
            *impares = *l;
        }
        else {
            if (*pares == NULL) 
                *pares = *l;
            else 
                ultPares->sig = *l;
            
            ultPares = *l;
        }
        
        *l = aux;
    }
    
    ultPares->sig = NULL;
}

void muestra(TLista l) {
    puts("");
    
    while (l != NULL) {
        printf("%d\n", l->dato);
        l = l->sig;
    }
    
    puts("");
}

int main()
{
    TLista l = NULL, pares = NULL, impares = NULL;
    int n = 7, arr[10] = {120, 61, 35, 22, 20, 11, 8};
    
    carga(arr, n, &l);
    muestra(l);
    
    divide(&l, &pares, &impares);
    //muestra(l);
    muestra(impares);
    muestra(pares);

    return 0;
}
