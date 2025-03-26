#include "DtGato.h"
#include "TipoPelo.h"

DtGato::DtGato(){}
DtGato::DtGato(string nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo):
DtMascota(nombre, genero, peso, racionDiaria){
    this->tipoPelo = tipoPelo;
}

TipoPelo DtGato::getTipoPelo(){
    return this->tipoPelo;
}

DtGato::~DtGato(){}