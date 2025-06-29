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
        case TipoProducto::Ropa:{ 
            return "Ropa";
            break;
        }
        case TipoProducto::Electrodomesticos:{ 
            return "Electrodomésticos";
            break;
        }
        case TipoProducto::Otros: {
            return "Otros";
            break;
        }
        default:{ 
            return "Desconocido";
            break;
        }
    }
}

#endif /* TIPOPRODUCTO_H */

