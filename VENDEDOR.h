#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "USUARIO.h"
#include "PRODUCTO.h"
#include "DataVendedor.h"
#include <string>
#include "ICollection/interfaces/ICollection.h" //Siu
class VENDEDOR : public USUARIO{
public:
    VENDEDOR();
    VENDEDOR(const VENDEDOR& orig);
    VENDEDOR(DataVendedor*,string);
    virtual ~VENDEDOR();
    string GetProductosAsoc();
    void crearPromo(std::string nombreProm,std::string descripcionProm,date fechaVen);
    string dameProductosPendientes();
    string getNicknameVendedor();
    string getContraseniaVendedor();
    date getFechaNacVendedor();
    string getRUT();
    void setNicknameVendedor(string);
    void setContraseniaVendedor(string);
    void setFechaNacVendedor(date);
    void setRUT(string);
private:
    std::string RUT;
    IDictionary* misProductos;
};

#endif /* VENDEDOR_H */