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
    cout << " >";
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
    cout << " >";
}
#include "carteles.h"


