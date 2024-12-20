#include <stdio.h>
#include <iostream>
#include <string.h>

#include "cargo.h"
#include "empleados.h"
#include "manejaListaAlf.h"

using namespace std;


// Cargo tiene un pointer a la linked list de personas
// hasta que el profesor explique como van a ser los trees
struct nodo_cargo {
    Cadena nombre;
    Empleado empleados;
    Cargo hijo;
    Cargo hermano_sig;
    Cargo hermano_ant;
    Cargo padre;
};


//________Funciones de imprimir 


void imprimeDesdeAbajo(Cargo cargos) 	{
//Esta funcion va iterativamente desde el cargo pasado hasta el cargo raiz
// Una vez en el cargo raiz imprime el dato de cada nodo
	
	if(cargos->padre==NULL) { // Si llegue el cargo raiz que no tiene cargo padre
		cout << getCarNom(cargos) << endl; // Imprimo el nombre y dejo de iterar
	}
	else if(cargos->padre != NULL) 	{ // Si mi cargo actual tiene un padre sigo recorriendo
		imprimeDesdeAbajo(cargos->padre);
		cout << getCarNom(cargos) << endl;
	}

}

void imprimirArbolCargos(Cargo cargos, int ident) {
// Se llama desde ListarJerarquia(). Usa un int para aumentar la identacion segun avanza por los hijos
	
	if(cargos == NULL) {
	} else {
		imprimirIdent(ident);
		cout << "->" << getCarNom(cargos) << endl;

		if(cargos->hijo != NULL) {
			imprimirArbolCargos(cargos->hijo, ident + 2);
		}
		if(cargos->hermano_sig != NULL) {
			imprimirArbolCargos(cargos->hermano_sig, ident);
		}
	}
}

void imprimeInfoCargo(Cargo cargo) {
// Esta función imprime los parientes de un cargo (llama a funciones de tipo get para obtener la info)

	cout << "Nombre: " << getCarNom(cargo) << " | " << "Nombre del hijo: " << getCarNomH(cargo) << " | " << "Nombre del padre: " << getCarNomP(cargo) << endl;
}

void imprimirIdent(int ident) {
// Recibe un int y imprime ese numero de espacios
	for(int i = 0; i<=ident; i++) {
		cout << " ";
	}
}



//________Funciones tipo get

Cadena getCarNom(Cargo cargo){
	if(cargo != NULL) {
		return cargo->nombre;
	} else
		return NULL;
}

Cadena getCarNomH(Cargo cargo){
	if(cargo->hijo != NULL) {
		cargo = cargo->hijo;
		return cargo->nombre;
	} else
		return NULL;
}

Cadena getCarNomP(Cargo cargo){
	if(cargo->padre != NULL) {
		cargo = cargo->padre;
		return cargo->nombre;
	} else
		return NULL;
}



//______Funiones tipo iterar y devolver

Cargo iteradorEmpresa(Cadena cargo, Cargo cargos) {
// Itera todo el arbol usando el nodo pasado como raiz y devuelve el puntero al cargo con el nombre pasado

	if(strcasecmp(cargos->nombre, cargo) == 0) { // Encontre un cargo con el mismo nombre
		return cargos;
	} else if(cargos->hermano_sig == NULL && cargos->hijo == NULL) {  // Si llegue al final de ambos
		return NULL;
	} else if(cargos->hermano_sig == NULL && cargos->hijo != NULL) { // Si llegue al final de hermano_sig voy al hijo
		return iteradorEmpresa(cargo, cargos->hijo);
	} else if(cargos->hermano_sig != NULL && cargos->hijo == NULL) { // Si llegue al final de hijo voy al hermano_sig
		return iteradorEmpresa(cargo, cargos->hermano_sig);
	} else if(cargos->hermano_sig != NULL && cargos->hijo != NULL) { // Si hay ramas para los dos lados voy a hijo primero (exploro toda esa rama)
		Cargo result = iteradorEmpresa(cargo, cargos->hijo);
        if (result != NULL) {
            return result;
        } else {
            return iteradorEmpresa(cargo, cargos->hermano_sig);
        }
	}
	return NULL;
}

