#include "PRODUCTO.h"
#include "ICollection/interfaces/IIterator.h"
#include "USUARIO.h"

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
string PRODUCTO::getCategoria(){
    //return this->tipoProd;
    return "a";
}

/*
string PRODUCTO::getVendedorAsoc(){
    VENDEDOR* V =(VENDEDOR*) this->miVendedor;
    string nickname = V->getNicknameVendedor();
     return nickname;
}
*/

bool PRODUCTO::pendienteEnvio(){
    bool recibio = true;
    compra_producto* cp;
    
    IIterator* it=this->misCompraProductos->getIterator();
    for(it; it->hasCurrent() and recibio; it->next()){
        cp = (compra_producto*)it->getCurrent();
        recibio = cp->getRecibido();
    }
    return recibio;
}
//Faltaria el getTipo o getCat pero el struct ese no se si va en un .h separado o dentro de alguno supongo que luego podemos preguntar

void PRODUCTO::Conoceme(promocion_producto* pp){
    this->PromosdeProducto->add(pp);
    
}