#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "date.h"

class USUARIO {
public:
    USUARIO();
    USUARIO(const USUARIO& orig);
    virtual ~USUARIO();
private:
    std::string nickname;
    std::string contrasenia;
    date fechaNac;
};

#endif /* USUARIO_H */

