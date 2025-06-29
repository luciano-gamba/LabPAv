#ifndef DATAPRODUCTO_H
#define DATAPRODUCTO_H
#include <string>

using namespace std;

class DataProducto {
public:
    DataProducto();
    DataProducto(const DataProducto& orig);
    virtual ~DataProducto();
    DataProducto(string, int);
    
    // Operador < necesario para std::set
    bool operator<(const DataProducto& other) const;
    
private:
    string codigo;
    std::string nombre;
    int cant;
    float precio;
    float coste;
};

#endif /* DATAPRODUCTO_H */

