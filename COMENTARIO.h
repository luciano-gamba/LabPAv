#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
#include <ctime>
#include "date.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/Integer.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/collections/OrderedDictionaryEntry.h"
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
    
    int getCodComent();
    string getTexto();
    date getFechaCom();
    
    string getInfoComentario();
    
    void asignarComentarioACom(COMENTARIO* c);
    void DesAsignarComentarioACom(COMENTARIO* c);
    
private:
    string texto;
    date fechaCom;
    
    PRODUCTO *miProducto;
    USUARIO *miUsuario;
    ICollection *misComentarios;
};

#endif /* COMENTARIO_H */

