#ifndef DATAPROD_H
#define DATAPROD_H
#include <string>

class DataProd {
public:
    DataProd();
    DataProd(const DataProd& orig);
    virtual ~DataProd();
private:
    int codigoProd;
    std::string nombreProd;
    float precioProd;
};

#endif /* DATAPROD_H */

