#include <iostream>
#include <iomanip>
using namespace std;
#include "menu.h"
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "usuario.h"
#include "producto.h"

// MENUES PRINCIPAL
void menuPrincipal(){
    bool menu = true;
    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) USUARIO" << endl;
        cout << "2) PRODUCTOS" << endl;
        cout << "3) CATEGORÍA" << endl;
        cout << "4) CONFIGURACIONES" << endl;
        cout << endl;
        cout << "0) SALIR DEL PROGRAMA" << endl;
        cout << endl;
        cout << "> ";
        int opc;
        cin>>opc;
        //cls();
        switch(opc){
            case 1:
                menuUsuario();
            break;
            case 2:
                menuProducto();
            break;
            case 3:
                menuCategoria();
            break;
            case 4:
                menuConfiguracion();
            break;
            case 0:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}


void menuUsuario(){
    bool menu = true;
    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) CREAR USUARIO" << endl;
        cout << "2) LISTAR USUARIOS" << endl;
        cout << endl;
        cout << "0) VOLVER ATRÁS" << endl;
        cout << endl;
        cout << "> ";
        int opc;
        cin>>opc;
        cls();
        switch(opc){
            case 1:
                crearUsuario();
            break;
            case 2:
                listarUsuarios();
            break;
            case 0:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

void menuProducto(){
    bool menu = true;
    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) CREAR PRODUCTO" << endl;
        cout << "2) MODIFICAR PRODUCTO" << endl;
        cout << "3) ELIMINAR PRODUCTO" << endl;
        cout << "4) LISTAR PRODUCTOS" << endl;
        cout << endl;
        cout << "0) VOLVER ATRÁS" << endl;
        cout << endl;
        cout << "> ";
        int opc;
        cin>>opc;
        cls();
        switch(opc){
            case 1:
                crearProducto();
            break;
            case 2:
                modificarProducto();
            break;
            case 3:
                eliminarProducto();
            break;
            case 4:
                listarProducto();
            break;
            case 0:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

void menuCategoria(){
    bool menu = true;
    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) CREAR CATEGORÍA" << endl;
        cout << "2) MODIFICAR CATEGORÍA" << endl;
        cout << "3) ELIMINAR CATEGORÍA" << endl;
        cout << "4) LISTAR CATEGORÍAS" << endl;
        cout << endl;
        cout << "0) VOLVER ATRÁS" << endl;
        cout << endl;
        cout << "> ";
        int opc;
        cin>>opc;
        cls();
        switch(opc){
            case 1:
                crearCategoria();
            break;
            case 2:
                modificarCategoria();
            break;
            case 3:
                eliminarCategoria();
            break;
            case 0:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

void menuConfiguracion(){
    bool menu = true;
    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) REALIZAR COPIA DE SEGURIDAD" << endl;
        cout << "2) RECUPERAR COPIA DE SEGURIDAD" << endl;
        cout << "3) EXPORTAR A CSV (Si es que me sale)" << endl;
        cout << endl;
        cout << "0) VOLVER ATRÁS" << endl;
        cout << endl;
        cout << "> ";
        int opc;
        cin>>opc;
        cls();
        switch(opc){
            case 1:
                copiaSeguridad();
            break;
            case 2:
                recuperarCopia();
            break;
            case 3:
                exportarDatos();
            break;
            case 0:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

// SUB MENU USUARIO

void crearUsuario(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    Usuario u; //Clase USUARIO
    u.cargar();
    if(u.escribirDisco()==true){
        msj("SE CREO CORRECTAMENTE EL USUARIO", rlutil::WHITE, rlutil::GREEN);
    }
}

void listarUsuarios(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "LISTADO DE TODOS LOS USUARIOS" << endl;
    cout << endl;
    cout << left;

    Usuario u;
	int pos=0;

	int ancho = 10;
    cout << setw(5) << "ID" << setw(ancho) << "NOMBRE" << setw(ancho) << "PERFIL" << setw(ancho) << "ESTADO";
	while(u.leerDisco(pos++)==1){ //  .Leer_de_disco(pos++)==1)
        if(u.getEstado()==1){
            u.mostrar(); // u.mostrar();
        }
	}
	if(pos==1){
		msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
		system("pause>nul");
    }
    cout << endl << "----------------------------------------------------------------------------"<< endl;
    anykey();
    /*
    cout << "1) MODIFICAR USUARIO" << endl;
    cout << "2) ELIMINAR USUARIO" << endl;
*/
}

// SUB MENU PRODUCTO

void crearProducto(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    Producto p;
    p.cargar();
    p.escribirDisco();
}

void modificarProducto(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    int pos, id, stock;
    Producto p;
    cout << "*MODIFICAR PRODUCTO" << endl;
    cout << "INGRESAR ID PRODUCTO" << endl;
    cin >> id;
    pos = buscarCod(id);
    if(pos!=-1){
		cout<<"INGRESE NUEVO STOCK: ";
		cin>>stock;
		p.leerDisco(pos);
		p.setStock(stock);
		if(p.modDisco(pos)==true){
            msj("SE MODIFICO CON ÉXITO", rlutil::WHITE, rlutil::GREEN);
		}

    }else{
		msj("NO EXISTE EL PRODUCTO", rlutil::WHITE, rlutil::RED);
		anykey();
    }
}

void eliminarProducto(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    int id, pos;
    char resp[2];
    cout << "*ELIMINAR PRODUCTO" << endl;
    cout << "INGRESAR ID PRODUCTO: ";
    cin >> id;
    pos = buscarCod(id);
    Producto p;
    if(pos!=-1){
        int ancho = 10;
        p.leerDisco(pos);
        cout << left;
        cout << endl;
        cout << setw(ancho) << "ID" << setw(ancho) << "NOMBRE" << setw(ancho) << "MARCA" << setw(ancho) << "CATEGORÍA" << setw(ancho) << "ESTADO" << setw(ancho) << "STOCK";
        cout << endl << "----------------------------------------------------------------------------"<< endl;
        p.mostrar();
        cout << endl << "----------------------------------------------------------------------------"<< endl;
        cout << endl;
        cout << "ELIMINAR? (SI/NO): ";
        cin >> resp;
        if(resp == "SI" || resp == "si"){
            p.setEstado(0);
            if(p.modDisco(pos)==true){
                msj("SE ELIMINO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
            }
        } else{
            msj("NO SE ELIMINO EL PRODUCTO", rlutil::WHITE, rlutil::RED);
        }
    }else{
		msj("NO EXISTE EL PRODUCTO", rlutil::WHITE, rlutil::RED);
    }
}

void listarProducto(){
    bool menu = true;
    while(menu){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << "1) LISTAR PRODUCTO POR CÓDIGO ASCENDENTE" << endl;
        cout << "2) LISTAR PRODUCTO POR CÓDIGO DESCENDENTE" << endl;
        cout << "3) LISTAR PRODUCTO INDIVIDUAL" << endl;
        cout << "4) LISTAR TODOS LOS PRODUCTOS" << endl;
        cout << endl;
        cout << "0) VOLVER ATRÁS" << endl;
        cout << endl;
        cout << "> ";
        int opc;
        cin>>opc;
        switch(opc){
            case 1:
                listarProductoPorCodAs();
            break;
            case 2:
                listarProductoPorCodDes();
            break;
            case 3:
                listarProductoInd();
            break;
            case 4:
                listarProductoTodos();
            break;
            case 0:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

// SUB MENU CATEGORIA

void crearCategoria(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    string nombre;
    int id;
    cout << "*CREAR CATEGORÍA" << endl;
    cout << "INGRESAR LOS SIGUIENTES DATOS " << endl;
    cout << "NOMBRE: " << endl;
    cin >> nombre;
    cout << endl;
    msj("SE CREO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
}

void modificarCategoria(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    string nombre;
    int id;
    cout << "*MODIFICAR CATEGORÍA" << endl;
    cout << "INGRESAR LOS SIGUIENTES DATOS " << endl;
    cout << "ID CATEGORÍA: " << endl;
    cin >> id;
    //funcion buscar id
    cout << "INGRESAR NOMBRE NUEVO: " << endl;
    cin >> nombre;
    cout << endl;
    msj("SE CREO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
}

void eliminarCategoria(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    int id;
    char resp[2];
    bool estado = true;
    cout << "*ELIMINAR CATEGORÍA" << endl;
    cout << "INGRESAR ID CATEGORÍA" << endl;
    cin >> id;
    cout << "ELIMINAR? (SI/NO): " << endl;
    cin >> resp;
    if(resp == "SI"){
        estado = false;
        msj("SE ELIMINO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
    }
}

// SUB MENU CONFIGURACION

void copiaSeguridad(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "*SE CREARA COPIA DE SEGURIDAD DE LOS DATOS.DAT" << endl;
    msj("SE CREO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
}

void recuperarCopia(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "*SE RECUPERA COPIA DE SEGURIDAD DE LOS DATOS.DAT" << endl;
    msj("SE RECUPERO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
}

void exportarDatos(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "*SE EXPORTA DATOS.DAT A CSV" << endl;
    cout << "Si es que me sale jaja by Max" << endl;
    msj("SE EXPORTO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
}

// SUB MENU PRODUCTO LISTAR PRODUCTOS

void listarProductoPorCodAs(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "LISTAR PRODUCTO POR CÓDIGO ASCENDENTE" << endl;
    cout << endl;
    cout << left;

    Producto p;
	int pos=0;

	int ancho = 10;
    cout << setw(ancho) << "ID" << setw(ancho) << "NOMBRE" << setw(ancho) << "MARCA" << setw(ancho) << "CATEGORÍA" << setw(ancho) << "ESTADO" << setw(ancho) << "STOCK";
	cout << endl << "----------------------------------------------------------------------------"<< endl;
	while(p.leerDisco(pos++)==1){
        if(p.getEstado()==1){
            p.mostrar();
            cout << endl << "----------------------------------------------------------------------------"<< endl;
        }
	}
	if(pos==1){
		msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
		system("pause>nul");
    }
    anykey();
}

void listarProductoPorCodDes(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "LISTAR PRODUCTO POR CÓDIGO DESCENDENTE" << endl;
    cout << endl;
    cout << left;

    Producto p;
	int pos=0;

	int ancho = 10;
    cout << setw(ancho) << "ID" << setw(ancho) << "NOMBRE" << setw(ancho) << "MARCA" << setw(ancho) << "CATEGORÍA" << setw(ancho) << "ESTADO" << setw(ancho) << "STOCK";
	cout << endl << "----------------------------------------------------------------------------"<< endl;
	while(p.leerDisco(pos++)==1){
        if(p.getEstado()==1){
            p.mostrar();
            cout << endl << "----------------------------------------------------------------------------"<< endl;
        }
	}
	if(pos==1){
		msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
		system("pause>nul");
    }
    anykey();
}

void listarProductoInd(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "LISTAR PRODUCTO INDIVIDUAL" << endl;
    cout << endl;
    cout << left;
    cout << "INGRESAR ID: ";
    int cod;
    cin >> cod;

    Producto p;
	int pos=0;

	int ancho = 10;
    cout << setw(ancho) << "ID" << setw(ancho) << "NOMBRE" << setw(ancho) << "MARCA" << setw(ancho) << "CATEGORÍA" << setw(ancho) << "ESTADO" << setw(ancho) << "STOCK";
	cout << endl << "----------------------------------------------------------------------------"<< endl;
	while(p.leerDisco(pos++)==1){
        if(p.getEstado()==1 && cod == p.getId()){
            p.mostrar();
            cout << endl << "----------------------------------------------------------------------------"<< endl;
        }
	}
	if(pos==1){
		msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
		system("pause>nul");
    }
    anykey();
}

void listarProductoTodos(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "LISTAR TODOS LOS PRODUCTOS" << endl;
    cout << endl;
    cout << left;

    Producto p;
	int pos=0;

	int ancho = 10;
    cout << setw(ancho) << "ID" << setw(ancho) << "NOMBRE" << setw(ancho) << "MARCA" << setw(ancho) << "CATEGORÍA" << setw(ancho) << "ESTADO" << setw(ancho) << "STOCK";
	cout << endl << "----------------------------------------------------------------------------"<< endl;
	while(p.leerDisco(pos++)==1){
        if(p.getEstado()==1){
            p.mostrar();
            cout << endl << "----------------------------------------------------------------------------"<< endl;
        }
	}
	if(pos==1){
		msj("Presione cualquier tecla para salir", rlutil::WHITE, rlutil::MAGENTA);
		system("pause>nul");
    }
    anykey();
}
