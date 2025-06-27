#include "DataProducto.h"

DataProducto::DataProducto() {
}

DataProducto::DataProducto(const DataProducto& orig) {
}

DataProducto::~DataProducto() {
}

bool DataProducto::operator<(const DataProducto& other) const {
    // Comparar por código del producto
    return this->codigo < other.codigo;
}

