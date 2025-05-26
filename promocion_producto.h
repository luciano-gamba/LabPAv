#ifndef PROMOCION_PRODUCTO_H
#define PROMOCION_PRODUCTO_H

class promocion_producto {
public:
    promocion_producto();
    promocion_producto(const promocion_producto& orig);
    virtual ~promocion_producto();
private:
    int cant;
    int cantMin;
    bool cumpleCant;
    float porcentaje;
    float precioConPromo;

};

#endif /* PROMOCION_PRODUCTO_H */

