#ifndef CLIENTE_H
#define CLIENTE_H
#include "USUARIO.h"
#include "DataDireccion.h"
#include "DataCliente.h"
#include <string>

class CLIENTE : public USUARIO{
public:
    CLIENTE();
    CLIENTE(const CLIENTE& orig);
    CLIENTE(DataCliente*, string);
    virtual ~CLIENTE();
    string getNicknameCliente();
    string getContraseniaCliente();
    date getFechaNacCliente();
    string getCiudad();
    DataDireccion getDireccion();
    void setNicknameCliente(string);
    void setContraseniaCliente(string);
    void setFechaNacCliente(date);
    void setCiudad(string);
    void setDireccion(DataDireccion);
private:
    std::string ciudad;
    DataDireccion direccion;    
};

#endif /* CLIENTE_H */

