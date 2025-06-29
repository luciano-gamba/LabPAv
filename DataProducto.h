#ifndef DATAPRODUCTO_H
#define DATAPRODUCTO_H
#include <string>

class DataProducto {
public:
    DataProducto();
    DataProducto(const DataProducto& orig);
    virtual ~DataProducto();
    
    // Operador < necesario para std::set
    bool operator<(const DataProducto& other) const;
    
private:
    int codigo;
    std::string nombre;
    int cant;
    float precio;
    float coste;
};

#endif /* DATAPRODUCTO_H */

