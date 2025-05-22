#ifndef CLIENTE_H
#define CLIENTE_H
#include "USUARIO.h"
#include "DataDireccion.h"
#include <string>

class CLIENTE : public USUARIO{
public:
    CLIENTE();
    CLIENTE(const CLIENTE& orig);
    virtual ~CLIENTE();
private:
    std::string ciudad;
    DataDireccion direccion;    
};

#endif /* CLIENTE_H */

