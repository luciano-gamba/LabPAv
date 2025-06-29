#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "USUARIO.h"
#include "PRODUCTO.h"
#include "PROMOCION.h"
#include "DataVendedor.h"
#include "DataVendedor.h"
#include "DTProducto.h"
using namespace std;

class VENDEDOR : public USUARIO{
public:
    VENDEDOR();
    VENDEDOR(const VENDEDOR& orig);
    VENDEDOR(DataVendedor*,string);
    virtual ~VENDEDOR();
    string GetProductosAsoc();
    PROMOCION* crearPromo(string nombreProm,string descripcionProm,date fechaVen);
    string dameProductosPendientes();
    PRODUCTO* añadirProducto(DTProducto*);
    string getNicknameVendedor();
    string getContraseniaVendedor();
    date getFechaNacVendedor();
    string getRUT();
    string getEmailVendedor();
    void setNicknameVendedor(string);
    void setContraseniaVendedor(string);
    void setFechaNacVendedor(date);
    void setRUT(string);
    void marcaloRecibido(int idCompra);
private:
    std::string RUT;
    IDictionary* misProductos;
    ICollection* misPromociones;
};

#endif /* VENDEDOR_H */