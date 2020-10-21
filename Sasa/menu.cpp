#include <iostream>

using namespace std;
#include "menu.h"
#include "ui.h"

void menuPrincipal(){
    initUI();
    menuLogin();
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACEN");
    gotoxy(1, 5);
    cout << "OPCION 1" << endl;
    cout << "OPCION 2" << endl;
    cout << "OPCION 3" << endl;
}

void menuLogin(){
    cls();
    char user[10]{}, pass[10];
    title("SISTEMA ADMINISTRACION DE STOCK ALMACEN");
    gotoxy(5, 5);
    cout << "INICIAR SESION" << endl;
    gotoxy(5, 6);
    cout << "Ingresar USER: > ";
    cin >> user;
    gotoxy(5, 7);
    cout << "Ingresar PASSWORD: > ";
    cin >> pass;
}
