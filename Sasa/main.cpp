#include <iostream>

using namespace std;
#include "menu.h"
#include "ui.h"
#include "rlutil.h"

int main()
{
    initUI();
    if(menuLogin()){
        menuPrincipal();
    }
    else {
        menuLogin();
    }

    //INGRESAR LAS FUNCIONES PARA PROBAR, COMENTANDO EL MENUPRINCIPAL
    return 0;
}
