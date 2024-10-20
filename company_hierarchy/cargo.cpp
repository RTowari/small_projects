#include <stdio.h>
#include <iostream>
#include <string.h>


#include "definiciones.h"
#include "cargo.h"

using namespace std;

TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo){
	
	if(ifCargoExiste(nuevoCargo, getEmpresaRaiz(e))) {
		return ERROR;
	}
	
	// Busco el cargo con el mismo nombre
	Cargo cargoPadre_nodo = getEmpresaRaiz(e);
	cargoPadre_nodo = iteradorEmpresa(cargoPadre, cargoPadre_nodo);

	// Asigno el nuevo nodo como hijo
	if (cargoPadre_nodo == NULL) {
		cout << ERROR << endl;
	} else {
		Cargo nuevoHijo_nodo = definirCargo(nuevoCargo);
		AsignarCargoHijo(nuevoHijo_nodo, cargoPadre_nodo);
	}


	return OK;
}

TipoRet EliminarCargo(Empresa &e, Cadena cargo){
// Eliminar un cargo, junto con sus subcargos y personas asociadas.
// Elimina un cargo en la empresa si cargo ya existe en la misma.
// En otro caso la operación quedará sin efecto.
// Si el cargo a eliminar posee subcargos, éstos deberán ser eliminados también, así como
// las personas asociadas a cada uno de los cargos suprimidos.
	
	Cargo cargo_a_eliminar, cargo_padre, cargo_hermano_ant, cargo_hermano_sig; // Declaro variables

	cargo_a_eliminar = getEmpresaRaiz(e); // Tomo el cargo raiz de la empresa

	if(!ifCargoExiste) // Compruebo que el cargo existe
		return ERROR;
	if(cargo_a_eliminar->padre == NULL) // Compruebo que no sea el primer cargo
		return ERROR;

	cargo_a_eliminar = iteradorEmpresa(cargo, cargo_a_eliminar); // Busco el cargo que quiero eliminar. Esta enlazado a todo su subarbol

	// Empiezo a modificar los nodos para no quedarme con punteros a direcciones liberadas
	if (cargo_a_eliminar->hermano_ant == NULL) { // Si el nodo no tiene un hermano anterior
		cargo_padre = cargo_a_eliminar->padre; // Me guardo el padre
		cargo_padre->hijo = NULL; // El padre pasa a no tener hijos.
	}
	else { // Si el cargo tiene un hermano anterior
		if(cargo_a_eliminar->hermano_sig == NULL) { // Si el cargo a eliminar no tiene un hermano sig
			cargo_hermano_ant = NULL; // Apunto a NULL el hermano ANTERIOR del cargo a eliminar
		}
		else { // Si el cargo tiene un hermano anterior y un hermano siguiente
			cargo_hermano_ant->hermano_sig = cargo_hermano_sig; // Me salto el del medio, que es el que quiero eliminar
		}
	}
	
	//Entro en una funcion recursiva que elimina todo los cargos que le pase
	eliminarCargosDesde(cargo_a_eliminar);


	
	return OK;
}

TipoRet ListarJerarquia(Empresa e){
// Listar todos los cargos de la empresa en orden jerárquico. 
// Lista todos los cargos de la empresa ordenados por nivel jerárquico e indentados
// según se muestra el ejemplo de la letra. 

	Cargo cargos = getEmpresaRaiz(e);
	

	imprimirArbolCargos(cargos, 0);
	
	return OK;
}

TipoRet ListarCargosAlf(Empresa e){
// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo.

	// Creo una lista que es la que voy a ordenar
	listaSimple lista = definirListaSimple();
	
	// A partir de ahora itero en todos los cargos y voy añadiendo nodos
	Cargo cargos = getEmpresaRaiz(e);
	ArbolCargo_A_ListaCargo(cargos, lista);


	// Empiezo la funcion de ordenar;
	lista = ordenarListaAlf(lista);

	// Imprimo la litra en orden alfabetico
	imprimeListaSimple(lista);

	return OK;
}

