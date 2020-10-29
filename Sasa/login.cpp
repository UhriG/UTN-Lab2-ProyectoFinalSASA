#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;
#include "login.h"
#include "menu.h"
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
        cout << "INGRESE UNA OPCIÓN" << endl;
        cout << "1 - INGRESAR" << endl;
        cout << "2 - REGISTRARSE" << endl;
        cout << "3 - SALIR" << endl;
        cin >> opc;
        cls();
        switch(opc){
            case 1: log = login();
                break;
            case 2: //registrar();
                break;
            case 3: return;
                break;
        }
        if(log==true){
            menuPrincipal();
        }else{
            msj("DEMASIADOS INTENTOS FALLIDOS, VUELVA A INTENTAR EN 3 MINUTOS", rlutil::WHITE, rlutil::RED);
            Sleep(300);
        }
    }
}

bool Login::login(){
    /// usuario y password de prueba, se deberá reemplazar por una busqueda en archivo
    string user = "admin", pass = "admin";

    /// Contador para solo permitir 3 intentos, si falla los 3 sale del programa
    int contador = 0;

    bool logueado = false;
    string usuario, password;

    do{
        system("cls");
        title("SISTEMA ADMINISTRACION DE STOCK ALMACEN");
        gotoxy(1, 5);
        cout << "\t\t\tLOGIN DE USUARIO" << endl;

        cout << ">USUARIO: ";
        cin >> usuario;

        char caracter;

        cout << ">CONTRASEÑA: ";
        caracter = getch();

        password = "";

        while(caracter != 13){ ///13 por el código ascii del enter, entonces le digo que haga lo del while mientras no se presione enter
            if (caracter != 8){ ///8 por el código ascii del retroceso
                password.push_back(caracter); ///vamos añadiendo al password caracter por caracter ingresado siempre y cuando no sea un enter o retroceso
                cout << "*";
            }else{
                if(password.length() > 0){ ///Acá hacemos que mientras la longitud del password sea mayor a cero se borren los caracteres ingresados
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        ///Comprobamos que el usuario y password ingresado coincidan con el definito temporalmente como default
        if(usuario == user && password == pass){
            logueado =  true;
        }

        if(!logueado){
            cout << "\n\nEL USUARIO Y/O PASSWORD SON INCORRECTOS" << endl;
            getch();
            contador++;
        }


    }while(logueado == false && contador < 3);

    return logueado;
}
