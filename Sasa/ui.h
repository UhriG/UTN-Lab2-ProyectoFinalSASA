#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

#define APP_BACKCOLOR 0 // DEFINE EL COLOR DE FONDO general
#define APP_FORECOLOR 15 // DEFINE EL COLOR DEL TEXTO general
#define APP_TITLEBACKCOLOR 1 // DEFINE EL COLOR DE FONDO en titulo
#define APP_TITLEFORECOLOR 15 // DEFINE EL COLOR DEL TEXTO en titulo
#define APP_ERRORCOLOR 4
#define APP_OKCOLOR 2
#define APP_DELAY 1000

/// COLORES
/*
    0 NEGRO
    1 AZUL
    2 VERDE
    3 CELESTE
    4 ROJO
    5 VIOLETA
    6 DORADO
    7 GRIS
    8 GRIS OSCURO
    9 CELESTE NEON
    10 VERDE NEON
    11 TURQUESA
    12 ROJO NEON
    13 VIOLETA FUERTE
    14 AMARILLO PALIDO
    15 BLANCO
    16 NEGRO
    17 AZUL
    18 VERDE OSCURO
    19 CELESTE OSCURO
    20 ROJO OSCURO
*/
enum Orientation{
    TEXT_LEFT,
    TEXT_RIGHT,
    TEXT_CENTER
};
void setColors(int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR);
void bar(int foreColor, int backColor, int y=SCREEN_HEIGHT, int width=SCREEN_WIDTH);
void title(const char *mensaje, int foreColor = APP_TITLEFORECOLOR, int backColor = APP_TITLEBACKCOLOR);
void msj(const char *mensaje, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR, int y = SCREEN_HEIGHT, Orientation o = TEXT_CENTER);
void delline(int line, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR);
void initUI();

void listarPlanilla();
void titleInt(const char *mensaje,int entero, int foreColor = APP_TITLEFORECOLOR, int backColor = APP_TITLEBACKCOLOR);
void titleFloat(const char *mensaje,float dato, int foreColor = APP_TITLEFORECOLOR, int backColor = APP_TITLEBACKCOLOR);
void msjInt(const char *mensaje,int entero, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR, int y = SCREEN_HEIGHT, Orientation o = TEXT_CENTER);
void msjFloat(const char *mensaje,float dato, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR, int y = SCREEN_HEIGHT, Orientation o = TEXT_CENTER);

#include <iostream>
using namespace std;
#include <iomanip>
#include <cstring>
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

void initUI() {

    system("mode con: cols=80 lines=25");
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
    setlocale(LC_ALL, "spanish");


}

void setColors(int foreColor, int backColor){
    setColor(foreColor);
    setBackgroundColor(backColor);
}

void bar(int foreColor, int backColor, int y, int width){
    if (width > SCREEN_WIDTH)
        width = SCREEN_WIDTH;
    if (y > SCREEN_HEIGHT)
        y = SCREEN_HEIGHT;

    setColors(foreColor, backColor);
    for (int x=1; x<=width; x++){
        gotoxy(x, y);
        cout << " ";
    }
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
    resetColor();
}
void msj(const char *mensaje, int foreColor, int backColor, int y, Orientation o){
    bar(foreColor, backColor, y, SCREEN_WIDTH);
    setColors(foreColor, backColor);

    //TODO: Analizar la orientación
    gotoxy(1, y);
    cout << mensaje;
    cin.ignore();
    anykey();
    resetColor();
    bar(APP_FORECOLOR, APP_BACKCOLOR, y, SCREEN_WIDTH);
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}
void title(const char *mensaje, int foreColor, int backColor){
    bar(foreColor, backColor, 1, SCREEN_WIDTH);
    setColors(foreColor, backColor);
    int centro = (SCREEN_WIDTH - strlen(mensaje))/2;
    gotoxy(centro, 1);
    cout << mensaje;
    resetColor();
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}
void delline(int line, int foreColor, int backColor){
    setColors(foreColor, backColor);
    for(int x=0; x<=SCREEN_WIDTH; x++){
        gotoxy(x, line);
        cout << " ";
    }
    resetColor();
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}
/// COPIAR FUNCION Y EDITAR LOS DATOS A MOSTRAR
void listarPlanilla(){
    int ancho =10; // Determina el ancho de cada columna
    cls();
    title("LISTAR PLANILLA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    gotoxy(1, 5);
    cout << left;
    cout << setw(ancho) << "COL-1" << setw(ancho) << "COL-2" << setw(ancho) << "COL-3" << setw(ancho) << "COL-4" << setw(ancho) << "COL-5";
    cout << endl << "----------------------------------------------------------------------------" << endl;
    for(int i = 0; i<2; i++){
        cout << setw(ancho) << "CELDA-1";
        cout << setw(ancho) << "CELDA-2";
        cout << setw(ancho) << "CELDA-3";
        cout << setw(ancho) << "CELDA-4";
        cout << setw(ancho) << "CELDA-5";
        cout << endl << "----------------------------------------------------------------------------" << endl;
    }
    msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
    return;
}

void msjInt(const char *mensaje, int entero, int foreColor, int backColor, int y, Orientation o){
    bar(foreColor, backColor, y, SCREEN_WIDTH);
    setColors(foreColor, backColor);

    //TODO: Analizar la orientación
    gotoxy(1, y);
    cout << mensaje << " " << entero;
    cin.ignore();
    anykey();
    resetColor();
    bar(APP_FORECOLOR, APP_BACKCOLOR, y, SCREEN_WIDTH);
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}

void msjFloat(const char *mensaje, float dato, int foreColor, int backColor, int y, Orientation o){
    bar(foreColor, backColor, y, SCREEN_WIDTH);
    setColors(foreColor, backColor);

    //TODO: Analizar la orientación
    gotoxy(1, y);
    cout << mensaje << " " << dato;
    cin.ignore();
    anykey();
    resetColor();
    bar(APP_FORECOLOR, APP_BACKCOLOR, y, SCREEN_WIDTH);
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}

void titleInt(const char *mensaje, int entero, int foreColor, int backColor){
    bar(foreColor, backColor, 1, SCREEN_WIDTH);
    setColors(foreColor, backColor);
    int centro = (SCREEN_WIDTH - strlen(mensaje))/2;
    gotoxy(centro, 1);
    cout << mensaje << " " << entero;
    resetColor();
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}

void titleFloat(const char *mensaje, float dato, int foreColor, int backColor){
    bar(foreColor, backColor, 1, SCREEN_WIDTH);
    setColors(foreColor, backColor);
    int centro = (SCREEN_WIDTH - strlen(mensaje))/2;
    gotoxy(centro, 1);
    cout << mensaje << " " << dato;
    resetColor();
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}

#endif // UI_H_INCLUDED
