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

/*void Producto::setCategoria(int c){
    categoria_id = c;
}*/

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
    id = cantProd()+1;
    cout << "ID: " << id <<endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Marca: ";
    cin >> marca;
    //cout << "Categoría: ";
    //cin >> categoria_id;
    estado = 1;
    cout << "Stock: ";
    cin >> stock;
}

void Producto::mostrar(){
    int ancho = 10;
    string estados[2] = {"Activo","Inactivo"};
    cout << setw(4) << id;
    cout << setw(20) << nombre;
    cout << setw(20) << marca;
    //cout << setw(ancho) << categoria_id;
    cout << setw(ancho) << estados[estado-1];
    cout << setw(5) << stock;
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

bool Producto::modDisco(int pos){
    bool guardo;
    FILE *p;
	p=fopen("datos/producto.dat","rb+");
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

int buscarCod(int codB){
	int pos=0;
	Producto p;
	while(p.leerDisco(pos)==1){
		if(codB == p.getId() && p.getEstado()==1){
            return pos;
		} // deberia filtrar el estado?
		pos++;
    }
	return -1;
}

int cantProd(){
    FILE *f;
    f = fopen("datos/producto.dat", "rb");
    if(f == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    cant = bytes / sizeof(Producto);
    return cant;
}
