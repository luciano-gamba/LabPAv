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
                int op;
                do{
                    cin >> op;
                }while (op<1 or op>2);
                    cout << "Ingrese nickname: ";
                    string nick;
                    cin >> nick;
                    
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
                    cin >> contr;
                if(op==1){
                    cout << "Ingrese ciudad: ";
                    string ciudad;
                    cin >> ciudad;
                    
                    cout << "Ingrese dirección: " << endl;
                    cout << "Nro Puerta: ";
                    int numPuerta;
                    cin >> numPuerta;
                    cout << "Nombre Calle: ";
                    string nomCalle;
                    cin >> nomCalle;
                    DataDireccion dir(numPuerta, nomCalle);
                    
                    DataCliente* datosC = new DataCliente(nick,fecha,ciudad,dir);
                    ic->ingresoCliente(datosC,contr);
                    cout << "ingresó el cliente" << endl;
                }else{
                    cout << "Ingrese RUT: ";
                    string rut;
                    cin >> rut;
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
            case 3:
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
                cout << ic->listarUsuarios();
                cout << endl <<"<> Ingrese opción: ";
                cout << ic->ListarProductos();
                cout << endl <<"<> Ingrese opción: ";
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

