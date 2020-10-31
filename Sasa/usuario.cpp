#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include <string>
#include "usuario.h"


void Usuario::setNombre(char *n){
    strcpy(nombre,n);
}

void Usuario::setPassword(char *p){
    strcpy(password,p);
}

void Usuario::setPerfil(int p){
    perfil = p;
}

void Usuario::setEstado(int e){
    estado = e;
}

void Usuario::cargar(){
    id = cantUsuario()+1;
    cout << "*CREAR USUARIO" << endl;
    cout << "ID USUARIO: " << id << endl;
    cout << "INGRESAR LOS SIGUIENTES DATOS " << endl;
    cout << "Nombre: ";
    cin >> nombre;

    int existe;
    while(existe=buscarNombre(nombre) != -1){
        msj("NOMBRE EXISTE, INGRESAR UNO DISTINTO", rlutil::WHITE, rlutil::RED);
        cout << "\nNombre: ";
        cin >> nombre;
    }
    cout << "Password: ";
    cin >> password;

    cout << "Perfil: ";
    cin >> perfil;  // 1 - Admin 2- Supervisor 3- Operador

    estado = 1;
}

void Usuario::mostrar(){
    int anchos = 10;
    string perfiles[3] = {"Admin", "Supervisor", "Operador"};
    string estados[2] = {"Activo","Inactivo"};

    //cout << setw(5) << "ID" << setw(anchos) << "NOMBRE" << setw(anchos) << "PERFIL" << setw(anchos) << "ESTADO";
    cout << endl << "----------------------------------------------------------------------------"<< endl;
    cout << setw(5) << id;
    cout << setw(anchos) << nombre;
    cout << setw(anchos) << perfiles[perfil-1];
    cout << setw(anchos) << estados[estado-1];
}

bool Usuario::escribirDisco(){
    bool guardo;
    FILE *f = fopen("datos/usuario.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

int Usuario::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("datos/usuario.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

void Usuario::admin(){

    strcpy(nombre,"admin");
    strcpy(password,"admin");
    id = 1;
    perfil = 1;
    estado = 1;
    escribirDisco();
}

// Funciones externas

int buscarNombre(char *nombreB){
	int pos=0;
	Usuario u;
	while(u.leerDisco(pos)==1){
		if(strcmp(nombreB,u.getNombre())==0 && u.getEstado()==1){
            return pos;
		}
		pos++;
    }
	return -1;
}

int cantUsuario(){
    FILE *f;
    f = fopen("datos/usuario.dat", "rb");
    if(f == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    cant = bytes / sizeof(Usuario);
    return cant;
}

void compAdmin(){
    int existe=cantUsuario();
    if(existe == 0){
        Usuario u;
        u.admin();
    }
}