TipoRet ListarSuperCargos (Empresa e, Cadena cargo){
// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo. 
	
	// Compruebo que el cargo al que quiero llegar existe
	if(!ifCargoExiste(cargo, getEmpresaRaiz(e))) {
		return ERROR;
	}
	
	// Entro en una funcion para imprimirlo
	Cargo cargos = getEmpresaRaiz(e);
	imprimirArbolCargosHasta(cargos, cargo, 0);
	
	return OK;
}

TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci){
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo siempre que el cargo 
// exista en la empresa y esa persona no este asignada a ese u otro cargo, en caso contrario la operación 
// quedara sin efecto.

	// Pido el primer cargo
	Cargo cargo_nodo = getEmpresaRaiz(e);

	if((!ifCargoExiste(cargo, getEmpresaRaiz(e))) || (existePersonaEmpresa(e,ci))) {
		return ERROR;
	}
	
	// se posiciona en cargo que debe asignar persona
	cargo_nodo = iteradorEmpresa(cargo, cargo_nodo);
	// asigna persona usando el cons empleado de empleados.h
	cargo_nodo->empleados = cons(cargo_nodo->empleados, ci, nom);
	
	return OK;
}

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci){
	if(!ifCargoExiste(cargo,getEmpresaRaiz(e)))	{
		return ERROR;
	}
	if (!existePersonaEmpresa(e,ci)){
		return ERROR;
	}
	//Se posiciona en cargo que debe asignar persona
	Cargo cargo_nodo = getEmpresaRaiz(e);
	Cargo cargo_asignar = iteradorEmpresa(cargo, cargo_nodo);
	if (EsEmpleado(cargo_asignar->empleados,ci)){
		return ERROR;
	}
	Cargo raiz = getEmpresaRaiz(e);
	//Busco cargo que debo desasignar
	Cargo cargo_desasignar = BuscaCargoPersona(raiz,ci);
	ReasignaEmpleado(cargo_desasignar ->empleados,cargo_asignar ->empleados,ci);
	return OK;
}

TipoRet EliminarPersona(Empresa &e, Cadena ci){
// Eliminar una persona de un cargo.
// Elimina una persona de cédula ci de la empresa siempre y cuando la misma exista,
// en caso contrario la operación quedará sin efecto.
	// Llama a una funcion que itera por toda la empresa para eliminar la cedula
	
	Cargo cargos = getEmpresaRaiz(e);  // Obtengo el cargo raiz

	// Compruebo que la persona existe
	if(!EsEmpleado(cargos->empleados, ci))
		return ERROR;
	
	Cargo cargo_con_persona = BuscaCargoPersona(cargos, ci); // Busco el cargo con esa persona (Gracias por esta funcion Mauro)
	EliminarEmpleadoPorCI(cargo_con_persona->empleados, ci); // Mando el cargo y la ci para eliminar el empleado

    return OK;
}

TipoRet ListarPersonas(Empresa e, Cadena cargo){
// Dado un cargo listar las personas asignadas al mismo ordenadas por fecha de alta a la empresa. 
// Lista todas las personas asignadas al cargo de nombre cargo. 

	if(!ifCargoExiste(cargo, getEmpresaRaiz(e))){
		return ERROR;
	}	
	else{
		Cargo c = iteradorEmpresa(cargo, getEmpresaRaiz(e)); //Encuentro cargo con el nombre pasado por parametro
		ListaEmpleados(c->empleados);//Manda imprimir a la funcion de empleados .h pasando la lista de empleados
	}
	return OK;
}



//________Funciones de imprimir 

