#ifndef PERSONA_H
#define PERSONA_H

#include "definiciones.h"

// Empleado tiene sus datos y un pointer al siguiente empleado
typedef struct nodo_persona * Persona;




Persona crearPers_vacia();
// Crea la persona vacia.

Persona creaPers(Cadena ci, Cadena nombre);
// Crea persona con Ci y nombre.

Persona destruir (Persona p);
// Destruye una persona liberando su memoria

Cadena getCI(Persona p);
// Dada una persona devuelve su cedula

Cadena getNombre(Persona p);
// Dada una persona devuelve su nombre

#endif