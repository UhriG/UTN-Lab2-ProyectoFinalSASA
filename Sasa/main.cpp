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
#include <string.h>

int main()
{
    initUI();
    int test = 0; // VALOR 0 NORMAL, 1 DEVELOPERS
    if(test == 0){
        compAdmin();
        Login l;
        l.eliminarTemp();
        l.menuLogin();
    } else { // FUNCIONES TESTER
        title("MODO DEV");
        gotoXYPred();

        cout << "NOMBRE: >";
        char nombre[15];
        cin >> nombre;
        int cant = cantMovNombre(nombre,1);
        Movimiento m;
        int mov[cant]={};
        vecMovimiento(mov,cant,nombre,1);


        for(int v=0; v<cant; v++){
            m.leerDisco(mov[v]);
            m.mostrar(1);
            cLinea(120);
        }
    }
    // ACA FINALIZAN LAS FUNCIONES TESTER
    return 0;
}
