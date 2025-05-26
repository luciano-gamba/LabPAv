#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string.h>
#include "date.h"

class COMENTARIO {
public:
    COMENTARIO();
    COMENTARIO(const COMENTARIO& orig);
    virtual ~COMENTARIO();
private:
    int codComent;
    std::string texto;
    date fechaCom;
};

#endif /* COMENTARIO_H */

