#ifndef PROMOCION_H
#define PROMOCION_H
#include <string>
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
    string getDescrip();
    string getInfoPromo();
    date getFechaVen();
    
private:
    string nombrePromo;
    string descripcionPromo;
    date fechaVen;
    date fechaSis;
};

#endif /* PROMOCION_H */

