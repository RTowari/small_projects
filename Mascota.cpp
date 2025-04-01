#include "Mascota.h"

Mascota::Mascota(){}
Mascota::Mascota(string nombre, Genero gen, float peso)
{
    this->nombre=nombre;
    this->genero=gen;
    this->peso=peso;
}

void Mascota::setNombre(string nombre){
    this->nombre=nombre;
}
string Mascota::getNombre(){
    return this->nombre;    
}
void Mascota::setGenero(Genero gen){
    this->genero=gen;
}
Genero Mascota::getGenero(){
    return this->genero;    
}
void Mascota::setPeso(float peso){
    this->peso=peso;
}
float Mascota::getPeso(){
    return this->peso;    
}
Mascota::~Mascota(){}