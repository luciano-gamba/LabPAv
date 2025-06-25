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

string CONTROLADOR::listarCompraProductoPendiente(int codigoProd){
   string compras;
   IKey* ik = new Integer(codigoProd);
   PRODUCTO* p = (PRODUCTO*)this->misProductos->find(ik);
   compras = p->dameComprasPend();
   return compras;
}

void CONTROLADOR::selectCompraProductoPendiente(int idCompra){
    VENDEDOR* v;
    IKey* ik = new Integer(idCompra);
    v = (VENDEDOR*)this->misVendedores->find(ik);
    v->marcaloRecibido(idCompra);
}

//CLIENTE
void CONTROLADOR::ingresoCliente(DataCliente* datosC, string contrasenia){    
    CLIENTE* c = new CLIENTE(datosC,contrasenia);
    string llave = datosC->getNicknameCliente();
    IKey* ik = new String(llave.c_str());
    bool existe = this->misUsuarios->member(ik);
    if(!existe){
        this->misClientes->add(ik, c);
        USUARIO* u = new USUARIO(llave, contrasenia, datosC->getDateCliente());
        this->misUsuarios->add(ik, u);
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

string CONTROLADOR::listarInfoBasica(string nick){
    string retorno;
    IKey* ik = new String(nick.c_str());
    USUARIO* u = (USUARIO*)this->misUsuarios->find(ik);
    return retorno = u->getNickname() + " " + to_string(u->getFechaNac().getDia()) + "/" + to_string(u->getFechaNac().getMes()) + "/" + to_string(u->getFechaNac().getAnio());
}

//PRODUCTO
void CONTROLADOR::ingresoProducto(int vendedor, DTProducto* datosProd){
    int control = this->misVendedores->getSize();
    if(vendedor > control or vendedor < 1){
        cout << "VENDEDOR SELECCIONADO NO VÁLIDO" << endl;
    }else{
        IIterator* iter = this->misVendedores->getIterator();
        VENDEDOR* v;
        while(vendedor != 0){
            v = (VENDEDOR*) iter->getCurrent();
            iter->next();
            vendedor = vendedor - 1;
        }
        v->añadirProducto(datosProd);
        cout << "Listo!" << endl;
    }
}
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
//VENDEDOR    
void CONTROLADOR::ingresoVendedor(DataVendedor* datosV, string contrasenia){
    VENDEDOR* v = new VENDEDOR(datosV,contrasenia);
    string llave = datosV->getNicknameVendedor();
    IKey* ik = new String(llave.c_str());
    bool existe = this->misUsuarios->member(ik);
    if(!existe){
        this->misVendedores->add(ik, v);
        USUARIO* u = new USUARIO(llave, contrasenia, datosV->getDateVendedor());
        this->misUsuarios->add(ik, u);
    }else{
        delete v;
    }
    cout << "Hecho!" << endl;
}

string CONTROLADOR::ListaVendedores(){
    string retorno = "\t<>VENDEDORES<>\n\n";
    IIterator* it = this->misVendedores->getIterator();
    
    VENDEDOR* v;
    if(it->hasCurrent()){
        int aux = 0;
        while(it->hasCurrent()){
            aux = aux + 1;
            string s = to_string(aux);
            v = (VENDEDOR*) it->getCurrent();
            retorno = retorno + s + ". " + v->getNicknameVendedor() + "\n\n";
            it->next();
        }
    }else{
        retorno = "#$%";
    }
    return retorno;
}

string CONTROLADOR::ListarProductosV(string NicknameV,string nombreProm,string descripcionProm,date fechaVenProm){
    return "a";
}
//PROMOCION
void CONTROLADOR::SelectProductoProm(int codigoP,int cantMin,int porcentajeDes){

}
   string CONTROLADOR::solicitarListaPromociones() {
    IIterator* it = this->misPromociones->getIterator(); 
    string resultado = "";
    PROMOCION* promoActual;
    while (it->hasCurrent()) {
        promoActual = (PROMOCION*)it->getCurrent();
        promoActual->obtenerFechaSistema(); // actualiza fechaSis internamente
//       if (promoActual->getFechaVen() > promoActual->getFechaSis()) {
//        string nombre = promoActual->getNombre();
//            resultado += nombre + "\n";
//        }

        it->next();
    }

    return resultado;
}

string CONTROLADOR::obtenerProductosVendedoresPromocion(string nombrePromo) {
    string resultado;
//    IKey* ikPromo = new String(nombrePromo.c_str());
//    PROMOCION* promo = (PROMOCION*)this->misPromociones->find(ikPromo);
//    delete ikPromo;
//    
//    if (promo == nullptr) {
//        return resultado; 
//    }
//    IIterator* it = this->misProductos->getIterator();
//    while (it->hasCurrent()) {
//        PRODUCTO* prod =(PRODUCTO*)(it->getCurrent());
//        if (prod != nullptr) {
//            string nombreProd = prod->getNombre();
//            float precio = prod->getPrecio();
//                string vend = prod->getNicknameVendedor();
//                string promoStr = nombreProd + " " + to_string(precio) + " " + vend;
//                resultado += promoStr + "\n"; 
//        }
//        it->next();
//    }
//    delete it; 
    return resultado; 
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