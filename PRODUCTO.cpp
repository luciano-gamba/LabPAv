#include "PRODUCTO.h"
#include "VENDEDOR.h"
#include "compra_producto.h"
#include "ICollection/interfaces/IIterator.h"

PRODUCTO::PRODUCTO() {
    this->vendedorAsociado = nullptr;
}

PRODUCTO::PRODUCTO(const PRODUCTO& orig) {
}

PRODUCTO::PRODUCTO(DTProducto* datosProd, int cod){
    this->codigo = cod;
    this->nombre = datosProd->getNomProd();
    this->precio = datosProd->getPrecio();
    this->stock = datosProd->getCantStock();
    this->descripcion = datosProd->getDescProd();
    this->vendedorAsociado = nullptr;
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

std::string PRODUCTO::getNicknameVendedor(){
    if(this->vendedorAsociado != nullptr){
        return this->vendedorAsociado->getNicknameVendedor();
    }
    return ""; // Si no hay vendedor asociado
}

void PRODUCTO::setVendedorAsociado(VENDEDOR* v){
    this->vendedorAsociado = v;
}

//Faltaria el getTipo o getCat pero el struct ese no se si va en un .h separado o dentro de alguno supongo que luego podemos preguntar
