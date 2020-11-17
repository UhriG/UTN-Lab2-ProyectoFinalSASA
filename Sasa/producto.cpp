#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "producto.h"
#include "categoria.h"
#include "Fecha.h"
#include "login.h"
#include "movimiento.h"

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
void Producto::setFechaCrea(){
    Fecha f;
    fecha_creacion = f.Fecha();
}
/*
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
    listarCategoriaSimple();
    cout << "Categoría ID: ";
    cin >> categoria_id;
    estado = 1;
    cout << "Stock: ";
    int s;
    cin >> s;
    while(s <= 0){
        cout << "Ingresar Stock mayor a 0: > ";
        cin >> s;
    }
    setStock(s);
   // m.fa.fechaActual();
}

void Producto::mostrar(int modo){
    string estados[2] = {"Activo","Inactivo"};
    Categoria c;
    int posCat = buscarIDcat(categoria_id);
    c.leerDisco(posCat);

    if(modo == 1){ // MODO 1 MUESTRA EN LISTA
        int ancho = 15;
        cout << setw(4) << id;
        cout << setw(ancho) << nombre;
        cout << setw(ancho) << marca;
        cout << setw(ancho) << c.getNombre();
        cout << setw(10) << estados[estado-1];
        cout << setw(5) << stock;
    } else{ //MODO NORMAL MUESTRA EN UNA COLUMNA
        cout << "ID: "<< id << endl;
        cout << "NOMBRE: "<< nombre << endl;
        cout << "MARCA: "<< marca << endl;
        cout << "CATEGORÍA: "<< c.getNombre() << endl;
        cout << "ESTADO: "<< estados[estado-1] << endl;
        cout << "STOCK: "<< stock << endl;
    }
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
