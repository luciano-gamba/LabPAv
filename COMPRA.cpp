#include "COMPRA.h"

COMPRA::COMPRA() {
}

COMPRA::~COMPRA() {
}

/*
void COMPRA::agregarProducto(string codigoProd ,int cant ) {
    iterator* it = this->misProductos->getIterator();
    producto* p;
    bool encontrado = false;

    for(it;it->hasCurrent(); it->next()){
        p = (producto*)it->getCurrent();
        if(p->getCodigo() == codigoProd){
            p->sumarCantidad(cant); //hay que crear la funcion
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        producto* nuevo = new producto(codigoProd,cant);
        this->misProductos->add(nuevo);
    }
    delete it;
}

DataCompra* Controlador::mostrarDetalleCompra(){
    date fechaC = com->fechaCompra();
    float montoC = com->montoCompra();
    set<DataProducto*> c = com->getItems();
    
    DataCompra* detalle = new DataCompra(fechaC,montoC,c);
    return detalle;
}
*/
