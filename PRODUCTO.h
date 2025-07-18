#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include "DTProducto.h"
#include "compra_producto.h"
#include "COMENTARIO.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "TipoProducto.h"
#include <ctime>

class promocion_producto;

#include "ICollection/collections/List.h"
#include <set>
//#include "VENDEDOR.h"
using namespace std;

// Declaración adelantada para evitar dependencia circular
class VENDEDOR;

class PRODUCTO : public ICollectible {
public:
    PRODUCTO();
    PRODUCTO(const PRODUCTO& orig);
    PRODUCTO(DTProducto*, int);
    virtual ~PRODUCTO();
    
    int getCodigo(); 
    int getStock();
    float getPrecio();
    string getNombre();
    string getDescripcion();
    string getNicknameVendedor();
    string getCategoria();
    
    void setstock(int);
    void setprecio(float);
    void setnombre(string);
    void setdescr(string);
    
    bool pendienteEnvio();
    void setVendedorAsociado(VENDEDOR* v);
    string dameComprasPend();
    void marcoRecibido(int idCompra);
  
    string getInfoMisComentarios();
    int getSizeMisComentarios();
    COMENTARIO* crearRespuesta(int opC, string texto);
    COMENTARIO* createComentario(string texto);
    void asignarComentarioAProd(COMENTARIO* c);
    void desAsignarComentarioAProd(COMENTARIO* c);
    void Conoceme(promocion_producto* pp);
    bool estoyEnPromo();
    void agregar(compra_producto*);
    
private:
    int codigo;
    int stock;
    float precio;
    string nombre;
    string descripcion;
    TipoProducto Categoria;
    ICollection* misCompraProductos;
    ICollection* PromosdeProducto;
    ICollection* misComentarios;
    VENDEDOR* vendedorAsociado;
};

#endif /* PRODUCTO_H */

