#include "VENDEDOR.h"
#include <cstdlib>

VENDEDOR::VENDEDOR() {
}

VENDEDOR::VENDEDOR(const VENDEDOR& orig) {
}

VENDEDOR::~VENDEDOR() {
}

ICollecction* VENDEDOR::GetProductosAsoc(){
    
    IIterator* IT=This->MisProductos.GetIterator();
    PRODUCTO* P;
    int codP;
    std::string nomP;
    std::string ProdVdato;
    IColecction* ProdV = new List(); //Creo una collecction donde guardare los datos que luego listare y esta función devolvera.
    for(IT,IT->hasCurrent(),IT->next()){
        P = (PRODUCTO)IT->getCurrent();
        codP=P.getCodigo(); 
        nomP=P.getNombre(); //Ambos datos del producto que necesito para el listado
        ProdVdato =to_string(codP) + " - " + nomP);
        ProdV.Add(ProdVdato);
    }
    return ProdV;
        
}
VENDEDOR::crearPromo(std::string nombreProm,std::string descripcionProm,date fechaVen){
    PROMOCION prom = new PROMOCION(nombreProm ,descripcionProm ,fechaVen);
    This->MisPromociones.Add(prom);
    
}    