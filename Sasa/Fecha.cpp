#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "fecha.h"
#include "producto.h"
#include "carteles.h"



void Fecha::setFecha(int d, int m, int a){ //settea la fecha del sistema
    Fecha f;
    dia=d;
    mes=m;
    anio=a;
};

void Fecha::mostrarFecha(){
    cout << dia << "/" << mes << "/" << anio;
};

void Fecha::cargarFecha(tm *registro){ //carga la fecha manualmente y la settea en sistema
    system("cls");
    cTitulo();
    Fecha f;
    struct tm *tmPtr=registro;
    int d;
    int m;
    int a;
    cout<<left;
    cout << "MOODIFICAR FECHA DEL REGISTRO/n"<< endl;
    cout << "-----------------------------"<< endl;
    cout << "D�a: " << endl;
    cin >> d;
    cout << "Mes: " << endl;
    cin >> m;
    cout << "A�o: " << endl;
    cin >> a;

    dia=d;
    mes=m;
    anio=a;
    tmPtr->tm_mday = dia;
    tmPtr->tm_mon = mes-1;
    tmPtr->tm_year=anio-1900;

};

void Fecha::fechaActual(tm *registro){ //consigue la fecha y la guarda en un registro de tipo tm
    int *d, *m, *a;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo=time(NULL);          //Obtener algoritmo de fecha del sistema
    tmPtr=localtime(&tiempo);   //Convierte el algoritmo y lo guarda en tmPtr
    registro=tmPtr;
    }

void Fecha::fechaActual(){
    int d, m, a;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo=time(NULL);
    tmPtr=localtime(&tiempo);
    d = tmPtr->tm_mday;
    m = tmPtr->tm_mon + 1;
    a = 1900+tmPtr->tm_year;
    setFecha(d,m,a);
};


void Fecha::conversorFecha(tm *registro){ //toma registro, lo convierte a formato d/m/a y la settea en sistema
    Fecha f;
    int *d, *m, *a;
    struct tm *tmPtr;
    tmPtr=registro;             //Convierte el algoritmo y lo guarda en tmPtr
    *d=tmPtr->tm_mday;          //Guarda en puntero el D�a
    *m=tmPtr->tm_mon+1;         //Guarda en puntero el Mes+1, ya que va del 0 al 11
    *a=1900+tmPtr->tm_year;     //Guarda en puntero el A�o+1900
    dia=*d;
    mes=*m;
    anio=*a;
    f.mostrarFecha();
};

//void Fecha::fechaActual(){ //consigue la fecha y la settea en sistema
//    int *d, *m, *a;
//    time_t tiempo;
//    struct tm *tmPtr;
//    tiempo=time(NULL);          //Obtener algoritmo de fecha del sistema
//    tmPtr=localtime(&tiempo);   //Convierte el algoritmo y lo guarda en tmPtr
//    *d=tmPtr->tm_mday;          //Guarda en puntero el D�a
//    *m=tmPtr->tm_mon+1;         //Guarda en puntero el Mes+1, ya que va del 0 al 11
//    *a=1900+tmPtr->tm_year;     //Guarda en puntero el A�o+1900
//    dia=*d;
//    mes=*m;
//    anio=*a;
//};

