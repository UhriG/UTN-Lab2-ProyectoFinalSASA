#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "fecha.h"
#include "producto.h"

Fecha::Fecha()
{
    dia = -1;
    mes = -1;
    anio = -1;
}
void Fecha::setDia(int d){
    dia=d;
};
void Fecha::setMes(int m){
    mes=m;
};;
void Fecha::setAnio(int a){
    anio=a;
};;
int Fecha::getDia(){
    return dia;
};
int Fecha::getMes(){
    return mes;
};
int Fecha::getAnio(){
    return anio;
};
void Fecha::cargarFecha(){
    Fecha f;
    int d;
    int m;
    int a;
    cin >> d;
    cin >> m;
    cin >> a;
    f.setDia(d);
    f.setMes(m);
    f.setAnio(a);
};
void Fecha::mostrarFecha(){
    cout << dia << "/" << mes << "/" << anio;
};

void fechaActual(int *d, int *m, int *a){
    time_t tiempo;
    struct tm *tmPtr;
    tiempo=time(NULL);
    tmPtr=localtime(&tiempo);
    *d=tmPtr->tm_mday;
    *m=tmPtr->tm_mon+1;
    *a=1900+tmPtr->tm_year;
};








