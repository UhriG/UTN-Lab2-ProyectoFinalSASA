#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "producto.h"
#include "Fecha.h"
#include "movimiento.h"
#include "login.h"
#include "categoria.h"

Movimiento m;
/*
void Movimiento::mostrar(){
    cout << "Usuario: " << m.getLogueado() << endl;
    cout << "Producto: " << m.getProducto() << endl;
    cout << "Marca: " << m.getMarca() << endl;
    cout << "Stock: " << m.getStock() << endl;
    cout << "Categoria: " << m.getCategoriaId() << endl;
    //cout << "Fecha: " << m.fa.mostrarFecha(1) << endl;
    cout << "Tipo de Movimiento: " << m.getTipoMovimiento() << endl;
}
*/

void Movimiento::mostrar(int modo){
    Categoria c;
    int posCat = buscarIDcat(m.getCategoriaId());
    c.leerDisco(posCat);
    string tmov[2] = {"Ingreso","Egreso"};

    if(modo == 1){ // MODO 1 MUESTRA EN LISTA
        int ancho = 15;
        //cout << setw(4) << id;
        cout << setw(ancho) << m.getLogueado();
        cout << setw(ancho) << m.getProducto();
        cout << setw(ancho) << m.getMarca();
        cout << setw(10) << c.getNombre();
        cout << setw(5) << m.getStock();
        cout << setw(5) << tmov[m.getTipoMovimiento()-1];
    } else{ //MODO NORMAL MUESTRA EN UNA COLUMNA
        //cout << "ID: "<< id << endl;
        cout << "USUARIO: " << m.getLogueado() << endl;
        cout << "PRODUCTO: "<< m.getProducto() << endl;
        cout << "MARCA: "<< m.getMarca() << endl;
        cout << "CATEGORÍA: "<< c.getNombre() << endl;
        cout << "STOCK: "<< m.getStock() << endl;
        cout << "MOVIMIENTO: " << tmov[m.getTipoMovimiento()-1] << endl;
    }
}

void Movimiento::setLogueado(char *n){
    strcpy(usuarioLogueado,n);
}

void Movimiento::setCategoriaId(int catId){
    categoria_id = catId;
}

void Movimiento::setStock(int stk){
    stock = stk;
}

void Movimiento::setMarca(char *m){
    strcpy(marca, m);
}

void Movimiento::setProducto(char *p){
    strcpy(producto, p);
}

void Movimiento::setTipoMovimiento(int tpMov){
    tipoMovimiento = tpMov;
}


/*void Movimiento::cargar(){

    cout << m.getCategoriaId() << endl;
    cout << m.getLogueado << endl;
    cout << m.getMarca << endl;
    cout << m.getProducto << endl;
    cout << m.getStock << endl;
    cout << m.getTipoMovimiento << endl;
}*/



bool Movimiento::escribirDisco(){
    bool guardo;
    FILE *f = fopen("datos/bitacora.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

int Movimiento::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("datos/bitacora.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

