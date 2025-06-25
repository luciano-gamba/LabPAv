#ifndef COMPRA_PRODUCTO_H
#define COMPRA_PRODUCTO_H
#include "date.h"
#include "ICollection/interfaces/ICollectible.h"
#include "DataCompraCliente.h"
#include "COMPRA.h"

class compra_producto: public ICollectible {
public:
    compra_producto();
    compra_producto(const compra_producto& orig);
    virtual ~compra_producto();
    bool getRecibido();
    DataCompraCliente dameCompra();
private:
    bool recibido;
    date fechaRecibida;
    COMPRA* miCompra;
};

#endif /* COMPRA_PRODUCTO_H */

