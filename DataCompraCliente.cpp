#include "DataCompraCliente.h"

DataCompraCliente::DataCompraCliente() {
}

DataCompraCliente::DataCompraCliente(const DataCompraCliente& orig) {
}

DataCompraCliente::~DataCompraCliente() {
}

void DataCompraCliente::setIdCompra(int i){
    this->idCompra = i;
}

void DataCompraCliente::setNicknameCli(string n){
    this->nicknameCli = n;
}

void DataCompraCliente::setFechaCompra(date f){
    this->fechaCompra = f;
}