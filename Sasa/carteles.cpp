#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "carteles.h"
#include "usuario.h"
void cTitulo(){
    cls();
    title("SISTEMA ADMINISTRACIÓN DE STOCK ALMACÉN");
    gotoXYPred();
}

void gotoXYPred(int x, int y){
    gotoxy(x, y);
}

void cMenuPrincipal(){
    cTitulo();
    cout << "1) USUARIO" << endl;
    cout << "2) PRODUCTOS" << endl;
    cout << "3) CATEGORÍA" << endl;
    cout << "4) MOVIMIENTOS" << endl;
    cout << "5) CONFIGURACIONES" << endl;
    cout << endl;
    cout << "6) CERRAR SESIÓN" << endl;
    cout << endl;
    cout << " > ";
}

void cMenuConfiguracion(){
    cTitulo();
    cout << "1) REALIZAR COPIA DE SEGURIDAD" << endl;
    cout << "2) RECUPERAR COPIA DE SEGURIDAD" << endl;
    cout << "3) EXPORTAR A CSV (Si es que me sale)" << endl;
    cout << endl;
    cout << "5) VOLVER ATRÁS" << endl;
    cout << endl;
    cout << " > ";
}

void cMenu(int selec){
    cTitulo();
    string subTi[3] = {"USUARIO", "PRODUCTO", "CATEGORÍA"};

    cout << "1) CREAR " << subTi[selec-1] << endl;
    cout << "2) MODIFICAR " << subTi[selec-1] << endl;
    cout << "3) ELIMINAR " << subTi[selec-1] << endl;
    cout << "4) LISTAR " << subTi[selec-1] << "S" << endl;
    cout << endl;
    cout << "5) VOLVER ATRÁS" << endl;
    cout << endl;
    cout << " > ";
}

void cMenuLogin(){
    cTitulo();
    cout << "INGRESE UNA OPCIÓN" << endl;
    cout << "1 - INGRESAR" << endl;
    cout << "2 - SALIR" << endl <<" > ";
}

void cMenuProdListar(){
    cout << "1) LISTAR PRODUCTO POR CÓDIGO ASCENDENTE" << endl;
    cout << "2) LISTAR PRODUCTO POR CÓDIGO DESCENDENTE" << endl;
    cout << "3) LISTAR PRODUCTO INDIVIDUAL" << endl;
    cout << "4) LISTAR TODOS LOS PRODUCTOS" << endl;
    cout << endl;
    cout << "5) VOLVER ATRÁS" << endl;
    cout << endl;
    cout << " > ";
}

void cMenuMovimientos(){
    cTitulo();
    cout << "1) INGRESOS" << endl;
    cout << "2) EGRESOS" << endl;
    cout << "3) BITÁCORA" << endl;
    cout << endl;
    cout << "4) SALIR" << endl;
    cout << endl;
    cout << " > ";
}

void cMenuBitacora(){
    cTitulo();
    cout << "1) LISTAR TODOS LOS MOVIMIENTOS" << endl;
    cout << "2) LISTAR MOVIMIENTOS POR USUARIO" << endl;
    cout << "3) LISTAR MOVIMIENTOS POR PRODUCTO" << endl;
    cout << "4) LISTAR MOVIMIENTOS POR FECHA" << endl;
    cout << endl;
    cout << "5) SALIR" << endl;
    cout << endl;
    cout << " > ";
}

void cTabla(int modo){
    if(modo == 1){ //MODO 1 PARA USUARIO
        int ancho1 = 15;
        cout << setw(5) << "ID" << setw(ancho1) << "NOMBRE" << setw(ancho1) << "PERFIL" << setw(ancho1) << "ESTADO";
        cLinea(45);
        }
    if(modo == 2){ // MODO 2 PARA PRODUCTO
        int ancho2 = 15;
        cout << setw(4) << "ID" << setw(ancho2) << "NOMBRE" << setw(ancho2) << "MARCA" << setw(ancho2) << "CATEGORÍA" << setw(10) << "ESTADO" << setw(5) << "STOCK";
        cLinea(120);
    }
    if(modo == 3){ //MODO 3 PARA CATEGORIA
        int ancho1 = 15;
        cout << setw(5) << "ID" << setw(ancho1) << "NOMBRE" << setw(ancho1) << "ESTADO";
        cLinea(30);
    }
    if(modo == 4){ //MODO 4 PARA MOVIMIENTO
        int ancho1 = 15;
        cout << setw(4) << "ID" << setw(ancho1) << "USUARIO" << setw(ancho1) << "PRODUCTO" << setw(ancho1) << "MARCA" << setw(10) << "CATEGORIA" << setw(6) << "STOCK" << setw(11) << "MOVIMIENTO" << setw(6) << "FECHA";
        cLinea(120);
    }

}

void cLinea(int cantidad){ // Determinamos la cantidad de repeticiones
    string linea = "-", lineas; // Determinamos el separador
    for(int i=0; i<cantidad; i++){
        lineas += linea;
    }
    cout << endl;
    cout << lineas << endl;
}

void cMsjPerfil(){
    msj("PERFIL SIN ACCESO", rlutil::WHITE, rlutil::RED);
}

void cListar(int cant, int modo, int submodo){
    string tipo[4] = {"USUARIOS","PRODUCTOS","CATEGORÍAS","MOVIMIENTOS"};

    cout << left;
    if(modo == 1){
        cout << "*LISTADO DE TODOS " << tipo[modo-1] << endl;
    }
    if(modo == 2){
        if(submodo == 0){cout << "*LISTAR TODOS LOS " << tipo[modo-1] << endl;}
        if(submodo == 1){cout << "*LISTAR TODOS LOS " << tipo[modo-1] << " POR COD ASCENDENTE" << endl;}
        if(submodo == 2){cout << "*LISTAR TODOS LOS " << tipo[modo-1] << " POR COD DESCENDENTE" << endl;}
    }
    if(modo == 3){
        cout << "*LISTADO DE TODOS " << tipo[modo-1] << endl;
    }
    if(modo == 4){
        if(submodo == 0){cout << "*LISTADO DE TODOS " << tipo[modo-1] << endl;}
        if(submodo == 1){cout << "*LISTADO DE TODOS " << tipo[modo-1] << " POR USUARIO"<< endl;}

        if(submodo == 3){cout << "*LISTADO DE TODOS " << tipo[modo-1] << " POR FECHA"<< endl;}
    }
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "TOTAL DE " << tipo[modo-1] << ": " << cant << endl;
    cout << "-----------------------------" << endl;

}

void cListarMovFecha(){
    string opcion[3] = {"DÍA ESPECIFÍCO","MES Y AÑO","AÑO"};
    for(int i=0; i<3; i++){
        cout << i+1 << "-" << opcion[i] << " ";
    }
    cout << endl;
}
