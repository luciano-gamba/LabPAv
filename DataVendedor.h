#ifndef DATAVENDEDOR_H
#define DATAVENDEDOR_H
#include <string>
#include "DataUsuario.h"
using namespace std;

class DataVendedor: public DataUsuario {
public:
    DataVendedor();
    DataVendedor(string,date,string);
    DataVendedor(const DataVendedor& orig);
    virtual ~DataVendedor();
    string getNicknameVendedor();
    date getDateVendedor();
    string getRUT();
    void setNicknameVendedor(string);
    void setDateVendedor(date);
    void setRUT(string);
private:
    string RUT;
};

#endif /* DATAVENDEDOR_H */

