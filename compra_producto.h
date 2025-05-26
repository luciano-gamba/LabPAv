#ifndef COMPRA_PRODUCTO_H
#define COMPRA_PRODUCTO_H
#include "date.h"

class compra_producto {
public:
    compra_producto();
    compra_producto(const compra_producto& orig);
    virtual ~compra_producto();
private:
    bool recibido;
    date fechaRecibida;
};

#endif /* COMPRA_PRODUCTO_H */

