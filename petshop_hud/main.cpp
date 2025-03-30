#define MAX_SOCIOS 30
#include "Socio.h"
#include "Consulta.h"
#include "Mascota.h"
#include "Perro.h"
#include "Gato.h"
#include "RazaPerro.h"
#include "Genero.h"
#include "TipoPelo.h"
#include "DtConsulta.h"
#include "DtFecha.h"
#include "DtPerro.h"
#include "DtGato.h"
#include "DtMascota.h"

#include <iostream>
#include <stdexcept>

using namespace std;

// Todos los usuarios del sistema
struct{
    Socio* socios[MAX_SOCIOS];
    int topeS = 0;
} arraySocios;

// OPERACION 1 (SEMI IMPLEMENTADA)
void registrarSocio();
void registrarSocio(string, string, DtFecha); // IMPLEMENTADA
// OPERACION 2 (SEMI IMPLEMENTADA)
void agregarMascota(); //  (SEMI IMPLEMENTADA)
void agregarMascota(string ci, DtMascota& dtMascota);//SEMI IMPLEMENTADA

// OPERACIONES POR IMPLEMENTAR
void eliminarSocio() {}
void obtenerMascota() {}

// Declaraciones de funciones
void ingresarConsulta(); // NO IMPLEMENTADA 
void verConsultasAntesDeFecha(); // NO IMPLEMENTADA 
DtConsulta** verConsultasAntesDeFecha(DtFecha&, string, int&); // /(SEMI IMPLEMENTADA)
void eliminarSocio(); // NO IMPLEMENTADA 
void obtenerMascotas(); // NO IMPLEMENTADA 
void liberarMemoria(); // IMPLEMENTADA

// OPERACIONES AUXILIARES
void noExisteSocio(string ci);
Socio* obtenerSocio(string ci);
void pesoCorrecto(float);
void racionDiariaCorrecta(float);
void limpiarPantalla();
void esperarPorInput();
void imprimirMascotasDeSocio();
void opcionesExtraEnMenu();
void imprimirSociosYMascotas();


int main() {
    //van todos los topes
    int opcion;
    do {
        cout << "\n--- Bienvenido a la Veterinaria ---" << endl;
        cout << "1) Registrar socio" << endl;
        cout << "2) Agregar mascota" << endl;
        cout << "3) Ingresar consulta" << endl;
        cout << "4) Ver consultas antes de fecha" << endl;
        cout << "5) Eliminar socio" << endl;
        cout << "6) Obtener mascotas" << endl;
        cout << "7) Menu de desarrollador" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: ";

        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarSocio();
                break;
            case 2:
                agregarMascota();
                break;
            case 3:
                ingresarConsulta();
                break;
            case 4:
                cout << "NO IMPLEMENTADA" << endl;
                //verConsultasAntesDeFecha();
                break;
            case 5:
                cout << "NO IMPLEMENTADA" << endl;
                //eliminarSocio();
                break;
            case 6:
                cout << "NO IMPLEMENTADA" << endl;
                //obtenerMascotas();
                break;
            case 7:
                opcionesExtraEnMenu();
            break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo..." << endl;
                break;
        }
    } while (opcion != 0);

    liberarMemoria();
    return 0;
}


 // OPERACION 1
