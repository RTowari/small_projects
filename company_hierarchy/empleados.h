#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#include "definiciones.h"
#include "persona.h"
#include "cargo.h"



TipoRet EliminarPersona(Empresa &e, Cadena ci);
// Eliminar una persona de un cargo.
// Elimina una persona de cédula ci de la empresa siempre y cuando la misma exista,
// en caso contrario la operación quedará sin efecto.

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci);
// Reasignar una persona a un nuevo cargo.
// Reasigna una persona de la empresa de cédula ci al nuevo cargo de nombre cargo
// siempre que el cargo exista en la empresa y esa persona no este ya asignada a
// dicho cargo. En caso contrario la operación quedará sin efecto.

//Define una lista vacia de empleados
Empleado CreaListaEmpleado();

//Define un nuevo nodo para empleado y lo pone al principio
Empleado cons(Empleado e, Cadena ci, Cadena nom);

//Lista las personas de una lista empleados
void ListaEmpleados(Empleado e);

//Verifica si persona de cedula CI existe en lista empleado
bool EsEmpleado(Empleado e, Cadena ci);

#endif




