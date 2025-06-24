#include "DataUsuario.h"

DataUsuario::DataUsuario() {
}

DataUsuario::DataUsuario(const DataUsuario& orig) {
}

DataUsuario::DataUsuario(string s, date d){
    
}

DataUsuario::~DataUsuario() {
}

string DataUsuario::getNickname(){
    return this->nickname;
}

date DataUsuario::getDate(){
    return this->fechaNac;
}

void DataUsuario::setNickname(string nick){
    this->nickname=nick;
}

void DataUsuario::setDate(date d){
    this->fechaNac=d;
}