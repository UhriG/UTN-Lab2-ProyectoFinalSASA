#include <iostream>

using namespace std;
#include "menu.h" // BORRAR DESPUES DE LA PRUEBA
#include "login.h"
#include "ui.h"
#include "rlutil.h"
#include "carteles.h" // BORRAR DESPUES DE LA PRUEBA
#include "usuario.h" // BORRAR DESPUES DE LA PRUEBA
#include "producto.h" // BORRAR DESPUES DE LA PRUEBA
#include "Fecha.h" // BORRAR DESPUES DE LA PRUEBA

int main()
{
    initUI();

    compAdmin();
    Login l;
    l.menuLogin();

    //INGRESAR LAS FUNCIONES PARA PROBAR, COMENTANDO EL MENUPRINCIPAL

    //return 0;
}


