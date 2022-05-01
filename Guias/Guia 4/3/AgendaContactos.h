#include "Contacto.h"

#define MAX_CONTACTOS 50

typedef struct {
    Contacto lista[MAX_CONTACTOS];
    int cant;
} AgendaContacto;

AgendaContacto iniciaAgenda();
void agregarContacto(Contacto c, AgendaContacto *a);
void listarAgenda(AgendaContacto a);
int indiceDe(char* nombre, AgendaContacto a);
Contacto busca(char* nombre, AgendaContacto a);
