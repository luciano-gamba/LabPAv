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
    CONTROLADOR();
//CLIENTE
    
//COMENTARIO

//USUARIO
   

    
    
private:
   
    /*
        CONTROLADOR* instancia = nullptr;
        CONTROLADOR();
    */
    
    
};

#endif /* CONTROLADOR_H */

