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
private:
    std::string nombrePromo;
    std::string descripcionPromo;
    date fechaVen;
};

#endif /* PROMOCION_H */

