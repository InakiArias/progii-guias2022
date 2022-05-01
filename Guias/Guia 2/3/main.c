#include <stdio.h>
#include <stdlib.h>

#define INICIA() malloc(sizeof(int))

void lee(int *n);
int suma(int *a, int *b, int *c);
int prod(int *a, int *b, int *c);

int main()
{
    int *a = INICIA(), *b = INICIA(), *c = INICIA();

    lee(a);
    lee(b);
    lee(c);

    printf("\n\nLa suma es: %d El producto es: %d\n\n", suma(a, b, c), prod(a, b, c));

    free(a);
    free(b);
    free(c);

    return 0;
}

void lee(int *n) {
    printf("Ingrese un numero: ");
    scanf("%d", n);
}

int suma(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int prod(int *a, int *b, int *c) {
    return *a * *b * *c;
}