void imprimirArbolCargosHasta(Cargo cargos, Cadena car_nom, int ident) {
// Imprime el arbol hasta el cargo pasado (no incluye el cargo pasado)

	// Me muevo recursivamente e imprimo hasta que encuentra un cargo con el mismo nombre
	if( strcmp ( getCarNom(cargos), car_nom ) == 0 ) {
		return;
	}
	else {
		// Esta parte pone la identacion segun avanza el programa
		imprimirIdent(ident);
		cout << "->" << getCarNom(cargos) << endl;

		if(cargos->hijo != NULL) {
			imprimirArbolCargosHasta(cargos->hijo, car_nom, ident + 2);
		}

		if(cargos->hermano_sig != NULL) {
			imprimirArbolCargosHasta(cargos->hermano_sig, car_nom, ident + 2);
		}
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

	if(strcmp(cargos->nombre, cargo) == 0) { // Encontre un cargo con el mismo nombre
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
}

Cargo iteradorCargohermano_sigs(Cargo cargos) {
	// Itera hasta el final de la lista de cargos hijos y devuelve el ultimo miembro

	if(cargos->hermano_sig == NULL) {
		return cargos;
	}
	else if(cargos->hermano_sig != NULL) {
		return (iteradorCargohermano_sigs(cargos->hermano_sig));
	}
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
	// Si el cargo padre ya tiene hijos itero hasta el final de esa lista
	} else {
		Cargo cargo_hermano_sig = iteradorCargohermano_sigs(cargo_padre->hijo); // Busco el ultimo cargo de la lista de hijos
		cargo_hermano_sig->hermano_sig = cargo_hijo; // Asigno el cargo que debo poner a lo ultimo de la lista
		cargo_hijo->hermano_ant = cargo_hermano_sig; // Al nuevo cargo que puse le asigno el hermano anterior

		cargo_hijo->padre = cargo_padre; // Señalo quien es el padre de este cargo
	}
}

void ArbolCargo_A_ListaCargo(Cargo cargos, listaSimple &lista) {
	if(cargos==NULL) {
		return;	
	}
	else {
		
		// Creo un nodo de tipo lista con los datos del nodo de cargos
		listaSimple nuevaLista = new(nodo_listaSimple);
		Cadena nombre = getCarNom(cargos);
		setNom(nuevaLista, nombre);
		nuevaLista->sig=NULL;

		// Si estoy en una lista que no se inicializo
		if(lista == NULL) {
			lista = nuevaLista;
		}
		else {
			nuevaLista->sig = lista;
			lista = nuevaLista;
		}


		// Entro al hijo primero sino es null
		if (cargos->hijo != NULL)
			ArbolCargo_A_ListaCargo(cargos->hijo, lista);
		
		if(cargos->hermano_sig != NULL) {
			ArbolCargo_A_ListaCargo(cargos->hermano_sig, lista);
		}
	}

	
}

Cargo eliminarCargosDesde(Cargo cargos){
// Dado un cargo, eliminarlo a este y todo lo que tiene por debajo (NO ELIMINO LOS HERMANOS EN ESTA FUNCION. USAR CON SEGURIDAD)
	
	eliminarCargos_Y_Parientes(cargos->hijo); // La funcion que paso elimina todo si o si

	// Elimino el nodo con tranquilidad
	EliminarEmpleadosLista(cargos->empleados); // Empiezo eliminando la lista de empleados
	delete[] cargos->nombre; // Elimino la string
	delete cargos; // Elimino el nodo 
	return NULL; 
}

Cargo eliminarCargos_Y_Parientes(Cargo cargos) {
// Dado un cargo raiz pasado, eliminar ese cargo y todo lo que este unido. (ELIMINA HERMANOS TAMBIEN)

	// Si estoy en un cargo null devuelvo null
	if (cargos == NULL) {
		return NULL;
	}

	// Entro en los cargos hijo si no estoy al final
	if(cargos->hijo != NULL) {
		eliminarCargosDesde(cargos->hijo);
		cargos->hijo = NULL;
	}

	// Entro en los cargos padre si no estoy al final
	if(cargos->hermano_sig != NULL) {
		eliminarCargosDesde(cargos->hermano_sig);
	}

	// En este punto ya me meti en todo lo posible asi que puedo eliminar nodo

	EliminarEmpleadosLista(cargos->empleados); // Empiezo eliminando la lista de empleados
	delete[] cargos->nombre; // Elimino la string
	delete cargos; // Elimino el nodo 
	return NULL; 
}



//_______Funciones tipo ifExiste

bool ifCargoExiste(Cadena cargo, Cargo cargos_lista) {

	if(cargo == NULL) {
		return false;
	} else if(strcmp(cargos_lista->nombre, cargo) == 0) {
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
}

bool existePersonaEmpresa(Empresa e, Cadena ci){
	// Esta funcion verifica si existe la CI como persona empleada en toda la empresa

	Cargo cargo_iter = getEmpresaRaiz(e);//Cargo para iterar que inicia desde raiz
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