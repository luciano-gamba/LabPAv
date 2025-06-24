#ifndef COMPRA_H
#define COMPRA_H
#include "date.h"
#include "DataProducto.h"
#include <set>

class COMPRA {
public:
    COMPRA();
    virtual ~COMPRA();
    void agregarProducto(string codigoProd ,int cant);
private:
    std::set<DataProducto> items;
    date fechaCompra;
    float monto;
};

#endif /* COMPRA_H */

