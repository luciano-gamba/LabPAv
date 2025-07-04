#include "DTProducto.h"

DTProducto::DTProducto() {
}

DTProducto::DTProducto(const DTProducto& orig) {
}

DTProducto::~DTProducto() {
}

DTProducto::DTProducto(string nom, float prec, int stock, string desc, TipoProducto cat){
    this->nomProd = nom;
    this->cantStock = stock;
    this->categoria = cat;
    this->precio = prec;
    this->descProd = desc;
}

string DTProducto::getNomProd(){
    return this->nomProd;
}

float DTProducto::getPrecio(){
    return this->precio;
}

int DTProducto::getCantStock(){
    return this->cantStock;
}

string DTProducto::getDescProd(){
    return this->descProd;
}

TipoProducto DTProducto::getCategoria(){
    return this->categoria;
}

string DTProducto::getCategoriaString(){
    return TipoProductoToString(this->categoria);
}