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
        cout << "CATEGORÍA: "<< c.getNombre() << endl;
        cout << "STOCK: "<< stock << endl;
    }
}*/
