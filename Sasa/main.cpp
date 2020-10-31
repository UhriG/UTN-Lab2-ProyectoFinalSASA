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
    menuPrincipal();


    //return 0;
}
