#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "producto.h"
#include "Fecha.h"

void Producto::setNombre();
void Producto::setCategoria();
void Producto::setEstado();
void Producto::setStock();
void Producto::setFechaCrea(Fecha);
void Producto::setFechaMod(Fecha);
int Producto::getId(){return id;};
string Producto::getNombre(){return nombre;};
int Producto::getCategoria(){return categoria_id;};
int Producto::getEstado(){return estado;};
int Producto::getStock(){return stock;};
Fecha Producto::getFechaCrea(){return Fecha;};
Fecha Producto::getFechaMod(){return Fecha;};
void Producto::cargar();
void Producto::mostrar();
bool Producto::escribirDisco();
bool Producto::leerDisco();
