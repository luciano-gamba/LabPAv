#include "CLIENTE.h"

CLIENTE::CLIENTE() {
}

CLIENTE::CLIENTE(const CLIENTE& orig) {
}

CLIENTE::~CLIENTE() {
}

string CLIENTE::getNicknameCliente(){
    return getNickname();
}

string CLIENTE::getContraseniaCliente(){
    return getContrasenia();
}

date CLIENTE::getFechaNacCliente(){
    return getFechaNac();
}

DataDireccion* CLIENTE::getDireccion(){
    return this->direccion;
}

string CLIENTE::getCiudad(){
    return this->ciudad;
}

void CLIENTE::setNicknameCliente(string n){
    setNickname(n);
}

void CLIENTE::setContraseniaCliente(string c){
    setContrasenia(c);
}

void CLIENTE::setFechaNacCliente(date f){
    setFechaNac(f);
}

void CLIENTE::setDireccion(DataDireccion* d){
    this->direccion=d;
}

void CLIENTE::setCiudad(string c){
    this->ciudad=c;
}

void CLIENTE::setCompraActiva(COMPRA* c) {
   this->compraActiva = c;
}

COMPRA* CLIENTE::getCompraActiva() {
    COMPRA* comp = new COMPRA();
    if(this->misCompras == nullptr){
        this->misCompras = new List();
    }
    int id = this->misCompras->getSize()+1;
    comp->setId(id);
    return comp;
}

CLIENTE::CLIENTE(DataCliente* datosC, string contrasenia){
    this->setNicknameCliente(datosC->getNicknameCliente());
    this->setContraseniaCliente(contrasenia);
    this->setFechaNacCliente(datosC->getDateCliente());
    this->setCiudad(datosC->getCiudad());
    this->setDireccion(datosC->getDireccion());
}
void CLIENTE::agregarMisCompras(COMPRA* com){
    this->misCompras->add(com);
}

string CLIENTE::getMisCompras(){
    if(this->misCompras == nullptr){
        this->misCompras = new List();
    }
    IIterator* it = this->misCompras->getIterator();
    COMPRA* c;
    string retorno;
    
    while(it->hasCurrent()){
        c = (COMPRA*)it->getCurrent();
        
        date f = c->getFechaCompra();
        float m = c->montoCompra();
        string items = c->getItems();
        
        retorno = retorno + "\n=== RESUMEN DE LA COMPRA ===\n" + "id compra: " + to_string(c->getid()) + "\n" + "Fecha de compra: " + f.getInfoDate() + "\n" + "Productos:\n" + items + "\n" + "Monto total: $" + to_string(m) + "\n" + "=============================\n";
        
        it->next();
    }
    return retorno;
}