#ifndef DTCONSULTA
#define DTCONSULTA

#include <string>
#include "DtFecha.h"

using namespace std;

class DtConsulta{
    protected:
        DtFecha fechaConsulta;
        string Motivo;
    public:
        DtConsulta();
        DtConsulta(DtFecha, string);
        DtFecha getfechaConsulta();
        string getMotivo();

        virtual ~DtConsulta();

        friend ostream& operator << (ostream&,const DtConsulta&);

};

#endif