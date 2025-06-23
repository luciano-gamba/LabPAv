#ifndef DATADIRECCION_H
#define DATADIRECCION_H
#include <string>
using namespace std;

class DataDireccion {
public:
    DataDireccion();
    DataDireccion(const DataDireccion& orig);
    DataDireccion(int,string);
    virtual ~DataDireccion();
private:
    int numPuerta;
    string nomCalle;
};

#endif /* DATADIRECCION_H */

