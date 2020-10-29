#include<iostream>
#include<iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "categoria.h"

void categoria::setNombre(string n){
    nombre = n;
};
void categoria::setCategoria(){
};
void categoria::setFechaCrea(Fecha);
void categoria::setFechaMod(Fecha);
int categoria::getId(){return id;};
string categoria::getNombre(){return nombre;};
Fecha categoria::getFechaCrea(){return Fecha;};
Fecha categoria::getFechaMod(){return Fecha;};
void categoria::cargar();
void categoria::mostrar();
bool categoria::escribirDisco();
bool categoria::leerDisco();



