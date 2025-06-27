#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H
#include <string>
#include "TipoProducto.h"

using namespace std;

class DTProducto {
public:
    DTProducto();
    DTProducto(const DTProducto& orig);
    DTProducto(string,float,int,string,TipoProducto);
    virtual ~DTProducto();
    
    string getNomProd();
    float getPrecio();
    int getCantStock();
    string getDescProd();
    TipoProducto getCategoria();
    string getCategoriaString();
private:
    string nomProd;
    float precio;
    int cantStock;
    string descProd;
    TipoProducto categoria;
};

#endif /* DTPRODUCTO_H */

