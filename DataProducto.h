#ifndef DATAPRODUCTO_H
#define DATAPRODUCTO_H
#include <string.h>

class DataProducto {
public:
    DataProducto();
    DataProducto(const DataProducto& orig);
    virtual ~DataProducto();
private:
    int codigo;
    std::string nombre;
    int cant;
    float precio;
    float coste;
};

#endif /* DATAPRODUCTO_H */

