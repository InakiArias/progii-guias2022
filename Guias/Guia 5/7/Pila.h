#include "TElementoP.h"

typedef struct nodop{
    TElementoP dato;
    struct nodop* sig;
} nodop;

typedef nodop* TPila;

void iniciaP(TPila* p);
void poneP(TPila* p, TElementoP x);
void sacaP(TPila* p, TElementoP* x);
TElementoP consultaP(TPila p);
int vaciaP(TPila p);
