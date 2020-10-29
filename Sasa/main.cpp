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

    //menuLogin();

    //INGRESAR LAS FUNCIONES PARA PROBAR, COMENTANDO EL MENUPRINCIPAL
    Usuario u;
    u.cargar();
    u.leerDisco();
    u.mostrar();

    //return 0;
}
