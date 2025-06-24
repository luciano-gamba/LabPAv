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
string CONTROLADOR::ListarProductosBasic(){ //Version de listar de Lucas el caso de uso dice que solo muestra el codigo y nombre de los productos
    string Prod = "";
    IIterator* it = this->misProductos->getIterator();
    PRODUCTO* p;

    while(it->hasCurrent()){
        p = (PRODUCTO*) it->getCurrent();
        Prod = Prod + to_string(p->getCodigo()) + p->getNombre() + "\n";
        it->next();
    }
    return Prod;

}
string CONTROLADOR::DescribeProducto(int codigoP){
    IKey* IK= new Integer(codigoP);
    PRODUCTO* p;
    string DescripcionGeneral;
    p=(PRODUCTO*)this->misProductos->find(IK);
    DescripcionGeneral = to_string(p->getPrecio()) + to_string(p->getStock()) + p->getDescripcion(); //+ p->getCategoria() + p->getVendedorAsoc();
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
    IIterator* IT=this->misVendedores->getIterator();
    VENDEDOR* V;
    string nickV;
    string ListaV = "";
    for(IT;IT->hasCurrent();IT->next()){
        V = (VENDEDOR*)IT->getCurrent();
        nickV=V->getNickname(); 
        ListaV=ListaV + nickV + "\n";
    }
    //Libero espacios de memoria
    delete IT;
    delete V;
    
    return ListaV;
}
string CONTROLADOR::ListarProductosV(string NicknameV,string nombreProm,string descripcionProm,date fechaVenProm){
    IKey* ik = new String(NicknameV.c_str());
    VENDEDOR* vend = (VENDEDOR*)this->misVendedores->find(ik);
    string productosDeVend = vend->GetProductosAsoc();
    PROMOCION* nuevaPromo = vend->crearPromo(nombreProm,descripcionProm,fechaVenProm);
    IKey* ikP = new String(nombreProm.c_str()); //Debo crear la clave para poder buscar las promociones por su nombreProm ya que es un IDictionary
    this->lasPromociones->add(ikP,nuevaPromo);
    
    //Liberar espacios de memoria
    delete ik;
    delete ikP;
    delete vend;
    delete nuevaPromo;
    
    return productosDeVend;
}
//PROMOCION
void CONTROLADOR::SelectProductoProm(int codigoP,string nombreProm,int cantMin,int porcentajeDes){
    IKey* ik = new Integer(codigoP);
    IKey* IKProm = new String(nombreProm.c_str());
    PRODUCTO* prod;
    PROMOCION* prom;
    prod = (PRODUCTO*)this->misProductos->find(ik);
    prom = (PROMOCION*)this->lasPromociones->find(IKProm);
    prom->Conoceme(prod,cantMin,porcentajeDes);
    
    
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