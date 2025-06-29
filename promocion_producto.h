#ifndef PROMOCION_PRODUCTO_H
#define PROMOCION_PRODUCTO_H

#include "ICollection/interfaces/ICollectible.h"

#include "PRODUCTO.h" //Como uso funciones de esta clase no puedo hacer un fordware declaration

class PROMOCION;
//Solucion para la referencia circular (es algo que si o si pasaria en tipos asociativos como este que apunta a ambas clases que lo "generan").


class promocion_producto : public ICollectible {
public:
    promocion_producto();
    promocion_producto(const promocion_producto& orig);
    promocion_producto(PROMOCION* prom,PRODUCTO* prod,int cantMini,int porcentajeDes);
    virtual ~promocion_producto();
private:
    int cant;
    int cantMin;
    bool cumpleCant;
    float porcentaje;
    float precioConPromo;
    PRODUCTO* miProducto;
    PROMOCION* miPromocion;
};

#endif /* PROMOCION_PRODUCTO_H */

