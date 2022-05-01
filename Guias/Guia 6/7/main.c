#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 20
#define LETRAS 26

typedef struct nodito {
    char nombre[MAXL];
    char titulo[MAXL];
    int anio;
    struct nodito* sig;
} nodito;

typedef nodito* Sublista;

typedef struct nodo {
    char nombre[MAXL];
    Sublista libros;
    struct nodo* sig;
} nodo;

typedef nodo* TLista;

void inicia(TLista biblio[]) {
    int i;

    for (i = 0; i < LETRAS; i++)
        biblio[i] = NULL;
}

void insertaNoditoOrd(Sublista* s, char* nombre, char* titulo, int anio) {
    Sublista aux, ant, act;

    aux = (Sublista) malloc(sizeof(nodito));
    strcpy(aux->nombre, nombre);
    strcpy(aux->titulo, titulo);
    aux->anio = anio;

    act = *s;

    while (act != NULL && strcmp(titulo, act->titulo) > 0) {
        ant = act;
        act = act->sig;
    }

    aux->sig = act;

    if (act == *s)
        *s = aux;
    else
        ant->sig = aux;
}

void agregaLibro(TLista* l, char* nombre, char* titulo, int anio) {
    TLista ant, act = *l, aux;

    while (act != NULL && strcmp(nombre, act->nombre) > 0) {
        ant = act;
        act = act->sig;
    }

    if (act != NULL && strcmp(nombre, act->nombre) == 0) {
        insertaNoditoOrd(&act->libros, nombre, titulo, anio);
    }
    else {
        aux = (TLista) malloc(sizeof(nodo));
        strcpy(aux->nombre, nombre);
        aux->libros = NULL;

        insertaNoditoOrd(&aux->libros, nombre, titulo, anio);

        aux->sig = act;

        if (act == *l)
            *l = aux;
        else
            ant->sig = aux;
    }
}

void eliminaLibroSublista(Sublista* s, char* titulo, int anio, int* elimino) {
    Sublista act = *s, ant;
    *elimino = 0;

    while (act != NULL && strcmp(titulo, act->titulo) > 0) {
        ant = act;
        act = act->sig;
    }

    while (act != NULL && strcmp(titulo, act->titulo) == 0 && anio != act->anio) {
        ant = act;
        act = act->sig;
    }

    if (act != NULL && strcmp(titulo, act->titulo) == 0 && anio == act->anio){
        if (act == *s)
            *s = act->sig;
        else
            ant->sig = act->sig;

        free(act);
        *elimino = 1;
    }
}

void eliminaLibro(TLista* l, char* nombre, char* titulo, int anio, int* elimino) {
    TLista ant, act = *l;
    *elimino = 0;

    while (act != NULL && strcmp(nombre, act->nombre) > 0) {
        ant = act;
        act = act->sig;
    }

    if (act != NULL && strcmp(nombre, act->nombre) == 0) {
        eliminaLibroSublista(&act->libros, titulo, anio, elimino);

        if (act->libros == NULL) {
            if (act == *l)
                *l = act->sig;
            else
                ant->sig = act->sig;

            free(act);
        }
    }
}

void agregaLibroABiblio(TLista biblio[], char* nombre, char* titulo, int anio) {
    int indice = nombre[0] - 65;

    agregaLibro(&biblio[indice], nombre, titulo, anio);
}

void muestra(TLista biblio[]) {
    TLista aux;
    Sublista auxS;
    int i;

    printf("LISTADO: \n\n");

    for (i = 0; i < LETRAS; i++) {
        if (biblio[i] != NULL) {
            printf("Letra '%c': \n", i + 65);

            aux = biblio[i];

            while (aux != NULL) {
                printf("\tAutor: %s\n", aux->nombre);

                auxS = aux->libros;

                while (auxS != NULL) {
                    printf("\t\t* %s, %d\n", auxS->titulo, auxS->anio);
                    auxS = auxS->sig;
                }

                aux = aux->sig;
            }

            puts("");
        }
    }
}

