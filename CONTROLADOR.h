#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "ICONTROLADOR.h"
#include "CLIENTE.h"
#include "COMENTARIO.h"
#include "USUARIO.h"
using namespace std;

class CONTROLADOR: public ICONTROLADOR{
public:
    //operaciones de funcionamiento
    CONTROLADOR *getInstancia();
    ~CONTROLADOR();
    
//CLIENTE
    
//COMENTARIO

//USUARIO
   

    
    
private:
    CONTROLADOR *CONTROLADOR();
    static CONTROLADOR *instancia = nullptr;
    
    
    
    
};

#endif /* CONTROLADOR_H */

