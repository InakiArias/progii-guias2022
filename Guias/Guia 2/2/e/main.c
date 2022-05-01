#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10
#define MAX_N2 20

void mezcla(int a[], int b[], int c[], int ind_a, int ind_b, int *nc) {
    if (ind_a == -1 && ind_b == -1) {
        *nc = 0;
    }
    else if (ind_a == -1) {
        mezcla(a, b, c, -1, ind_b - 1, nc);
        c[*nc] = b[ind_b];
        (*nc)++;
    }
    else if (ind_b == -1) {
        mezcla(a, b, c, ind_a - 1, -1, nc);
        c[*nc] = a[ind_a];
        (*nc)++;
    }
    else if (a[ind_a] > b[ind_b]) {
        mezcla(a, b, c, ind_a - 1, ind_b, nc);
        c[*nc] = a[ind_a];
        (*nc)++;
    }
    else {
        mezcla(a, b, c, ind_a, ind_b - 1, nc);
        c[*nc] = b[ind_b];
        (*nc)++;
    }

}

void asigna_c(int asignado, int c[], int *nc) {
    if (*nc == 0 || asignado != c[*nc - 1]) {
        c[*nc] = asignado;
        (*nc)++;
    }
}

void mezcla2(int a[], int b[], int c[], int ind_a, int ind_b, int *nc) {
    if (ind_a == -1 && ind_b == -1) {
        *nc = 0;
    }
    else if (ind_a == -1) {
        mezcla2(a, b, c, -1, ind_b - 1, nc);
        asigna_c(b[ind_b], c, nc);
    }
    else if (ind_b == -1) {
        mezcla2(a, b, c, ind_a - 1, -1, nc);
        asigna_c(a[ind_a], c, nc);
    }
    else if (a[ind_a] > b[ind_b]) {
        mezcla2(a, b, c, ind_a - 1, ind_b, nc);
        asigna_c(a[ind_a], c, nc);
    }
    else {
        mezcla2(a, b, c, ind_a, ind_b - 1, nc);
        asigna_c(b[ind_b], c, nc);
    }

}

int main() {
    int a[MAX_N] = {1, 2, 2, 3, 3, 4, 4, 10, 15, 100},
        b[MAX_N] = {9, 9, 10, 10, 15, 15, 30, 30, 89, 90},
        c[MAX_N2], na, nb, nc;

    na = nb = MAX_N;

    mezcla2(a, b, c, na - 1, nb - 1, &nc);

    return 0;
}