void registrarSocio() {
    // Variables para los datos del socio
    string socio_ci, socio_nombre;
    int dia, mes, anio;
    
    // Variables para los datos de la mascota
    string nombre_mascota;
    Genero genero;
    float peso, racionDiaria;
    bool vacunaCachorro;
    RazaPerro raza;
    TipoPelo tipoPelo;
    DtPerro dtperro;
    DtGato dtgato;
    int Perro_o_Gato;  // 1 para perro y 0 para gato

    limpiarPantalla(); // Esta funcion limpia la pantalla en linux y windows
    cout <<"________________________"<<endl;
    cout <<"____REGISTRO_DE_SOCIO____"<< endl;
    

    cout << "\nCI: ";
    cin >> socio_ci;

    try {

        // Me aseguro de que el socio no existe y de que tengo espacios para agregar mas socios
        noExisteSocio(socio_ci); // Esta funcion devuelve error si el socio ya existe
        
        int tope;
        tope = arraySocios.topeS;
        if (tope==MAX_SOCIOS) // Si ya tengo la maxima cantidad de socios
            throw invalid_argument("\nERROR: HAY DEMASIADOS USUARIOS EN EL SISTEMA\n");

        cout << "NOMBRE: ";
        cin >> socio_nombre;

        cout << "\nFECHA DE INGRESO" << endl;
        cout << "DIA: ";
        cin >> dia;

        cout << "MES: ";
        cin >> mes;

        cout << "ANIO: ";
        cin >> anio;

        DtFecha fecha = DtFecha(dia, mes, anio);
                
        // pide los datos de la mascota
        cout <<"____REGISTRO_DE_MASCOTA____"<< endl;

        cout << "NOMBRE MASCOTA: ";
        cin >> nombre_mascota;

        int opGenero;
        cout << "\nGENERO?\n\t1.Macho\n\t2.Hembra\nINDIQUE: ";
							cin >> opGenero;
							
							switch(opGenero){
								case 1: genero=MACHO;
										break;
								case 2: genero=HEMBRA;
										break;
							}

        cout << "\nPESO (kg):" << endl;
        cin >> peso;
        try{
            pesoCorrecto(peso);

                int opMascota, opVacuna, opPelo;				
				cout << "\nTIPO DE MASCOTA" << endl << "\t1.Perro\n\t2.Gato\nINDIQUE: ";
				cin >> opMascota;
				
				switch(opMascota){
					case 1:	Perro_o_Gato = 1;
                            cout << "\nTIENE VACUNA?\n\t1.Si\n\t2.No\nINDIQUE: ";
							cin >> opVacuna;							
							vacunaCachorro = (opVacuna == 1);

                            int opRaza;
                            cout << "\nINGRESE RAZA:\n\t1.Labrador\n\t2.Ovejero\n\t3.Bulldog\n\t4.Pitbull\n\t5.Collie\n\t6.Pekines\n\t7.Otro\nINDIQUE: ";    
							cin >> opRaza;
							
							switch(opRaza){
								case 1: raza=LABRADOR;
										break;
								case 2: raza=OVEJERO;
                                        break;
                                case 3: raza=BULLDOG;
										break;
                                case 4: raza=PITBULL;
                                        break;
                                case 5: raza=COLLIE;
                                        break;
                                case 6: raza=PEKINES;
                                        break;
                                case 7: raza=OTRO;
                                        break;
							}
                            break;


					case 2: Perro_o_Gato = 0;
                        cout << "\nTIPO DE PELO?\n\t1.Corto\n\t2.Mediano\n\t3.Largo\nINDIQUE: ";
						cin >> opPelo;
						
						switch(opPelo){
							case 1: tipoPelo=CORTO;
								break;
							case 2: tipoPelo=MEDIANO;
								break;
                                case 3: tipoPelo=LARGO;
									break;
						}
                        break;

                            
				}

        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
        }    

        // Pongo al socio en la array
        registrarSocio(socio_ci, socio_nombre, fecha);
        cout << "\nSe ha registrado en el Sistema al socio " << socio_nombre << " de CI " << socio_ci << " correctamente\n";

        // Pongo a la mascota en el socio
        if(Perro_o_Gato == 1) {
            dtperro = DtPerro(nombre_mascota,genero,peso,raza,vacunaCachorro);
            agregarMascota(socio_ci, dtperro);
        }
        else {
            dtgato = DtGato(nombre_mascota,genero,peso,tipoPelo);
            agregarMascota(socio_ci, dtgato);
        }

        cout << "\nSe ha registrado en el Sistema la mascota " << nombre_mascota << " del socio CI " << socio_ci << " correctamente\n";


        esperarPorInput(); // lee el enter del usuario en linux y windows
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
    }
}

 // OPERACION 2
 void agregarMascota() {

    limpiarPantalla(); // Esta funcion limpia la pantalla en linux y windows
    cout <<"________________________"<<endl;
    cout <<"____REGISTRO_DE_MASCOTA____"<< endl;
    
    string nombre_mascota, socio_ci;
    Genero genero;
    float peso, racionDiaria;
    bool vacunaCachorro;
    int Perro_o_Gato;
    RazaPerro raza;
    TipoPelo tipoPelo;
	DtPerro dtperro;
	DtGato dtgato;

    cout << "\nCI: ";
    cin >> socio_ci;

    try {
        Socio* validaSocio = obtenerSocio(socio_ci);
        
        cout << "NOMBRE MASCOTA: ";
        cin >> nombre_mascota;

        int opGenero;
        cout << "\nGENERO?\n\t1.Macho\n\t2.Hembra\nINDIQUE: ";
							cin >> opGenero;
							
							switch(opGenero){
								case 1: genero=MACHO;
										break;
								case 2: genero=HEMBRA;
										break;
							}

        cout << "\nPESO (kg):" << endl;
        cin >> peso;
        try{
            pesoCorrecto(peso);

                int opMascota, opVacuna, opPelo;				
				cout << "\nTIPO DE MASCOTA" << endl << "\t1.Perro\n\t2.Gato\nINDIQUE: ";
				cin >> opMascota;
				
				switch(opMascota){
					case 1:	cout << "\nTIENE VACUNA?\n\t1.Si\n\t2.No\nINDIQUE: ";
							cin >> opVacuna;							
							vacunaCachorro = (opVacuna == 1);

                            int opRaza;
                            cout << "\nINGRESE RAZA:\n\t1.Labrador\n\t2.Ovejero\n\t3.Bulldog\n\t4.Pitbull\n\t5.Collie\n\t6.Pekines\n\t7.Otro\nINDIQUE: ";    
							cin >> opRaza;
							
							switch(opRaza){
								case 1: raza=LABRADOR;
										break;
								case 2: raza=OVEJERO;
                                        break;
                                case 3: raza=BULLDOG;
										break;
                                case 4: raza=PITBULL;
                                        break;
                                case 5: raza=COLLIE;
                                        break;
                                case 6: raza=PEKINES;
                                        break;
                                case 7: raza=OTRO;
                                        break;
							}

							dtperro = DtPerro(nombre_mascota,genero,peso,raza,vacunaCachorro);
							agregarMascota(socio_ci, dtperro);
							break;
					case 2: cout << "\nTIPO DE PELO?\n\t1.Corto\n\t2.Mediano\n\t3.Largo\nINDIQUE: ";
							cin >> opPelo;
							
							switch(opPelo){
								case 1: tipoPelo=CORTO;
										break;
								case 2: tipoPelo=MEDIANO;
										break;
                                case 3: tipoPelo=LARGO;
										break;
							}
                            dtgato = DtGato(nombre_mascota,genero,peso,tipoPelo);
							agregarMascota(socio_ci, dtgato);
							break;
				}
                cout << "\nSe ha registrado en el Sistema la mascota " << nombre_mascota << " del socio CI " << socio_ci << " correctamente\n";
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
        }                  
      
        esperarPorInput(); // lee el enter del usuario en linux y windows
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
    }
}

