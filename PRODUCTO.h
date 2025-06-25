#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include "DTProducto.h"
#include "compra_producto.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include <set>

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
    bool pendienteEnvio();
    string dameComprasPend();
    void marcoRecibido(int idCompra);
private:
    int codigo;
    int stock;
    float precio;
    std::string nombre;
    std::string descripcion;
    IDictionary* misCompraProductos;
};

#endif /* PRODUCTO_H */

