#include <cstdlib>
#include <iostream>
using namespace std;
#include "FABRICA.h"
#include "ICONTROLADOR.h"

int main(int argc, char** argv) {

    FABRICA* fb= new FABRICA();
    ICONTROLADOR* ic = fb->getIControlador();
    
    int opcion;
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
    cout << endl <<"<> Ingrese opción: ";
    cin >> opcion;
    }while(opcion<1 || opcion>11);
    
    switch (opcion){
        case 1:
            break;
        case 2:
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
    return 0;
}

