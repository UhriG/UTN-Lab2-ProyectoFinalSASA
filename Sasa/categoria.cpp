#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "categoria.h"
#include "Fecha.h"
#include "carteles.h"
#include "validaciones.h"

//SET

void Categoria::setNombre(char *n){
    strcpy(nombre,n);
};

void Categoria::setEstado(int e){
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

void Categoria::cargar(){
    id = cantCategoria()+1;
    cout << "*CREAR CATEGORÍA" << endl;
    cout << "ID CATEGORÍA: " << id << endl;
    cout << "INGRESAR LOS SIGUIENTES DATOS " << endl;
    cout << "Nombre: ";
    validarNombre(nombre);

    int existe;
    while(existe=buscarNombrecat(nombre) != -1){
        msj("NOMBRE DE CATEGORÍA EXISTE, INGRESAR UNO DISTINTO", rlutil::WHITE, rlutil::RED);
        cout << "\nNombre: ";
        validarNombre(nombre);
    }

    estado = 1;
};
void Categoria::mostrar(int modo){
    string estados[2] = {"Activo","Inactivo"};

    if(modo == 1){ //MODO 1 MUESTRA EN LISTA
        int anchos = 15;
        cout << setw(5) << id;
        cout << setw(anchos) << nombre;
        cout << setw(anchos) << estados[estado-1];
        cLinea(30);
    }else{ //MODO NORMAL MUESTRA EN UNA COLUMNA
        cout << "ID: "<< id << endl;
        cout << "NOMBRE: "<< nombre << endl;
        cout << "ESTADO: "<< estados[estado-1] << endl;
        cout << "Fecha: ";
    }

};
bool Categoria::escribirDisco(){
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
bool Categoria::leerDisco(int pos){
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

bool Categoria::modDisco(int pos){
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
	Categoria c;
	while(c.leerDisco(pos)==1){
		if(idB == c.getId() && c.getEstado()==1){
            return pos;
		}
		pos++;
    }
	return -1;
}

int buscarNombrecat(char *nombreB){
	int pos=0;
	Categoria c;
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
    cant = bytes / sizeof(Categoria);
    return cant;
}


void ordenarCategoriaDesc(Categoria *cat, int cantReg){
  Categoria aux;
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

void listarCategoriaSimple(){
    Categoria c;
    int tot = cantCategoria();
    int pos = 0, idanterior;
    cTitulo();
    cTabla(3);
    for(pos; pos < tot; pos++){
        c.leerDisco(pos);
        if(c.getEstado()==1 && c.getId()!=idanterior){
           c.mostrar(1);
        cout << endl << "----------------------------------------------------------------------------"<< endl;
        idanterior = c.getId();
        }
    }
}

bool copiaCategoria(){
    Categoria c;
    FILE *f = fopen("datos/categoria.dat", "rb");
    FILE *backup = fopen("datos/categoriaBK.dat", "wb"); //Seteo a 0 el archivo de bk
    fclose(backup);
    if(f == NULL){
        cout << "No se puede leer categoria.dat .";
        system("pause");
        return false;
    }
    while(fread(&c, sizeof(Categoria), 1, f)){
        FILE *bk = fopen("datos/categoriaBK.dat", "ab");
        if(bk == NULL){
            cout << "No se puede guardar en BK.";
            system("pause");
            return false;
        }
        fwrite(&c, sizeof(Categoria), 1, bk);
        fclose(bk);
    }
    fclose(f);
    return true;
}

bool recCategoria(){
    Categoria c;
    FILE *bk = fopen("datos/categoriaBK.dat", "rb");
    FILE *orig = fopen("datos/categoria.dat", "wb"); //Seteo a 0 el archivo original
    fclose(orig);
    if(bk == NULL){
        cout << "No se puede leer el categoriaBK.dat .";
        system("pause");
        return false;
    }
    while(fread(&c, sizeof(Categoria), 1, bk)){
        FILE *f = fopen("datos/categoria.dat", "ab");
        if(f == NULL){
            cout << "No se puede guardar en categoria.";
            system("pause");
            return false;
        }
        fwrite(&c, sizeof(Categoria), 1, f);
        fclose(f);
    }
    fclose(bk);
    return true;
}
