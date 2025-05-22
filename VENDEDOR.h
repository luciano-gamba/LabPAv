#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "USUARIO.h"
#include <string>

class VENDEDOR : public USUARIO{
public:
    VENDEDOR();
    VENDEDOR(const VENDEDOR& orig);
    virtual ~VENDEDOR();
private:
    std::string RUT;
};

#endif /* VENDEDOR_H */