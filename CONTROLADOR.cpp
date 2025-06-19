#include "CONTROLADOR.h"

CONTROLADOR:: CONTROLADOR() {
}

CONTROLADOR::~CONTROLADOR() {
}

/*
CONTROLADOR::CONTROLADOR *getInstancia(){
    if(CONTROLADOR::instancia==NULL){
        CONTROLADOR::instancia = new CONTROLADOR();
    }
    return (CONTROLADOR::instancia);
}
*/

string CONTROLADOR::listarProductosPendientes(string nick) {
    string productosPendientes;
    IKey* ik = new String(nick.c_str());
    VENDEDOR* v = (VENDEDOR*)misVendedores->find(ik);
    productosPendientes = v->dameProductosPendientes();
    return productosPendientes;
}

//set<dataCompraCliente> CONTROLADOR::listarCompraProductoPendiente(int codigoProd){
//    return NULL;
//}