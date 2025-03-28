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
        DtPerro(string, Genero, float, RazaPerro, bool, float racionDiaria = 0);

        RazaPerro getraza();
        bool getvacunaCachorro();

        ~DtPerro();
};


#endif