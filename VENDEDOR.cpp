#include "VENDEDOR.h"
#include "DataVendedor.h"
#include <cstdlib>

VENDEDOR::VENDEDOR() {
}

VENDEDOR::VENDEDOR(const VENDEDOR& orig) {
}

VENDEDOR::~VENDEDOR() {
}

string VENDEDOR::getNicknameVendedor(){
    return getNickname();
}

string VENDEDOR::getContraseniaVendedor(){
    return getContrasenia();
}

date VENDEDOR::getFechaNacVendedor(){
    return getFechaNac();
}

string VENDEDOR::getRUT(){
    return this->RUT;
}

void VENDEDOR::setNicknameVendedor(string n){
    setNickname(n);
}

void VENDEDOR::setContraseniaVendedor(string c){
    setContrasenia(c);
}

void VENDEDOR::setFechaNacVendedor(date f){
    setFechaNac(f);
}

void VENDEDOR::setRUT(string r){
    this->RUT=r;
}

VENDEDOR::VENDEDOR(DataVendedor* datosV, string contrasenia){
    this->setNicknameVendedor(datosV->getNicknameVendedor());
    this->setContraseniaVendedor(contrasenia);
    this->setFechaNacVendedor(datosV->getDateVendedor());
    this->setRUT(datosV->getRUT());
    this->misProductos = new OrderedDictionary;
}

void VENDEDOR::añadirProducto(DTProducto* datosProd){
    int maxProd = this->misProductos->getSize() + 1;
    PRODUCTO* p = new PRODUCTO(datosProd, maxProd);
    p->setVendedorAsociado(this); 
    IKey* ik = new Integer(maxProd);
    this->misProductos->add(ik, p);
    delete ik;
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
    string ProdV = ""; //Creo una collecction donde guardare los datos que luego listare y esta función devolvera
    for(IT;IT->hasCurrent();IT->next()){
        P = (PRODUCTO*)IT->getCurrent();
        codP=P->getCodigo(); 
        nomP=P->getNombre(); //Ambos datos del producto que necesito para el listado
        ProdV=ProdV +to_string(codP) + " - " + nomP + "\n";
    }
    return ProdV;
}

PROMOCION* VENDEDOR::crearPromo(string nombreProm,string descripcionProm,date fechaVen){
    PROMOCION* prom = new PROMOCION(nombreProm ,descripcionProm ,fechaVen);
    this->misPromociones->add(prom);
    return prom;
}

void VENDEDOR::marcaloRecibido(int idCompra){
    IKey* ik = new Integer(idCompra);
    PRODUCTO* p = (PRODUCTO*)this->misProductos->find(ik);
    p->marcoRecibido(idCompra);
}
