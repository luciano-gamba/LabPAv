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