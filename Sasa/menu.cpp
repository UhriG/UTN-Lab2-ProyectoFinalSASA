#include <iostream>
#include <iomanip>
using namespace std;
#include "menu.h"
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

// MENUES PRINCIPAL
void menuPrincipal(){
    bool menu = true;
    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) USUARIO" << endl;
        cout << "2) PRODUCTOS" << endl;
        cout << "3) CATEGORÍA" << endl;
        cout << "4) CONFIGURACIONES" << endl;
        cout << endl;
        cout << "0) SALIR DEL PROGRAMA" << endl;
        cout << endl;
        cout << "> ";
        int opc;
        cin>>opc;
        cls();
        switch(opc){
            case 1:
                menuUsuario();
            break;
            case 2:
                menuProducto();
            break;
            case 3:
                menuCategoria();
            break;
            case 4:
                menuConfiguracion();
            break;
            case 0:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}


void menuUsuario(){
    bool menu = true;
    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) CREAR USUARIO" << endl;
        cout << "2) LISTAR USUARIOS" << endl;
        cout << endl;
        cout << "0) VOLVER ATRÁS" << endl;
        cout << endl;
        cout << "> ";
        int opc;
        cin>>opc;
        cls();
        switch(opc){
            case 1:
                crearUsuario();
            break;
            case 2:
                listarUsuarios();
            break;
            case 0:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

void menuProducto(){
    bool menu = true;
    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) CREAR PRODUCTO" << endl;
        cout << "2) MODIFICAR PRODUCTO" << endl;
        cout << "3) ELIMINAR PRODUCTO" << endl;
        cout << "4) LISTAR PRODUCTOS" << endl;
        cout << endl;
        cout << "0) VOLVER ATRÁS" << endl;
        cout << endl;
        cout << "> ";
        int opc;
        cin>>opc;
        cls();
        switch(opc){
            case 1:
                crearProducto();
            break;
            case 2:
                //subMenu2();
            break;
            case 3:
                //subMenu3();
            break;
            case 4:
                //subMenu3();
            break;
            case 0:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

void menuCategoria(){
    bool menu = true;
    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) CREAR CATEGORÍA" << endl;
        cout << "2) MODIFICAR CATEGORÍA" << endl;
        cout << "3) ELIMINAR CATEGORÍA" << endl;
        cout << "4) LISTAR CATEGORÍAS" << endl;
        cout << endl;
        cout << "0) VOLVER ATRÁS" << endl;
        cout << endl;
        cout << "> ";
        int opc;
        cin>>opc;
        cls();
        switch(opc){
            case 1:
                //menuUsuario();
            break;
            case 2:
                //subMenu2();
            break;
            case 3:
                //subMenu3();
            break;
            case 0:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

void menuConfiguracion(){
    bool menu = true;
    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) REALIZAR COPIA DE SEGURIDAD" << endl;
        cout << "2) RECUPERAR COPIA DE SEGURIDAD" << endl;
        cout << "3) EXPORTAR A CSV (Si es que me sale)" << endl;
        cout << endl;
        cout << "0) VOLVER ATRÁS" << endl;
        cout << endl;
        cout << "> ";
        int opc;
        cin>>opc;
        cls();
        switch(opc){
            case 1:
                //menuUsuario();
            break;
            case 2:
                //subMenu2();
            break;
            case 3:
                //subMenu3();
            break;
            case 0:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

// SUB MENU USUARIO

void crearUsuario(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    string user, nombre, apellido;
    int id, dni, perfil;
    cout << "*CREAR USUARIO" << endl;
    cout << "INGRESAR LOS SIGUIENTES DATOS " << endl;
    cout << "USUARIO: " << endl;
    cin >> user;
    cout << "NOMBRE: " << endl;
    cin >> nombre;
    cout << "APELLIDO: " << endl;
    cin >> apellido;
    cout << "DNI: " << endl;
    cin >> dni;
    cout << "1- ADMINISTRADOR, 2- SUPERVISOR, 3- OPERADOR"<< endl;
    cout << "PERFIL: " << endl;
    cin >> perfil;
    cout << endl;
}

void listarUsuarios(){
    int ancho =10; // Determina el ancho de cada columna
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "LISTADO DE TODOS LOS USUARIOS";
    cout << left;
    cout << setw(ancho) << "COL-1" << setw(ancho) << "COL-2" << setw(ancho) << "COL-3" << setw(ancho) << "COL-4" << setw(ancho) << "COL-5";
    cout << endl << "----------------------------------------------------------------------------" << endl;
    for(int i = 0; i<2; i++){
        cout << setw(ancho) << "CELDA-1";
        cout << setw(ancho) << "CELDA-2";
        cout << setw(ancho) << "CELDA-3";
        cout << setw(ancho) << "CELDA-4";
        cout << setw(ancho) << "CELDA-5";
        cout << endl << "----------------------------------------------------------------------------" << endl;
    }
    cout << "1) MODIFICAR USUARIO" << endl;
    cout << "2) ELIMINAR USUARIO" << endl;
    msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
}

// SUB MENU PRODUCTO

void crearProducto(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    int id, categoria_id, estado, stock;
    string nombre;
    cout << "*CREAR PRODUCTO" << endl;
    cout << "INGRESAR LOS SIGUIENTES DATOS " << endl;
    cout << "NOMBRE: " << endl;
    cin >> nombre;
    cout << "CATEGORIA: " << endl;
    cin >> categoria_id;
    cout << "STOCK: " << endl;
    cin >> stock;
    cout << endl;
}
