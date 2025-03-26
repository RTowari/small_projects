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
        DtGato(string nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo);
        
        TipoPelo getTipoPelo();
        
        ~DtGato();
};

#endif