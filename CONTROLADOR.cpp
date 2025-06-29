#include "CONTROLADOR.h"
#include <iostream>


//CONTROLADOR* CONTROLADOR::instancia = nullptr;

CONTROLADOR::CONTROLADOR() {
    this->misProductos = new OrderedDictionary;
    this->misUsuarios = new OrderedDictionary;
    this->misVendedores = new OrderedDictionary;
    this->misClientes = new OrderedDictionary;
    this->misPromociones = new OrderedDictionary;
    this->com = nullptr;
}

CONTROLADOR::~CONTROLADOR() {
}

//CONTROLADOR* CONTROLADOR::getInstancia(){
//    if(instancia==nullptr){
//       instancia = new CONTROLADOR();
//    }
//    return instancia;
//}


string CONTROLADOR::listarProductosPendientes(string nick) {
    string productosPendientes;
    IKey* ik = new String(nick.c_str());
    if(this->misVendedores->member(ik)){
        VENDEDOR* ve = (VENDEDOR*)this->misVendedores->find(ik);
        productosPendientes = ve->dameProductosPendientes();
        return productosPendientes;
    }else{
        cout << "Este nick no existe";
        getchar();
        getchar();
        return "^&*";
    } 
}

string CONTROLADOR::listarCompraProductoPendiente(int codigoProd){
    string compras;
    IKey* ik = new Integer(codigoProd);
    PRODUCTO* pr = (PRODUCTO*)this->misProductos->find(ik);
    compras = pr->dameComprasPend();
    return compras;
}

void CONTROLADOR::selectCompraProductoPendiente(int idCompra){
    
    VENDEDOR* v;
    IKey* ik = new Integer(idCompra);
    v = (VENDEDOR*)this->misVendedores->find(ik);
    v->marcaloRecibido(idCompra);
    
}

