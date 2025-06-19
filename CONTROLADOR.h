#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "ICONTROLADOR.h"
#include "ICollection/interfaces/IDictionary.h" 
#include "CLIENTE.h"
#include "COMENTARIO.h"
#include "USUARIO.h"
#include "DataCompra.h"
//#include "DataVendedor.h"
//#include "DTProducto.h"
//#include "dataCliente.h"
using namespace std;

class CONTROLADOR: public ICONTROLADOR{
public:
    //operaciones de funcionamiento
    CONTROLADOR *getInstancia();
    ~CONTROLADOR();
    CONTROLADOR();
//CLIENTE
    //void ingresoCliente(dataCliente datosC, string contraseña);
//COMENTARIO
    
//USUARIO
   
//PRODUCTO
    //int ingresoProducto(string vendedor, DTProducto datosProd);
    string ListarProductos();
    string DescribeProducto(int codigoP);
    string listarProductosPendientes(string nick);
    //set<dataCompraCliente> listarCompraProductoPendiente(int codigoProd);
    void selectCompraProductoPendiente(int idCompra);
//VENDEDOR    
    //void ingresoVendedor(dataVendedor datosV, string contraseña);
    string ListaVendedores();
    string ListarProductosV(string NicknameV,string nombreProm,string descripcionProm,date fechaVenProm);
//PROMOCION
    void SelectProductoProm(int codigoP,int cantMin,int porcentajeDes);
    string solicitarListaPromociones();
    string obtenerProductosVendedoresPromocion();    
//COMPRA
    string listarNicknamesC();
    void selectNicknameC(string nick);
    void agregarProducto(string codigoProd, int cant);
    DataCompra mostrarDetalleCompra();
    
private:
   
    /*
        CONTROLADOR* instancia = nullptr;
        CONTROLADOR();
    */
    
    
};

#endif /* CONTROLADOR_H */

