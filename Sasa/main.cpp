#include <iostream>

using namespace std;
#include "menu.h"
#include "login.h"
#include "ui.h"
#include "rlutil.h"

#include "usuario.h"
#include "producto.h" // BORRAR DESPUES DE LA PRUEBA
int validarMenu(int opc, int min, int max);
int main()
{
    initUI();

    compAdmin();
    Login l;
    l.menuLogin();

    //INGRESAR LAS FUNCIONES PARA PROBAR, COMENTANDO EL MENUPRINCIPAL
    //menuPrincipal();

    //return 0;
}


