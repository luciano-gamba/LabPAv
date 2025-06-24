#include "DataVendedor.h"

DataVendedor::DataVendedor() {
}

DataVendedor::DataVendedor(string nick,date fecha,string rut): DataUsuario(nick, fecha), RUT(rut){
    
}

DataVendedor::DataVendedor(const DataVendedor& orig) {
}

DataVendedor::~DataVendedor() {
}

string DataVendedor::getNicknameVendedor(){
    return getNickname();
}

date DataVendedor::getDateVendedor(){
    return getDate();
}

string DataVendedor::getRUT(){
    return this->RUT;
}

void DataVendedor::setNicknameVendedor(string n){
    setNickname(n);
}

void DataVendedor::setDateVendedor(date d){
    setDate(d);
}

void DataVendedor::setRUT(string r){
    this->RUT=r;
}