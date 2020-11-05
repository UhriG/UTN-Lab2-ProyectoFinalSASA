#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "carteles.h"

void cTitulo(){
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
}

void gotoXYPred(int x, int y){
    gotoxy(x, y);
}

void cMenuPrincipal(){
    cls();
    cTitulo();
    gotoxy(1, 5);
    cout << "1) USUARIO" << endl;
    cout << "2) PRODUCTOS" << endl;
    cout << "3) CATEGORÍA" << endl;
    cout << "4) CONFIGURACIONES" << endl;
    cout << endl;
    cout << "5) CERRAR SESIÓN" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuUsuario(){
    cls();
    cTitulo();
    gotoxy(1, 5);
    cout << "1) CREAR USUARIO" << endl;
    cout << "2) MODIFICAR USUARIO" << endl;
    cout << "3) ELIMINAR USUARIO" << endl;
    cout << "4) LISTAR USUARIOS" << endl;
    cout << endl;
    cout << "5) VOLVER ATRÁS" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuProducto(){
    cls();
    cTitulo();
    gotoxy(1, 5);
    cout << "1) CREAR PRODUCTO" << endl;
    cout << "2) MODIFICAR PRODUCTO" << endl;
    cout << "3) ELIMINAR PRODUCTO" << endl;
    cout << "4) LISTAR PRODUCTOS" << endl;
    cout << endl;
    cout << "0) VOLVER ATRÁS" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuCategoria(){
    cls();
    cTitulo();
    gotoxy(1, 5);
    cout << "1) CREAR CATEGORÍA" << endl;
    cout << "2) MODIFICAR CATEGORÍA" << endl;
    cout << "3) ELIMINAR CATEGORÍA" << endl;
    cout << "4) LISTAR CATEGORÍAS" << endl;
    cout << endl;
    cout << "0) VOLVER ATRÁS" << endl;
    cout << endl;
    cout << "> ";
}

void cMenuConfiguracion(){
    cls();
    cTitulo();
    gotoxy(1, 5);
    cout << "1) REALIZAR COPIA DE SEGURIDAD" << endl;
    cout << "2) RECUPERAR COPIA DE SEGURIDAD" << endl;
    cout << "3) EXPORTAR A CSV (Si es que me sale)" << endl;
    cout << endl;
    cout << "0) VOLVER ATRÁS" << endl;
    cout << endl;
    cout << "> ";
}

void cMenu(int selec){
    cls();
    cTitulo();
    gotoXYPred();
    string subTi[3] = {"USUARIO", "PRODUCTO", "CATEGORÍA"};

    cout << "1) CREAR " << subTi[selec-1] << endl;
    cout << "2) MODIFICAR " << subTi[selec-1] << endl;
    cout << "3) ELIMINAR " << subTi[selec-1] << endl;
    cout << "4) LISTAR " << subTi[selec-1] << "S" << endl;
    cout << endl;
    cout << "0) VOLVER ATRÁS" << endl;
    cout << endl;
    cout << "> ";
}


#include "carteles.h"


