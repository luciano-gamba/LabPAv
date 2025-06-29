#include "COMENTARIO.h"
#include "USUARIO.h"
#include "PRODUCTO.h"


COMENTARIO::COMENTARIO() {
    
}

COMENTARIO::~COMENTARIO() {
    this->miProducto->desAsignarComentarioAProd(this);
    this->miUsuario->desAsignarComentarioAUsu(this);
    IIterator* itC = this->misComentarios->getIterator();
    COMENTARIO* cr;
    while(itC->hasCurrent()){
        cr = (COMENTARIO*) itC->getCurrent();
        cr->~COMENTARIO();
        delete cr;
        itC->next();
    }
}

void COMENTARIO::setTexto(string t){
    this->texto=t;
}
void COMENTARIO::setFechaCom(){
    time_t ya = time(NULL);
    date d = date(localtime(&ya)->tm_mday,localtime(&ya)->tm_mon+1,localtime(&ya)->tm_year+1900);
    this->fechaCom = d;
}


string COMENTARIO::getTexto(){
    return this->texto;
}
date COMENTARIO::getFechaCom(){
    return this->fechaCom;
}

string COMENTARIO::getInfoComentario(){
    return "Texto: "+this->texto+"\nFecha: "+this->fechaCom.getInfoDate();
}

void COMENTARIO::asignarComentarioACom(COMENTARIO* c){
    ICollectible *ic = c;
    this->misComentarios->add(ic);
}
void COMENTARIO::DesAsignarComentarioACom(COMENTARIO* c){
    ICollectible *ic = c;
    this->misComentarios->remove(ic);
}