//CLIENTE
void CONTROLADOR::ingresoCliente(DataCliente* datosC, string contrasenia){    
    CLIENTE* c = new CLIENTE(datosC,contrasenia);
    string llave = datosC->getNicknameCliente();
    IKey* ik = new String(llave.c_str());
    bool existe = this->misUsuarios->member(ik);
    if(!existe){
        this->misClientes->add(ik, c);
        this->misUsuarios->add(ik, c);
    }else{
        delete c;
    }
    cout << "Hecho!" << endl;
}
//COMENTARIO
string CONTROLADOR::listarComentariosProducto(int opP){
    
    string retorno;
    int controlP = this->misProductos->getSize();
    if (controlP>=opP){
        
        IIterator* itP = this->misProductos->getIterator();
        PRODUCTO* p;
        while(opP != 1){
           opP--;
           itP->next();
        }
        p = (PRODUCTO*) itP->getCurrent();
        delete itP;
    
        retorno = p->getInfoMisComentarios();
    }
    return retorno;
}
string CONTROLADOR::listarComentariosUsuario(int opU){
    string retorno;
    int controlU = this->misUsuarios->getSize();
    if (controlU>=opU){
        IIterator* itU = this->misUsuarios->getIterator();
        USUARIO* u;
        while(opU != 1){
            opU--;
            itU->next();
        }
        u = (USUARIO*) itU->getCurrent();
        delete itU;
    
        retorno = u->getInfoMisComentarios();
    }
    return retorno;    
}
void CONTROLADOR::responderComentarioProducto(int opU, int opP, int opC, string texto){
    
    int controlU = this->misUsuarios->getSize();
    int controlP = this->misProductos->getSize();   
    if (controlU < opU || controlP < opP){
        
        cout << endl << "OPCIONES NO VÁLIDAS - COMENTARIO NO GUARDADO" << endl << endl;
        cout << "VOLVER AL MENU:  ";
        string s;
        getline(cin,s);
        getline(cin,s);
    
    }else{
        
        IIterator* itU = this->misUsuarios->getIterator();
        USUARIO* u;
        while(opU != 1){
            opU--;
            itU->next();
        }
        u = (USUARIO*) itU->getCurrent();
        delete itU;
        
        IIterator* itP = this->misProductos->getIterator();
        PRODUCTO* p;
        while(opP != 1){
            opP--;
            itP->next();
        }
        p = (PRODUCTO*) itP->getCurrent();
        delete itP;
        
        
        int controlC = p->getSizeMisComentarios(); 
        if(controlC < opC){
            
            cout << endl << "OPCIONES NO VÁLIDAS - COMENTARIO NO GUARDADO" << endl << endl;
            cout << "VOLVER AL MENU:  ";
            string s;
            getline(cin,s);
            getline(cin,s);
        
        }else{
            
            COMENTARIO* c = p->crearRespuesta(opC,texto);
            p->asignarComentarioAProd(c);
            u->asignarComentarioAUsu(c);

            cout << endl << "OPCIONES VÁLIDAS - COMENTARIO GUARDADO" << endl << endl;
            cout << "VOLVER AL MENU:  ";
            string s;
            getline(cin, s);
            getline(cin, s);

        }
    }

}
void CONTROLADOR::escribirComentarioProducto(int opU, int opP, string texto){
    
    int controlU = this->misUsuarios->getSize();
    int controlP = this->misProductos->getSize();
   
    if (controlU < opU || controlP < opP){
        cout << endl << "OPCIONES NO VÁLIDAS - COMENTARIO NO GUARDADO" << endl << endl;
        cout << "VOLVER AL MENU:  ";
        string s;
        getline(cin,s);
        getline(cin,s);
    }else{
        
        IIterator* itU = this->misUsuarios->getIterator();
        USUARIO* u;
        while(opU != 1){
            opU--;
            itU->next();
        }
        u = (USUARIO*) itU->getCurrent();
        delete itU;
        
        IIterator* itP = this->misProductos->getIterator();
        PRODUCTO* p;
        while(opP != 1){
            opP--;
            itP->next();
        }
        p = (PRODUCTO*) itP->getCurrent();
        delete itP;
          
        COMENTARIO* c = p->createComentario(texto);
        p->asignarComentarioAProd(c);
        u->asignarComentarioAUsu(c);
        
        cout << endl << "OPCIONES VÁLIDAS - COMENTARIO GUARDADO" << endl << endl;
        cout << "VOLVER AL MENU:  ";
        string s;
        getline(cin,s);
        getline(cin,s);
        
    }
    
}
void CONTROLADOR::eliminarComentarioUsuario(int opU, int opC){
    
    int controlU = this->misUsuarios->getSize();
   
    if (controlU < opU){
        cout << endl << "OPCIONES NO VÁLIDAS - COMENTARIO NO BORRADO" << endl << endl;
        cout << "VOLVER AL MENU:  ";
        string s;
        getline(cin,s);
        getline(cin,s);
        
    }else{
        
        IIterator* itU = this->misUsuarios->getIterator();
        USUARIO* u;
        while(opU != 1){
            opU--;
            itU->next();
        }
        u = (USUARIO*) itU->getCurrent();
        delete itU;
                   
        u->eliminarComentarioUsuario(opC);
    }
}      
//USUARIO
string CONTROLADOR::listarUsuarios(){

    string retorno;
    IIterator* it = this->misUsuarios->getIterator();
    
    USUARIO* u;
    int aux=0;

    while(it->hasCurrent()){
        u = (USUARIO*) it->getCurrent();
        aux++;
        retorno = retorno + "<" + to_string(aux) + ">" + u->getNickname() + "\n";
        it->next();
    }
    return retorno;
}
string CONTROLADOR::listarUsuariosCompletos() {
    string retorno;
    IIterator* it = this->misUsuarios->getIterator();
    while (it->hasCurrent()) {
        USUARIO* u = (USUARIO*) it->getCurrent();
        
        if (u != nullptr) {
            CLIENTE* c = dynamic_cast<CLIENTE*>(u);
            if (c != nullptr) {
                retorno += "Nombre: " + c->getNickname() + "\n";
                retorno += "Nacimiento: " + c->getFechaNac().getInfoDate() + "\n";
                retorno += "Direccion: " + c->getDireccion()->getInfoDireccion() + "\n";
                retorno += "Ciudad: " + c->getCiudad() + "\n\n";
            } else {
                VENDEDOR* v = dynamic_cast<VENDEDOR*>(u);
                if (v != nullptr) {
                    retorno += "Nombre: " + v->getNickname() + "\n";
                    retorno += "Nacimiento: " + v->getFechaNac().getInfoDate() + "\n";
                    retorno += "RUT: " + v->getRUT() + "\n\n";
                }
            }
        }

        it->next();
    }

    delete it;
    return retorno;
}
string CONTROLADOR::listarInfoBasica(string nick){
    string retorno;
    IKey* ik = new String(nick.c_str());
    if(this->misUsuarios->member(ik)){
        USUARIO* u = (USUARIO*)this->misUsuarios->find(ik);
        retorno = u->getNickname() + " " + to_string(u->getFechaNac().getDia()) + "/" + to_string(u->getFechaNac().getMes()) + "/" + to_string(u->getFechaNac().getAnio());
    }else{
        retorno  = "Este usuario no existe";
    }
    return retorno;
}

//PRODUCTO
void CONTROLADOR::ingresoProducto(int vendedor, DTProducto* datosProd){
    int control = this->misVendedores->getSize();
    if(vendedor > control or vendedor < 1){
        cout << "VENDEDOR SELECCIONADO NO VÁLIDO" << endl;
    }else{
        IIterator* iter = this->misVendedores->getIterator();
        VENDEDOR* v;
        while(vendedor != 1){
            iter->next();
            vendedor--;
        }
        v = (VENDEDOR*) iter->getCurrent();
        PRODUCTO* p = v->añadirProducto(datosProd);
        IKey* ik = new Integer(this->misProductos->getSize()+1);
        this->misProductos->add(ik,p);
        cout << "Listo!" << endl;
    }
}

