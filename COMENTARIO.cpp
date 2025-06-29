#include "COMENTARIO.h"
#include "USUARIO.h"
#include "PRODUCTO.h"


COMENTARIO::COMENTARIO() {
    this->miUsuario = nullptr;
    this->miProducto = nullptr;    
    this->misComentarios = new List();
    
}

COMENTARIO::~COMENTARIO() {
    
    this->miProducto->desAsignarComentarioAProd(this);
    this->miUsuario->desAsignarComentarioAUsu(this);

    if (this->misComentarios != nullptr) {

        IIterator* itC = this->misComentarios->getIterator();
        COMENTARIO* cr;
        while (itC->hasCurrent()) {
            cr = (COMENTARIO*) itC->getCurrent();
            delete cr;
            itC->next();
        }
        delete itC;
        
        delete this->misComentarios;
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
void COMENTARIO::asignarUsuarioACom(USUARIO* u){
    this->miUsuario=u;
}

void COMENTARIO::asignarProductoACom(PRODUCTO* p) {
    this->miProducto=p;
}