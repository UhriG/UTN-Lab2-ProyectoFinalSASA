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
<<<<<<< HEAD
    /*if(menuLogin()){
        menuPrincipal();
    }
    else {
        menuLogin();
    }*/
    Login l;
    l.menuLogin();
=======
    //menuLogin();
>>>>>>> maxi

    //INGRESAR LAS FUNCIONES PARA PROBAR, COMENTANDO EL MENUPRINCIPAL
    Usuario u;
    u.cargar();
    u.leerDisco();
    u.mostrar();

    //return 0;
}
