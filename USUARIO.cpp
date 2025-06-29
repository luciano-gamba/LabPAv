#include "USUARIO.h"

USUARIO::USUARIO() {
    this->misComentarios = new List();
}

USUARIO::USUARIO(string nick, string contra, date fecha){
    this->nickname = nick;
    this->contrasenia = contra;
    this->fechaNac = fecha;
    this->misComentarios = new List();
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
    c->asignarUsuarioACom(this);
    ICollectible* ic = c;
    this->misComentarios->add(ic);
}

void USUARIO::desAsignarComentarioAUsu(COMENTARIO* c){
    ICollectible* ic = c;
    this->misComentarios->remove(ic);
}
void USUARIO::eliminarComentarioUsuario(int opC){
    
    int controlC = this->misComentarios->getSize();

    if (controlC < opC) {

        cout << endl << "OPCIONES NO VALIDAS - COMENTARIO NO BORRADO" << endl << endl;
        cout << "VOLVER AL MENU:  ";
        string s;
        getline(cin, s);
        getline(cin, s);

    } else {

        IIterator* itC = this->misComentarios->getIterator();
        COMENTARIO* c;
        while (opC != 1) {
            opC--;
            itC->next();
        }
        c = (COMENTARIO*) itC->getCurrent();
        delete itC;
        
        delete c;

        cout << endl << "OPCIONES VALIDAS - COMENTARIO BORRADO" << endl << endl;
        cout << "VOLVER AL MENU:  ";
        string s;
        getline(cin, s);
        getline(cin, s);
    }
}
