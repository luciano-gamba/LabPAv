#include "promocion_producto.h"
#include "PROMOCION.h"

promocion_producto::promocion_producto() {
}

promocion_producto::promocion_producto(const promocion_producto& orig) {
}

promocion_producto::~promocion_producto() {
}

promocion_producto::promocion_producto(PROMOCION* prom,PRODUCTO* prod,int cantMini,int porcentajeDes){
    //this->cant= prod->getStock(); //Que se supone que hace este cant?
    this->cantMin = cantMini;
    //this->cumpleCant = cant>=cantMin; //Este cumpleCant supongo que esta relacionado con la Compra pero ahora empiezo a creer que no va acá
    this->porcentaje = porcentajeDes;
    float precio = prod->getPrecio();
    this->precioConPromo = (precio*porcentajeDes)/100;
    this->miProducto = prod;
    this->miPromocion = prom;
    prod->Conoceme(this);
}
date promocion_producto::getFechaVen(){
    return this->miPromocion->getFechaVen();
}