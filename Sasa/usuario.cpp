#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include <string>
#include "usuario.h"
#include "carteles.h"
#include "validaciones.h"


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
    validarNombre(nombre);

    int existe;
    while(existe=buscarNombre(nombre) != -1){
        msj("NOMBRE EXISTE, INGRESAR UNO DISTINTO", rlutil::WHITE, rlutil::RED);
        cout << "\nNombre: ";
        cin >> nombre;
    }
    cout << "Password: ";
    validarNombre(password);

    cout << "Perfil: ";
    int p;
    cin >> p;  // 1 - Admin 2- Supervisor 3- Operador
    while (p > 3 || p <= 0){
        cout << "Perfil DEBE SER 1, 2 O 3: > ";
        cin >> p;
    }
    setPerfil(p);
    estado = 1;
}

void Usuario::mostrar(int modo){
    string perfiles[3] = {"Admin", "Supervisor", "Operador"};
    string estados[2] = {"Activo","Inactivo"};

    if(modo == 1){ //MODO 1 MUESTRA EN LISTA
        int anchos = 15;
        cout << setw(5) << id;
        cout << setw(anchos) << nombre;
        cout << setw(anchos) << perfiles[perfil-1];
        cout << setw(anchos) << estados[estado-1];
    }else{ //MODO NORMAL MUESTRA EN UNA COLUMNA
        cout << "ID: "<< id << endl;
        cout << "NOMBRE: "<< nombre << endl;
        cout << "PERFIL: "<< perfiles[perfil-1] << endl;
        cout << "ESTADO: "<< estados[estado-1] << endl;
    }

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

bool Usuario::modDisco(int pos){
    bool guardo;
    FILE *p;
	p=fopen("datos/usuario.dat","rb+");
	if(p==NULL){
        cout<<"Error de archivo";
        return false;
    }
	fseek(p,pos*sizeof *this,0);
	guardo = fwrite(this,sizeof *this,1,p);
	fclose(p);
	return guardo;
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
int buscarID(int idB){
    int pos=0;
	Usuario u;
	while(u.leerDisco(pos)==1){
		if(idB == u.getId() && u.getEstado()==1){
            return pos;
		}
		pos++;
    }
	return -1;
}

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

void ordenarUsuarioDesc(Usuario *user, int cantReg){
  Usuario aux;
  int i, j, pMayor;
  for(i=0; i<cantReg-1; i++){
    pMayor = i;
    for(j=i+1; j<cantReg; j++){
        if(user[j].getId() > user[pMayor].getId()){
            pMayor = j;
        }
    }
    aux = user[i];
    user[i] = user[pMayor];
    user[pMayor] = aux;
  }
}

bool copiaUsuario(){
    Usuario u;
    FILE *f = fopen("datos/usuario.dat", "rb");
    FILE *backup = fopen("datos/usuarioBK.dat", "wb"); //Seteo a 0 el archivo de bk
    fclose(backup);
    if(f == NULL){
        cout << "No se puede leer usuario.dat .";
        system("pause");
        return false;
    }
    while(fread(&u, sizeof(Usuario), 1, f)){
        FILE *bk = fopen("datos/usuarioBK.dat", "ab");
        if(bk == NULL){
            cout << "No se puede guardar en BK.";
            system("pause");
            return false;
        }
        fwrite(&u, sizeof(Usuario), 1, bk);
        fclose(bk);
    }
    fclose(f);
    return true;
}

bool recUsuario(){
    Usuario u;
    FILE *bk = fopen("datos/usuarioBK.dat", "rb");
    FILE *orig = fopen("datos/usuario.dat", "wb"); //Seteo a 0 el archivo original
    fclose(orig);
    if(bk == NULL){
        cout << "No se puede leer el usuarioBK.dat .";
        system("pause");
        return false;
    }
    while(fread(&u, sizeof(Usuario), 1, bk)){
        FILE *f = fopen("datos/usuario.dat", "ab");
        if(f == NULL){
            cout << "No se puede guardar en usuario.";
            system("pause");
            return false;
        }
        fwrite(&u, sizeof(Usuario), 1, f);
        fclose(f);
    }
    fclose(bk);
    return true;
}
