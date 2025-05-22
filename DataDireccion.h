#ifndef DATADIRECCION_H
#define DATADIRECCION_H
#include <string>

class DataDireccion {
public:
    DataDireccion();
    DataDireccion(const DataDireccion& orig);
    virtual ~DataDireccion();
private:
    int numPuerta;
    std::string nomCalle;
};

#endif /* DATADIRECCION_H */

