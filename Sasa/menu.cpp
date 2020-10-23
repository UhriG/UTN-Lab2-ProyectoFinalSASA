#include <iostream>
#include <iomanip>
using namespace std;
#include "menu.h"
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

void menuPrincipal(){
    bool menu = true;
    while(menu){

        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) USUARIO" << endl;
        cout << "2) PRODUCTOS" << endl;
        cout << "3) CATEGORÍA" << endl;

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


void menuUsuario(){
    bool menu = true;
    while(menu){
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) CREAR NUEVO USUARIO" << endl;
        cout << "2) LISTAR USUARIOS" << endl;

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

void menuProducto(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "1) CREAR NUEVO PRODUCTO" << endl;
    cout << "2) MODIFICAR PRODUCTO" << endl;
    cout << "3) ELIMINAR PRODUCTO" << endl;
    cout << "4) LISTAR PRODUCTOS" << endl;

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
            return;
        break;
        default:
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
        break;
    }
    system("pause");
}
