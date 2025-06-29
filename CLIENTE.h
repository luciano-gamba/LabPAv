#ifndef CLIENTE_H
#define CLIENTE_H
#include "USUARIO.h"
#include "DataDireccion.h"
#include "DataCliente.h"
#include "COMPRA.h"
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
    DataDireccion* getDireccion();
    COMPRA* getCompraActiva();
    void setCompraActiva(COMPRA* c);
    void setNicknameCliente(string);
    void setContraseniaCliente(string);
    void setFechaNacCliente(date);
    void setCiudad(string);
    void setDireccion(DataDireccion*);
    void agregarMisCompras(COMPRA*);
private:
    COMPRA* compraActiva;
    string ciudad;
    DataDireccion* direccion;  
    ICollection* misCompras;
};

#endif /* CLIENTE_H */

