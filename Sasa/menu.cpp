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
    cout << "OPCION 1" << endl;
    cout << "OPCION 2" << endl;
    cout << "OPCION 3" << endl;
}

bool menuLogin(){
    cls();
    char user[10]{}, pass[10];
    bool login = false;
    title("SISTEMA ADMINISTRACION DE STOCK ALMACEN");
    gotoxy(5, 5);
    cout << "*INICIAR SESION" << endl;

    gotoxy(5, 6);
    cout << "USER: > ";
    cin >> user;

    gotoxy(5, 7);
    cout << "PASSWORD: > ";
    cin >> pass;
    login = true;
    return login;
}
