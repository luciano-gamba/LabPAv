#include "compra_producto.h"
#include "COMPRA.h"
#include "PRODUCTO.h"
#include <string>
using namespace std;

compra_producto::compra_producto() {
}

compra_producto::compra_producto(const compra_producto& orig) {
}

compra_producto::~compra_producto() {
}

bool compra_producto::getRecibido(){
    return this->recibido;
}

string compra_producto::dameCompra(){
    string comProd;
    COMPRA* c;
    c = (COMPRA*)this->miCompra;
    date f = c->getFecha();
    comProd = to_string(c->getid()) + " " + c->getNickname() + " " + to_string(f.getDia()) + " " + to_string(f.getMes()) + " " + to_string(f.getAnio());
    return comProd;
}

bool compra_producto::getsi_idCompra(int idCompra){
    int id;
    COMPRA* c = (COMPRA*)this->miCompra;
    id = c->getid();
    if(id == idCompra){
        return true;
    }else{
        return false;
    }
}

void compra_producto::marcaRecibido(){
    this->recibido = true;
}