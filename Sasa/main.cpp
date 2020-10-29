#include <iostream>
using namespace std;
#include "menu.h"
#include "login.h"
#include "ui.h"
#include "rlutil.h"
#include "usuario.h"

#include "producto.h"

int main()
{
    initUI();

    //menuLogin();

    //INGRESAR LAS FUNCIONES PARA PROBAR, COMENTANDO EL MENUPRINCIPAL
    Producto p;
    p.cargar();
    cout << endl;
    p.mostrar();

    //return 0;
}
