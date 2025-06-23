#ifndef DATAUSUARIO_H
#define DATAUSUARIO_H
#include <string>
#include "date.h"
using namespace std;

class DataUsuario {
public:
    DataUsuario();
    DataUsuario(const DataUsuario& orig);
    DataUsuario(string,date);
    virtual ~DataUsuario();
    string getNickname();
    date getDate();
    void setNickname(string);
    void setDate(date);
private:
    string nickname;
    date fechaNac;
};

#endif /* DATAUSUARIO_H */

