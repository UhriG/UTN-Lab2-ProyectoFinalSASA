#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include <string>
#include "usuario.h"


void Usuario::setNombre(string n){
    nombre = n;
}

void Usuario::setPassword(string p){
    password = p;
}

void Usuario::setPerfil(int p){
    perfil = p;
}

void Usuario::setEstado(int e){
    estado = e;
}

void Usuario::cargar(){
    cls();
    id++;
    cout << "Ingresar Nombre: ";
    cin >> nombre;

    cout << "Ingresar Password: ";
    cin >> password;

    cout << "Ingresar Perfil: ";
    cin >> perfil;  // 1 - Admin 2- Supervisor 3- Operador

    setEstado();
    escribirDisco();
}

void Usuario::mostrar(){
    //cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    int ancho = 10;
    string perfiles[3] = {"Admin", "Supervisor", "Operador"};
    string estados[2] = {"Activo","Inactivo"};
    cout << left;
    cout << setw(5) << "ID" << setw(ancho) << "NOMBRE" << setw(ancho) << "PERFIL" << setw(ancho) << "ESTADO";
    cout << endl << "----------------------------------------------------------------------------" << endl;
    cout << setw(5) << id;
    cout << setw(ancho) << nombre;
    cout << setw(ancho) << perfiles[perfil-1];
    cout << setw(ancho) << estados[estado-1];
    cout << endl << "----------------------------------------------------------------------------" << endl;
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

bool Usuario::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("datos/usuario.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return false;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

bool Usuario::buscarUsuario(string busNombre){
    /*FILE *p;
    int pos=0;
    bool en = false;
	p=fopen("datos/usuario.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return false;
    }
	fseek(p,pos*sizeof *this,0);
	while(fread(this,sizeof *this,1,p)){
        if(busNombre == nombre){
            //fclose(p);
            en = true;
        }
	}
	fclose(p);
	return en;*/

}

