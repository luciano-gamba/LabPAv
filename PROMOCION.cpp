#include "PROMOCION.h"

set<string> Controlador::solicitarListaPromociones(){
    set<string> promocionesActivas;
    date fechaSistema = obtenerFechaSistema(); //despues se hara esta funcion

    iterator* it= this->pPromociones->getIterator();
    while(it->hasCurrent()){
        Promocion* p = (Promocion*)it->getCurrent();
        if(p->GetFechaVen() > fechaSistema){
            promocionesActivas.insert(p->GetNombre());
        }
        it->next();
    }
    delete it;
    return promocionesActivas;
}

PROMOCION::PROMOCION() {
}

PROMOCION::PROMOCION(const PROMOCION& orig) {
}

PROMOCION::~PROMOCION() {
}

