#include "Socio.h"

Socio::Socio(){}
Socio::Socio(string CI, string nombre, DtFecha fecha) {
    this->CI=CI;
    this->nombre=nombre;
    this->fechaIngreso = fecha;
    this->topeMascotas = 0;
    this->topeConsultas = 0;
}

string Socio::getCI(){
    return this->CI;
}
void Socio::setCI(string CI){
    this->CI=CI;
}

string Socio::getNombre(){
    return this->nombre;
}
void Socio::setNombre(string nombre){
    this->nombre=nombre;
}

DtFecha Socio::getFechaIngreso(){
    return this->fechaIngreso;
}
void Socio::setFechaIngreso(DtFecha fechai){
    this->fechaIngreso=fechai;
}

void Socio::setConsulta(Consulta* consulta){
    this->consultas[topeConsultas] = consulta;  
    this->topeConsultas++;
}

void Socio::agregarMascota(Mascota* mascota){
    this->mascotas[this->topeMascotas]=mascota;
    this->topeMascotas++;
}


Mascota** Socio:: obtenerMascotas(int& cantMascotas){
    cantMascotas=this->topeMascotas;
    return this->mascotas;
}

Socio::~Socio(){}