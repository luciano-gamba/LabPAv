#include "DataDireccion.h"
#include <iostream>

DataDireccion::DataDireccion() {
}

DataDireccion::DataDireccion(const DataDireccion& orig) {
}

DataDireccion::~DataDireccion() {
}

DataDireccion::DataDireccion(int puerta, string calle){
    this->nomCalle = calle;
    this->numPuerta = puerta;
}

string DataDireccion::getInfoDireccion(){
    return this->nomCalle + "-" + to_string(this->numPuerta);
}