Cargo iteradorCargohermano_sigs(Cargo cargos) {
	// Itera hasta el final de la lista de cargos hermanos y devuelve el ultimo miembro

	if(cargos->hermano_sig == NULL) {
		return cargos;
	}
	else if(cargos->hermano_sig != NULL) {
		return (iteradorCargohermano_sigs(cargos->hermano_sig));
	}
	return NULL;
}

Cargo iteradorCargohermano_ants(Cargo cargos) {
	if(cargos->hermano_ant == NULL) {
		return cargos;
	}
	else if(cargos->hermano_ant != NULL) {
		return (iteradorCargohermano_ants(cargos->hermano_ant));
	}
	return NULL;
}

Cargo BuscaCargoPersona(Cargo cargos, Cadena ci) {
// Itera todo el arbol buscando el cargo de la persona Ci pasa por parametro, devuelve el cargo donde este la persona o null

	if(EsEmpleado(cargos->empleados,ci)) { // Encontre un cargo con la persona como empleado
		return cargos;
	} else if(cargos->hermano_sig == NULL && cargos->hijo == NULL) {  // Si llegue al final de ambos
		return NULL;
	} else if(cargos->hermano_sig == NULL && cargos->hijo != NULL) { // Si llegue al final de hermano_sig voy al hijo
		return BuscaCargoPersona(cargos->hijo, ci);
	} else if(cargos->hermano_sig != NULL && cargos->hijo == NULL) { // Si llegue al final de hijo voy al hermano_sig
		return BuscaCargoPersona(cargos->hermano_sig, ci);
	} else if(cargos->hermano_sig != NULL && cargos->hijo != NULL) { // Si hay ramas para los dos lados voy a hijo primero (exploro toda esa rama)
		Cargo result = BuscaCargoPersona(cargos->hijo, ci);
        if (result != NULL) {
            return result;
        } else {
            return BuscaCargoPersona(cargos->hermano_sig, ci);
        }
	}
	return NULL;
}



//_______Funcciones tipo asignar, definir y eliminar

Cargo definirCargo(Cadena cargo_nom) {
	
	Cargo nuevo_cargo = new(nodo_cargo);
	nuevo_cargo->empleados = CreaListaEmpleado();
	nuevo_cargo->hijo = NULL;
	nuevo_cargo->hermano_sig = NULL;
	nuevo_cargo->hermano_ant = NULL;
	nuevo_cargo->padre = NULL;

	Cadena nombre = new char[MAX_COMANDO];
	strcpy(nombre, cargo_nom);
	nuevo_cargo->nombre = nombre;
	
	return nuevo_cargo;
}

void AsignarCargoHijo(Cargo cargo_hijo, Cargo cargo_padre) {
// Asigno el nuevo cargo como hijo del cargo pedido

	// Si el cargo padre esta vacio pongo el cargo nuevo
	if(cargo_padre->hijo == NULL) {
		cargo_padre->hijo=cargo_hijo;
		cargo_hijo->padre = cargo_padre;
		cargo_padre->hijo->nombre;

	// Si el cargo padre ya tiene hijos itero hasta el final de esa lista
	} else {
		Cargo cargo_hermano_sig = iteradorCargohermano_sigs(cargo_padre->hijo); // Busco el ultimo cargo de la lista de hijos
		cargo_hermano_sig->hermano_sig = cargo_hijo; // Asigno el cargo que debo poner a lo ultimo de la lista
		cargo_hijo->hermano_ant = cargo_hermano_sig; // Al nuevo cargo que puse le asigno el hermano anterior

		cargo_hijo->padre = cargo_padre; // Señalo quien es el padre de este cargo
	}
}

