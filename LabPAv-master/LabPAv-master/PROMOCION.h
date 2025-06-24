#ifndef PROMOCION_H
#define PROMOCION_H
#include <string>
#include "USUARIO.h"
#include "PRODUCTO.h"
#include <ctime>
#include "date.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "USUARIO.h"
#include "PRODUCTO.h"
#include "promocion_producto.h"
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
    date getFechaSis() const; 
    void setNombre(string);
    void setDescripcion(string);
    void setFechaVen(date);
    
    void Conoceme(PRODUCTO* prod,int cantMin,int porcentajeDes);
private:
    IDictionary* coleccionPromociones;
    string nombrePromo;
    string descripcionPromo;
    date fechaVen;
    ICollection* ProductosdePromo;
    date fechaSis;
};

#endif /* PROMOCION_H */

