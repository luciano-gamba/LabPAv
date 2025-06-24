#ifndef ICONTROLADOR_H
#define ICONTROLADOR_H
#include <string>
#include "DataCompra.h"
#include "DataCliente.h"
#include "DataVendedor.h"
#include "DTProducto.h"
using namespace std;
class ICONTROLADOR{
public:
    //virtual ~ICONTROLADOR();
//CLIENTE
    virtual void ingresoCliente(DataCliente* datosC, string contraseña) = 0;
//COMENTARIO
    
//USUARIO
    virtual string listarUsuarios()=0;
//PRODUCTO
    virtual void ingresoProducto(int vendedor, DTProducto* datosProd) = 0;
    virtual string ListarProductos() = 0;
    virtual string DescribeProducto(int codigoP) = 0;
    virtual string listarProductosPendientes(string nick) = 0;
    //virtual set<dataCompraCliente> listarCompraProductoPendiente(int codigoProd) = 0;
    virtual void selectCompraProductoPendiente(int idCompra) = 0;
//VENDEDOR    
    virtual void ingresoVendedor(DataVendedor* datosV, string contraseña) = 0;
    virtual string ListaVendedores() = 0;
    virtual string ListarProductosV(string NicknameV,string nombreProm,string descripcionProm,date fechaVenProm) = 0;
//PROMOCION
    virtual void SelectProductoProm(int codigoP,int cantMin,int porcentajeDes) = 0;
    virtual string solicitarListaPromociones() = 0;
    virtual string obtenerProductosVendedoresPromocion() = 0;    
//COMPRA
    virtual string listarNicknamesC() = 0;
    virtual void selectNicknameC(string nick) = 0;
    virtual void agregarProducto(string codigoProd, int cant) = 0;
    //virtual DataCompra mostrarDetalleCompra() = 0;

};
#endif /* ICONTROLADOR_H */

