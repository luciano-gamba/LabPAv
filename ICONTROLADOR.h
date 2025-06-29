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
    virtual string listarComentariosProducto(int opP) = 0;
    virtual string listarComentariosUsuario(int opU) = 0;
    virtual void responderComentarioProducto(int opU, int opP, int opC, string texto) = 0;
    virtual void escribirComentarioProducto(int opU, int opP, string texto) = 0;
    virtual void eliminarComentarioUsuario(int opU, int opC) = 0;
    //USUARIO
    virtual string listarUsuarios()=0;
    virtual string listarUsuariosCompletos()=0;
    virtual string listarInfoBasica(string nick)=0;
    
//PRODUCTO
    virtual void ingresoProducto(int vendedor, DTProducto* datosProd) = 0;
    virtual string ListarProductos() = 0;
    virtual string DescribeProducto(int indiceP) = 0;
    virtual string listarProductosPendientes(string nick) = 0;
    virtual string listarCompraProductoPendiente(int codigoProd) = 0;
    virtual string ListarProductosBasic() = 0;
    //virtual set<dataCompraCliente> listarCompraProductoPendiente(int codigoProd) = 0;
    virtual void selectCompraProductoPendiente(int idCompra) = 0;
//VENDEDOR    
    virtual void ingresoVendedor(DataVendedor* datosV, string contraseña) = 0;
    virtual string ListaVendedores() = 0;
    virtual string ListarProductosV(int Vendor,string nombreProm,string descripcionProm,date fechaVenProm) = 0;
//PROMOCION
    virtual void SelectProductoProm(int indiceProd,string nombreProm,int cantMin,int porcentajeDes) = 0;
    virtual string solicitarListaPromociones() = 0;
    virtual string obtenerProductosVendedoresPromocion(string nombrePromo) = 0;    
//COMPRA
    virtual string listarNicknamesC() = 0;
    virtual void selectNicknameC(string nick) = 0;
    virtual void agregarProducto(string codigoProd, int cant) = 0;
    virtual void mostrarDetalleCompra() = 0;

//GET
    
    virtual void getUsuario(string nick) = 0;
    
};
#endif /* ICONTROLADOR_H */

