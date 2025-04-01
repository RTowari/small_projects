#ifndef CONSULTA
#define CONSULTA

#include <string>
#include "DtFecha.h"

using namespace std;

class Consulta{
    private:
        DtFecha fechaConsulta;
        string motivo;
        
    public:
        Consulta();
        Consulta(DtFecha, string);
        
        DtFecha getfechaConsulta();
        void setfechaConsulta(DtFecha);

        string getMotivo();
        void setMotivo(string);

        ~Consulta();


};

#endif