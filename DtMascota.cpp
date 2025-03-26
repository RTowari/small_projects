#include "DtMascota.h"

DtMascota::DtMascota(){}
DtMascota::DtMascota(string nombre, Genero genero, float peso, float racionDiaria){
    this->nombre=nombre;
    this->genero=genero;
    this->peso=peso;
    this->racionDiaria;
}

string DtMascota::getnombre(){
    return this->nombre;
}

Genero DtMascota::getgenero(){
    return this->genero;
}

float DtMascota::getpeso(){
    return this->peso;
}

float DtMascota::getracionDiaria(){
    return this->racionDiaria;
}

DtMascota::~DtMascota(){}