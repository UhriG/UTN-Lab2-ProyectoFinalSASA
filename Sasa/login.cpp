#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;
#include "login.h"
#include "menu.h"
#include "usuario.h"
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

void Login::menuLogin(){
    int opc;
    bool menu=true;
    bool log = false;

    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACEN");
        gotoxy(1, 5);
        cout << "INGRESE UNA OPCI�N" << endl;
        cout << "1 - INGRESAR" << endl;
        cout << "2 - REGISTRARSE" << endl;
        cout << "3 - SALIR" << endl <<" >";

        while(!(cin >> opc) || (opc < 1 || opc > 3)){
            cout << "SOLO SE ACEPTAN NUMEROS DEL 1 al 3: ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        switch(opc){
            case 1: login();
                break;
            case 2: //registrar();
                break;
            case 3: return;
                break;
            //default: msj("INRGRESE UN VALOR V�LIDO DEL 1 AL 3", rlutil::WHITE, rlutil::RED);
        }
    }
}

void Login::login(){

    /// Contador para solo permitir 3 intentos, si falla los 3 sale del programa
    int contador = 0;

    bool logueado = false;
    char usuario[20], password[10];

    do{
        system("cls");
        title("SISTEMA ADMINISTRACION DE STOCK ALMACEN");
        gotoxy(1, 5);
        cout << "\t\t\tLOGIN DE USUARIO" << endl;

        cout << ">USUARIO: ";
        cin >> usuario;

        cout << ">PASSWORD: ";
        cin >> password;

        if(comprobarCredenciales(password, usuario) != -1){
            logueado = true;
        }else{
            msj("CREDENCIALES INCORRECTAS, INTENTE NUEVAMENTE", rlutil::WHITE, rlutil::RED);
            contador++;
        }

    }while(logueado == false && contador < 3);

    if(logueado){
        menuPrincipal();
    }else{
        cls();
        system("color 47");
        cout << "\n\n\n\t\tDEMASIADOS INTENTOS FALLIDOS, EL PROGRAMA SE CERRAR�" << endl;
        exit(0);
    }
}

int Login::comprobarCredenciales(char *passB, char *nombreB){
	int pos=0;
	Usuario u;
	while(u.leerDisco(pos)==1){
		if(strcmp(passB,u.getPassword())==0 && strcmp(nombreB,u.getNombre())==0 && u.getEstado()==1){
            return pos;
		}
		pos++;
    }
	return -1;
}
