#include "COMENTARIO.h"

COMENTARIO::COMENTARIO() {
}

COMENTARIO::~COMENTARIO() {
}

void COMENTARIO::setCodComent(int n){
    this->codComent=n;
}
void COMENTARIO::setTexto(string t){
    this->texto=t;
}
void COMENTARIO::setFechaCom(){
    time_t ya = time(NULL);
    date d = date(localtime(&ya)->tm_mday,localtime(&ya)->tm_mon+1,localtime(&ya)->tm_year+1900);
    this->fechaCom = d;
}

int COMENTARIO::getCodComent(){
    return this->codComent;
}
string COMENTARIO::getTexto(){
    return this->texto;
}
date COMENTARIO::getFechaCom(){
    return this->fechaCom;
}

string COMENTARIO::getInfoComentario(){
    return "<>Codigo: "+to_string(this->codComent)+"\n<>Texto: "+this->texto+"\n<>Fecha: "+this->fechaCom.getInfoDate();
}