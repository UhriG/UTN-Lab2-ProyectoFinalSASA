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

    //compAdmin();
    //menuLogin();

    //INGRESAR LAS FUNCIONES PARA PROBAR, COMENTANDO EL MENUPRINCIPAL
    //menuPrincipal();
    //int z, a;
    gotoxy(35,10);
    printf("CARGANDO");
    for(int i=1; i<90; i++){
        gotoxy(i,13);
        printf("%c",177);
        for(int x=50; x<70; x++){
            for(int y=1; y<70; y++){
                gotoxy(y,24);
            }
        }
    }
    printf("\n \n CARGA COMPLETA");

    //return 0;
}
