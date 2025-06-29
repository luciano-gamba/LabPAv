#include "DataDireccion.h"

DataDireccion::DataDireccion() {
}

DataDireccion::DataDireccion(const DataDireccion& orig) {
}

DataDireccion::~DataDireccion() {
}

DataDireccion::DataDireccion(int puerta, string calle){
    
}
string DataDireccion::getInfoDireccion(){
    return this->nomCalle + " " + to_string(this->numPuerta);
}