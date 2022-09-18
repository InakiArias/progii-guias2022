#define TAM_COLA 30
#define CAD_FECHA 9

typedef struct {
    char datos[TAM_COLA][CAD_FECHA];
    int pri, ult;
} Cola;

Cola iniciaC();
int vaciaC(Cola c);
void poneC(Cola *c, char x[CAD_FECHA]);
void consultaC(Cola c, char x[CAD_FECHA]);
void sacaC(Cola *c, char x[CAD_FECHA]);



