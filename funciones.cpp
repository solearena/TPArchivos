#include <iostream>
using namespace std;
#include <clocale>
#include "Pais.h"
#include "Ciudad.h"
#include <cstdio>
#include <cstring>

//1 - Agregar una función global que busque un registro de país a partir de su código. La función debe poder devolver si el registro existe o no.

bool buscarRegistro(char*codigo ){
    FILE *p;
    Pais paises;
    p = fopen("paises.dat", "rb");
    if( p == NULL ){
        cout << "No se pudo abrir el archivo." << endl;
    }

    while( fread(&paises, sizeof (Pais), 1, p)==1){
        if( strcmp(paises.getCodigo(),codigo)==0 ){
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

//2 - Agregar una función global que permita agregar un registro de Pais al archivo de países.
void agregarRegistro(){
    FILE *p;
    Pais paises;
    p = fopen("paises.dat", "ab");
    if( p == NULL ){
        cout << "No se pudo abrir el archivo." << endl;
    }
    paises.cargar();
    fwrite(&paises, sizeof(Pais), 1, p );
    fclose(p);
}

//3 - Agregar una función global que permita listar todos los países del archivo de países.
void mostrarRegistros(){
    FILE* p;
    Pais paises;
    p = fopen("paises.dat", "rb");
    if( p == NULL ){
        cout << "No se pudo abrir el archivo." << endl;
    }
    while( fread(&paises, sizeof(Pais), 1, p) == 1){
        paises.mostrar();
        cout << endl;
    }
    fclose(p);
}

//4 - Agregar una función global que permita listar todos las ciudades y su población que pertenezcan a un país cuyo código se ingresa previamente por teclado. Mostrar la capital del país, si se tiene registro de ella, al final de todo.
void listarCiudad(char *codigo){
    FILE *p;
    Ciudad ciudades;
    p = fopen("ciudades.dat", "rb");
    if( p == NULL ){
        cout << "No se pudo abrir el archivo." << endl;
    }
    while( fread(&ciudades, sizeof (Ciudad), 1, p)==1){
        if( strcmp(ciudades.getIDPais(),codigo) == 0 ){
            ciudades.mostrar();
        }
    }
    fclose(p);
}
//5 - Agregar una función global que permita listar todos los países con su nombre y superficie. Además, indicar qué porcentaje representa esa superficie sobre el total mundial.
void mostrarPaises(){
    float superficieTotal = 0;
    FILE* p;
    Pais paises;
    p = fopen("paises.dat", "rb");
    if( p == NULL ){
        cout << "No se pudo abrir el archivo." << endl;
    }
    while( fread(&paises, sizeof(Pais), 1, p) == 1){
        superficieTotal += paises.getSuperficie();
        cout << superficieTotal << endl << endl;
    }
    fseek(p, 0, 0);
    while( fread(&paises, sizeof(Pais), 1, p) == 1){
        cout << "NOMBRE    : " << paises.getNombre() << endl;
        cout << "SUPERFICIE: " << paises.getSuperficie() << endl;
        cout << "PORCENTAJE DE SUPERFICIE SOBRE EL TOTAL MUNDIAL: " << paises.getSuperficie()*100/superficieTotal << endl;
    }
    fclose(p);
}
