#ifndef FABRICA_H
#define FABRICA_H
#include "CONTROLADOR.h"
#include "ICONTROLADOR.h"
class FABRICA {
public:
    FABRICA();
    FABRICA(const FABRICA& orig);
    virtual ~FABRICA();
    
    ICONTROLADOR* getControlador();
private:

};

#endif /* FABRICA_H */

