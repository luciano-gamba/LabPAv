#include "USUARIO.h"
#include "ICollection/Integer.h"
#include "COMENTARIO.h"


USUARIO::USUARIO() {
    //this->misComentarios = new OrderedDictionary();
}

USUARIO::~USUARIO() {
}

string USUARIO::getNickname(){
    return this->nickname;
}

void USUARIO::desAsignarComentarioAProd(COMENTARIO *c){
    IKey *ik = new Integer(c->getCodComent());
    this->misComentarios->remove(ik);
    delete ik;
}