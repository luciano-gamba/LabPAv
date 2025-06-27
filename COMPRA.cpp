#include "COMPRA.h"
#include "PRODUCTO.h"
#include "CONTROLADOR.h"
COMPRA::COMPRA() {
}

COMPRA::~COMPRA() {
}

COMPRA* COMPRA::create() {
    return new COMPRA();
}

date COMPRA::getFechaCompra(){
    return this->fechaCompra;
}
 float COMPRA::montoCompra(){
    return this->monto;
 }

 set<DataProducto> COMPRA::getItems() {
    return items;
}

 void COMPRA::setFechaCompra(date f){
     this->fechaCompra=f;
 }

 void COMPRA::setMontoCompra(float m){
    this->monto=m;
 }

void COMPRA::agregarProducto(string codigoProd, int cant) {
    
    DataProducto dataProducto;
    items.insert(dataProducto);
    
   
}

