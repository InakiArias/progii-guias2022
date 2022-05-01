#include <stdio.h>
#include <stdlib.h>

float promedio(float vec[], int i, int n) {
    if (i == 0)
        return vec[i];
    if (i == n - 1)
        return (vec[i] + promedio(vec, i - 1, n)) / n;

    return vec[i] + promedio(vec, i - 1, n);
}

int main()
{
    float vec[] = {10, 20, 30, 40, 50, 70};

    printf("Prom: %g", promedio(vec, 5, 6));


    return 0;
}
