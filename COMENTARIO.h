#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
#include <ctime>
#include "date.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/Integer.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

class USUARIO;
class PRODUCTO;

class COMENTARIO : public ICollectible{
public:
    COMENTARIO();
    ~COMENTARIO();
   
    void setTexto(string t);
    void setFechaCom();
    
    string getTexto();
    date getFechaCom();
    
    string getInfoComentario();
    
    void asignarComentarioACom(COMENTARIO* c);
    void DesAsignarComentarioACom(COMENTARIO* c);
    
    void asignarUsuarioACom(USUARIO* u);
    void asignarProductoACom(PRODUCTO* p);
    
private:
    string texto;
    date fechaCom;
    
    PRODUCTO *miProducto;
    USUARIO *miUsuario;
    ICollection *misComentarios;
};

#endif /* COMENTARIO_H */

