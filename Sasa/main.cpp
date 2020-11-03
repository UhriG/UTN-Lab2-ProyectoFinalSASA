#include <iostream>

using namespace std;
#include "menu.h"
#include "login.h"
#include "ui.h"
#include "rlutil.h"

#include "usuario.h"

int main()
{
    initUI();

    compAdmin();
    //menuLogin();

    //INGRESAR LAS FUNCIONES PARA PROBAR, COMENTANDO EL MENUPRINCIPAL
    //menuPrincipal();
    cout << "Ingresar Nombre: >";
    char n[5];
    cin >> n;
    while(n == " "){
        cout << "NO DEBE ESTAR VACIO EL CAMPO NOMBRE: >";
        cin >> n;
    }
    cout << n;
    //return 0;
}
