#ifndef PROMOCION_H
#define PROMOCION_H
#include <string>
#include <ctime>
#include "date.h"
using namespace std;

class PROMOCION {
public:
    PROMOCION();
    PROMOCION(const PROMOCION& orig);
    virtual ~PROMOCION();
    void obtenerFechaSistema();
    string solicitarListaPromociones();
    string getNombre();
    string getDescrip();
    string getInfoPromo();
     date getFechaVen();
    
private:
    std::string nombrePromo;
    std::string descripcionPromo;
    date fechaVen;
    date fechaSis;
};

#endif /* PROMOCION_H */

