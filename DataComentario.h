#ifndef DATACOMENTARIO_H
#define DATACOMENTARIO_H
#include <string.h>
#include "date.h"

class DataComentario {
public:
    DataComentario();
    DataComentario(const DataComentario& orig);
    virtual ~DataComentario();
private:
    int codComent;
    std::string texto;
    date fechaCom;
};

#endif /* DATACOMENTARIO_H */

