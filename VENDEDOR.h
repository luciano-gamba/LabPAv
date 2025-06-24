#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "USUARIO.h"
#include "PRODUCTO.h"
#include "PROMOCION.h"
#include "DataVendedor.h"
#include <string>
#include "ICollection/interfaces/ICollection.h" //Siu
using namespace std;

class VENDEDOR : public USUARIO{
public:
    VENDEDOR();
    VENDEDOR(const VENDEDOR& orig);
    VENDEDOR(DataVendedor*,string);
    virtual ~VENDEDOR();
    string GetProductosAsoc();
    PROMOCION* crearPromo(std::string nombreProm,std::string descripcionProm,date fechaVen);
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
    ICollection* misPromociones;
};

#endif /* VENDEDOR_H */