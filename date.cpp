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