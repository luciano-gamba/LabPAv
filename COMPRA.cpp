#include "COMPRA.h"
#include "PRODUCTO.h"
#include "CLIENTE.h"
#include "ICollection/String.h"

COMPRA::COMPRA() {
    this->idCompra = 0;
    this->monto = 0.0;
    this->miCliente = nullptr;
    this->productosCompra = nullptr;
    this->items = new List();
}

COMPRA::~COMPRA() {
}

int COMPRA::getid(){
    return this->idCompra;
}

string COMPRA::getNickname(){
    if(miCliente != nullptr) {
        return this->miCliente->getNicknameCliente();
    }
    return "";
}

date COMPRA::getFecha(){
    return this->fechaCompra;
}

COMPRA* COMPRA::create() {
    return new COMPRA();
}

date COMPRA::getFechaCompra(){
    return this->fechaCompra;
}
 float COMPRA::montoCompra(){
    return this->monto;
 }
 
 void COMPRA::setTodo(int idCompra, date fechaCompra, float monto){
     this->fechaCompra = fechaCompra;
     this->monto = monto;
     this->idCompra = idCompra;
 }
 
 void COMPRA::setMiCliente(CLIENTE* cli){
     this->miCliente = cli;
 }

string COMPRA::getItems() {
    string retorno;
    IIterator* it = this->items->getIterator();
    DataProducto* dp;
    while(it->hasCurrent()){
        dp = (DataProducto*)it->getCurrent();
        retorno = retorno + dp->getInfo() + "\n";
        it->next();
    }
    return retorno;
}

 void COMPRA::setFechaCompra(){
    time_t ya = time(NULL);
    date d = date(localtime(&ya)->tm_mday,localtime(&ya)->tm_mon+1,localtime(&ya)->tm_year+1900);
    this->fechaCompra = d;
 }

 void COMPRA::setMontoCompra(float m){
    this->monto=m;
 }
 
 void COMPRA::setId(int id){
    this->idCompra = id;
}

void COMPRA::agregarProducto(int codigoProd, int cant, PRODUCTO* p) {
    if(this->productosCompra == nullptr){
        this->productosCompra = new OrderedDictionary;
    }
    this->setFechaCompra();
    compra_producto* cp = new compra_producto(p, cant, this);
    IKey* ik = new Integer(codigoProd);
    this->productosCompra->add(ik, cp);
    p->agregar(cp);
    DataProducto* dataProducto = new DataProducto(p->getPrecio(), p->getNombre(),codigoProd, cant);
    this->monto = this->monto + (p->getPrecio()*cant);
    this->items->add(dataProducto);
}

//void COMPRA::setCP(){
//    this->micp = new compra_producto();
//    PRODUCTO* p;
//}
