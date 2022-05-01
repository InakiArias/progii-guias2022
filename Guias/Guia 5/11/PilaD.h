typedef float tElementoPD;

typedef struct nodop {
    tElementoPD dato;
    struct nodop *sig;
} nodop;

typedef nodop* PilaD;

PilaD iniciaPD();
int vaciaPD(PilaD P);
void ponePD(PilaD *P, tElementoPD x);
tElementoPD consultaPD(PilaD P);
tElementoPD sacaPD(PilaD *p);


