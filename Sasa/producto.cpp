#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "producto.h"

void Producto::setNombre(string n){
    nombre = n;
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
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Categoria: ";
    cin >> categoria_id;
    cout << "Estado: ";
    cin >> estado;
    cout << "Stock: ";
    cin >> stock;
}

void Producto::mostrar(){
    cout << "Detalles del producto: " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Categoria: " << categoria_id << endl;
    cout << "Estado: " << estado << endl;
    cout << "Stock: " << stock << endl;
}

//bool Producto::escribirDisco();
//bool Producto::leerDisco();
