#include "DtConsulta.h"
#include <iostream>

DtConsulta::DtConsulta() {}
DtConsulta::DtConsulta(DtFecha fechaConsulta, string Motivo) {
    this->fechaConsulta = fechaConsulta;
    this->Motivo = Motivo;
}

DtFecha DtConsulta::getfechaConsulta(){
    return this->fechaConsulta; 
}

string DtConsulta::getMotivo() {
    return this->Motivo;    
}

DtConsulta::~DtConsulta() {}

ostream& operator<<(ostream& salida, const DtConsulta& consulta) {
    salida << consulta.fechaConsulta << " / " << consulta.Motivo;
    return salida;
}