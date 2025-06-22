
#include "FABRICA.h"

FABRICA::FABRICA() {
}
FABRICA::~FABRICA() {
}
ICONTROLADOR* FABRICA::getIControlador(){
    return CONTROLADOR::getInstancia();
    ;
}

