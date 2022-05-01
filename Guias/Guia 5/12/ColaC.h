typedef int tElementoC;

#define MAX 10

typedef struct {
    tElementoC datos[MAX];
    int pri, ult;
} ColaC;

void iniciaC(ColaC* c);
void poneC(ColaC* c, tElementoC x);
void sacaC(ColaC* c, tElementoC *x);
tElementoC consultaC(ColaC c);
int vaciaC(ColaC c);
