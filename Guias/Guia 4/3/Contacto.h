typedef struct {
    char* nombre;
    char* numero;
} Contacto;

Contacto nuevoContacto(char* nombre, char* numero);
char* nombre(Contacto c);
char* numero(Contacto c);
