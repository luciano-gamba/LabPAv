#include "PROMOCION.h"
#include "promocion_producto.h"


PROMOCION::PROMOCION() {
}

PROMOCION::PROMOCION(string nombre,string descripcion,date fechaV){
    this->nombrePromo = nombre;
    this->descripcionPromo = descripcion;
    this->fechaVen = fechaV;
    this->coleccionPromociones = new List;
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

date PROMOCION::obtenerFechaSistema(){  
    time_t ya = time(NULL);
    date d = date(localtime(&ya)->tm_mday,localtime(&ya)->tm_mon+1,localtime(&ya)->tm_year+1900);
    this->fechaSis = d;
    return d;  
}

void PROMOCION::Conoceme(PRODUCTO* prod,int cantMin,int porcentajeDes){
    promocion_producto* pp = new promocion_producto(this,prod,cantMin,porcentajeDes);
    this->coleccionPromociones->add(pp);
    
}