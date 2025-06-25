#include <cstdlib>
#include <iostream>
//#include <string>
using namespace std;
#include "FABRICA.h"
#include "ICONTROLADOR.h"
#include "date.h"
#include "DataDireccion.h"
#include "DataCliente.h"

int main(int argc, char** argv) {

    FABRICA* fb= new FABRICA();
    ICONTROLADOR* ic = fb->getIControlador();
    int opcion = 1;
    while (opcion != 0){
        do{
            cout << "\t<><UtecMercadoSuelto><>" << endl<< endl;
            cout << "<1> Alta de Usuario" << endl;
            cout << "<2> Listado de Usuarios" << endl;
            cout << "<3> Alta de Producto" << endl;
            cout << "<4> Consulta Producto" << endl;
            cout << "<5> Crear Promoción" << endl;
            cout << "<6> Consultar Promoción" << endl;
            cout << "<7> Realizar Compra" << endl;
            cout << "<8> Dejar Comentario" << endl;
            cout << "<9> Eliminar Comentario" << endl;
            cout << "<10> Enviar Producto" << endl;
            cout << "<11> Expediente de Usuario" << endl;
            cout << "<0> Cerrar Programa" << endl;
            cout << endl <<"<> Ingrese opción: ";
            cin >> opcion;
        }while(opcion<0 || opcion>11);
    
        switch (opcion){
            case 1: {
                cout << "Cliente o Vendedor? (1-2)";
                int opcion1;
                do{
                    cin >> opcion1;
                }while (opcion1<1 or opcion1>2);
                    cout << "Ingrese nickname: ";
                    string nick;
                    cin.ignore();
                    getline(cin, nick);
                    
                    cout << "Ingrese fecha de nacimiento: " << endl;
                    cout << "Dia: ";
                    int dia;
                    cin >> dia;
                    cout << "Mes: ";
                    int mes;
                    cin >> mes;
                    cout << "Año: ";
                    int anio;
                    cin >> anio;
                    date fecha(dia,mes,anio);
                    
                    cout << "Ingrese contraseña: ";
                    string contr;
                    cin.ignore();
                    getline(cin, contr);
                if(opcion1==1){
                    cout << "Ingrese ciudad: ";
                    string ciudad;
                    cin.ignore();
                    getline(cin, ciudad);
                    
                    cout << "Ingrese dirección: " << endl;
                    cout << "Nro Puerta: ";
                    int numPuerta;
                    cin >> numPuerta;
                    cout << "Nombre Calle: ";
                    string nomCalle;
                    getline(cin, nomCalle);
                    DataDireccion dir(numPuerta, nomCalle);
                    
                    DataCliente* datosC = new DataCliente(nick,fecha,ciudad,dir);
                    ic->ingresoCliente(datosC,contr);
                    cout << "ingresó el cliente" << endl;
                }else{
                    cout << "Ingrese RUT: ";
                    cin.ignore();
                    string rut;
                    getline(cin, rut);
                    DataVendedor* datosV = new DataVendedor(nick,fecha,rut);
                    ic->ingresoVendedor(datosV,contr);
                }
                break;
            }
            case 2:{
                string u = ic->listarUsuarios();
                cout << u;
                }
                break; //Darle opciones de nicknames existentes tipo al listarlo le pones un numero alado (indice)
            case 3:{
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
                    cout << "Ingresa la descripción del producto: ";
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
            }
                break; //No se puede pedir una preecondicion de por ejemplo que el usuario no exista al querer crearlo debes revisar esto dentro de la oper que lo creo justamente
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                int op;
                cout << ic->listarUsuarios();
                cout << endl <<"<> Ingrese opción: ";
                cin >> op;
                
                cout << ic->ListarProductos();
                cout << endl <<"<> Ingrese opción: ";
                cin >> op;
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;          
        }
    }
    
    return 0;
}

