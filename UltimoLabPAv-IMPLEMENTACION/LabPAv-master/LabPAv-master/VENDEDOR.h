#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "USUARIO.h"
#include <string>

class VENDEDOR : public USUARIO{
public:
    VENDEDOR();
    VENDEDOR(const VENDEDOR& orig);
    virtual ~VENDEDOR();
    ICollecction* GetProductosAsoc()
    void crearPromo(std::string nombreProm,std::string descripcionProm,date fechaVen);
private:
    std::string RUT;
};

#endif /* VENDEDOR_H */