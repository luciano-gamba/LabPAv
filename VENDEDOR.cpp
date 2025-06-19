#include "VENDEDOR.h"
#include <cstdlib>

VENDEDOR::VENDEDOR() {
}

VENDEDOR::VENDEDOR(const VENDEDOR& orig) {
}

VENDEDOR::~VENDEDOR() {
}

string VENDEDOR::dameProductosPendientes(){
     bool pendiente;
     PRODUCTO* p;
     string productosPendientes;
    
    IIterator* it=this->misProductos->getIterator();
    for(it; it->hasCurrent(); it->next()){
      p = (PRODUCTO*)it->getCurrent();
      pendiente = p->pendienteEnvio();
      if(pendiente){
          productosPendientes = productosPendientes + to_string(p->getCodigo()) + " " + p->getNombre() + "/n";
      }
    }
    return productosPendientes;
}


string VENDEDOR::GetProductosAsoc(){
    
    IIterator* IT=this->misProductos->getIterator();
    PRODUCTO* P;
    int codP;
    string nomP;
    string ProdV = ""; //Creo una collecction donde guardare los datos que luego listare y esta función devolvera.
    for(IT;IT->hasCurrent();IT->next()){
        P = (PRODUCTO*)IT->getCurrent();
        codP=P->getCodigo(); 
        nomP=P->getNombre(); //Ambos datos del producto que necesito para el listado
        ProdV=ProdV +to_string(codP) + " - " + nomP + "\n";
    }
    return ProdV;
}
/*
VENDEDOR::crearPromo(string nombreProm,string descripcionProm,date fechaVen){
    PROMOCION prom = new PROMOCION(nombreProm ,descripcionProm ,fechaVen);
    This->MisPromociones.Add(prom);
    
} 
 */   