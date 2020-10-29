#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "producto.h"

void setNombre();
void setCategoria();
void setEstado();
void setStock();
void setFechaCrea(Fecha);
void setFechaMod(Fecha);
int getId(){return id;};
string getNombre(){return nombre;};
int getCategoria(){return categoria_id;};
int getEstado(){return estado;};
int getStock(){return stock;};
Fecha getFechaCrea(){return Fecha;};
Fecha getFechaMod(){return Fecha;};
void cargar();
void mostrar();
bool escribirDisco();
bool leerDisco();
