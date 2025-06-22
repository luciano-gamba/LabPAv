#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "ICONTROLADOR.h"
#include "ICollection/interfaces/IDictionary.h" 
#include "ICollection/interfaces/IKey.h"
#include "ICollection/String.h"
#include "ICollection/interfaces/IIterator.h"
#include "CLIENTE.h"
#include "COMENTARIO.h"
#include "USUARIO.h"
#include "DataCompra.h"

#include <string>
#include "VENDEDOR.h"
//#include "DataVendedor.h"
//#include "DTProducto.h"
//#include "dataCliente.h"
using namespace std;

class CONTROLADOR: public ICONTROLADOR{
public:
    //operaciones de funcionamiento
    static CONTROLADOR *getInstancia();
    ~CONTROLADOR();
    
//CLIENTE
    //void ingresoCliente(dataCliente datosC, string contraseña);
//COMENTARIO
    
//USUARIO
    string listarUsuarios();
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
    //DataCompra mostrarDetalleCompra();
    
private:
   
    CONTROLADOR();
    static CONTROLADOR* instancia;
    

    IDictionary* misProductos;
    IDictionary* misUsuarios;
    IDictionary* misVendedores;
};

#endif /* CONTROLADOR_H */