void prestamo(TLista biblio[], TLista* socios, char* nombreSocio, char* nombre, char* titulo, int anio) {
    int elimino, indice = nombre[0] - 65;
    TLista aux, ant, act;

    eliminaLibro(&biblio[indice], nombre, titulo, anio, &elimino);

    if (elimino) {
        act = *socios;

        while (act != NULL && strcmp(nombreSocio, act->nombre) > 0) {
            ant = act;
            act = act->sig;
        }

        if (act != NULL && strcmp(nombreSocio, act->nombre) == 0) {
            insertaNoditoOrd(&act->libros, nombre, titulo, anio);
        }
        else {
            aux = (TLista) malloc(sizeof(nodo));
            strcpy(aux->nombre, nombreSocio);
            aux->libros = NULL;
            insertaNoditoOrd(&aux->libros, nombre, titulo, anio);

            aux->sig = act;

            if (act == *socios)
                *socios = aux;
            else
                ant->sig = aux;
        }
    }
}

void devolucion(TLista biblio[], TLista* socios, char* nombreSocio, char* nombre, char* titulo, int anio) {
    TLista act = *socios, ant;
    Sublista antS, actS;
    int eliminado = 0;

    while (act != NULL && strcmp(nombreSocio, act->nombre) > 0) {
            ant = act;
            act = act->sig;
    }

    if (act != NULL && strcmp(nombreSocio, act->nombre) == 0) {
        actS = act->libros;

        while (actS != NULL && strcmp(titulo, actS->titulo) > 0)  {
            antS = actS;
            actS = actS->sig;
        }

        while (actS != NULL && strcmp(titulo, actS->titulo) == 0 && strcmp(nombre, actS->nombre) != 0 && anio != actS->anio) {
            antS = actS;
            actS = actS->sig;
        }

        if (actS != NULL && strcmp(titulo, actS->titulo) == 0 && strcmp(nombre, actS->nombre) == 0 && anio == actS->anio) {
            if (actS == act->libros)
                act->libros = actS->sig;
            else
                antS->sig = actS->sig;

            free(actS);
            eliminado = 1;
        }
    }

    if (eliminado) {
        if (act->libros == NULL) {
            if (act == *socios)
                *socios = act->sig;
            else
                ant->sig = act->sig;

            free(act);
        }

        agregaLibroABiblio(biblio, nombre, titulo, anio);
    }

}

void muestraSocios(TLista socios) {
    Sublista aux;

    printf("SOCIOS: \n\n");

    while (socios != NULL) {
        printf("Socio: %s\n", socios->nombre);

        aux = socios->libros;

        while (aux != NULL) {
            printf("\t* '%s', %s, %d\n", aux->titulo, aux->nombre, aux->anio);
            aux = aux->sig;
        }

        socios = socios->sig;
    }
}

int main()
{
    TLista biblio[LETRAS];
    TLista socios = NULL;
    inicia(biblio);

    agregaLibroABiblio(biblio, "Galeano, Eduardo", "Venas Abiertas", 2010);
    agregaLibroABiblio(biblio, "Galeano, Eduardo", "Venas Abiertas", 2005);
    agregaLibroABiblio(biblio, "Galeano, Eduardo", "Venas Abiertas", 2003);
    agregaLibroABiblio(biblio, "Cortazar, Julio", "Las Armas Secretas", 1995);
    agregaLibroABiblio(biblio, "Christie, Agatha", "Muerte en el Nilo", 2000);
    agregaLibroABiblio(biblio, "Christie, Agatha", "Muerte en el Nilo", 1997);

    muestra(biblio);

    prestamo(biblio, &socios, "Juan", "Cortazar, Julio", "Las Armas Secretas", 1995);
    prestamo(biblio, &socios, "Ana", "Christie, Agatha", "Muerte en el Nilo", 2000);
    prestamo(biblio, &socios, "Juan", "Christie, Agatha", "Muerte en el Nilo", 1997);
    devolucion(biblio, &socios, "Juan", "Christie, Agatha", "Muerte en el Nilo", 1997);

    muestra(biblio);
    muestraSocios(socios);

    return 0;
}
