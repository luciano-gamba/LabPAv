#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "date.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"
using namespace std;

class COMENTARIO;

class USUARIO : public ICollectible {
public:
    USUARIO();
    virtual ~USUARIO();
    
    string getNickname();
    
    void desAsignarComentarioAUsu(COMENTARIO *c);
    
private:
    string nickname;
    string contrasenia;
    date fechaNac;
    
    IDictionary *misComentarios;
};

#endif /* USUARIO_H */

