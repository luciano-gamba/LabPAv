#ifndef PROMOCION_H
#define PROMOCION_H
#include <string.h>
#include <string>
#include "date.h"

class PROMOCION {
public:
    PROMOCION();
    PROMOCION(const PROMOCION& orig);
    virtual ~PROMOCION();
    void obtenerFechaSistema();
    
private:
    std::string nombrePromo;
    std::string descripcionPromo;
    date fechaVen;
    date fechaSis;
};

#endif /* PROMOCION_H */

