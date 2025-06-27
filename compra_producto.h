#ifndef COMPRA_PRODUCTO_H
#define COMPRA_PRODUCTO_H
#include "date.h"
#include "ICollection/interfaces/ICollectible.h"

// Declaración adelantada para evitar dependencia circular
class PRODUCTO;

class compra_producto: public ICollectible {
public:
    compra_producto();
    compra_producto(const compra_producto& orig);
    virtual ~compra_producto();
    bool getRecibido();
    compra_producto(PRODUCTO* p, int cant);
    PRODUCTO* getProducto();
    int getCantidad();
    void add();
private:
    PRODUCTO* prod;
    int cantidad;
    bool recibido;
    date fechaRecibida;
};

#endif /* COMPRA_PRODUCTO_H */

