#define MAX 31

typedef struct {
    int dia;
    float tMin, tMax;
} tElementop;

typedef struct pila{
    tElementop datos[MAX];
    int tope;
} tPila;

void iniciaP(tPila *p);
void poneP(tPila *p, tElementop x);
void sacaP(tPila *p, tElementop *x);
tElementop consultaP(tPila p);
int vaciaP(tPila p);