string CONTROLADOR::ListarProductos(){
    string retorno;
    IIterator* it = this->misProductos->getIterator();
    PRODUCTO* p;
    int aux=0;
    while(it->hasCurrent()){
        p = (PRODUCTO*) it->getCurrent();
        aux++;
        retorno = retorno + "<"+to_string(aux)+">"+"Codigo: "+to_string(p->getCodigo())+"\nNombre: "+p->getNombre()+"\nPrecio: $"+to_string(p->getPrecio())+"\n\n";
        it->next();
    }
    return retorno;

}
string CONTROLADOR::ListarProductosBasic(){ //Version de listar de Lucas el caso de uso dice que solo muestra el codigo y nombre de los productos
    string Prod = "";
    IIterator* it = this->misProductos->getIterator();
    PRODUCTO* p;
    int aux = 0;
    while(it->hasCurrent()){
        p = (PRODUCTO*) it->getCurrent();
        aux++;
        Prod = Prod + "<" + to_string(aux) + ">" + "Codigo: " + to_string(p->getCodigo()) + " - Nombre: "+p->getNombre() + "\n\n";
        it->next();
    }
    return Prod;
}
string CONTROLADOR::DescribeProducto(int indiceP){
    string Product = "";
    int control = this->misProductos->getSize();
    
    
    if(indiceP > control or indiceP < 1){
        Product =  "PRODUCTO SELECCIONADO NO EXISTENTE";
    }else{
        IIterator* iter = this->misProductos->getIterator(); //Pido que me ingrese que producto a describir por el indice no puedo usar find.
        while(indiceP != 1){
            iter->next();
            indiceP--;
        }
        PRODUCTO* p = (PRODUCTO*) iter->getCurrent();
        Product = "Precio: " + to_string(p->getPrecio()) + "\nStock : " + to_string(p->getStock()) + "\nDescripcion: " + p->getDescripcion() + "\nCategoria: " + p->getCategoria() + "\nVendedor Asociado: "+ p->getNicknameVendedor();
    }
    
    return Product;
}
//VENDEDOR    
void CONTROLADOR::ingresoVendedor(DataVendedor* datosV, string contrasenia){
    VENDEDOR* v = new VENDEDOR(datosV,contrasenia);
    string llave = datosV->getNicknameVendedor();
    IKey* ik = new String(llave.c_str());
    bool existe = this->misUsuarios->member(ik);
    if(!existe){
        this->misVendedores->add(ik,v);
        this->misUsuarios->add(ik, v);
    }else{
        delete v;
    }
    cout << "Hecho!" << endl;
}

string CONTROLADOR::ListaVendedores(){
    string retorno = "\t<>VENDEDORES<>\n\n";
    IIterator* it = this->misVendedores->getIterator();
    
    VENDEDOR* v;
    if(it->hasCurrent()){
        int aux = 0;
        while(it->hasCurrent()){
            aux = aux + 1;
            string s = to_string(aux);
            v = (VENDEDOR*) it->getCurrent();
            retorno = retorno + s + ". " + v->getNicknameVendedor() + "\n\n";
            it->next();
        }
    }else{
        retorno = "#$%";
    }
    return retorno;
}

