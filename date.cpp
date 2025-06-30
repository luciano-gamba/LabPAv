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
void date::SetearFecha(){ //La pense y escribi por si alguien quiere ingresar una fecha y validarla asi se simplefica y no esta dentro del main
    cout << "Dia: " << endl;
    int dia;
    cin >> dia;   
    while(dia>31 or dia <1){
        cout<< "Dia invalido, ingrese nuevamente: ";
        cin >> dia;
    }
    cout << "Mes: " << endl;
    int mes;
    cin >> mes;
    while(mes>12 or mes <1){
        cout<< "Mes invalido, ingrese nuevamente: ";
        cin >> mes;
    }
    cout << "Anio: " << endl;
    int anio;
    cin >> anio;
    while(anio < 1900){
        cout<< "Anio invalido, ingrese nuevamente: ";
        cin >> anio;
    }
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
}