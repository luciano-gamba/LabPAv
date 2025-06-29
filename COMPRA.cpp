#include "COMPRA.h"
#include "PRODUCTO.h"
#include "CLIENTE.h"
#include "ICollection/String.h"

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

void COMPRA::agregarProducto(string codigoProd, int cant, PRODUCTO* p) {
    
    if(this->productosCompra != nullptr){
        this->productosCompra = new OrderedDictionary;
    }
    compra_producto* cp = cp->create(p, cant);
    IKey* ik = new String(codigoProd.c_str());
    this->productosCompra->add(ik, cp);
    p->agregar(cp);
    
    DataProducto dataProducto(codigoProd, cant);
    items.insert(dataProducto);
}

//void COMPRA::setCP(){
//    this->micp = new compra_producto();
//    PRODUCTO* p;
//}