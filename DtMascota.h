#ifndef DTMASCOTA
#define DTMASCOTA

#include <string>
#include "Genero.h"

using namespace std;

class DtMascota{
    protected:
        string nombre;
        Genero genero;
        float peso;
        float racionDiaria;
    public:
        DtMascota();
        DtMascota(string, Genero, float, float);
        string getnombre();
        Genero getgenero();
        float getpeso();
        float getracionDiaria();

        virtual ~DtMascota();

};

#endif