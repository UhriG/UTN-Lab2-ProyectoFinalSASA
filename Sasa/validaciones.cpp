#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "producto.h"
#include "categoria.h"
#include "Fecha.h"
#include "login.h"
#include "movimiento.h"
#include "validaciones.h"

int validarCategoria(){
    int posCat, catId;

    do{

        while(!(cin >> catId)){
            cout << "Solo se admiten números: > ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        Producto p;
        p.setCategoria(catId);
        Categoria c;
        posCat = buscarIDcat(p.getCatId());
        if(posCat == -1){cout << "Ingresar una categoría válida: > ";}

    }while(posCat == -1);

    return posCat+1;
}

int validarStock(){
    int s;
    do{
        while(!(cin >> s)){
            cout << "Ingresar stock mayor a 0: > ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        if(s <=0 ){cout << "Ingresar stock mayor a 0: > ";}
    }while(s <= 0);
    return s;
}


void validarNombre(char *n){
    fflush(stdin);
    long int longitud;
    cin.getline(n, 20);
    longitud=strlen(n);
    while (n[0] == ' ' || n[longitud-1] == ' ' || longitud==0){
        cout << "> No se admiten espacios vacíos: ";
        cin.getline(n, 20);
        longitud=strlen(n);
    }
}

int validarNumEntero(){
    int num;
    while(!(cin >> num) || num < 1){
        if(cin.fail()){
            cout << "INGRESAR SOLO NUMEROS" << endl;
        }
        if(num<1){
            cout << "INGRESAR NÚMERO POSITIVO" << endl;
        }
        cin.clear();
        cin.ignore(123, '\n');
        cout << "> ";
    }
    return num;
}

int comprobarProducto(char *nombreB, char *marcaB){
	int pos=0;
	Producto u;
	while(u.leerDisco(pos)==1){
		if(strcmp(nombreB,u.getNombre())==0 && strcmp(marcaB,u.getMarca())==0 && u.getEstado()==1){
            return pos;
		}
		pos++;
    }
	return -1;
}
