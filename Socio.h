#ifndef SOCIO
#define SOCIO

#define CANT_MASCOTAS 10
#define CANT_CONSULTAS 20


#include <string>
#include "DtFecha.h"
#include "Mascota.h"
#include "Consulta.h"

using namespace std;

class Socio{
    private:
        string CI;
        string nombre;
        DtFecha fechaIngreso;
        Mascota* mascotas[CANT_MASCOTAS];
        Consulta* consultas[CANT_CONSULTAS];
        int topeMascotas;
        int topeConsultas;
        int topeSocios;
    public:
        Socio();
        Socio(string, string, DtFecha);
        
        string getCI();
        void setCI(string);

        string getNombre();
        void setNombre(string);

        DtFecha getFechaIngreso();
        void setFechaIngreso(DtFecha);

        void setConsulta(Consulta*);

        ~Socio();

        void agregarMascota(Mascota*);

        Mascota** obtenerMascotas(int&);
        Consulta** obtenerConsulta(int&);

};

#endif