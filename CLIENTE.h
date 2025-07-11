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
    COMPRA* getCompraActiva(CLIENTE* cli);
    void setCompraActiva(COMPRA* c);
    void setNicknameCliente(string);
    void setContraseniaCliente(string);
    void setFechaNacCliente(date);
    void setCiudad(string);
    void setDireccion(DataDireccion*);
    void agregarMisCompras(COMPRA*);
    string getMisCompras();
private:
    COMPRA* compraActiva;
    string ciudad;
    DataDireccion* direccion;  
    ICollection* misCompras = nullptr;
};

#endif /* CLIENTE_H */

