#include <cstdlib>
#include <iostream>
#include <string>
#include <valarray>
using namespace std;
#include "FABRICA.h"
#include "ICONTROLADOR.h"
#include "date.h"
#include "DataDireccion.h"
#include "DataCliente.h"
#include "DataVendedor.h"
#include "DTProducto.h"
#include "TipoProducto.h"

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void centrarTexto(const string& texto) {
    int ancho = 120;
    int espacios = (ancho - texto.length()) / 2;
    for (int i = 0; i < espacios; i++) {
        cout << " ";
    }
    cout << texto << endl;
}


int main(int argc, char** argv) {

    FABRICA* fb= new FABRICA();
    ICONTROLADOR* ic = fb->getIControlador();
    int opcion = 1;
    while (opcion != 0){
        do{
            limpiarPantalla();
            centrarTexto("<><UtecMercadoSuelto><>");
            cout << endl;
            cout << "<1> Alta de Usuario" << endl;
            cout << "<2> Listado de Usuarios" << endl;
            cout << "<3> Alta de Producto" << endl;
            cout << "<4> Consulta Producto" << endl;
            cout << "<5> Crear Promocion" << endl;
            cout << "<6> Consultar Promocion" << endl;
            cout << "<7> Realizar Compra" << endl;
            cout << "<8> Dejar Comentario" << endl;
            cout << "<9> Eliminar Comentario" << endl;
            cout << "<10> Enviar Producto" << endl;
            cout << "<11> Expediente de Usuario" << endl;
            cout << "<0> Cerrar Programa" << endl;
            cout << "\nEsperando Instruccion: ";
            cin >> opcion;
        }while(opcion<0 || opcion>11);
    
        switch (opcion){
            case 1: {
                limpiarPantalla();
                centrarTexto("=== ALTA DE USUARIO ===");
                cout << endl;
                cout << "Cliente o Vendedor? (1-2)" << endl;
                int opcion1;
                do{
                    cin >> opcion1;
                }while (opcion1<1 or opcion1>2);
                cout << "Ingrese nickname: ";
                string nick;
                cin.ignore();
                getline(cin, nick);

                cout << "Ingrese fecha de nacimiento: " << endl;
                date fecha;
                fecha.SetearFecha();  
                
                cout << "Ingrese contraseña: ";
                string contr;
                cin.ignore();
                getline(cin, contr);
                if(opcion1==1){
                    cout << "Ingrese ciudad: ";
                    string ciudad;
                    getline(cin, ciudad);
                    
                    cout << "Ingrese direccion: " << endl;
                    cout << "Nro Puerta: ";
                    int numPuerta;
                    cin >> numPuerta;
                    cout << "Nombre Calle: ";
                    string nomCalle;
                    cin.ignore();
                    getline(cin, nomCalle);
                    DataDireccion* dir = new DataDireccion(numPuerta, nomCalle);
                    DataCliente* datosC = new DataCliente(nick,fecha,ciudad,dir);
                    ic->ingresoCliente(datosC,contr);
                }else{
                    string rut;
                    cout << "Ingrese RUT: ";
                    getline(cin, rut);
                    while(rut.length() != 12){
                        cout << "ERROR, el RUT debe de ser de 12 caracteres: ";
                        getline(cin, rut);
                    }
                    DataVendedor* datosV = new DataVendedor(nick,fecha,rut);
                    ic->ingresoVendedor(datosV,contr);
                }
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            }
            case 2:{
                limpiarPantalla();
                centrarTexto("=== LISTADO DE USUARIOS ===");
                cout << endl;
                cout << ic->listarUsuariosCompletos();
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                }
                break; 
            case 3:{
                limpiarPantalla();
                centrarTexto("=== ALTA DE PRODUCTO ===");
                cout << endl;
                string v = ic->ListaVendedores();
                if(v == "#$%"){
                    cout << "\t<>VENDEDORES<>\n\nNo existen vendedores.\n\n";
                }else{
                    cout << v << endl;
                    cout << "Elige un vendedor válido: ";
                    int opcion3 = 0;
                    cin >> opcion3;
                    cout << "Ingresa el nombre del producto: ";
                    string nomProd;
                    cin.ignore();
                    getline(cin, nomProd);
                    cout << "Ingresa el precio del producto: ";
                    float precio;
                    cin >> precio;
                    cout << "Ingresa el stock del producto: ";
                    int cantStock;
                    cin >> cantStock;
                    cout << "Ingresa la descripcion del producto: ";
                    string descProd;
                    cin.ignore();
                    getline(cin, descProd);
                    cout << "Elija la categoria del producto: \n1.Ropa\n2.Electrodomesticos\n3.Otros\nOpcion: ";
                    int opcionP = 0;
                    do{    
                        cin >> opcionP;
                    }while(opcionP < 1 or opcionP > 3);
                    TipoProducto tipo;
                    switch (opcionP){
                        case 1:{
                            tipo = TipoProducto::Ropa;
                            break;
                        }
                        case 2:{
                            tipo = TipoProducto::Electrodomesticos;
                            break;
                        }
                        case 3:{
                            tipo = TipoProducto::Otros;
                            break;
                        }
                    }
                    DTProducto* datosProd = new DTProducto(nomProd, precio, cantStock, descProd, tipo);
                    ic->ingresoProducto(opcion3,datosProd);
                }
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
               // cin.get();
                break;
            }
            case 4:{
                
                limpiarPantalla();
                centrarTexto("=== CONSULTA PRODUCTO ===");
                cout << endl;
                string listaProduct = ic->ListarProductosBasic();
                
                if (listaProduct.empty()){
                    cout << "No hay productos en el sistema." << endl;
                    cout << "\nPresione Enter para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                cout<<"Productos Disponibles: "<<endl;
                cout<<listaProduct<<endl; 
                
                cout<<"\n\nSeleccione el producto a describir(por su indice): "<<endl;
                cout<<"\nEsperando Instruccion: ";
                
                int codigoP;
                cin.ignore();
                cin >> codigoP;
                
                string descProd = ic->DescribeProducto(codigoP);
                
                cout<<descProd<<endl;
                
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            }
            case 5:{
                
                limpiarPantalla();
                centrarTexto("=== CREAR PROMOCION ===");
                cout << endl;
                // CREAR PROMOCION
                string Vend = ic->ListaVendedores();
                if(Vend.empty()){
                    cout << "No hay vendedores registrados en el sistema." << endl;
                    cout << "\nPresione Enter para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                cout<<"Vendedores del Sistema: "<<endl;
                cout<<Vend<<endl; 
                
                cout<<"\n\nSeleccione el vendedor que ofrecera la promocion(por su indice): ";
                
                int Vendedor;
                cin.ignore();
                cin >> Vendedor;
                string nomProm;
                cout << "Ingrese el nombre de la promocion: ";
                cin.ignore();
                getline(cin, nomProm);
                string descProm;
                cout << "Ingrese la descripcion de la promocion: ";
                cin.ignore();
                getline(cin,descProm);
                
                
                cout << "Ingrese fecha de vencimiento de la Promocion: " << endl;
                    
                date Fecha;
                Fecha.SetearFecha();  // el usuario ingresa una fecha

                // Uso un objeto temporal de tipo PROMOCION solo para acceder a obtenerFechaSistema
                PROMOCION promoAux;
                date fechaActual = promoAux.obtenerFechaSistema();
                
                while (!(Fecha > fechaActual)) {
                    cout << "ERROR: La fecha debe ser posterior a hoy. Ingresela nuevamente: " << endl;
                    Fecha.SetearFecha();
                }
                
                string prod = ic->ListarProductosV(Vendedor,nomProm,descProm,Fecha);
                if(prod.empty()){
                    cout<<"Vendedor no tiene productos asociados"<<endl;
                    cout << "\nPresione Enter para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                if(prod == "VENDEDOR SELECCIONADO NO VÁLIDO"){
                    cout<<prod<<endl;
                    cout << "\nPresione Enter para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                
                
                bool quiere;
                do{
                cout << "Productos del vendedor: " << endl;
                cout << prod <<endl;
                cout<<"\n\nSeleccione el producto a agregar a la promocion(por su indice): "<<endl;
                cout<<"\nEsperando Instruccion: ";
                
                int codigoP;
                cin.ignore();
                cin >> codigoP;
                
                cout<<"\n\nIngrese la minima cantidad de este producto para que se aplique la promocion: ";
                cout<<"\nEsperando Instruccion: ";
                int cantMini;
                cin.ignore();
                cin >> cantMini;
                
                cout<<"\n\nSeleccione el porcentaje de descuento a aplicar a este producto en la promocion: ";
                cout<<"\nEsperando Instruccion: ";
                int porcentajeDesc;
                cin.ignore();
                cin >> porcentajeDesc;
                
                ic->SelectProductoProm(codigoP,nomProm,cantMini,porcentajeDesc);
                
                int opQuiere;
                cout<<"\n\n¿Quiere seguir ingresando productos a la promocion?(1:si/2:no) :"<<endl;
                cin >> opQuiere;
                while(opQuiere>2 or opQuiere<1) {
                    cout<<"\n\nOpcion incorrecta(1:si/2:no) :"<<endl;
                    cin >> opQuiere;
                }    
                    if (opQuiere == 1) {
                        quiere = true;
                    } else {
                        quiere = false;
                        cout << "Saliendo.." << endl;
                    }
                
                }while(quiere);
                
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            }
            case 6: {
                limpiarPantalla();
                centrarTexto("=== CONSULTAR PROMOCION ===");
                cout << endl;
                
                string listaPromociones = ic->solicitarListaPromociones();
                
                if (listaPromociones.empty()) {
                    cout << "No hay promociones disponibles." << endl;
                    cout << "\nPresione Enter para continuar...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                
                cout << "Promociones disponibles:" << endl;
                cout << listaPromociones << endl;
                
                cout << "Ingrese el nombre de la promocion a consultar: " << endl;
                cout << "\nEsperando Instruccion: ";
                string nombrePromo;
                cin >> nombrePromo;
                
                string productosVendedores = ic->obtenerProductosVendedoresPromocion(nombrePromo);
                
                if (productosVendedores.empty()) {
                    cout << "No se encontro la promocion o no tiene productos asociados." << endl;
                } else {
                    cout << "\nProductos y vendedores en la promocion '" << nombrePromo << "':" << endl;
                    cout << productosVendedores << endl;
                }
                
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                //cin.get();
                break;
            }
            case 7: {
                limpiarPantalla();
                centrarTexto("=== REALIZAR COMPRA ===");
                cout << endl;
                
                string listaClientes = ic->listarNicknamesC();
                cout << listaClientes << endl;
                
                cout << "Seleccione el numero del cliente: " << endl;
                cout << "\nEsperando Instruccion: ";
                int numCliente;
                cin >> numCliente;
                
                cout << "Ingrese el nickname del cliente: " << endl;
                cout << "\nEsperando Instruccion: ";
                string nicknameCliente;
                cin >> nicknameCliente;
                
                ic->selectNicknameC(nicknameCliente);
                
                bool continuarComprando = true;
                while (continuarComprando) {
                    string productos = ic->ListarProductos();
                    cout << "\nProductos disponibles:" << endl;
                    cout << productos << endl;
                    
                    cout << "Ingrese el codigo del producto a agregar (0 para terminar): " << endl;
                    cout << "\nEsperando Instruccion: ";
                    int codigoProducto;
                    cin >> codigoProducto;
                    
                    if (codigoProducto == 0) {
                        continuarComprando = false;
                    } else {
                        cout << "Ingrese la cantidad: " << endl;
                        cout << "\nEsperando Instruccion: ";
                        int cantidad;
                        cin >> cantidad;
                        
                        ic->agregarProducto(codigoProducto, cantidad);
                        cout << "Producto agregado a la compra." << endl;
                        
                        cout << "¿Desea agregar otro producto? (1=Si, 0=No): " << endl;
                        cout << "\nEsperando Instruccion: ";
                        int continuar;
                        cin >> continuar;
                        continuarComprando = (continuar == 1);
                    }
                }
                
                cout << "\n=== RESUMEN DE COMPRA ===" << endl;
                cout << "Compra finalizada para el cliente: " << nicknameCliente << endl;
                ic->mostrarDetalleCompra();
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            }
            case 8:
            {
                int opU;
                centrarTexto("<>USUARIOS<>\n");
                cout << ic->listarUsuarios();
                do {
                    cout << "<> Ingrese opción: ";
                    cin >> opU;
                } while (opU < 1);

                int opP;
                centrarTexto("<>PRODUCTOS<>\n");
                cout << ic->ListarProductos();
                do {
                    cout << "<> Ingrese opción: ";
                    cin >> opP;
                } while (opP < 1);

                int op;
                do {
                    cout << "<> ¿Desea responder un comentario? (1:SI 2:NO): ";
                    cin >> op;
                } while (op != 1 && op != 2);

                if (op == 1) {

                    int opC;
                    centrarTexto("<>COMENTARIOS<>\n");
                    cout << ic->listarComentariosProducto(opP);
                    do {
                        cout << "<> Ingrese opción: ";
                        cin >> opC;
                    } while (opC < 1);

                    string texto;
                    cout << endl << "<> Escriba su comentario: ";
                    cin >> texto;
                    ic->responderComentarioProducto(opU, opP, opC, texto);

                } else {
                    string texto;
                    cout << endl << "<> Escriba su comentario: ";
                    cin >> texto;
                    ic->escribirComentarioProducto(opU, opP, texto);
                }
                break;
            }
            case 9:
            {
                int opU;
                centrarTexto("<>USUARIOS<>\n");
                cout << ic->listarUsuarios();
                do {
                    cout << "<> Ingrese opción: ";
                    cin >> opU;
                } while (opU < 1);

                int opC;
                centrarTexto("<>COMENTARIOS<>\n");
                cout << ic->listarComentariosUsuario(opU);
                do {
                    cout << "<> Ingrese opción: ";
                    cin >> opC;
                } while (opC < 1);

                ic->eliminarComentarioUsuario(opU, opC);

                break;
            case 10:{
                string v = ic->ListaVendedores();
                if(v == "#$%"){
                    cout << "\t<>VENDEDORES<>\n\nNo existen vendedores.\n\n";
                    getchar();
                    getchar();
                }else{
                    cout << v << endl;
                    string opcion3;
                    cout << "Elige un vendedor válido (NOMBRE no numero): ";
                    cin >> opcion3;
                    string PP;
                    
                    if(v.find(opcion3) != string::npos){
                        PP = ic->listarProductosPendientes(opcion3);
                        if(PP == "^&*"){
                            break;
                        }
                    }else{
                        cout << "Este nick no existe";
                        getchar();
                        getchar();
                        break;
                    }
                    
                    cout << PP << endl;
                    
                    int opcion4 = 0;
                    do{
                    cout << "Elige un producto valido: ";
                    cin >> opcion4;
                    } while(opcion4 < 0);
                    
                    string CPP;
                    
                    if (PP.find(to_string(opcion4)) != string::npos){
                        CPP = ic->listarCompraProductoPendiente(opcion4);
                    }else{
                        break;
                    }
                    
                    cout << CPP << endl;
                    
                    int idCompra = 0;
                    do{
                    cout << "Selecciona un producto valido para marcarlo enviado: ";
                    cin >> idCompra;
                    } while(idCompra < 0);
                    
                    if (CPP.find(to_string(idCompra)) != string::npos){
                        ic->selectCompraProductoPendiente(idCompra);
                    }
                }
                break;
               }
            }
            case 11:{
                
                string usu;
                usu = ic->listarUsuarios();
                cout << usu;
                
                if(usu.empty()){
                    cout << "No hay usuarios ingresados" << endl;
                    getchar();
                    getchar();
                    break;
                }
                
                string nick;
                cout << "Mandame el nick pa: ";
                cin >> nick;
                
                if(usu.find(nick) != string::npos){
                    string LFB;
                    LFB = ic->listarInfoBasica(nick);
                    cout << LFB << endl;
                }else{
                    break;
                }
                
               USUARIO* usuario = new USUARIO; //lo tengo que cambiar!!!!!!!!!!!
                
                if (dynamic_cast<VENDEDOR*>(usuario)) {
                   cout << ic->ListarProductos();
                   cout << ic->solicitarListaPromociones();
                   getchar();
                   getchar();
                }else{
                    //cout << ic->listarCompras(); -FALTA-
                }
                break;
            }
        }
    }
    
    return 0;
}

