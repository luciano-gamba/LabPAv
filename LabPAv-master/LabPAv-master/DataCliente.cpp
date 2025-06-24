#include "DataCliente.h"

DataCliente::DataCliente() {
}

DataCliente::DataCliente(string nick,date fecha,string ciud,DataDireccion dir): DataUsuario(nick, fecha), direccion(dir){
    
}

DataCliente::DataCliente(const DataCliente& orig) {
}

DataCliente::~DataCliente() {
}

string DataCliente::getNicknameCliente(){
    return getNickname();
}

date DataCliente::getDateCliente(){
    return getDate();
}

string DataCliente::getCiudad(){
    return this->ciudad;
}
DataDireccion DataCliente::getDireccion(){
    return this->direccion;
}

void DataCliente::setNicknameCliente(string n){
    setNickname(n);
}

void DataCliente::setDateCliente(date d){
    setDate(d);
}

void DataCliente::setCiudad(string c){
    this->ciudad=c;
}

void DataCliente::setDireccion(DataDireccion d){
    this->direccion=d;
}