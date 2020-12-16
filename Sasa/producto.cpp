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
#include "validaciones.h"
#include "carteles.h"

#include <fstream>
#include <string>

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
    int existe=0;
    do{
        cTitulo();
        fflush(stdin);
        cout << "Ingresar Producto, completar los siguientes datos: " << endl;
        id = cantProd()+1;

        cout << "> ID: " << id <<endl;

        cout << "> Nombre: ";
        validarNombre(nombre);
        cout << "> Marca: ";
        validarNombre(marca);

        existe = comprobarProducto(nombre,marca);
        if(existe >= 0){
            msj("INGRESAR UN PRODUCTO CON DIFERENTE NOMBRE/MARCA", rlutil::WHITE, rlutil::RED);
        }

    }while(existe >= 0);

    listarCategoriaSimple();
    cout << "> Categoría ID: ";
    setCategoria(validarCategoria());
    estado = 1;
    cout << "\n> Stock: ";
    setStock(validarStock());
}

void Producto::mostrar(int modo){
    string estados[2] = {"Inactivo","Activo"};
    Categoria c;
    int posCat = buscarIDcat(categoria_id);
    c.leerDisco(posCat);

    if(modo == 1){ // MODO 1 MUESTRA EN LISTA
        int ancho = 15;
        cout << setw(4) << id;
        cColumna();
        cout << setw(ancho) << nombre;
        cColumna();
        cout << setw(ancho) << marca;
        cColumna();
        cout << setw(ancho) << c.getNombre();
        cColumna();
        cout << setw(10) << estados[estado];
        cColumna();
        cout << setw(5) << stock;
    } else{ //MODO NORMAL MUESTRA EN UNA COLUMNA
        cout << "ID: "<< id << endl;
        cout << "NOMBRE: "<< nombre << endl;
        cout << "MARCA: "<< marca << endl;
        cout << "CATEGORÍA: "<< c.getNombre() << endl;
        cout << "ESTADO: "<< estados[estado] << endl;
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

    /*int cant=0, pos=0;
    Producto u;
    while(u.leerDisco(pos)==1){
        if(u.getEstado()==1){
            cant++;
        }
        pos++;
    }*/
    return cant;
}

bool copiaProducto(){
    Producto p;
    FILE *f = fopen("datos/producto.dat", "rb");
    FILE *backup = fopen("datos/productoBK.dat", "wb"); //Seteo a 0 el archivo de bk
    fclose(backup);
    if(f == NULL){
        cout << "No se puede leer producto.dat .";
        system("pause");
        return false;
    }
    while(fread(&p, sizeof(Producto), 1, f)){
        FILE *bk = fopen("datos/productoBK.dat", "ab");
        if(bk == NULL){
            cout << "No se puede guardar en BK.";
            system("pause");
            return false;
        }
        fwrite(&p, sizeof(Producto), 1, bk);
        fclose(bk);
    }
    fclose(f);
    return true;
}

bool recProducto(){
    Producto p;
    FILE *bk = fopen("datos/productoBK.dat", "rb");
    FILE *orig = fopen("datos/producto.dat", "wb"); //Seteo a 0 el archivo original
    fclose(orig);
    if(bk == NULL){
        cout << "No se puede leer el productoBK.dat .";
        system("pause");
        return false;
    }
    while(fread(&p, sizeof(Producto), 1, bk)){
        FILE *f = fopen("datos/producto.dat", "ab");
        if(f == NULL){
            cout << "No se puede guardar en producto.";
            system("pause");
            return false;
        }
        fwrite(&p, sizeof(Producto), 1, f);
        fclose(f);
    }
    fclose(bk);
    return true;
}

bool expCsvProducto(){
    string estados[2] = {"Inactivo","Activo"};
    Categoria c;
    int posCat=0;

    std::ofstream filename("datos/Producto.csv");
    filename << "ID" << "," << "PRODUCTO" << "," << "MARCA" << "," << "CATEGORÍA" << "," << "ESTADO" << "," << "STOCK" << endl;
    Producto u;
    int pos=0;
    while(u.leerDisco(pos++)){
        posCat = buscarIDcat(u.getCatId());
        c.leerDisco(posCat);
        filename <<u.getId()<<","<<u.getNombre()<<","<<u.getMarca()<<","<<c.getNombre()<<","<<estados[u.getEstado()]<<","<<u.getStock()<<endl;
    }
    filename.close();

    return true;
}
