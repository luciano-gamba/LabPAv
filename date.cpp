#include "date.h"

date::date() {
}

date::date(int d, int m, int a) {
    this->dia=d;
    this->mes=m;
    this->anio=a;
}

date::~date() {
}

int date::getDia(){
    return this->dia;
}
int date::getMes(){
    return this->mes;
}
int date::getAnio(){
    return this->anio;
}
string date::getInfoDate(){
    return to_string(this->dia)+"/"+to_string(this->mes)+"/"+to_string(this->anio);
}
//cambio hecho por manolo pa que me funke el operador en promocion(se acepta una nueva sugerencia si hay otra solucion)
bool date::operator>(const date& otra) const {
    if (this->anio != otra.anio)
        return this->anio > otra.anio;
    if (this->mes != otra.mes)
        return this->mes > otra.mes;
    return this->dia > otra.dia;
}
