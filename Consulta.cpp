#include "Consulta.h"

Consulta::Consulta(){}
Consulta::Consulta(DtFecha fechaConsulta, string motivo){
    this->fechaConsulta=fechaConsulta;
    this->motivo=motivo;
}

DtFecha Consulta::getfechaConsulta(){
    return this->fechaConsulta;
}
void Consulta::setfechaConsulta(DtFecha fechaConsulta){
    this->fechaConsulta=fechaConsulta;
}

string Consulta::getMotivo(){
    return this->motivo;
}
void Consulta::setMotivo(string motivo){
    this->motivo=motivo;
}