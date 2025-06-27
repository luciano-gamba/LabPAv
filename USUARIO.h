#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "date.h"
#include "COMENTARIO.h"
#include "ICollection/Integer.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"
using namespace std;


class USUARIO : public ICollectible {
public:
    USUARIO();
    USUARIO(string, string, date);
    virtual ~USUARIO();
    
    string getNickname();
    string getContrasenia();
    date getFechaNac();
    
    void setNickname(string);
    void setContrasenia(string);
    void setFechaNac(date);
    
    string getInfoMisComentarios();
    void asignarComentarioAUsu(COMENTARIO* c);
    void desAsignarComentarioAUsu(COMENTARIO* c);
    void eliminarComentarioUsuario(int opU);
    
private:
    string nickname;
    string contrasenia;
    date fechaNac;
    
    ICollection* misComentarios;
};

#endif /* USUARIO_H */

