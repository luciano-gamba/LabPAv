#ifndef DATAPROD_H
#define DATAPROD_H

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

