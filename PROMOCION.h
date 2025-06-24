#ifndef PROMOCION_H
#define PROMOCION_H
#include <string>
#include "USUARIO.h"
#include "PRODUCTO.h"
#include <ctime>
#include "date.h"
#include "ICollection/interfaces/ICollectible.h"

using namespace std;

class PROMOCION: public ICollectible{
public:
    PROMOCION();
    PROMOCION(string nombre,string descripcion,date fechaV);
    virtual ~PROMOCION();
    void obtenerFechaSistema();
    string solicitarListaPromociones();
    string getNombre();
    string getDescripcion();
    date getFechaVen();
    date getFechaSis(); 
    void setNombre(string);
    void setDescripcion(string);
    void setFechaVen(date);
    void setFechaSis(date);
    
private:
    IDictionary* coleccionPromociones;
    string nombrePromo;
    string descripcionPromo;
    date fechaVen;
    date fechaSis;
};

#endif /* PROMOCION_H */

