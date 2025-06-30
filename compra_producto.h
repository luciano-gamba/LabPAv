#ifndef COMPRA_PRODUCTO_H
#define COMPRA_PRODUCTO_H
#include "date.h"
#include "ICollection/interfaces/ICollectible.h"

// Declaraciones adelantadas para evitar dependencia circular
class PRODUCTO;
class COMPRA;

class compra_producto: public ICollectible {
public:
    compra_producto();
    compra_producto(const compra_producto& orig);
    virtual ~compra_producto();
    compra_producto(PRODUCTO* p, int cant, COMPRA* c);
    bool getRecibido();
    string dameCompra();
    bool getsi_idCompra(int idCompra);
    void marcaRecibido();
    PRODUCTO* getProducto();
    int getCantidad();
    void add();
    compra_producto* create(PRODUCTO*, int);
private:
    PRODUCTO* prod;
    int cantidad;
    bool recibido;
    date fechaRecibida;
    COMPRA* miCompra;
};

#endif /* COMPRA_PRODUCTO_H */

