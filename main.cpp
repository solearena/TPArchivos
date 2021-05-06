#include <iostream>
using namespace std;
#include "Pais.h"
#include "Ciudad.h"
#include <clocale>
#include "funciones.h"
#include <cstdio>

int main(){
	setlocale(LC_ALL, "Spanish");
    int opcion;
    char codigo[4];
    bool punto1=false;
//    Pais *pais1 = nullptr;
//    pais1 = new Pais();

    do{
        system("cls");
        cout << "MEN�" << endl;
        cout << "----" << endl;
        cout << "1- BUSCAR REGISTRO DE PA�S" << endl;
        cout << "2- AGREGAR UN REGISTRO DE PA�S" << endl;
        cout << "3- LISTAR TODOS LOS REGISTROS DE PA�S" << endl;
        cout << "4- LISTAR TODAS LAS CIUDADES DE UN PA�S" << endl;
        cout << "5- LISTAR TODOS LOS PAISES: NOMBRE, SUPERFICIE." << endl;
        cout << "0- SALIR" << endl;
        cin >> opcion;
        switch (opcion){
            case 1:
                cin.ignore();
                cout << "INGRESE EL C�DIGO A BUSCAR: ";
                cin.getline(codigo,4);
                punto1 = buscarRegistro(codigo);
                if( punto1==true ){
                    cout << "EXISTE EL REGISTRO DEL PA�S" << endl;
                }
                else{
                    cout << "NO EXISTE ESE C�DIGO DE REGISTRO" << endl;
                }
                break;
            case 2:
                agregarRegistro();
                break;
            case 3:
                mostrarRegistros();
                break;
            case 4:
                cin.ignore();
                cout << "INGRESE EL C�DIGO A BUSCAR: ";
                cin.getline(codigo,4);
                punto1 = buscarRegistro(codigo);
                if( punto1==true ){
                    listarCiudad(codigo);
                }
                else{
                    cout << "NO EXISTE ESE C�DIGO DE REGISTRO" << endl;
                }
                break;
            case 5:
                mostrarPaises();
                break;
            case 0:
                cout << "MUCHAS GRACIAS POR SU VISITA" << endl << endl;
                break;
            default:
                cout << "OPCI�N INCORRECTA" << endl << endl;
                break;
        }
        system("pause");
    } while (opcion != 0);
//    delete pais1;

	return 0;
}
