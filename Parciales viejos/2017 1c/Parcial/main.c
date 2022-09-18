#include "headers.h"

typedef struct ns {
    char nombre[CAD_SABOR];
    int gramos;
    int fil;
    int col;
    Cola baldes;
    struct ns *sig;
} nodoS;

typedef nodoS* ListaSabor;

typedef struct nb {
    char nombre[CAD_SABOR];
    char fecha[CAD_FECHA];
    int fil;
    int col;
    struct nb *sig;
} nodoB;

typedef nodoB* ListaCircBalde;

typedef struct {
    char nombre[CAD_SABOR];
    int gramos;
} ElemMatriz;

ListaSabor creaNodoSabor(char nombre[CAD_SABOR], int gramos, int fil, int col) {
    ListaSabor p = malloc(sizeof(nodoS));

    strcpy(p->nombre, nombre);
    p->gramos = gramos;
    p->fil = fil;
    p->col = col;
    p->baldes = iniciaC();
    p->sig = NULL;

    return p;
}

void insertaOrdenado(ListaSabor insertado, ListaSabor *cabeza) {
    ListaSabor *ptr = cabeza;

    while (*ptr != NULL && strcmp(insertado->nombre, (*ptr)->nombre) > 0)
        ptr = &(*ptr)->sig;

    insertado->sig = *ptr;
    *ptr = insertado;
}

ListaSabor creaListaSabores(char *nomArch) {
    FILE *arch = fopen(nomArch, "r");

    if (arch == NULL)
        return NULL;

    ListaSabor cabeza = NULL;
    ListaSabor aux;

    char nombre[CAD_SABOR];
    char fecha[CAD_FECHA];
    int gramos;
    int fil;
    int col;

    int i;
    char c;
    int cantBaldes;

    while (!feof(arch)) {
        i = 0;
        c = fgetc(arch);

        while (c != ' ') {
            nombre[i] = c;
            i++;
            c = fgetc(arch);
        }

        nombre[i] = '\0';

        fscanf(arch, "%d %d %d %d", &gramos, &fil, &col, &cantBaldes);

        aux = creaNodoSabor(nombre, gramos, fil, col);
        insertaOrdenado(aux, &cabeza);

        fgetc(arch);

        for (i = 0; i < cantBaldes; i++) {
            fgets(fecha, CAD_FECHA, arch);
            poneC(&aux->baldes, fecha);
            fgetc(arch);
        }
    }

    return cabeza;
}

void muestraLista(ListaSabor cabeza) {
    ListaSabor ptr = cabeza;

    while (ptr != NULL) {
        printf("\n%s %d %d %d Baldes: \n", ptr->nombre, ptr->gramos, ptr->fil, ptr->col);

        while (!vaciaC(ptr->baldes)) {
            char fecha[CAD_FECHA];
            sacaC(&ptr->baldes, fecha);
            puts(fecha);
        }

        ptr = ptr->sig;

    }

    printf("\n\n");
}

ListaCircBalde creaNodoBalde(char nombre[CAD_SABOR], char fecha[CAD_FECHA], int fil, int col) {
    ListaCircBalde p = malloc(sizeof(nodoB));

    strcpy(p->nombre, nombre);
    strcpy(p->fecha, fecha);
    p->fil = fil;
    p->col = col;
    p->sig = NULL;

    return p;
}

void calculaTam(ListaSabor cabeza, int *n, int *m) {
    ListaSabor ptr = cabeza;
    *n = *m = -1;

    while (ptr != NULL) {
        if (ptr->fil > *n)
            *n = ptr->fil;
        if (ptr->col > *m)
            *m = ptr->col;

        ptr = ptr->sig;
    }

    *n = *n + 1;
    *m = *m + 1;
}

void insertaAlFinal(ListaCircBalde insertado, ListaCircBalde *final) {
    if (*final == NULL) {
        insertado->sig = insertado;
        *final = insertado;
        return;
    }

    insertado->sig = (*final)->sig;
    (*final)->sig = insertado;
    *final = insertado;
}

