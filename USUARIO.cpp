#include "USUARIO.h"

USUARIO::USUARIO() {
//    this->misComentarios = new OrderedDictionary();
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

string USUARIO::getInfoMisComentarios(){
    
    string retorno;
    int aux=0;
    IIterator* it = this->misComentarios->getIterator();
    COMENTARIO* c;
    while(it->hasCurrent()){
        aux++;
        c = (COMENTARIO*) it->getCurrent();
        retorno = retorno +"<"+ to_string(aux) +">"+ c->getInfoComentario() + "\n";
        it->next();
    }
    delete it;
    
    return retorno;  
}
void USUARIO::asignarComentarioAUsu(COMENTARIO* c){
    ICollectible* ic = c;
    this->misComentarios->add(ic);
}

void USUARIO::desAsignarComentarioAUsu(COMENTARIO* c){
    ICollectible* ic = c;
    this->misComentarios->remove(ic);
}
void USUARIO::eliminarComentarioUsuario(int opC){

    IIterator* itC = this->misComentarios->getIterator();
    COMENTARIO* c;
    while (opC != 1) {
        opC--;
        itC->next();
    }
    c = (COMENTARIO*) itC->getCurrent();
    delete itC;
    
    c->~COMENTARIO();
    delete c;
}
