#include "PROMOCION.h"


PROMOCION::PROMOCION() {
}

PROMOCION::PROMOCION(string nombre,string descripcion,date fechaV){
    this->nombrePromo = nombre;
    this->descripcionPromo = descripcion;
    this->fechaVen = fechaV;
}

PROMOCION::~PROMOCION() {
}

string PROMOCION::getNombre(){
   return this->nombrePromo;
}

string PROMOCION::getDescripcion(){
   return this->descripcionPromo;
}

date PROMOCION::getFechaVen(){
    return this->fechaVen;
}

void PROMOCION::setNombre(string n){
    this->nombrePromo=n;
}

void PROMOCION::setDescripcion(string d){
    this->descripcionPromo=d;
}

void PROMOCION::setFechaVen(date f){
    this->fechaVen=f;
}

void PROMOCION::obtenerFechaSistema(){
    time_t ya = time(NULL);
    date d = date(localtime(&ya)->tm_mday,localtime(&ya)->tm_mon+1,localtime(&ya)->tm_year+1900);
    this->fechaSis = d;
}

string PROMOCION::solicitarListaPromociones() {
    IIterator* it = this->coleccionPromociones->getIterator(); 
    string resultado = "";
    PROMOCION* promoActual;
    while (it->hasCurrent()) {
        promoActual = (PROMOCION*)it->getCurrent();
        promoActual->obtenerFechaSistema(); // actualiza fechaSis internamente
       if (promoActual->getFechaVen() > promoActual->getFechaSis()) {
        string nombre = promoActual->getNombre();
            resultado += nombre + "\n";
        }

        it->next();
    }

    return resultado;
}

