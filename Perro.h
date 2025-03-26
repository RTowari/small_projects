#ifndef PERRO
#define PERRO

#include <string>
#include "Mascota.h"
#include "RazaPerro.h"

using namespace std;

class Perro: public Mascota{
    private:
        RazaPerro raza;
        bool vacunaCachorro;
    public:
        Perro();
        Perro(string, Genero, float, RazaPerro, bool);

        RazaPerro getRazaPerro();
        void setRazaPerro(RazaPerro);

        bool getvacunaCachorro();
        void setvacunaCachorro(bool);

        ~Perro();

        float obtenerRacionDiaria(float);
        
};


#endif