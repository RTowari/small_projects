#ifndef DT_GATO
#define DT_GATO

#include <string>
#include "DtMascota.h"
#include "TipoPelo.h"


using namespace std;

class DtGato : public DtMascota{

    private:
        TipoPelo tipoPelo;
    public:
        DtGato();
        DtGato(string nombre, Genero genero, float peso, TipoPelo tipoPelo, float racionDiaria = 0);
        
        TipoPelo getTipoPelo();
        
        ~DtGato();
};


#endif