// OPERACION 3
void ingresarConsulta() {
            
        limpiarPantalla(); // Esta funcion limpia la pantalla en linux y windows

        cout <<"________________________"<<endl;
        cout <<"____REGISTRO_DE_MASCOTA____"<< endl;

        string motivo, ci;
        int dia, mes, anio;

        cout << "\nINGRESE CI: ";
        cin >> ci;

    try{   
        Socio* s = obtenerSocio(ci);
        
        cin.ignore();

        cout << "\nMOTIVO DE LA CONSULTA: ";
        getline(cin, motivo);
        
        cout << "\nFECHA DE LA CONSULTA: " << endl;
        cout << "DIA: ";
        cin >> dia;
        cout << "MES: ";
        cin >> mes;
        cout << "ANIO: ";
        cin >> anio;
        
        DtFecha fecha = DtFecha(dia, mes, anio);         //en la letra el cabezal de la funcion no pide fecha (?
        
        Consulta* c = new Consulta(fecha, motivo);
        s->setConsulta(c);

        cout << "\nConsulta registrada con exito para el socio: " << s->getNombre() << " -CI: " << s->getCI() << "\n-MOTIVO: " << c->getMotivo() << endl;
        cout << "\n" << endl;
        
        esperarPorInput(); // lee el enter del usuario en linux y windows

    }catch(invalid_argument& e){
        cout << e.what() << endl;
    }  

}

// Operación 4

