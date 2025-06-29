#include "DataProducto.h"

DataProducto::DataProducto() {
}

DataProducto::DataProducto(const DataProducto& orig) {
}

DataProducto::~DataProducto() {
}

DataProducto::DataProducto(string codigoP, int cant) {
    this->cant = cant;
    this->codigo = codigoP;
}

bool DataProducto::operator<(const DataProducto& other) const {
    // Comparar por código del producto
    return this->codigo < other.codigo;
}

