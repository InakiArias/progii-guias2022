typedef int tElementoAN;
typedef int tPosicion;

#define POS_NULA -1

typedef struct {
    tElementoAN dato;
    tPosicion hMasIzq;
    tPosicion hnoDer;
    int activo;
} tNodo;

#define MAX 100

typedef struct {
    tNodo nodos[MAX];
    tPosicion posMayor;
} tArbolN;

int vacio(tArbolN a);
int nulo(tPosicion p);
tPosicion hijoMasIzq(tPosicion p, tArbolN a);
tPosicion hermanoDer(tPosicion p, tArbolN a);
tElementoAN info(tPosicion p, tArbolN a);
tPosicion raiz(tArbolN a);
tPosicion padre(tPosicion p, tArbolN a);
