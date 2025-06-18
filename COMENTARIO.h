#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
#include <ctime>
#include "date.h"
using namespace std;


class COMENTARIO {
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
    
private:
    int codComent;
    string texto;
    date fechaCom;
};

#endif /* COMENTARIO_H */

