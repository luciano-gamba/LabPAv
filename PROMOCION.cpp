#include "PROMOCION.h"

PROMOCION::PROMOCION() {
}

PROMOCION::PROMOCION(const PROMOCION& orig) {
}

PROMOCION::~PROMOCION() {
}

void PROMOCION::obtenerFechaSistema(){
    time_t ya = time(NULL);
    date d = date(localtime(&ya)->tm_mday,localtime(&ya)->tm_mon+1,localtime(&ya)->tm_year+1900);
    this->fechaSis = d;
}

/*string PROMOCION::solicitarListaPromociones(){
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
*/
string PROMOCION::getNombre(){
    return this->nombrePromo;
}
string PROMOCION::getDescrip(){
    return this->descripcionPromo;
}

date PROMOCION::getFechaVen(){
    return this->fechaVen;
}

string PROMOCION::getInfoPromo(){
    return "<>NombrePromo: "+(this->nombrePromo)+"\n<>Desc: "+this->descripcionPromo+"\n<>Fecha: "+this->fechaVen.getInfoDate();
}