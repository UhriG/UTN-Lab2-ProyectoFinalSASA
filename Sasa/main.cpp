#include <iostream>

using namespace std;
#include "menu.h"
#include "login.h"
#include "ui.h"
#include "rlutil.h"

#include "usuario.h"
#include "producto.h" // BORRAR DESPUES DE LA PRUEBA

int main()
{
    initUI();

    compAdmin();
    Login l;
    l.menuLogin();

    //INGRESAR LAS FUNCIONES PARA PROBAR, COMENTANDO EL MENUPRINCIPAL
/*
    bool salir = true;
    int resp=0, v=0, x=5;
    int paginas = 5;
    int hoja = 1;
    while(salir){
        cout << "VALOR DE RESP: " << resp << endl;
        cout << "VALOR DE V: " << v << endl;
        cout << "VALOR DE X: " << x << endl;
        cout << "-----------" << endl;
        for(v; v<x; v++){
            cout << "CONTADOR :" << v << endl;
        }
        cout << endl;
        cout << "PAGINA: " << hoja << " / " << paginas << endl;
        cout << "A- ADELANTAR | V- VOLVER ATRAS | 0- SALIR" << endl;
        cout << "INGRESAR HOJA: > " << endl;
        cin >> resp;
        cout << endl;
        hoja = resp;
        if(resp == 0){
            salir = false;
        } else {
            v = 5*(hoja - 1);
            x = v +5;
        }
    }
    cout << "SALISTE!!!"; */
    //return 0;
}


