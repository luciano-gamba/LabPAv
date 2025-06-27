#include "COMPRA.h"
#include "PRODUCTO.h"
#include "CLIENTE.h"

COMPRA::COMPRA() {
    idCompra = 0;
    monto = 0.0;
    miCliente = nullptr;
    productosCompra = nullptr;
}

COMPRA::~COMPRA() {
}

int COMPRA::getid(){
    return this->idCompra;
}

string COMPRA::getNickname(){
    if(miCliente != nullptr) {
        return this->miCliente->getNicknameCliente();
    }
    return "";
}

date COMPRA::getFecha(){
    return this->fechaCompra;
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

