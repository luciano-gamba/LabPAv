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

//CLIENTE
    //void CONTROLADOR::ingresoCliente(dataCliente datosC, string contraseña);
//COMENTARIO
    
//USUARIO
   
//PRODUCTO
    //int CONTROLADOR::ingresoProducto(string vendedor, DTProducto datosProd);
    string CONTROLADOR::ListarProductos(){
        return "a";
    }
    string CONTROLADOR::DescribeProducto(int codigoP){
        return "a";
    }
    //set<dataCompraCliente> CONTROLADOR::listarCompraProductoPendiente(int codigoProd);
    void CONTROLADOR::selectCompraProductoPendiente(int idCompra){
        
    }
//VENDEDOR    
    //void CONTROLADOR::ingresoVendedor(dataVendedor datosV, string contraseña);
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