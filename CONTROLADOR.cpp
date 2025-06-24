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
//PRODUCTO
void CONTROLADOR::ingresoProducto(int vendedor, DTProducto* datosProd){
    int control = this->misVendedores->getSize();
    if(control < vendedor){
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
//set<dataCompraCliente> CONTROLADOR::listarCompraProductoPendiente(int codigoProd);
void CONTROLADOR::selectCompraProductoPendiente(int idCompra){

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
    int aux = 0;
    if(it->hasCurrent()){
       while(it->hasCurrent()){
        aux = aux + 1;
        string s = to_string(aux);
        v = (VENDEDOR*) it->getCurrent();
        retorno = retorno + s + ". " + v->getNicknameVendedor() + "\n\n";
        it->next();
       }
    }else{
        retorno = retorno + "No existen vendedores. [Seleccione 0 para salir]" + "\n\n";
    }
    return retorno;
}

string CONTROLADOR::ListarProductosV(string NicknameV,string nombreProm,string descripcionProm,date fechaVenProm){
    return "a";
}
//PROMOCION
void CONTROLADOR::SelectProductoProm(int codigoP,int cantMin,int porcentajeDes){

}

/*string CONTROLADOR::solicitarListaPromociones(){
    return "a";
}
   string CONTROLADOR::obtenerProductosVendedoresPromocion() {
    string resultado;
    PROMOCION* promo = (PROMOCION*)this->misPromociones->find(nombrePromo);
    
    if (promo == nullptr) {
        return resultado; 
    }
    ICollection* productos = promo->obtenerPromocion();
    IIterator* it = productos->getIterator();
    while (it->hasCurrent()) {
        Producto* prod =Producto*(it->getCurrent());
        if (prod != nullptr) {
            string nombreProd = prod->getNombre();
            float precio = prod->getPrecio();
            Vendedor* vend = prod->getVendedorAsociado();
            if (vend != nullptr) { 
                string nombreV = vend->getNombreVendedor();
                string mailV = vend->getEmailVendedor();
                string telV = vend->getTelVendedor();
                string V = nombreV + " " + mailV + " " + telV;
                string promoStr = nombreProd + " " + to_string(precio) + " " + V;
                resultado += promoStr + "\n"; 
            }
        }
        it->next();
    }
    delete it; 
    return resultado; 
}
*/
//COMPRA
string CONTROLADOR::listarNicknamesC(){
    return "a";
}
void CONTROLADOR::selectNicknameC(string nick){

}
void CONTROLADOR::agregarProducto(string codigoProd, int cant){

}
    //DataCompra CONTROLADOR::mostrarDetalleCompra(){}