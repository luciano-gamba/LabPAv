#include <cstdlib>
#include <iostream>
//#include <string>
using namespace std;
#include "FABRICA.h"
#include "ICONTROLADOR.h"
#include "date.h"
#include "DataDireccion.h"
#include "DataCliente.h"

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
                cout << "\nEsperando Instruccion: ";
                int opcion1;
                do{
                    cin >> opcion1;
                }while (opcion1<1 or opcion1>2);
                    cout << "Ingrese nickname: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    string nick;
                    cin >> nick;
                    
                    cout << "Ingrese fecha de nacimiento: " << endl;
                    cout << "Dia: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    int dia;
                    cin >> dia;
                    cout << "Mes: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    int mes;
                    cin >> mes;
                    cout << "Año: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    int anio;
                    cin >> anio;
                    date fecha(dia,mes,anio);
                    
                    cout << "Ingrese contraseña: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    string contr;
                    cin >> contr;
                if(opcion1==1){
                    cout << "Ingrese ciudad: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    string ciudad;
                    cin >> ciudad;
                    
                    cout << "Ingrese direccion: " << endl;
                    cout << "Nro Puerta: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    int numPuerta;
                    cin >> numPuerta;
                    cout << "Nombre Calle: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    string nomCalle;
                    cin >> nomCalle;
                    DataDireccion dir(numPuerta, nomCalle);
                    
                    DataCliente* datosC = new DataCliente(nick,fecha,ciudad,dir);
                    ic->ingresoCliente(datosC,contr);
                    cout << "ingresó el cliente" << endl;
                }else{
                    cout << "Ingrese RUT: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    string rut;
                    cin >> rut;
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
                string u = ic->listarUsuarios();
                cout << u;
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
                cout << v << endl;
                cout << "Elige un vendedor válido: " << endl;
                cout << "\nEsperando Instruccion: ";
                int opcion3 = 0;
                cin >> opcion3;
                if(opcion3 > 0){
                    cout << "Ingresa el nombre del producto: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    string nomProd;
                    cin >> nomProd;
                    cout << "Ingresa el precio del producto: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    float precio;
                    cin >> precio;
                    cout << "Ingresa el stock del producto: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    int cantStock;
                    cin >> cantStock;
                    cout << "Ingresa la descripcion del producto: " << endl;
                    cout << "\nEsperando Instruccion: ";
                    string descProd;
                    cin >> descProd;
                    cout << "Elija la categoria del producto: \n1.Ropa\n2.Electrodomesticos\n3.Otros\nOpcion: " << endl;
                    cout << "\nEsperando Instruccion: ";
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
                cin.get();
                break;
            }
            case 4:
                limpiarPantalla();
                centrarTexto("=== CONSULTA PRODUCTO ===");
                cout << endl;
                // IMPLEMENTAR CONSULTA PRODUCTO
                cout << "Funcionalidad no implementada";
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 5:
                limpiarPantalla();
                centrarTexto("=== CREAR PROMOCION ===");
                cout << endl;
                // IMPLEMENTAR CREAR PROMOCION
                cout << "Funcionalidad no implementada";
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
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
                cin.get();
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
                    string codigoProducto;
                    cin >> codigoProducto;
                    
                    if (codigoProducto == "0") {
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
                
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            }
            case 8:
                limpiarPantalla();
                centrarTexto("=== DEJAR COMENTARIO ===");
                cout << endl;
                // IMPLEMENTAR DEJAR COMENTARIO
                cout << "Funcionalidad no implementada";
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 9:
                limpiarPantalla();
                centrarTexto("=== ELIMINAR COMENTARIO ===");
                cout << endl;
                // IMPLEMENTAR ELIMINAR COMENTARIO
                cout << "Funcionalidad no implementada";
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 10:
                limpiarPantalla();
                centrarTexto("=== ENVIAR PRODUCTO ===");
                cout << endl;
                // IMPLEMENTAR ENVIAR PRODUCTO
                cout << "Funcionalidad no implementada";
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 11:
                limpiarPantalla();
                centrarTexto("=== EXPEDIENTE DE USUARIO ===");
                cout << endl;
                // IMPLEMENTAR EXPEDIENTE DE USUARIO
                cout << "Funcionalidad no implementada";
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
        }
    }
    
    return 0;
}