void verConsultasAntesDeFecha() {

    limpiarPantalla();
    cout << "________________________" << endl;
    cout << "__VER__CONSULTAS__ANTES__DE__FECHA__" << endl;

    string socio_ci;
    int dia, mes, anio, cantConsultas;
    DtFecha dtFecha;

    cout << "\nCI: ";
    cin >> socio_ci;


    try {
       /* obtenerSocio(socio_ci);
        cout << "Cantidad de socios registrados: " << arraySocios.topeS<< endl;

       if (true)
            cout << "\nsi existe socio en el sistema con la CI " << socio_ci << " .\n";
        else
        
        cout << "\nno existe socio en el sistema con la CI " << socio_ci << " .\n";
        esperarPorInput();// lee el enter del usuario en linux y windows  No me aparece para comprobar si existe o no la ci*/
 
        cout << "\nANTES DE LA FECHA" << endl;
        cout << "DIA: ";
        cin >> dia;
        cout << "MES: ";
        cin >> mes;
        cout << "ANIO: ";
        cin >> anio;

            if (dia <= 0 || mes <= 0 || mes > 12 || anio <= 0) {
                throw invalid_argument("Error: Fecha ingresada no valida.");
            }
        
        
        dtFecha = DtFecha(dia, mes, anio);

        cout << "\nCONSULTAS ANTES DE " << dtFecha << ": " << endl;

        DtConsulta** consultasFecha = verConsultasAntesDeFecha(dtFecha, socio_ci, cantConsultas);

        if (cantConsultas == 0) {
            cout << "No hay consultas antes de " << dtFecha << "." << endl;
        } else {
            for (int i = 0; i < cantConsultas; i++) {
                cout << "\nFecha: " << consultasFecha[i]->getfechaConsulta()
                     << " | Motivo: " << consultasFecha[i]->getMotivo();
                delete consultasFecha[i];
            }
        }

        delete[] consultasFecha;

        esperarPorInput();// lee el enter del usuario en linux y windows

    } catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
}

// OPERACIONES A IMPLEMENTAR
void registrarSocio(string ci, string nombre, DtFecha fecha) {
    Socio* socio = new Socio(ci,nombre,fecha);
    arraySocios.socios[arraySocios.topeS] = socio;
    arraySocios.topeS++;
}
void agregarMascota(string ci, DtMascota& mascota){
    try{
        DtPerro& dtPerro = dynamic_cast<DtPerro&>(mascota);
        Perro* perro = new Perro(dtPerro.getnombre(),dtPerro.getgenero(),dtPerro.getpeso(),dtPerro.getraza(),dtPerro.getvacunaCachorro());
        
        Socio* socio = obtenerSocio(ci);
        socio->agregarMascota(perro);
    }catch(bad_cast){
    try{
        DtGato& dtGato = dynamic_cast<DtGato&>(mascota);
        Gato* gato = new Gato(dtGato.getnombre(),dtGato.getgenero(),dtGato.getpeso(),dtGato.getTipoPelo());
        
        try{
            Socio* socio = obtenerSocio(ci);
            socio->agregarMascota(gato);
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
        }  
        
    }catch(bad_cast){}    
    }
}

DtConsulta** verConsultasAntesDeFecha(DtFecha& dtFecha, string ci, int& cantConsultas) {
    cantConsultas = 0;
    Socio* socio = obtenerSocio(ci);

    int cantidad;
    Consulta** consultas = socio->obtenerConsulta(cantidad);
    DtConsulta** dtConsultas = new DtConsulta*[cantidad];

    int i = 0;
    while (i < cantidad) {
        if (consultas[i]->getfechaConsulta() < dtFecha) {
            dtConsultas[cantConsultas] = new DtConsulta(consultas[i]->getfechaConsulta(), consultas[i]->getMotivo());
            cantConsultas++;
        }
        i++;
    }

    return dtConsultas;
}

// OPERACIONES AUXILIARES
void noExisteSocio(string ci) {
    int i=0;
    bool existe=false;
    while((i<arraySocios.topeS)&&(!existe)){

        if(ci == arraySocios.socios[i]->getCI()){
            existe=true;
        }
        i++;
    }
    if (existe)
        throw invalid_argument("\nERROR: YA EXISTE USUARIO CON ESA CI EN EL SISTEMA\n");
}

Socio* obtenerSocio(string ci){
	Socio* socioObtenido;
	int i=0;
	bool existe=false;
	while((i<arraySocios.topeS)&&(!existe)){
		if(ci == arraySocios.socios[i]->getCI()){
			socioObtenido=arraySocios.socios[i];
			existe=true;
		}
		i++;
	}

	if(existe) 
        return socioObtenido;
    else
        throw invalid_argument("\nERROR: NO EXISTE USUARIO CON ESA CI EN EL SISTEMA\n");
}

void limpiarPantalla(){
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear");
    #endif
}

void esperarPorInput() {
    #ifdef _WIN32
        system("pause");
    #else
        system("read -p \"Press enter to continue...\" X");
    #endif
}

