#include <iostream>
#include <iomanip>
using namespace std;
#include "menu.h"
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

void menuPrincipal(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACEN");
    gotoxy(1, 5);
    cout << "1) SUBMENU 1" << endl;
    cout << "2) SUBMENU 2" << endl;
    cout << "3) SUBMENU 3" << endl;
    cout << "0) SALIR DEL PROGRAMA" << endl;
    cout << endl;
    cout << "> ";
    int opc;
    cin>>opc;
    system("cls");
    switch(opc){
        case 1:
            //subMenu1();
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



