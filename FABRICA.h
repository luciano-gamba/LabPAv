#ifndef FABRICA_H
#define FABRICA_H
#include "CONTROLADOR.h"
#include "ICONTROLADOR.h"
class FABRICA {
public:
    FABRICA();  
    ~FABRICA();
    ICONTROLADOR* getIControlador();
private:
};

#endif /* FABRICA_H */

