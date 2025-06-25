#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include "DTProducto.h"
#include "compra_producto.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "VENDEDOR.h"
class PRODUCTO : public ICollectible {
public:
    PRODUCTO();
    PRODUCTO(const PRODUCTO& orig);
    PRODUCTO(DTProducto*, int);
    virtual ~PRODUCTO();
    int getCodigo(); 
    int getStock();
    float getPrecio();
    std::string getNombre();
    std::string getDescripcion();
    string getNicknameVendedor();
    bool pendienteEnvio();
private:
    int codigo;
    int stock;
    float precio;
    std::string nombre;
    std::string descripcion;
    IDictionary* misCompraProductos;
    VENDEDOR* vendedorAsociado;
};

#endif /* PRODUCTO_H */

