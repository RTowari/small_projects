#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#include "definiciones.h"

typedef struct nodo_empleado * Empleado;


// ________Funciones tipo definir

Empleado CreaListaEmpleado();



// ________Funciones tipo manipular nodos (iterar, devolver y eliminar)

// Inserta persona al inicio de lista empleado.
Empleado consEmpleado(Empleado e, Cadena ci, Cadena nom);

//re direcciona nodo a la nueva lista de empleados, la idea es usar el mismo espacio de memoria
void ReasignaEmpleado(Empleado &origen, Empleado &destino, Cadena ci);

//Busca un empleado por CI y devuelve puntero a su nodo empleado
Empleado BuscaEmpleado(Empleado e, Cadena ci);

void EliminarEmpleadoPorCI(Empleado &e, Cadena ci);

// Elimina toda la lista de empleados
Empleado EliminarEmpleadosLista(Empleado e);




// __________Funciones tipo imprimir

void ListaEmpleados(Empleado e);



// _________Funciones tipo ifExiste

//Verifica si persona pertenece a la lista de empleados retorna true
bool EsEmpleado(Empleado e, Cadena ci);



#endif




