#include "USUARIO.h"
#include "ICollection/Integer.h"
#include "COMENTARIO.h"


USUARIO::USUARIO() {
    //this->misComentarios = new OrderedDictionary();
}

USUARIO::USUARIO(string nick, string contra, date fecha){
    this->nickname = nick;
    this->contrasenia = contra;
    this->fechaNac = fecha;
}

USUARIO::~USUARIO() {
}

string USUARIO::getNickname(){
    return this->nickname;
}

string USUARIO::getContrasenia(){
    return this->contrasenia;
}
    
date USUARIO::getFechaNac(){
    return this->fechaNac;
}
    
void USUARIO::setNickname(string n){
    this->nickname=n;
}
    
void USUARIO::setContrasenia(string c){
    this->contrasenia=c;
}
    
void USUARIO::setFechaNac(date f){
    this->fechaNac=f;
}

void USUARIO::desAsignarComentarioAUsu(COMENTARIO *c){
    IKey *ik = new Integer(c->getCodComent());
    this->misComentarios->remove(ik);
    delete ik;
}