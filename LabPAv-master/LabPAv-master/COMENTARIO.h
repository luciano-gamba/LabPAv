#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
#include <ctime>
#include "date.h"
#include "USUARIO.h"
#include "PRODUCTO.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/Integer.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/collections/OrderedDictionaryEntry.h"
#include "ICollection/interfaces/ICollectible.h"
using namespace std;


class COMENTARIO : public ICollectible{
public:
    COMENTARIO();
    ~COMENTARIO();
   
    void setCodComent(int n);
    void setTexto(string t);
    void setFechaCom();
    
    int getCodComent();
    string getTexto();
    date getFechaCom();
    
    string getInfoComentario();
    
    COMENTARIO* crearRespuesta(string t);
    
private:
    int codComent;
    string texto;
    date fechaCom;
    
    PRODUCTO *miProducto;
    USUARIO *miUsuario;
    IDictionary *misComentarios;
};

#endif /* COMENTARIO_H */

