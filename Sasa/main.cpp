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
    //initUI();

    //compAdmin();
    //menuLogin();

    //INGRESAR LAS FUNCIONES PARA PROBAR, COMENTANDO EL MENUPRINCIPAL
    //menuPrincipal();
    Producto pr;
    int cant = cantProd();
    int pos=0, productos = 5;
    int resp=1;
    while(resp != 0){
        FILE *p;
        p=fopen("datos/producto.dat","rb");
        if(p==NULL){
            cout<<"No existe el archivo";
            return -1;
        }
        for(pos; pos < productos; pos++){

            fseek(p,pos*sizeof(Producto),0);
            fread(&pr,sizeof(Producto),1,p);
            pr.mostrar(2);

        }
        fclose(p);
        cout << endl;
        cout << "0- SALIR 1- PAGINA SIGUIENTE" << endl;
        cin >> resp;
        if(resp != 0){
            pos+5;
            productos+5;
        }
    }
    //return 0;
}
