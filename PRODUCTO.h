#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

class PRODUCTO {
public:
    PRODUCTO();
    PRODUCTO(const PRODUCTO& orig);
    virtual ~PRODUCTO();
private:
    int codigo;
    int stock;
    float precio;
    std::string nombre;
    std::string descripcion;
};

#endif /* PRODUCTO_H */

