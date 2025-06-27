#ifndef COMPRA_H
#define COMPRA_H
#include "date.h"
#include "DataProducto.h"
#include "DataCompra.h"
#include <set>
#include "CLIENTE.h"
#include "ICollection/interfaces/IDictionary.h"
#include "compra_producto.h"

class COMPRA {
public:
    COMPRA();
    virtual ~COMPRA();
    void agregarProducto(string codigoProd ,int cant);
    static COMPRA* create();
    date getFechaCompra();
    float montoCompra();
    set<DataProducto> getItems();
    void setFechaCompra(date);
    void setMontoCompra(float);
       
    int getid();
    string getNickname();
    date getFecha();
private:
    int idCompra;
    std::set<DataProducto> items;
    date fechaCompra;
    float monto;
    IDictionary* productosCompra;
    CLIENTE* miCliente;
};

#endif /* COMPRA_H */

