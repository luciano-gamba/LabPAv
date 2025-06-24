#ifndef TIPOPRODUCTO_H
#define TIPOPRODUCTO_H
#include <string>
using namespace std;

enum class TipoProducto{
    Ropa,
    Electrodomesticos,
    Otros
};

inline string TipoProductoToString(TipoProducto tipo) {
    switch (tipo) {
        case TipoProducto::Ropa: 
            return "Ropa";
        case TipoProducto::Electrodomesticos: 
            return "Electrodomésticos";
        case TipoProducto::Otros: 
            return "Otros";
        default: 
            return "Desconocido";
    }
}

#endif /* TIPOPRODUCTO_H */

