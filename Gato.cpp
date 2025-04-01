#include "Gato.h"
#include "TipoPelo.h"

Gato::Gato(){}
Gato::Gato(string nombre, Genero genero, float peso, TipoPelo tipoPelo):Mascota(nombre, genero, peso) {
    this->tipoPelo=tipoPelo;
}

TipoPelo Gato::gettipoPelo(){
    return this->tipoPelo;
}
void Gato::settipoPelo(TipoPelo){
    this->tipoPelo=tipoPelo;
}

Gato::~Gato(){}

float Gato::obtenerRacionDiaria(float peso) {
    return this->getPeso()*0.015;
}