ListaCircBalde procesoSemanal(char fechaTope[CAD_FECHA], ListaSabor cabeza, ElemMatriz matriz[MAX_N][MAX_M], int n, int m) {
    int i, j;
    ListaCircBalde finListaBaldes = NULL;
    ListaSabor ptrSab = cabeza;
    char fecha[CAD_FECHA];

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            matriz[i][j].gramos = -1;
            matriz[i][j].nombre[0] = '\0';
        }


    while (ptrSab != NULL) {
        i = ptrSab->fil;
        j = ptrSab->col;
        strcpy(matriz[i][j].nombre, ptrSab->nombre);
        matriz[i][j].gramos = ptrSab->gramos;

        while (!vaciaC(ptrSab->baldes)) {
            sacaC(&ptrSab->baldes, fecha);

            if (strcmp(fecha, fechaTope) < 0) {
                ListaCircBalde aux = creaNodoBalde(ptrSab->nombre, fecha, ptrSab->fil, ptrSab->col);
                insertaAlFinal(aux, &finListaBaldes);
            }
        }

        ptrSab = ptrSab->sig;
    }

    return finListaBaldes;
}

void muestraMatriz(ElemMatriz matriz[MAX_N][MAX_M], int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%s %d ", matriz[i][j].nombre, matriz[i][j].gramos);

        printf("\n");
    }

    printf("\n\n");
}

void muestraListaCirc(ListaCircBalde fin) {
    printf("Baldes desechados: \n\n");

    if (fin == NULL)
        return;

    ListaCircBalde ptr = fin->sig;

    do {
        printf("%s %s %d %d\n", ptr->nombre, ptr->fecha, ptr->fil, ptr->col);
        ptr = ptr->sig;
    } while (ptr != fin->sig);

    printf("\n\n");
}

int eliminaDeLista(int fila, ListaCircBalde *final) {
    if (*final == NULL)
        return 0;

    int cant = 0;
    ListaCircBalde *ptr = &(*final)->sig;
    ListaCircBalde aux;

    while (*ptr != *final) {
        if ((*ptr)->fil == fila) {
            aux = *ptr;
            *ptr = (*ptr)->sig;
            free(aux);
            cant++;
        }
        else
            ptr = &(*ptr)->sig;
    }

    if ((*final)->fil == fila) {
        aux = *final;

        if ((*final)->sig == *final)
            *ptr = *final = NULL;
        else
            *ptr = *final = (*final)->sig;

        free(aux);
        cant++;
    }

    return cant;
}

void calculaPromedios(ElemMatriz matriz[MAX_N][MAX_M], int i, int j, int n, int cantActual, int cantTotal, float promCols[MAX_M], float *promedioGeneral) {
    if (j < 0) {
        *promedioGeneral /= cantTotal != 0 ? cantTotal : 1;
    }
    else if (i > -1) {
        int gramos = matriz[i][j].gramos;

        if (gramos > -1) {
            cantActual++;
            cantTotal++;
            *promedioGeneral += gramos;
            promCols[j] += gramos;
        }

        calculaPromedios(matriz, i - 1, j, n, cantActual, cantTotal, promCols, promedioGeneral);
    }
    else {
        promCols[j] /= cantActual != 0 ? cantActual : 1;
        calculaPromedios(matriz, n, j - 1, n, 0, cantTotal, promCols, promedioGeneral);
    }
}

void muestraProms(float arr[MAX_M], int m) {
    int j;

    for (j = 0; j < m; j++)
        printf("Prom de col %d: $%g\n", j, arr[j]);
}

int main()
{
    ListaSabor listaSabores = creaListaSabores("Datos.txt");

    //muestraLista(listaSabores);

    ElemMatriz matriz[MAX_N][MAX_M];
    int n, m;
    calculaTam(listaSabores, &n, &m);

    char fechaTope[CAD_FECHA];
    printf("Ingrese fecha tope: ");
    gets(fechaTope);

    ListaCircBalde listaBaldes = procesoSemanal(fechaTope, listaSabores, matriz, n, m);
    muestraMatriz(matriz, n, m);

    muestraListaCirc(listaBaldes);

    int filaEliminada;
    printf("Ingrese fila a eliminar de la lista: ");
    scanf("%d", &filaEliminada);


    printf("Cant borrados %d\n", eliminaDeLista(filaEliminada, &listaBaldes));

    muestraListaCirc(listaBaldes);

    float promCols[MAX_M], promedioGeneral = 0;

    calculaPromedios(matriz, n - 1, m - 1, n - 1, 0, 0, promCols, &promedioGeneral);
    muestraProms(promCols, m);

    printf("Prom total $%g\n\n", promedioGeneral);


    return 0;
}
