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

void Fecha::cargarFecha(){ //carga la fecha manualmente y la settea en sistema
    system("cls");
    cTitulo();
    Fecha f;
    int d;
    int m;
    int a;
    cout<<left;
    cout << "MOODIFICAR FECHA DEL REGISTRO/n"<< endl;
    cout << "-----------------------------"<< endl;
    cout << "Día: " << endl;
    cin >> d;
    cout << "Mes: " << endl;
    cin >> m;
    cout << "Año: " << endl;
    cin >> a;

    dia=d;
    mes=m;
    anio=a;
    cout << "-----------------------------"<< endl;
    cout << "LA NUEVA FECHA SERÁ/n"<< endl;
    f.mostrarFecha();
    cout << "ES CORRECTO?/n"<< endl;

};


void Fecha::fechaActual(){ //consigue la fecha y la settea en sistema
    int *d, *m, *a;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo=time(NULL);          //Obtener algoritmo de fecha del sistema
    tmPtr=localtime(&tiempo);   //Convierte el algoritmo y lo guarda en tmPtr
    *d=tmPtr->tm_mday;          //Guarda en puntero el Día
    *m=tmPtr->tm_mon+1;         //Guarda en puntero el Mes+1, ya que va del 0 al 11
    *a=1900+tmPtr->tm_year;     //Guarda en puntero el Año+1900
    dia=*d;
    mes=*m;
    anio=*a;
};

