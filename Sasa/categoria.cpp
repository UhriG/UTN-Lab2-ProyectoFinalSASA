#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "categoria.h"
#include "Fecha.h"

//SET

void categoria::setNombre(char *n){
    strcpy(nombre,n);
};

void categoria::setEstado(int e){
    estado = e;
}

//void categoria::setFechaCrea(Fecha);
//void categoria::setFechaMod(Fecha);

//GET
//Fecha categoria::getFechaCrea(){
//    return Fecha;
//};
//Fecha categoria::getFechaMod(){
//    return Fecha;
//};

void categoria::cargar(){
    id = cantCategoria()+1;
    cout << "*CREAR CATEGORIA" << endl;
    cout << "ID CATEGORIA: " << id << endl;
    cout << "INGRESAR LOS SIGUIENTES DATOS " << endl;
    cout << "Nombre: ";
    cin >> nombre;

    int existe;
    while(existe=buscarNombrecat(nombre) != -1){
        msj("NOMBRE DE CATEGORIA EXISTE, INGRESAR UNO DISTINTO", rlutil::WHITE, rlutil::RED);
        cout << "\nNombre: ";
        cin >> nombre;
    }

    estado = 1;

//    cls();
//    cout << "Ingresar Categoría: ";
//    cin >> categoria;
//
//
    escribirDisco();
};
void categoria::mostrar(int modo){
    string estados[2] = {"Activo","Inactivo"};

    if(modo == 1){ //MODO 1 MUESTRA EN LISTA
        int anchos = 15;
        cout << setw(5) << id;
        cout << setw(anchos) << nombre;
        cout << setw(anchos) << estados[estado-1];
    }else{ //MODO NORMAL MUESTRA EN UNA COLUMNA
        cout << "ID: "<< id << endl;
        cout << "NOMBRE: "<< nombre << endl;
        cout << "ESTADO: "<< estados[estado-1] << endl;
    }

};
bool categoria::escribirDisco(){
    bool guardo;
    FILE *f = fopen("datos/categoria.dat", "ab");
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
	p=fopen("datos/categoria.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
};

bool categoria::modDisco(int pos){
    bool guardo;
    FILE *p;
	p=fopen("datos/categoria.dat","rb+");
	if(p==NULL){
        cout<<"Error de archivo";
        return false;
    }
	fseek(p,pos*sizeof *this,0);
	guardo = fwrite(this,sizeof *this,1,p);
	fclose(p);
	return guardo;
}


// Funciones externas
int buscarIDcat(int idB){
    int pos=0;
	categoria c;
	while(c.leerDisco(pos)==1){
		if(idB == c.getId() && c.getEstado()==1){
            return pos;
		}
		pos++;
    }
	return -1;
}

int buscarNombre(char *nombreB){
	int pos=0;
	categoria c;
	while(c.leerDisco(pos)==1){
		if(strcmp(nombreB,c.getNombre())==0 && c.getEstado()==1){
            return pos;
		}
		pos++;
    }
	return -1;
}

int cantCategoria(){
    FILE *f;
    f = fopen("datos/categoria.dat", "rb");
    if(f == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    cant = bytes / sizeof(categoria);
    return cant;
}

//void compCategoria(){
//    int existe=cantCategoria();
//    if(existe == 0){
//        categoria c;
//        c.admin();
//    }
//}

void ordenarCategoriaDesc(categoria *cat, int cantReg){
  categoria aux;
  int i, j, pMayor;
  for(i=0; i<cantReg-1; i++){
    pMayor = i;
    for(j=i+1; j<cantReg; j++){
        if(cat[j].getId() > cat[pMayor].getId()){
            pMayor = j;
        }
    }
    aux = cat[i];
    cat[i] = cat[pMayor];
    cat[pMayor] = aux;
  }
}

