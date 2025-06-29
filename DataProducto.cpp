#include "DataProducto.h"

DataProducto::DataProducto() {
}

DataProducto::DataProducto(const DataProducto& orig) {
}

DataProducto::~DataProducto() {
}

DataProducto::DataProducto(float precio ,string nombre, int codigoP, int cant) {
    this->precio = precio;
    this->nombre = nombre;
    this->coste = precio*cant;
    this->cant = cant;
    this->codigo = codigoP;
}

bool DataProducto::operator<(const DataProducto& other) const {
    // Comparar por código del producto
    return this->codigo < other.codigo;
}

string DataProducto::getInfo(){
    return this->nombre + " " + to_string(this->coste);
}

