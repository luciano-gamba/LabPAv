#ifndef DATAPRODUCTO_H
#define DATAPRODUCTO_H
#include <string>
#include "ICollection/interfaces/ICollectible.h"

using namespace std;

class DataProducto : public ICollectible {
public:
    DataProducto();
    DataProducto(const DataProducto& orig);
    virtual ~DataProducto();
    DataProducto(float, string, int, int);
    
    string getInfo();
    // Operador < necesario para std::set
    bool operator<(const DataProducto& other) const;
    
private:
    int codigo;
    string nombre;
    int cant;
    float precio;
    float coste;
};

#endif /* DATAPRODUCTO_H */

