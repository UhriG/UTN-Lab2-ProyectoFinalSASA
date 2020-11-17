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
    int test = 1; // VALOR 0 NORMAL, 1 DEVELOPERS
    if(test == 0){
        compAdmin();
        Login l;
        l.menuLogin();
    } else { // FUNCIONES PARA TESTEAR
        /*Producto p;
        p.cargar();
        m.setLogueado("admin");
        m.setCategoriaId(p.getCatId());
        m.setProducto(p.getNombre());
        m.setMarca(p.getMarca());
        m.setStock(p.getStock());
        m.setTipoMovimiento(1);

        m.mostrar();

        m.escribirDisco();*/
        m.leerDisco(0);
        m.mostrar(2);
    }

    //return 0;
}
