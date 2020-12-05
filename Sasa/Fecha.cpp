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
    dia=d;
    mes=m;
    anio=a;
};

void Fecha::mostrarFecha(int modo){
    if(modo == 1){
        cout << dia << "/" << mes << "/" << anio << endl;
    }
    if(modo == 2){
        cout << dia << "/" << mes << "/" << anio;
    }
    if(modo == 3){
        cout << setw(2) << dia << setw(1) << "/" << setw(2) << mes << setw(1) << "/" << setw(2) << anio;
    }

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
    cout << "Día: " << endl;
    cin >> d;
    cout << "Mes: " << endl;
    cin >> m;
    cout << "Año: " << endl;
    cin >> a;

    dia=d;
    mes=m;
    anio=a;
    tmPtr->tm_mday = dia;
    tmPtr->tm_mon = mes-1;
    tmPtr->tm_year=anio-1900;

};

void Fecha::fechaActual(){
    time_t tiempo;
    struct tm *tmPtr;
    tiempo=time(NULL);
    tmPtr=localtime(&tiempo);
    dia = tmPtr->tm_mday;
    mes = tmPtr->tm_mon + 1;
    anio = 1900+tmPtr->tm_year;
};



