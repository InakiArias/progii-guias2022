#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int dato;
    struct n *izq, *der;
} n;

typedef n* TArbol;

int cantArboles(TArbol a) { // Ej 19
    int res = 0;

    while (a != NULL) {
        res++;
        a = a->der;
    }

    return res;
}

int cantNodos(TArbol a, int nivelAct) { // Ej 20
    int cuenta;

    if (a == NULL)
        return 0;
    else {
        cuenta = nivelAct % 2 == 1 ? 1 : 0;

        return cantNodos(a->izq, nivelAct + 1) + cantNodos(a->der, nivelAct) + cuenta;
    }
} //cantNodos(a, 1)

int gradoOriginal(TArbol a) {
    int res = 0;
    a = a->izq;

    while (a != NULL) {
        res++;
        a = a->der;
    }

    return res;
}

void prom_rec(TArbol a, int k, int* cant, int* suma) {
    if (a != NULL) {
        if (gradoOriginal(a) == k) {
            (*cant)++;
            *suma += a->dato;
        }
        prom_rec(a->izq, k, cant, suma);
        prom_rec(a->der, k, cant, suma);
    }
}

void prom(TArbol a, int k, int* suma, int* cant) { //Ej 21
    *cant = *suma = 0;
    prom_rec(a, k, cant, suma);
}

int altura(TArbol a) { //ej 22
    int altIzq, altDer;

    if (a == NULL)
        return -1;
    else {
        altIzq = altura(a->izq) + 1;
        altDer = altura(a->der);

        return altIzq > altDer ? altIzq : altDer;
    }
}

void gradoArbolOriginal_rec(TArbol a, int* res) { //Ej 23
    int gradoAct;

    if (a != NULL) {
        gradoAct = gradoOriginal(a);

        if (gradoAct > *res)
            *res = gradoAct;

        gradoArbolOriginal_rec(a->izq, res);
        gradoArbolOriginal_rec(a->der, res);
    }
}

void gradoArbolOriginal(TArbol a, int* res) {
    *res = 0;
    gradoArbolOriginal_rec(a, res);
}

void cantAlturaK(TArbol a, int k, int* res) { //ej 24
    *res = 0;

    while (a != NULL) {
        if (altura(a->izq) + 1 >= k)
            (*res)++;
        a = a->der;
    }
}

void maximo(TArbol a, int* res) {
    if (a != NULL) {
        if (a->dato > *res)
            *res = a->dato;

        maximo(a->izq, res);
        maximo(a->der, res);
    }
}

void maximosBosque(TArbol a, int arr[], int* n) { //Ej 25
    *n = 0;

    while (a != NULL) {
        arr[*n] = a->dato;
        maximo(a->izq, &arr[*n]);

        (*n)++;
        a = a->der;
    }
}

int conteniaGrado(TArbol a, int k) {
    if (a == NULL)
        return 0;
    else
        return gradoOriginal(a) == k || conteniaGrado(a->izq, k) || conteniaGrado(a->der, k);
}

int todosContenianGrado(TArbol a, int k) { //Ej 26
    while (a != NULL && (gradoOriginal(a) == k || conteniaGrado(a->izq, k)))
        a = a->der;

    return a == NULL;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}








