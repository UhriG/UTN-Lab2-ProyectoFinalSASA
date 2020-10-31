#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include <string>
#include "usuario.h"


void Usuario::setNombre(char *n){
    strcpy(nombre,n);
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
    id = cantUsuario()+1;
    cout << "*CREAR USUARIO" << endl;
    cout << "ID USUARIO: " << id << endl;
    cout << "INGRESAR LOS SIGUIENTES DATOS " << endl;
    cout << "Nombre: ";
    cin >> nombre;

    int existe=-1;
    //existe=buscarNombre(nombre);
	if(existe==-1){
        cout << "Password: ";
        cin >> password;

        cout << "Perfil: ";
        cin >> perfil;  // 1 - Admin 2- Supervisor 3- Operador

        estado = 1;
	} else {
        cout << "NOMBRE USADO";
        anykey();
	}
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
