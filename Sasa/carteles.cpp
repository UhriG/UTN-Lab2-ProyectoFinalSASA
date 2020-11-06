#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "carteles.h"

void cTitulo(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMAC�N");
    gotoXYPred();
}

void gotoXYPred(int x, int y){
    gotoxy(x, y);
}

void cMenuPrincipal(){
    cTitulo();
    cout << "1) USUARIO" << endl;
    cout << "2) PRODUCTOS" << endl;
    cout << "3) CATEGOR�A" << endl;
    cout << "4) CONFIGURACIONES" << endl;
    cout << endl;
    cout << "5) CERRAR SESI�N" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuConfiguracion(){
    cTitulo();
    cout << "1) REALIZAR COPIA DE SEGURIDAD" << endl;
    cout << "2) RECUPERAR COPIA DE SEGURIDAD" << endl;
    cout << "3) EXPORTAR A CSV (Si es que me sale)" << endl;
    cout << endl;
    cout << "5) VOLVER ATR�S" << endl;
    cout << endl;
    cout << "> ";
}

void cMenu(int selec){
    cTitulo();
    string subTi[3] = {"USUARIO", "PRODUCTO", "CATEGOR�A"};

    cout << "1) CREAR " << subTi[selec-1] << endl;
    cout << "2) MODIFICAR " << subTi[selec-1] << endl;
    cout << "3) ELIMINAR " << subTi[selec-1] << endl;
    cout << "4) LISTAR " << subTi[selec-1] << "S" << endl;
    cout << endl;
    cout << "5) VOLVER ATR�S" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuLogin(){
    cls();
    cTitulo();
    gotoXYPred();
    cout << "INGRESE UNA OPCI�N" << endl;
    cout << "1 - INGRESAR" << endl;
    cout << "2 - REGISTRARSE" << endl;
    cout << "3 - SALIR" << endl <<" > ";
}

void cMenuProdListar(){
    cout << "1) LISTAR PRODUCTO POR C�DIGO ASCENDENTE" << endl;
    cout << "2) LISTAR PRODUCTO POR C�DIGO DESCENDENTE" << endl;
    cout << "3) LISTAR PRODUCTO INDIVIDUAL" << endl;
    cout << "4) LISTAR TODOS LOS PRODUCTOS" << endl;
    cout << endl;
    cout << "5) VOLVER ATR�S" << endl;
    cout << endl;
    cout << "> ";
}

#include "carteles.h"


