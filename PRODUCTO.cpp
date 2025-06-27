#include "PRODUCTO.h"

PRODUCTO::PRODUCTO() {
}

PRODUCTO::PRODUCTO(const PRODUCTO& orig) {
}

PRODUCTO::PRODUCTO(DTProducto* datosProd, int cod){
    this->codigo = cod;
    this->nombre = datosProd->getNomProd();
    this->precio = datosProd->getPrecio();
    this->stock = datosProd->getCantStock();
    this->descripcion = datosProd->getDescProd();
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

string PRODUCTO::dameComprasPend(){
    string compra;
    compra_producto* cp;
    string comProd;
    
    IIterator* it = this->misCompraProductos->getIterator();
    for(it; it->hasCurrent(); it->next()){
        cp = (compra_producto*)it->getCurrent();
        if(!cp->getRecibido()){
            comProd = comProd + cp->dameCompra() + "\n";
        }
    }
    return compra;
}

void PRODUCTO::marcoRecibido(int idCompra){
    compra_producto* cp;
    
    IIterator* it = this->misCompraProductos->getIterator();
    cp = (compra_producto*)it->getCurrent();
    for(it; it->hasCurrent() and cp->getsi_idCompra(idCompra); it->next()){
        cp = (compra_producto*)it->getCurrent();
        if(cp->getsi_idCompra(idCompra)){
            cp->marcaRecibido();
        }
    }
}
//Faltaria el getTipo o getCat pero el struct ese no se si va en un .h separado o dentro de alguno supongo que luego podemos preguntar

string PRODUCTO::getInfoMisComentarios(){
    
    string retorno;
    int aux=0;
    IIterator* it = this->misComentarios->getIterator();
    COMENTARIO* c;
    while(it->hasCurrent()){
        aux++;
        c = (COMENTARIO*) it->getCurrent();
        retorno = retorno +"<"+ to_string(aux) +">"+ c->getInfoComentario() + "\n";
        it->next();
    }
    delete it;
    
    return retorno;           
}
int PRODUCTO::getSizeMisComentarios(){
    return this->misComentarios->getSize();   
}
COMENTARIO* PRODUCTO::crearRespuesta(int opC, string texto){
    
    IIterator* it = this->misComentarios->getIterator();
    COMENTARIO* co;
    while(opC != 1){
        opC--;
        it->next();
    }
    co = (COMENTARIO*) it->getCurrent();
    delete it;
    
    COMENTARIO* cr = this->createComentario(texto);
    co->asignarComentarioACom(cr);
    
    return cr;
}

COMENTARIO* PRODUCTO::createComentario(string texto){
    COMENTARIO* c = new COMENTARIO();
    c->setTexto(texto);
    c->setFechaCom();
    return c;
}

void PRODUCTO::asignarComentarioAProd(COMENTARIO* c){
    ICollectible* ic = c;
    this->misComentarios->add(ic);
}
void PRODUCTO::desAsignarComentarioAProd(COMENTARIO* c){
    ICollectible* ic = c;
    this->misComentarios->remove(ic);    
}