string CONTROLADOR::ListarProductosV(int Vendor,string nombreProm,string descripcionProm,date fechaVenProm){
    int control = this->misVendedores->getSize();
    if(Vendor > control or Vendor < 1){
        return "VENDEDOR SELECCIONADO NO VÁLIDO";
    }
    IIterator* iter = this->misVendedores->getIterator();
    VENDEDOR* vend;
    while(Vendor != 1){
        iter->next();
        Vendor--;
    }
    vend = (VENDEDOR*) iter->getCurrent();
    string productosDeVend = vend->GetProductosAsoc();
    PROMOCION* nuevaPromo = vend->crearPromo(nombreProm,descripcionProm,fechaVenProm);
    IKey* ikP = new String(nombreProm.c_str()); //Debo crear la clave para poder buscar las promociones por su nombreProm ya que es un IDictionary
    this->misPromociones->add(ikP,nuevaPromo);
    //Liberar espacios de memoria
    delete iter;
    //No se debe liberar punteros obtenidos por Find porque te tira error
    
    return productosDeVend;
    
        
}
//PROMOCION
void CONTROLADOR::SelectProductoProm(int indiceProd,string nombreProm,int cantMin,int porcentajeDes){
    int control = this->misProductos->getSize();
    if(indiceProd > control or indiceProd < 1){
        cout<<"\nProducto seleccionado no valido"<<endl;
        return;
    }
    IIterator* iter = this->misProductos->getIterator();
    
    IKey* ikP = new String(nombreProm.c_str()); 
    PRODUCTO* prod;
    PROMOCION* prom;
    //prod = (PRODUCTO*)this->misProductos->find(ik); //Ya que el producto lo quiero pedir segun el indice no puedo usar un find
    
    while(indiceProd != 1){
        iter->next();
        indiceProd--;
    }
    
    prod = (PRODUCTO*) iter->getCurrent(); 
    if(prod->estoyEnPromo()){
        cout<<"\t\tERROR:Producto ya pertenece a otra promocion activa"<<endl;
        return;
    }
        
    prom = (PROMOCION*)this->misPromociones->find(ikP);
    prom->Conoceme(prod,cantMin,porcentajeDes);
    
}
string CONTROLADOR::solicitarListaPromociones() {
    IIterator* it = this->misPromociones->getIterator(); 
    string resultado = "";
    PROMOCION* promoActual;
    while (it->hasCurrent()) {
        promoActual = (PROMOCION*)it->getCurrent();
        promoActual->obtenerFechaSistema(); // actualiza fechaSis internamente
      if (promoActual->getFechaVen() > promoActual->obtenerFechaSistema()) {
        string nombre = promoActual->getNombre();           
        resultado += nombre + "\n";
        }

        it->next();
    }

    return resultado;
}

string CONTROLADOR::obtenerProductosVendedoresPromocion(string nombrePromo) {
    string resultado;
    IKey* ikPromo = new String(nombrePromo.c_str());
    PROMOCION* promo = (PROMOCION*)this->misPromociones->find(ikPromo);
    delete ikPromo;
   
   if (promo == nullptr) {
        return resultado; 
    }
    IIterator* it = this->misProductos->getIterator();
    while (it->hasCurrent()) {
        PRODUCTO* prod =(PRODUCTO*)(it->getCurrent());
        if (prod != nullptr) {
            string nombreProd = prod->getNombre();
            float precio = prod->getPrecio();
                string vend = prod->getNicknameVendedor();
               string promoStr = nombreProd + " " + to_string(precio) + " " + vend;
                resultado += promoStr + "\n"; 
        }
        it->next();
    }
    delete it; 
    return resultado; 
}

//COMPRA
string CONTROLADOR::listarNicknamesC(){
    string listar = "\t<>CLIENTES<>\n\n";
    IIterator* it= this->misClientes->getIterator();
    CLIENTE* c;
    int aux = 0;
    if(it->hasCurrent()){
        while(it->hasCurrent()){
            aux = aux +1;
            string l = to_string(aux);
            c = (CLIENTE*) it->getCurrent();
            listar = listar + l + " " + c->getNicknameCliente() + "\n\n";
            it->next();
        }
    }else{
        listar = listar + "No hay Clientes" + "\n\n";
    }
    
    return listar;
}
void CONTROLADOR::selectNicknameC(string nick){
    string seleccion;
    IKey* ikCliente = new String(nick.c_str());
   CLIENTE* cliente = (CLIENTE*)this->misClientes->find(ikCliente);
    delete ikCliente;
    
    if (cliente == nullptr) {
       cout<<"Cliente no Encontrado"<<endl;
   }

   if(cliente->getCompraActiva() != nullptr){
        //delete cliente->getCompraActiva();
   }
   cliente->setCompraActiva(COMPRA::create());

   cout<<"Compra Iniciada" + nick + "\n\n";
}
void CONTROLADOR::agregarProducto(string codigoProd, int cant) {
    IKey* key = new String(codigoProd.c_str());

    if (!misProductos->member(key)) {
        std::cout << "Producto no encontrado.\n";
        delete key;
        return;
    }

    PRODUCTO* p = (PRODUCTO*)misProductos->find(key);

    if (p == nullptr) {
        std::cout << "Error al recuperar el producto.\n";
        delete key;
        return;
    }

    this->com->agregarProducto(codigoProd, cant);

    delete key;
}

 void CONTROLADOR::mostrarDetalleCompra() {
    date f = com->getFechaCompra();
    float m = com->montoCompra();
    set<DataProducto> items = com->getItems();

    

    cout << "=== RESUMEN DE LA COMPRA ===\n";
    cout << "Fecha de compra: " << f.getInfoDate() << "\n";
    cout << "Productos:\n";
    
    for (const DataProducto& item : items) {
        cout << "- Producto incluido en la compra\n";
    }

    cout << "Monto total: $" << m << "\n";
    cout << "=============================\n";

    
}
 
void CONTROLADOR::getUsuario(string nick){
    USUARIO* u;
    IKey* ik = new String(nick.c_str());
    u = (USUARIO*)this->misUsuarios->find(ik);
}
