#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "carteles.h"

void cMenuPrincipal(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMAC�N");
    gotoxy(1, 5);
    cout << "1) USUARIO" << endl;
    cout << "2) PRODUCTOS" << endl;
    cout << "3) CATEGOR�A" << endl;
    cout << "4) CONFIGURACIONES" << endl;
    cout << endl;
    cout << "5) CERRAR SESI�N" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuUsuario(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMAC�N");
    gotoxy(1, 5);
    cout << "1) CREAR USUARIO" << endl;
    cout << "2) MODIFICAR USUARIO" << endl;
    cout << "3) ELIMINAR USUARIO" << endl;
    cout << "4) LISTAR USUARIOS" << endl;
    cout << endl;
    cout << "5) VOLVER ATR�S" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuProducto(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMAC�N");
    gotoxy(1, 5);
    cout << "1) CREAR PRODUCTO" << endl;
    cout << "2) MODIFICAR PRODUCTO" << endl;
    cout << "3) ELIMINAR PRODUCTO" << endl;
    cout << "4) LISTAR PRODUCTOS" << endl;
    cout << endl;
    cout << "0) VOLVER ATR�S" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuCategoria(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMAC�N");
    gotoxy(1, 5);
    cout << "1) CREAR CATEGOR�A" << endl;
    cout << "2) MODIFICAR CATEGOR�A" << endl;
    cout << "3) ELIMINAR CATEGOR�A" << endl;
    cout << "4) LISTAR CATEGOR�AS" << endl;
    cout << endl;
    cout << "0) VOLVER ATR�S" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuConfiguracion(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMAC�N");
    gotoxy(1, 5);
    cout << "1) REALIZAR COPIA DE SEGURIDAD" << endl;
    cout << "2) RECUPERAR COPIA DE SEGURIDAD" << endl;
    cout << "3) EXPORTAR A CSV (Si es que me sale)" << endl;
    cout << endl;
    cout << "0) VOLVER ATR�S" << endl;
    cout << endl;
    cout << "> ";
}

#include "carteles.h"