void ArbolCargo_A_ListaCargo(Cargo cargos) {

	// Creo una lista vacia que sera la que ordenare alfabeticamente
	listaSimple lista = definirListaSimpleVacia();

	// Itero a traves de mi arbol de cargos y voy poniendolos en una lista
	iterarArbol_Anadir_a_Lista(cargos, lista);

	// ordeno mi lista alfabeticamente
	lista = ordenarListaAlf(lista);
	
	// Imprimo la lista
	imprimeListaSimple(lista);
}

void iterarArbol_Anadir_a_Lista(Cargo cargos, listaSimple &lista) {
	if(cargos==NULL) {
		return;	
	}
	else {
		
		// Creo un nodo de tipo lista con los datos del nodo de cargos
		Cadena nombre = getCarNom(cargos);
		
		listaSimple nuevaLista = definirListaSimple(nombre);
		
		// Engancho mi nuevo nodo a la lista. La funcion se fija si acabo de crear la lista
		concatenarLista(lista, nuevaLista);

		// Entro al hijo primero sino es null
		if (cargos->hijo != NULL)
			iterarArbol_Anadir_a_Lista(cargos->hijo, lista);
		
		if(cargos->hermano_sig != NULL)
			iterarArbol_Anadir_a_Lista(cargos->hermano_sig, lista);
	}

}

Cargo eliminaHermanosSig_Y_Hijos(Cargo cargos) {
// Dado un cargo raiz pasado, eliminar ese cargo y todo lo que este unido.

	// Si estoy en un cargo null devuelvo null
	if (cargos == NULL) {
		return NULL;
	}

	// Entro en los cargos hijo si tengo
	if(cargos->hijo != NULL) {
		eliminaHermanosSig_Y_Hijos(cargos->hijo);
		cargos->hijo = NULL;
	}

	if(cargos->hermano_sig != NULL) {
		eliminaHermanosSig_Y_Hijos(cargos->hermano_sig);
	}

	// En este punto ya me meti en todo lo posible asi que puedo eliminar nodo

	EliminarEmpleadosLista(cargos->empleados); // Empiezo eliminando la lista de empleados
	delete[] cargos->nombre; // Elimino la string
	delete cargos; // Elimino el nodo 
	return NULL; 
}

void EliminaPersonaDeCargo (Cargo cargo, Cadena ci){
	EliminarEmpleadoPorCI(cargo->empleados, ci);
}

void AsignoPersonaCargo (Cargo &cargos, Cadena ci, Cadena nombre){
	cargos -> empleados = consEmpleado(cargos->empleados, ci, nombre);
}

bool eliminarCargoSeleccionado(Cargo cargo_a_eliminar){
	Cargo cargo_padre, cargo_hermano_ant, cargo_hermano_sig, aux; // Declaro variables
	
	if(cargo_a_eliminar->padre == NULL) {// Compruebo que no sea el primer cargo
		return false;
	}

	if(cargo_a_eliminar->hermano_sig == NULL && cargo_a_eliminar->hermano_ant == NULL) { // Si el cargo a eliminar no tiene hermanos
		cargo_padre = cargo_a_eliminar->padre;
		cargo_padre->hijo = NULL;
	}
	else { // Compruebo las diferentes situaciones que se pueden dar en el nodo
		if(cargo_a_eliminar->hermano_ant == NULL && cargo_a_eliminar->hermano_sig != NULL){ // Sino tiene un hermano anterior pero si uno siguiente
			cargo_hermano_sig = cargo_a_eliminar->hermano_sig;	// Apunto el padre al hermano siguiente y me quedo con el del medio
			cargo_padre = cargo_a_eliminar->padre; 
			
			cargo_padre->hijo = cargo_hermano_sig;
			cargo_hermano_sig->hermano_ant=NULL;
		}
		else if(cargo_a_eliminar->hermano_ant != NULL && cargo_a_eliminar->hermano_sig == NULL){
			cargo_hermano_ant = cargo_a_eliminar->hermano_ant;
			cargo_hermano_ant->hermano_sig = NULL;
		}
		else {
			cargo_hermano_ant = cargo_a_eliminar->hermano_ant;
			cargo_hermano_sig = cargo_a_eliminar->hermano_sig;

			cargo_hermano_ant->hermano_sig = cargo_hermano_sig;
		}
	

	}

	//Entro en una funcion recursiva que elimina todo los cargos que le pase incluyendo hermanos y demas
	if(cargo_a_eliminar->hijo != NULL) 	{
		cargo_a_eliminar->hijo = eliminaHermanosSig_Y_Hijos(cargo_a_eliminar->hijo); // Elimino todo desde ese cargo
	}

	

	EliminarEmpleadosLista(cargo_a_eliminar->empleados); // Empiezo eliminando la lista de empleados
	delete[] cargo_a_eliminar->nombre; // Elimino la string
	delete cargo_a_eliminar; // Elimino el nodo 

	return true;
}


