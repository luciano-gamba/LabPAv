#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "USUARIO.h"
#include "PRODUCTO.h"
#include <string>
#include "ICollection/interfaces/ICollection.h" //Siu
class VENDEDOR : public USUARIO{
public:
    VENDEDOR();
    VENDEDOR(const VENDEDOR& orig);
    virtual ~VENDEDOR();
    ICollection* GetProductosAsoc();
    void crearPromo(std::string nombreProm,std::string descripcionProm,date fechaVen);
    string dameProductosPendientes();
private:
    std::string RUT;
    IDictionary* misProductos;
};

#endif /* VENDEDOR_H */