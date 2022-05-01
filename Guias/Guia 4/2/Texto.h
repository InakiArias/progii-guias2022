typedef struct {
    char* texto;
    unsigned int largo;
} Texto;

Texto crear(char* cadena);
void destruir(Texto *texto);
char* texto(Texto texto);
int largo(Texto texto);
char caracterEn(Texto texto, unsigned int indice);
Texto concatena(Texto texto1, Texto texto2);
Texto reemplazar(Texto texto, char caracter, char nuevoCaracter);
Texto subTexto(Texto texto, unsigned int desde, unsigned int hasta);
int comienzaCon(Texto texto, Texto prefijo);
int terminaCon(Texto texto, Texto sufijo);