void ReasignaEmpleadoEnCargo (Cargo Cdesde, Cargo Cpara, Cadena ci){
	ReasignaEmpleado(Cdesde->empleados, Cpara->empleados, ci);
}

void ListaEmpleadosCargo (Cargo cargo){
	ListaEmpleados(cargo->empleados);
}


//_______Funciones tipo ifExiste

bool ifCargoExiste(Cadena cargo, Cargo cargos_lista) {

	if(cargo == NULL) {
		return false;
	} else if(strcasecmp(cargos_lista->nombre, cargo) == 0) {
		return true;
	} else if(cargos_lista->hijo != NULL && cargos_lista->hermano_sig != NULL) {
		return (ifCargoExiste(cargo, cargos_lista->hijo) || ifCargoExiste(cargo, cargos_lista->hermano_sig));
	} else if(cargos_lista->hijo != NULL && cargos_lista->hermano_sig == NULL) {
		return ifCargoExiste(cargo, cargos_lista->hijo);
	} else if(cargos_lista->hijo == NULL && cargos_lista->hermano_sig != NULL) {
		return ifCargoExiste(cargo, cargos_lista->hermano_sig);
	} else if(cargos_lista->hijo == NULL && cargos_lista->hermano_sig == NULL) {
		return false;
	}
	return false;
}

bool existePersonaEmpresa(Cargo cargo_iter, Cadena ci){
	// Esta funcion verifica si existe la CI como persona empleada en toda la empresa

	bool retorno = false;	
	while (cargo_iter != NULL and !retorno){//Mientras cargo donde estoy no es NULL y aún no encontre a la persona sigo iterando		
		retorno = EsEmpleado (cargo_iter->empleados, ci);//En cada nodo verifico si Ci existe usando funcion pertenece de empleado.h		
		if (cargo_iter->hijo != NULL) { //Si tengo hijo avanzo a ese hijo
			cargo_iter = cargo_iter->hijo;
		}
		else if (cargo_iter->hermano_sig != NULL){//No tiene hijo pero tiene hermano_sig, voy a ese hermano_sig
			cargo_iter = cargo_iter->hermano_sig;
		}
		else {//Si estoy en una hoja sin hijo/hermano_sig, retrocedo a padre  			
			while (cargo_iter != NULL && cargo_iter ->hermano_sig == NULL){
				cargo_iter = cargo_iter ->padre;
			}
			if (cargo_iter != NULL){//itero en siguiente hermano_sig
				cargo_iter = cargo_iter -> hermano_sig;
			}
		}
	}
	// Si en algún ciclo encontre a la persona, se acaba while y retorno será true
	return retorno;
}

bool EsEmpleadoEnCargo(Cargo cargo, Cadena ci){
	return EsEmpleado (cargo->empleados, ci);
}