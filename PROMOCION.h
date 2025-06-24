#ifndef PROMOCION_H
#define PROMOCION_H
#include <string>
#include "USUARIO.h"
#include "PRODUCTO.h"
#include <ctime>
#include "date.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"

using namespace std;

class PROMOCION : public ICollectible {
public:
    PROMOCION();
    PROMOCION(string nombre, string descripcion, date fechaV);
    virtual ~PROMOCION();

    // Getters
    string getNombre();
    string getDescripcion();
    date getFechaVen();
    date getFechaSis(); 
    void setNombre(string);
    void setDescripcion(string);
    void setFechaVen(date);
    
private:
    IDictionary* coleccionPromociones;  // productos asociados a la promoción
    string nombrePromo;
    string descripcionPromo;
    date fechaVen;
    date fechaSis;
    string promoStr;
};

#endif /* PROMOCION_H */
