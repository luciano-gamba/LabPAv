#ifndef DATACOMPRACLIENTE_H
#define DATACOMPRACLIENTE_H
#include <string>
#include "date.h"
using namespace std;

class DataCompraCliente {
public:
    DataCompraCliente();
    DataCompraCliente(const DataCompraCliente& orig);
    virtual ~DataCompraCliente();
    void setIdCompra(int);
    void setNicknameCli(string);
    void setFechaCompra(date);
private:
    int idCompra;
    string nicknameCli;
    date fechaCompra;
};

#endif /* DATACOMPRACLIENTE_H */

