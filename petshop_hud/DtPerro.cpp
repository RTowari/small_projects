#include "DtPerro.h"

DtPerro::DtPerro(){}
DtPerro::DtPerro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacuna, float racionDiaria):
DtMascota(nombre,genero,peso,racionDiaria){
    this->raza = raza; 
    this->vacunaCachorro = vacuna;
}

RazaPerro DtPerro::getraza(){
    return this->raza;
}

bool DtPerro::getvacunaCachorro(){
    return this->vacunaCachorro;
}

DtPerro::~DtPerro(){}