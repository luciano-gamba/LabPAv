#ifndef COMPRA_H
#define COMPRA_H
#include "date.h"
#include "DataProducto.h"
#include <set>

class COMPRA {
public:
    COMPRA();
    COMPRA(const COMPRA& orig);
    virtual ~COMPRA();
private:
    std::set<DataProducto> items;
    date fechaCompra;
    float monto;
};

#endif /* COMPRA_H */

