#ifndef MASCOTA
#define MASCOTA

#include <string>
#include "Genero.h"

using namespace std;

class Mascota{
    private:
        string nombre;
        Genero genero;
        float peso;
    public:
        Mascota();
        Mascota(string, Genero, float);
        
        string getNombre();
        void setNombre(string);

        Genero getGenero();
        void setGenero(Genero);

        float getPeso();
        void setPeso(float);

        ~Mascota();

        virtual float obtenerRacionDiaria(float)=0;

};

#endif