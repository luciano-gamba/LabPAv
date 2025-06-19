#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "date.h"
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

class USUARIO : public ICollectible {
public:
    USUARIO();
    virtual ~USUARIO();
    
    string getNickname();
    
    
private:
    string nickname;
    string contrasenia;
    date fechaNac;
};

#endif /* USUARIO_H */

