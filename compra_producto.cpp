#include "compra_producto.h"

compra_producto::compra_producto() {
}

compra_producto::compra_producto(const compra_producto& orig) {
}

compra_producto::~compra_producto() {
}

bool compra_producto::getRecibido(){
    return this->recibido;
}

DataCompraCliente compra_producto::dameCompra(){
    DataCompraCliente comProd;
    COMPRA* c;
    c = (COMPRA*)this->miCompra;
    comProd.setIdCompra(c->getid());
    comProd.setNicknameCli(c->getNickname());
    comProd.setFechaCompra(c->getFecha());
    return comProd;
}