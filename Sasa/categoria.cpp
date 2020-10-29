#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "categoria.h"
#include "Fecha.h"

void categoria::setNombre(string n){
    nombre = n;
};
//void categoria::setFechaCrea(Fecha);
//void categoria::setFechaMod(Fecha);
int categoria::getId(){
    return id;
};
string categoria::getNombre(){
    return nombre;
};
//Fecha categoria::getFechaCrea(){
//    return Fecha;
//};
//Fecha categoria::getFechaMod(){
//    return Fecha;
//};

void categoria::cargar(int categoria){
    cls();
    cout << "Ingresar Categoría: ";
    cin >> categoria;


    escribirDisco();
};
void categoria::mostrar(){
    cls();

};
bool categoria::escribirDisco(){
    bool guardo;
    FILE *f = fopen("datos/usuario.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
};
bool categoria::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("datos/usuario.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
};



