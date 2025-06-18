#include "PRODUCTO.h"

PRODUCTO::PRODUCTO() {
}

PRODUCTO::PRODUCTO(const PRODUCTO& orig) {
}

PRODUCTO::~PRODUCTO() {
}

int PRODUCTO::getCodigo(){
    return codigo;
}
int PRODUCTO::getStock(){
    return stock;
}
float PRODUCTO::getPrecio(){
    return precio;
}
std::string PRODUCTO::getNombre(){
    return nombre;
}
std::string PRODUCTO::getDescripcion(){
    return descripcion;
}
//Faltaria el getTipo o getCat pero el struct ese no se si va en un .h separado o dentro de alguno supongo que luego podemos preguntar