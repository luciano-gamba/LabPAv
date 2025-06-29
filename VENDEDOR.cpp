#include "VENDEDOR.h"


VENDEDOR::VENDEDOR() {
    this->misProductos = new OrderedDictionary();
    this->misPromociones = new List();
}

VENDEDOR::VENDEDOR(const VENDEDOR& orig) {
}

VENDEDOR::VENDEDOR(DataVendedor* datosV, string contrasenia){
    this->setNicknameVendedor(datosV->getNicknameVendedor());
    this->setContraseniaVendedor(contrasenia);
    this->setFechaNacVendedor(datosV->getDateVendedor());
    this->setRUT(datosV->getRUT());
    this->misProductos = new OrderedDictionary;
}

VENDEDOR::~VENDEDOR() {
    delete this->misProductos;
    delete this->misPromociones;
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

PRODUCTO* VENDEDOR::añadirProducto(DTProducto* datosProd){
    
    int maxProd = this->misProductos->getSize() + 1;
    PRODUCTO* p = new PRODUCTO(datosProd, maxProd);
    
    p->setVendedorAsociado(this); 
    IKey* ik = new Integer(maxProd);
    ICollectible* ic = p;
    this->misProductos->add(ik, ic);
    
    return p;
}

string VENDEDOR::dameProductosPendientes(){
     bool pendiente;
     PRODUCTO* p;
     string productosPendientes;
    
    IIterator* it=this->misProductos->getIterator();
    for(it; it->hasCurrent();it->next()){
      p = (PRODUCTO*)it->getCurrent();
      pendiente = p->pendienteEnvio();
      if(pendiente == true){
          productosPendientes = productosPendientes + to_string(p->getCodigo()) + " " + p->getNombre() + "\n";
      }
    }
    return productosPendientes;
}


string VENDEDOR::GetProductosAsoc(){
    
    IIterator* IT=this->misProductos->getIterator();
    PRODUCTO* P;
    int aux = 0;
    string ProdV = ""; //Creo string que devolvere luego de ingresarle todos los codigo y nombre de los productos de este vendedor
    for(IT;IT->hasCurrent();IT->next()){
        P = (PRODUCTO*)IT->getCurrent();
        aux++;
        ProdV=ProdV + "<" +to_string(aux) + ">" + "Codigo: " + to_string(P->getCodigo()) + " - Nombre: "+ P->getNombre() + "\n\n";;
    }
    //Liberando espacio de memoria
    delete IT;
    
    return ProdV;
}

PROMOCION* VENDEDOR::crearPromo(string nombreProm,string descripcionProm,date fechaVen){
    PROMOCION* prom = new PROMOCION(nombreProm ,descripcionProm ,fechaVen);
    if(this->misPromociones == NULL){
        this->misPromociones = new List;
    }
    this->misPromociones->add(prom);
    return prom;
}

void VENDEDOR::marcaloRecibido(int idCompra){
    IKey* ik = new Integer(idCompra);
    PRODUCTO* p = (PRODUCTO*)this->misProductos->find(ik);
    p->marcoRecibido(idCompra);
}
