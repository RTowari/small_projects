#include "Perro.h"

Perro::Perro(){}
Perro::Perro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro): 
Mascota(nombre, genero, peso){
    this->raza=raza;
    this->vacunaCachorro=vacunaCachorro;
}

RazaPerro Perro::getRazaPerro(){
    return this->raza;
}
void Perro::setRazaPerro(RazaPerro raza){
    this->raza=raza;
}

bool Perro::getvacunaCachorro(){
    return this->vacunaCachorro;
}
void Perro::setvacunaCachorro(bool vacunaCachorro){
    this->vacunaCachorro=vacunaCachorro;
}

Perro::~Perro(){}

float Perro::obtenerRacionDiaria(float peso) {
    return this->getPeso()*0.025;
}