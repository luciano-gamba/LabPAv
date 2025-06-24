#ifndef DATACLIENTE_H
#define DATACLIENTE_H
#include <string>
#include "DataDireccion.h"
#include "DataUsuario.h"
using namespace std;

class DataCliente: public DataUsuario {
public:
    DataCliente();
    DataCliente(string,date,string,DataDireccion);
    DataCliente(const DataCliente& orig);
    virtual ~DataCliente();
    string getNicknameCliente();
    date getDateCliente();
    string getCiudad();
    DataDireccion getDireccion();
    void setNicknameCliente(string);
    void setDateCliente(date);
    void setCiudad(string);
    void setDireccion(DataDireccion);
private:
    string ciudad;
    DataDireccion direccion;
};

#endif /* DATACLIENTE_H */
