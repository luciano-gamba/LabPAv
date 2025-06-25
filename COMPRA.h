#ifndef COMPRA_H
#define COMPRA_H
#include "date.h"
#include "DataProducto.h"
#include <set>
#include "CLIENTE.h"

class COMPRA {
public:
    COMPRA();
    virtual ~COMPRA();
    void agregarProducto(string codigoProd ,int cant);
    int getid();
    string getNickname();
    date getFecha();
private:
    int idCompra;
    std::set<DataProducto> items;
    date fechaCompra;
    float monto;
    CLIENTE* miCliente;
};

#endif /* COMPRA_H */

