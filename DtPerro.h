#ifndef DTPERRO
#define DTPERRO

#include <string>
#include "DtMascota.h"
#include "RazaPerro.h"

using namespace std;

class DtPerro: public DtMascota{
    private:
        RazaPerro raza;
        bool vacunaCachorro;
    public:
        DtPerro();
        DtPerro(string, Genero, float, float, RazaPerro, bool);

        RazaPerro getraza();
        bool getvacunaCachorro();

        ~DtPerro();
};


#endif