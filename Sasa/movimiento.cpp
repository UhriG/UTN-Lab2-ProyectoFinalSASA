#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "producto.h"
#include "Fecha.h"
#include "movimiento.h"
#include "login.h"

void Movimiento::setLogueado(char *n){
    strcpy(usuarioLogueado,n);
}
/*Movimiento::Movimiento()
{
    //ctor
}*/
/*
void Movimiento::cargar(){
    f.fechaActual();
    setLogueado()
}
/*
void Movimiento::mostrar(int modo){
    //Usuario
    Login l;
    l.getLogueado();

    Categoria c;
    int posCat = buscarIDcat(categoria_id);
    c.leerDisco(posCat);

    if(modo == 1){ // MODO 1 MUESTRA EN LISTA
        int ancho = 15;
        cout << setw(4) << id;
        cout << setw(ancho) << u.getNombre;
        cout << setw(ancho) << marca;
        cout << setw(ancho) << c.getNombre();
        cout << setw(10) << estados[estado-1];
        cout << setw(5) << stock;
    } else{ //MODO NORMAL MUESTRA EN UNA COLUMNA
        cout << "ID: "<< id << endl;
        cout << "USUARIO: " << c
        cout << "NOMBRE: "<< nombre << endl;
        cout << "MARCA: "<< marca << endl;
        cout << "CATEGOR�A: "<< c.getNombre() << endl;
        cout << "STOCK: "<< stock << endl;
    }
}*/

bool Movimiento::escribirDisco(){
    bool guardo;
    FILE *f = fopen("datos/bitacora.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

int Movimiento::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("datos/bitacora.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

