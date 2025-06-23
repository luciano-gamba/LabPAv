#include "CONTROLADOR.h"
#include <iostream>

//CONTROLADOR* CONTROLADOR::instancia = nullptr;

CONTROLADOR::CONTROLADOR() {
    this->misProductos = new OrderedDictionary;
    this->misUsuarios = new OrderedDictionary;
    this->misVendedores = new OrderedDictionary;
    this->misClientes = new OrderedDictionary;
}

CONTROLADOR::~CONTROLADOR() {
}

//CONTROLADOR* CONTROLADOR::getInstancia(){
//    if(instancia==nullptr){
//       instancia = new CONTROLADOR();
//    }
//    return instancia;
//}


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

//CLIENTE
void CONTROLADOR::ingresoCliente(DataCliente* datosC, string contraseña){    
    CLIENTE* c = new CLIENTE(datosC,contraseña);
    string llave = datosC->getNicknameCliente();
    IKey* ik = new String(llave.c_str());
    bool existe = this->misClientes->member(ik);
    if(!existe){
//        c = (CLIENTE*) 
        this->misClientes->add(ik, c);
        //this->misUsuarios->add(ik, c);
    }else{
        delete c;
    }
    cout << "Hecho!" << endl;
}
//COMENTARIO
    
//USUARIO
string CONTROLADOR::listarUsuarios(){

    string retorno = "\t<>USUARIOS<>\n\n";
    IIterator* it = this->misUsuarios->getIterator();
    
    USUARIO* u;

    while(it->hasCurrent()){
        u = (USUARIO*) it->getCurrent();
        retorno = retorno + u->getNickname() + "\n\n";
        it->next();
    }
    return retorno;
}
//PRODUCTO
//int CONTROLADOR::ingresoProducto(string vendedor, DTProducto datosProd){
//}
string CONTROLADOR::ListarProductos(){
    string retorno = "\t<>PRODUCTOS<>\n\n";
    IIterator* it = this->misProductos->getIterator();
    PRODUCTO* p;

    while(it->hasCurrent()){
        p = (PRODUCTO*) it->getCurrent();
        retorno = retorno+"<>Codigo: "+to_string(p->getCodigo())+"\n<>Nombre: "+p->getNombre()+"\n<>Precio: $"+to_string(p->getPrecio())+"\n\n";
        it->next();
    }
    return retorno;

}
string CONTROLADOR::DescribeProducto(int codigoP){
    return "a";
}
//set<dataCompraCliente> CONTROLADOR::listarCompraProductoPendiente(int codigoProd);
void CONTROLADOR::selectCompraProductoPendiente(int idCompra){

}
//VENDEDOR    
void CONTROLADOR::ingresoVendedor(DataVendedor* datosV, string contraseña){
    VENDEDOR* v = new VENDEDOR(datosV,contraseña);
    string llave = datosV->getNicknameVendedor();
    IKey* ik = new String(llave.c_str());
    bool existe = this->misVendedores->member(ik);
    if(!existe){
    //    v = (VENDEDOR*) 
    this->misVendedores->add(ik, v);
    }else{
        delete v;
    }
    cout << "Hecho!" << endl;
}

string CONTROLADOR::ListaVendedores(){
    return "a";
}
string CONTROLADOR::ListarProductosV(string NicknameV,string nombreProm,string descripcionProm,date fechaVenProm){
    return "a";
}
//PROMOCION
void CONTROLADOR::SelectProductoProm(int codigoP,int cantMin,int porcentajeDes){

}
string CONTROLADOR::solicitarListaPromociones(){
    return "a";
}
string CONTROLADOR::obtenerProductosVendedoresPromocion(){
    return "a";
}
//COMPRA
string CONTROLADOR::listarNicknamesC(){
    return "a";
}
void CONTROLADOR::selectNicknameC(string nick){

}
void CONTROLADOR::agregarProducto(string codigoProd, int cant){

}
    //DataCompra CONTROLADOR::mostrarDetalleCompra(){}