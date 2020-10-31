#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "producto.h"

void Producto::setNombre(char *n){
    strcpy(nombre,n);
}

void Producto::setMarca(char *m){
   strcpy(marca,m);
}

void Producto::setCategoria(int c){
    categoria_id = c;
}

void Producto::setEstado(int e){
    estado = e;
}

void Producto::setStock(int s){
    stock = s;
}
/*
void Producto::setFechaCrea(Fecha f){
    fecha_creacion = f;
}

void Producto::setFechaMod(Fecha f){
    fecha_modificacion = f;
}
*/

void Producto::cargar(){
    cout << "Ingresar Producto, completar los siguientes datos: " << endl;
    id =1;
    cout << "ID: " << id <<endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Marca: ";
    cin >> marca;
    cout << "Categor�a: ";
    cin >> categoria_id;
    estado = 1;
    cout << "Stock: ";
    cin >> stock;
}

void Producto::mostrar(){
    int anchos = 10;
    string estados[2] = {"Activo","Inactivo"};
    cout << setw(anchos) << id;
    cout << setw(anchos) << nombre;
    cout << setw(anchos) << marca;
    cout << setw(anchos) << categoria_id;
    cout << setw(anchos) << estados[estado-1];
    cout << setw(anchos) << stock;
}

bool Producto::escribirDisco(){
    bool guardo;
    FILE *f = fopen("datos/producto.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

int Producto::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("datos/producto.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

// Funciones externas
/*
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
*/
