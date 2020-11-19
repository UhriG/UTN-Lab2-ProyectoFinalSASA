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
#include "movimiento.h" // BORRAR DESPUES DE LA PRUEBA

int main()
{
    initUI();
    int test = 0; // VALOR 0 NORMAL, 1 DEVELOPERS
    if(test == 0){
        compAdmin();
        Login l;
        l.eliminarTemp();
        l.menuLogin();
    } else { // FUNCIONES PARA TESTEAR
       /* Producto p;
        p.cargar();
        p.escribirDisco();
        Movimiento m;
        m.cargar(p);
        m.escribirDisco();

        rlutil::cls();

        for(int i=0;i<3;i++){
            m.leerDisco(i);
            if(m.getId() != 0){
                m.mostrar(4);
                rlutil::anykey();
            }
            cout << endl << "------------------------" << endl;
        }*/

        Login l;
        l.leerUsuario(0);
        cout << l.getNombre();
    }

    //return 0;
}
