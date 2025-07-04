#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include <iostream>
#include "ICONTROLADOR.h"
#include "ICollection/interfaces/IDictionary.h" 
#include "ICollection/interfaces/IKey.h"
#include "ICollection/String.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/Integer.h"
#include "CLIENTE.h"
#include "COMENTARIO.h"
#include "USUARIO.h"
#include "DataCompra.h"
#include "PROMOCION.h"
#include "COMPRA.h"
#include <string>
#include "VENDEDOR.h"
#include "DataVendedor.h"
#include "DTProducto.h"
#include "DataCliente.h"
#include "DataVendedor.h"
#include <set>
using namespace std;

class CONTROLADOR: public ICONTROLADOR{
public:
    //operaciones de funcionamiento
    //static CONTROLADOR* getInstancia();
    CONTROLADOR();
    ~CONTROLADOR();
    
//CLIENTE
    void ingresoCliente(DataCliente* datosC, string contraseña);
//COMENTARIO
    string listarComentariosProducto(int opP);
    string listarComentariosUsuario(int opU);
    void responderComentarioProducto(int opU, int opP, int opC, string texto);
    void escribirComentarioProducto(int opU, int opP, string texto);
    void eliminarComentarioUsuario(int opU, int opC);
//USUARIO
    string listarUsuarios();
    string listarUsuariosCompletos();
    string listarInfoBasica(string);
    void getUsuario(string nick);
    void listarSegun(string nick);
//PRODUCTO
    void ingresoProducto(int vendedor, DTProducto* datosProd);
    string ListarProductos();
    string ListarProductosBasic(); //No muestra en el listado el precio a diferencia del otro es para que quede igual al caso de uso
    string DescribeProducto(int indiceP);
    string listarProductosPendientes(string nick);
    string listarCompraProductoPendiente(int codigoProd);
    void selectCompraProductoPendiente(int idCompra);
//VENDEDOR    
    void ingresoVendedor(DataVendedor* datosV, string contraseña);
    string ListaVendedores();
    string ListarProductosV(int Vendor,string nombreProm,string descripcionProm,date fechaVenProm);
//PROMOCION
    void SelectProductoProm(int indiceProd,string nombreProm,int cantMin,int porcentajeDes);
    string solicitarListaPromociones();
    string obtenerProductosVendedoresPromocion(string nombrePromo);    
//COMPRA
    string listarNicknamesC();
    void selectNicknameC(int indiceCli);
    void agregarProducto(int indice, int cant);
    void mostrarDetalleCompra();
    void confirmarCompra(int indiceCli);
    
private:
   
    //CONTROLADOR();
    //static CONTROLADOR* instancia;
    
    COMPRA* com;
    IDictionary* misProductos;
    IDictionary* misUsuarios;
    IDictionary* misVendedores = NULL;
    IDictionary* misClientes;
    IDictionary* misPromociones;
};

#endif /* CONTROLADOR_H */

