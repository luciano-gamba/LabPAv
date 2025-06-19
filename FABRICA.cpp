
#include "FABRICA.h"

FABRICA::FABRICA() {
}

FABRICA::FABRICA(const FABRICA& orig) {
}

FABRICA::~FABRICA() {
}
ICONTROLADOR* FABRICA::getControlador(){
    return(new CONTROLADOR());
}

