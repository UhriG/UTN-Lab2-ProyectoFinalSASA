#include <iostream>

using namespace std;
#include "menu.h"
#include "ui.h"

void menuPrincipal(){
    initUI();
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACEN");
    gotoxy(1, 5);
    cout << "OPCION 1" << endl;
    cout << "OPCION 2" << endl;
    cout << "OPCION 3" << endl;
}

bool menuLogin(){
    cls();
    char user[10]{}, pass[10];
    bool login;
    title("SISTEMA ADMINISTRACION DE STOCK ALMACEN");
    gotoxy(5, 5);
    cout << "*INICIAR SESION" << endl;
    gotoxy(5, 6);
    cout << "USER: > ";
    cin >> user;
    gotoxy(5, 7);
    cout << "PASSWORD: > ";
    cin >> pass;
    return login;
}