// Esta funcion imprime todas las mascotas de un socio
void imprimirMascotasDeSocio() {
    cout << "IMPRIME LAS MASCOTAS DE UN SOCIO" << endl;
    cout << "CI:";

    string socio_ci;
    cin >> socio_ci;
    
    try {
    // Voy a buscar el socio con esta cedula en el sistema
        Socio* socioObtenido;
        socioObtenido = obtenerSocio(socio_ci);

        // Consigo la lista de mascotas del socio y el numero de estas que tiene
        int cantidadMascotas;
        Mascota** listaMascotas = socioObtenido->obtenerMascotas(cantidadMascotas);

        for(int i=0; i<cantidadMascotas; i++) {
            cout << "NOMBRE: " << listaMascotas[i]->getNombre() << " | " 
            << "GENERO: " << listaMascotas[i]->getGenero() << " | "
            << "PESO: " << listaMascotas[i]->getPeso() << " | "
            << endl;

            // Me fijo si tengo un perro usando cast
            try{
                Perro& perro = dynamic_cast<Perro&>(*listaMascotas[i]);
                cout << "RAZA: " << perro.getRazaPerro() << " | "
                << "TIENE VACUNA: " << perro.getvacunaCachorro() << endl;
                cout << "_______________________________" << endl;
            } 
            catch(bad_cast) { 
            }
            // Me fijo si tengo un gato usando cast
            try{
                Gato& gato = dynamic_cast<Gato&>(*listaMascotas[i]);
                cout << "TIPO DE PELO: " << gato.gettipoPelo() << endl;
                cout << "_______________________________" << endl;
            } 
            catch(bad_cast) { 
            }
        }


    } catch(invalid_argument& e){
        cout << e.what() << endl;
    }
}

void imprimirSociosYMascotas(){
    cout << "IMPRIME SOCIOS Y SUS MASCOTAS" << endl;

    int tope = arraySocios.topeS;
    for(int i=0; i < tope; i++){
        Socio* socioActual = arraySocios.socios[i];
        DtFecha fecha = socioActual->getFechaIngreso();

        cout << "___________SOCIO___________" << endl;
        cout << "CI: " << socioActual->getCI() << " | "
        << "NOMBRE: " << socioActual->getNombre() << " | "
        << "FECHA DE INGRESO: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << endl;

        // Consigo la lista de mascotas del socio y el numero de estas que tiene
        int cantidadMascotas;
        Mascota** listaMascotas = socioActual->obtenerMascotas(cantidadMascotas);

        for(int i=0; i<cantidadMascotas; i++) {
            cout << "___________MASCOTA: " << listaMascotas[i]->getNombre() << "___________" << endl;
            cout << "GENERO: " << listaMascotas[i]->getGenero() << " | "
            << "PESO: " << listaMascotas[i]->getPeso() << " | "
            << endl;

            // Me fijo si tengo un perro usando cast
            try{
                Perro& perro = dynamic_cast<Perro&>(*listaMascotas[i]);
                cout << "RAZA: " << perro.getRazaPerro() << " | "
                << "TIENE VACUNA: " << perro.getvacunaCachorro() << endl;
                cout << "_______________________________" << endl;
            } 
            catch(bad_cast) { 
            }
            // Me fijo si tengo un gato usando cast
            try{
                Gato& gato = dynamic_cast<Gato&>(*listaMascotas[i]);
                cout << "TIPO DE PELO: " << gato.gettipoPelo() << endl;
                cout << "_______________________________" << endl;
            } 
            catch(bad_cast) { 
            }
        }

    }

}

// Esta funciona agrega opciones extra en el menu para las opciones de desarrollador
void opcionesExtraEnMenu() {
    int opcion;
    do {
        
        cout << "\n--- Bienvenido a la Veterinaria ---" << endl;
        cout << "1) Imprimir mascotas de un socio" << endl;
        cout << "2) Imprimir msocios y mascotas" << endl;
        cout << "0) Salir al menu anterior" << endl;

        cin >> opcion;

        switch (opcion) {
            case 1:
                imprimirMascotasDeSocio();
                break;
            case 2:
                imprimirSociosYMascotas();
            break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo..." << endl;
                break;
        }
    } while (opcion != 0);
}

//Funcion para liberar los socios almacenados en arraySocios
void liberarMemoria() {
    for (int i = 0; i < arraySocios.topeS; ++i) {
        delete arraySocios.socios[i]; 
    }
    arraySocios.topeS = 0; 
}

void pesoCorrecto(float peso){
	if (peso<=0)
		throw invalid_argument("\nERROR: EL PESO DEBE SER MAYOR A CERO");
}
void racionDiariaCorrecta(float racion){
	if (racion<=0)
		throw invalid_argument("\nERROR: KA RACION DEBE SER MAYOR A CERO");
}
