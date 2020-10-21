#include <iostream>

using namespace std;
#include "menu.h"

int main()
{

    if(menuLogin()){
        menuPrincipal();
    }
    else {
        menuLogin();
    }

    //INGRESAR LAS FUNCIONES PARA PROBAR, COMENTANDO EL MENUPRINCIPAL
    return 0;
}
