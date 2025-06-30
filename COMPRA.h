#ifndef COMPRA_H
#define COMPRA_H
#include "date.h"
#include "DataProducto.h"
#include "DataCompra.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "PRODUCTO.h"

// Declaraciones adelantadas para evitar dependencia circular
class CLIENTE;
class compra_producto;

class COMPRA : public ICollectible{
public:
    COMPRA();
    virtual ~COMPRA();
    void agregarProducto(int codigoProd ,int cant, PRODUCTO* p);
    static COMPRA* create();
    date getFechaCompra();
    float montoCompra();
    string getItems();
    void setFechaCompra();
    void setMontoCompra(float);
    void setCP();
    void setId(int id);
       
    int getid();
    string getNickname();
    date getFecha();
private:
    int idCompra;
    ICollection* items; //aca se guardan los productos
    date fechaCompra;
    float monto;
    IDictionary* productosCompra;
    CLIENTE* miCliente;
};

#endif /* COMPRA_H */

