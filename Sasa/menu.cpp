#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
#include "menu.h"
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "carteles.h"
#include "usuario.h"
#include "producto.h"
#include "categoria.h"
#include "movimiento.h"
#include "login.h"

// MENUES PRINCIPAL
void menuPrincipal(){
    bool menu = true;
    int opc;
    while(menu){
        cMenuPrincipal();
        while(!(cin >> opc)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenuPrincipal();
        }

        switch(opc){
            case 1:
                if(perfilTemp() != 3){menuUsuario();}
                else{cMsjPerfil();}
            break;
            case 2:
                menuProducto();
            break;
            case 3:
                if(perfilTemp() != 3){menuCategoria();}
                else{cMsjPerfil();}
            break;
            case 4:
                if(perfilTemp() != 3){menuMovimientos();}
                else{cMsjPerfil();}
            break;
            case 5:
                menuConfiguracion();
            break;
            case 6:
                Login l;
                l.eliminarTemp();
                menu = false;
            break;
            default: msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
                break;
        }
    }
}

void menuUsuario(){
    bool menu = true;
    int opc;
    while(menu){
        cMenu(1); // CARTEL MENU GENERAL ( USUARIO )
        while(!(cin >> opc)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenu(1); // CARTEL MENU GENERAL ( USUARIO )
        }

        switch(opc){
            case 1:
                if(perfilTemp() == 1){crearUsuario();}
                else{cMsjPerfil();}
            break;
            case 2:
                if(perfilTemp() == 1){modificarUsuario();}
                else{cMsjPerfil();}
            break;
            case 3:
                if(perfilTemp() == 1){eliminarUsuario();}
                else{cMsjPerfil();}
            break;
            case 4:
                listarUsuarios();
            break;
            case 5:
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
    int opc;
    while(menu){
        cMenu(2); // CARTEL MENU GENERAL ( PRODUCTO )
        while(!(cin >> opc)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenu(2); // CARTEL MENU GENERAL ( PRODUCTO )
        }

        switch(opc){
            case 1:
                crearProducto();
            break;
            case 2:
                if(perfilTemp() != 3){modificarProducto();}
                else{cMsjPerfil();}
            break;
            case 3:
                if(perfilTemp() == 1){eliminarProducto();}
                else{cMsjPerfil();}
            break;
            case 4:
                listarProducto();
            break;
            case 5:
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
    int opc;
    while(menu){
        cMenu(3); // CARTEL MENU GENERAL ( CATEGORÍA )
        while(!(cin >> opc)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenu(3); // CARTEL MENU GENERAL ( CATEGORÍA )
        }

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
            case 4:
                listarCategoria();
            break;
            case 5:
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
    int opc;
    while(menu){
        cMenuConfiguracion(); // CARTEL MENU CONFIGURACION
        while(!(cin >> opc)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenuConfiguracion(); // CARTEL MENU CONFIGURACION
        }

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
            case 5:
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
    cTitulo();
    Usuario u; //Clase USUARIO
    u.cargar();
    if(u.escribirDisco()==true){
        msj("SE CREO CORRECTAMENTE EL USUARIO", rlutil::WHITE, rlutil::GREEN);
    }
}

void modificarUsuario(){
    cTitulo();
    Usuario u;
    int pos, id;
    cout << "*MODIFICAR USUARIO" << endl;
    cout << "INGRESAR ID USUARIO: ";

    while(!(cin >> id)){
        msj("INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }

    cout << endl;
    pos = buscarID(id);
    if(pos!=-1){
		u.leerDisco(pos);
		u.mostrar(2);
		cout << endl;
		cout << "NOMBRE: 1 \tCONTRASEÑA: 2 \tPERFIL: 3 \tSALIR: 5" << endl;
		cout << "ELEGIR UNA OPCIÓN: ";
		int opc;
		while(!(cin >> opc)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        switch(opc){
            case 1:
                char n[20];
                cout << "INGRESAR NOMBRE: ";
                cin >> n;
                u.setNombre(n);
            break;
            case 2:
                char p[10];
                cout << "INGRESAR PASSWORD: ";
                cin >> p;
                u.setPassword(p);
            break;
            case 3:
                int per;
                cout << "INGRESAR PERFIL: ";
                while(!(cin >> per)){
                    msj("OPCIÓN INCORRECTA: 1 - ADMIN \t2 - SUPERVISOR \t3 - OPERADOR", rlutil::WHITE, rlutil::RED);
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                u.setPerfil(per);
            break;
            case 5:
                return;
        }
		if(u.modDisco(pos)==true){
            msj("SE MODIFICO CON ÉXITO", rlutil::WHITE, rlutil::GREEN);
		}
    }else{
		msj("NO EXISTE EL USUARIO", rlutil::WHITE, rlutil::RED);
		anykey();
    }
}

void eliminarUsuario(){
    cTitulo();
    int id, pos;
    char conf;
    cout << "*ELIMINAR USUARIO" << endl;
    cout << "INGRESAR ID USUARIO: ";
    while(!(cin >> id)){
        msj("INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << endl;
    pos = buscarID(id);
    Usuario u;
    if(pos!=-1){
        int ancho = 10;
        u.leerDisco(pos);
        u.mostrar(2);
        cout << endl;
        cout << "ELIMINAR? (S/N): ";
        conf = getche();
        while(conf!='S' && conf!='s' && conf!='N' && conf!='n'){
            cout << "\nIngrese una opción válida!" << endl << " >";
            conf = getche();
        }
        if(conf == 's' || conf == 'S'){
            int baja = 0;
            u.setEstado(baja);
            if(u.modDisco(pos)==true){
                msj("SE ELIMINO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
            }
        }else{
            msj("NO SE ELIMINO EL USUARIO", rlutil::WHITE, rlutil::RED);
        }
    }else{
		msj("NO EXISTE EL USUARIO", rlutil::WHITE, rlutil::RED);
    }
}

void listarUsuarios(){
    Usuario u;
    int cant = cantUsuario(), pos = 0, usuarios = 5, paginas;
    if(cant % usuarios == 0){
        paginas = cant / usuarios;
    } else {
        paginas = (cant / usuarios)+1;
    }
    int idanterior = -1, hoja = 1, resp = 1;
    while(resp != 0){
        cTitulo();
        cout << left;
        cout << "*LISTADO DE TODOS LOS USUARIOS" << endl;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "TOTAL DE USUARIOS: " << cant << endl;
        cout << "-----------------------------" << endl;
        cTabla(1); // MODO 1 USUARIO
        for(pos; pos < usuarios; pos++){
            u.leerDisco(pos);
            if(u.getEstado()==1 && u.getId() != idanterior){
                u.mostrar();
                cout << endl << "----------------------------------------------------------------------------"<< endl;
            }
            idanterior = u.getId();
        }
        cout << "*PAGINA: " << hoja << " / " << paginas << endl;
        cout << endl;
        cout << "0- SALIR | INDIQUE PÁGINA: > ";
        while(!(cin >> resp)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
            msj("NO HAY MÁS DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
            resp = 0;
        }
        if(resp != 0){
            pos = 5 *(hoja-1);
            usuarios = pos + 5;
        }
    }
}

// SUB MENU PRODUCTO

void crearProducto(){
    cTitulo();
    Producto p;
    p.cargar();
    if(p.escribirDisco()==true){
        msj("SE CREO PRODUCTO CON ÉXITO", rlutil::WHITE, rlutil::GREEN);
        Movimiento m;
        m.cargar(p);//SI EL PRODUCTO SE CREA CON EXITO SE GUARDA EL MOVIMIENTO EN LA BITACORA
        m.escribirDisco();
    } else{
        msj("ERROR AL CREAR PRODUCTO", rlutil::WHITE, rlutil::RED);
    }

}

void modificarProducto(){
    cTitulo();
    int pos, id, stock;
    Producto p;
    cout << "*MODIFICAR PRODUCTO (STOCK)" << endl;
    cout << "INGRESAR ID PRODUCTO: ";
    while(!(cin >> id)){
        msj(" INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << endl;
    pos = buscarCod(id);
    if(pos!=-1){
		p.leerDisco(pos);
		p.mostrar(2);
		cout << endl;
		cout<<"INGRESE NUEVO STOCK: ";
		while(!(cin >> stock)){
            msj("INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS ENTEROS", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
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
    cTitulo();
    int id, pos;
    char conf;
    cout << "*ELIMINAR PRODUCTO" << endl;
    cout << "INGRESAR ID PRODUCTO: ";
    while(!(cin >> id)){
        msj(" INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << endl;
    pos = buscarCod(id);
    Producto p;
    if(pos!=-1){
        int ancho = 10;
        p.leerDisco(pos);
        p.mostrar(2);
        cout << endl;
        cout << "ELIMINAR? (S/N): ";
        conf = getche();
        while(conf!='S' && conf!='s' && conf!='N' && conf!='n'){
            cout << "\nIngrese una opción válida!" << endl << " >";
            conf = getche();
        }
        if(conf == 'S' || conf == 's'){
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
        cTitulo();
        cMenuProdListar();
        int opc;
        while(!(cin >> opc)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cTitulo();
            cMenuProdListar();
        }
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
            case 5:
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
    cTitulo();
    Categoria c; //Clase categoria
    c.cargar();
    if(c.escribirDisco()==true){
        msj("SE CREO CORRECTAMENTE LA CATEGORÍA", rlutil::WHITE, rlutil::GREEN);
    }else{
        msj("ERROR AL CREAR CATEGORÍA", rlutil::WHITE, rlutil::GREEN);
    }
}


void modificarCategoria(){
    cTitulo();
    Categoria c;
    int pos, id;
    cout << "*MODIFICAR CATEGORÍA" << endl;
    cout << "INGRESAR ID CATEGORÍA: ";

    while(!(cin >> id)){
        msj("INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }

    cout << endl;
    pos = buscarIDcat(id);
    if(pos!=-1){
		c.leerDisco(pos);
		c.mostrar(2);
		cout << endl;
		cout << "NOMBRE: 1 \tSALIR: 5" << endl;
		cout << "ELEGIR UNA OPCIÓN: ";
		int opc;
		while(!(cin >> opc)){
            msj("OPCION INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        switch(opc){
            case 1:
                char n[20];
                cout << "INGRESAR NOMBRE: ";
                cin >> n;
                c.setNombre(n);
            break;
            case 5:
                return;
        }
		if(c.modDisco(pos)==true){
            msj("SE MODIFICO CON ÉXITO", rlutil::WHITE, rlutil::GREEN);
		}
    }else{
		msj("NO EXISTE LA CATEGORÍA", rlutil::WHITE, rlutil::RED);
		anykey();
    }
}


void eliminarCategoria(){
    cTitulo();
    int id, pos;
    char conf;
    cout << "*ELIMINAR CATEGORÍA" << endl;
    cout << "INGRESAR ID CATEGORÍA: ";
    while(!(cin >> id)){
        msj("INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << endl;
    pos = buscarIDcat(id);
    Categoria c;
    if(pos!=-1){
        int ancho = 10;
        c.leerDisco(pos);
        c.mostrar(2);
        cout << endl;
        cout << "ELIMINAR? (S/N): ";
        conf = getche();
        while(conf!='S' && conf!='s' && conf!='N' && conf!='n'){
            cout << "\nIngrese una opción válida!" << endl << " >";
            conf = getche();
        }
        if(conf == 's' || conf == 'S'){
            int baja = 0;
            c.setEstado(baja);
            if(c.modDisco(pos)==true){
                msj("SE ELIMINO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
            }
        }else{
            msj("NO SE ELIMINO LA CATEGORÍA", rlutil::WHITE, rlutil::RED);
        }
    }else{
		msj("NO EXISTE LA CATEGORÍA", rlutil::WHITE, rlutil::RED);
    }
}


void listarCategoria(){
    Categoria c;
    int cant = cantCategoria(), pos = 0, categorias = 5, paginas;
    if(cant % categorias == 0){
        paginas = cant / categorias;
    } else {
        paginas = (cant / categorias)+1;
    }
    int idanterior = -1, hoja = 1, resp = 1;
    while(resp != 0){
        cTitulo();
        cout << left;
        cout << "*LISTADO DE TODAS LAS CATEGORIAS" << endl;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "TOTAL DE CATEGORIAS: " << cant << endl;
        cout << "-----------------------------" << endl;
        cTabla(3); // MODO 3 CATEGORÍA
        for(pos; pos < categorias; pos++){
            c.leerDisco(pos);
            if(c.getEstado()==1 && c.getId() != idanterior){
                c.mostrar();
                cout << endl << "----------------------------------------------------------------------------"<< endl;
            }
            idanterior = c.getId();
        }
        cout << "*PAGINA: " << hoja << " / " << paginas << endl;
        cout << endl;
        cout << "0- SALIR | INDIQUE PAGINA: > ";
        while(!(cin >> resp)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
            msj("NO HAY MÁS DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
            resp = 0;
        }
        if(resp != 0){
            pos = 5 *(hoja-1);
            categorias = pos + 5;
        }
    }
}


// SUB MENU CONFIGURACION

void copiaSeguridad(){
    cTitulo();
    // BARRA DE PROGRESO
    gotoxy(35,10);
    printf("CARGANDO");
    for(int i=1; i<90; i++){
        gotoxy(i,13);
        printf("#");
        for(int x=50; x<70; x++){
            for(int y=1; y<70; y++){
                gotoxy(y,24);
            }
        }
    }
    // TERMINA BARRA
    int guardo =0;
    guardo += copiaUsuario();
    guardo += copiaProducto();
    guardo += copiaCategoria();
    if(guardo == 3){
        msj("SE CREO COPIA DE SEGURIDAD",rlutil::WHITE, rlutil::GREEN);
    } else {
        msj("ERROR AL CREAR COPIA DE SEGURIDAD",rlutil::WHITE, rlutil::RED);
    }
}

void recuperarCopia(){
    cTitulo();
    // BARRA DE PROGRESO
    gotoxy(35,10);
    printf("CARGANDO");
    for(int i=1; i<90; i++){
        gotoxy(i,13);
        printf("#");
        for(int x=50; x<70; x++){
            for(int y=1; y<70; y++){
                gotoxy(y,24);
            }
        }
    }
    // TERMINA BARRA
    int rec = 0;
    rec += recUsuario();
    rec += recProducto();
    rec += recCategoria();
    if(rec == 3){
        msj("SE RECUPERO CORRECTAMENTE",rlutil::WHITE, rlutil::GREEN);
    } else {
        msj("ERROR AL RECUPERAR COPIA DE SEGURIDAD",rlutil::WHITE, rlutil::RED);
    }
}

void exportarDatos(){
    cTitulo();
    cout << "*SE EXPORTA DATOS.DAT A CSV" << endl;
    cout << "Si es que me sale jaja by Max" << endl;
    msj("SE EXPORTO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
}

// SUB MENU PRODUCTO LISTAR PRODUCTOS

void listarProductoPorCodAs(){
    Producto p;
    int cant = cantProd(), pos = 0, productos = 5, paginas;
    if(cant % productos == 0){
        paginas = cant / productos;
    } else {
        paginas = (cant / productos)+1;
    }
    int idanterior = -1, hoja = 1;
    int resp=1;
    while(resp != 0){
        cTitulo();
        cout << left;
        cout << "*LISTAR TODOS LOS PRODUCTOS POR COD ASCENDENTE" << endl;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "TOTAL DE PRODUCTOS: " << cant << endl;
        cout << "-----------------------------" << endl;
        cTabla(2); // MODO 2 PRODUCTO
        for(pos; pos < productos; pos++){
            p.leerDisco(pos);
            if(p.getEstado()==1 && p.getId() != idanterior){
                p.mostrar();
                cout << endl << "----------------------------------------------------------------------------"<< endl;
            }
            idanterior = p.getId();
        }
        cout << "*PAGINA: " << hoja << " / " << paginas << endl;
        cout << endl;
        cout << "0- SALIR | INDIQUE PÁGINA: > ";
        while(!(cin >> resp)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
                msj("NO HAY MÁS DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            pos = 5 *(hoja-1);
            productos = pos + 5;
        }
    }
}

void listarProductoPorCodDes(){
    Producto p;
    int cant = cantProd(), pos = cant, productos = 5, paginas;
    if(cant % productos == 0){
        paginas = cant / productos;
    } else {
        paginas = (cant / productos)+1;
    }
    productos = cant -5; // ASIGNAMOS EL VALOR DE HASTA DONDE IR
    int idanterior = -1, hoja = 1;
    int resp=1;
    while(resp != 0){
        cTitulo();
        cout << left;
        cout << "*LISTAR TODOS LOS PRODUCTOS POR COD DESCENDENTE" << endl;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "TOTAL DE PRODUCTOS: " << cant << endl;
        cout << "-----------------------------" << endl;
        cTabla(2); // MODO 2 PRODUCTO
        for(pos; pos > productos; pos--){
            p.leerDisco(pos);
            if(p.getEstado()==1 && p.getId() != idanterior && p.getId() != 0){
                p.mostrar();
                cout << endl << "----------------------------------------------------------------------------"<< endl;
            }
            idanterior = p.getId();
        }
        cout << "PAGINA: " << hoja << " / " << paginas << endl;
        cout << "0- SALIR | INDIQUE PÁGINA: > ";
        while(!(cin >> resp)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
                msj("NO HAY MÁS DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            pos = cant - (5*(hoja-1));
            productos = pos - 5;
        }
    }
}

void listarProductoInd(){
    cTitulo();
    cout << "LISTAR PRODUCTO INDIVIDUAL" << endl;
    cout << endl;
    cout << left;
    cout << "INGRESAR ID: ";
    int cod, pos;
    while(!(cin >> cod)){
        msj("INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }
    pos=buscarCod(cod);
    Producto p;
    p.leerDisco(pos);
    cTabla(2); // MODO 2 PRODUCTO
	p.mostrar();
    cout << endl << "----------------------------------------------------------------------------"<< endl;
    anykey();
}

void listarProductoTodos(){
    Producto p;
    int cant = cantProd(), pos = 0, productos = 5, paginas;
    if(cant % productos == 0){
        paginas = cant / productos;
    } else {
        paginas = (cant / productos)+1;
    }
    int idanterior = -1, hoja = 1;
    int resp=1;
    while(resp != 0){
        cTitulo();
        cout << left;
        cout << "*LISTAR TODOS LOS PRODUCTOS" << endl;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "TOTAL DE PRODUCTOS: " << cant << endl;
        cout << "-----------------------------" << endl;
        cTabla(2); // MODO 2 PRODUCTO
        for(pos; pos < productos; pos++){
            p.leerDisco(pos);
            if(p.getEstado()==1 && p.getId() != idanterior){
                p.mostrar();
                cout << endl << "----------------------------------------------------------------------------"<< endl;
            }
            idanterior = p.getId();
        }
        cout << "PAGINA: " << hoja << " / " << paginas << endl;
        cout << "0- SALIR | INDIQUE PÁGINA: > ";
        while(!(cin >> resp)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
                msj("NO HAY MÁS DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            pos = 5 *(hoja-1);
            productos = pos + 5;
        }
    }
}

// MENÚ BITÁCORA
void menuMovimientos(){
    bool menu = true;
    int opc;
    while(menu){
        cMenuMovimientos(); // CARTEL MENU GENERAL ( USUARIO )
        while(!(cin >> opc)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenuMovimientos(); // CARTEL MENU GENERAL ( USUARIO )
        }

        switch(opc){
            case 1:
                //cargarIngresos();
            break;
            case 2:
                //cargarEgresos();
            break;
            case 3:
                listarBitacora();
            break;
            case 4:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

// LISTAR BITACORA
void listarBitacora(){
    bool menu = true;
    int opc;
    while(menu){
        cMenuBitacora(); // CARTEL MENU GENERAL ( USUARIO )
        while(!(cin >> opc)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenuBitacora(); // CARTEL MENU GENERAL ( USUARIO )
        }

        switch(opc){
            case 1:
                listarMovimientosTodos();
            break;
            case 2:
                //cargarEgresos();
            break;
            case 3:
               // listarBitacora();
            break;
            case 4:
               // listarBitacora();
            break;
            case 5:
                menu = false;
            break;
            default:
                msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

//LISTAR TODOS LOS MOVIMIENTOS BITACORA
void listarMovimientosTodos(){
    Movimiento m;
    int cant = cantMov(), pos = 0, movimientos = 5, paginas;
    if(cant % movimientos == 0){
        paginas = cant / movimientos;
    } else {
        paginas = (cant / movimientos)+1;
    }
    int idanterior = -1, hoja = 1;
    int resp=1;
    while(resp != 0){
        cTitulo();
        cout << left;
        cout << "*LISTAR TODOS LOS MOVIMIENTOS" << endl;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "TOTAL DE MOVIMIENTOS: " << cant << endl;
        cout << "-----------------------------" << endl;
        cTabla(4); // MODO 4 BITACORA
        for(pos; pos < movimientos; pos++){
            m.leerDisco(pos);
            if(m.getId() != idanterior && m.getId() != 0){
                m.mostrar(1);
                cout << endl << "------------------------------------------------------------------------------------------"<< endl;
            }
            idanterior = m.getId();
        }
        cout << "PAGINA: " << hoja << " / " << paginas << endl;
        cout << "0- SALIR | INDIQUE PÁGINA: > ";
        while(!(cin >> resp)){
            msj("OPCIÓN INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
                msj("NO HAY MÁS DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            pos = 5 *(hoja-1);
            movimientos = pos + 5;
        }
    }
}

// SUB MENU COPIA DE SEGURIDAD
bool copiaUsuario(){
    Usuario u;
    FILE *f = fopen("datos/usuario.dat", "rb");
    FILE *backup = fopen("datos/usuarioBK.dat", "wb"); //Seteo a 0 el archivo de bk
    fclose(backup);
    if(f == NULL){
        cout << "No se puede leer usuario.dat .";
        system("pause");
        return false;
    }
    while(fread(&u, sizeof(Usuario), 1, f)){
        FILE *bk = fopen("datos/usuarioBK.dat", "ab");
        if(bk == NULL){
            cout << "No se puede guardar en BK.";
            system("pause");
            return false;
        }
        fwrite(&u, sizeof(Usuario), 1, bk);
        fclose(bk);
    }
    fclose(f);
    return true;
}

bool copiaProducto(){
    Producto p;
    FILE *f = fopen("datos/producto.dat", "rb");
    FILE *backup = fopen("datos/productoBK.dat", "wb"); //Seteo a 0 el archivo de bk
    fclose(backup);
    if(f == NULL){
        cout << "No se puede leer producto.dat .";
        system("pause");
        return false;
    }
    while(fread(&p, sizeof(Producto), 1, f)){
        FILE *bk = fopen("datos/productoBK.dat", "ab");
        if(bk == NULL){
            cout << "No se puede guardar en BK.";
            system("pause");
            return false;
        }
        fwrite(&p, sizeof(Producto), 1, bk);
        fclose(bk);
    }
    fclose(f);
    return true;
}

bool copiaCategoria(){
    Categoria c;
    FILE *f = fopen("datos/categoria.dat", "rb");
    FILE *backup = fopen("datos/categoriaBK.dat", "wb"); //Seteo a 0 el archivo de bk
    fclose(backup);
    if(f == NULL){
        cout << "No se puede leer categoria.dat .";
        system("pause");
        return false;
    }
    while(fread(&c, sizeof(Categoria), 1, f)){
        FILE *bk = fopen("datos/categoriaBK.dat", "ab");
        if(bk == NULL){
            cout << "No se puede guardar en BK.";
            system("pause");
            return false;
        }
        fwrite(&c, sizeof(Categoria), 1, bk);
        fclose(bk);
    }
    fclose(f);
    return true;
}

bool copiaMovimiento(){
    Movimiento m;
    FILE *f = fopen("datos/bitacora.dat", "rb");
    FILE *backup = fopen("datos/bitacoraBK.dat", "wb"); //Seteo a 0 el archivo de bk
    fclose(backup);
    if(f == NULL){
        cout << "No se puede leer bitacora.dat .";
        system("pause");
        return false;
    }
    while(fread(&m, sizeof(Movimiento), 1, f)){
        FILE *bk = fopen("datos/bitacoraBK.dat", "ab");
        if(bk == NULL){
            cout << "No se puede guardar en BK.";
            system("pause");
            return false;
        }
        fwrite(&m, sizeof(Movimiento), 1, bk);
        fclose(bk);
    }
    fclose(f);
    return true;
}

// SUB MENU RESTAURAR COPIA DE SEGURIDAD
bool recUsuario(){
    Usuario u;
    FILE *bk = fopen("datos/usuarioBK.dat", "rb");
    FILE *orig = fopen("datos/usuario.dat", "wb"); //Seteo a 0 el archivo original
    fclose(orig);
    if(bk == NULL){
        cout << "No se puede leer el usuarioBK.dat .";
        system("pause");
        return false;
    }
    while(fread(&u, sizeof(Usuario), 1, bk)){
        FILE *f = fopen("datos/usuario.dat", "ab");
        if(f == NULL){
            cout << "No se puede guardar en usuario.";
            system("pause");
            return false;
        }
        fwrite(&u, sizeof(Usuario), 1, f);
        fclose(f);
    }
    fclose(bk);
    return true;
}

bool recProducto(){
    Producto p;
    FILE *bk = fopen("datos/productoBK.dat", "rb");
    FILE *orig = fopen("datos/producto.dat", "wb"); //Seteo a 0 el archivo original
    fclose(orig);
    if(bk == NULL){
        cout << "No se puede leer el productoBK.dat .";
        system("pause");
        return false;
    }
    while(fread(&p, sizeof(Producto), 1, bk)){
        FILE *f = fopen("datos/producto.dat", "ab");
        if(f == NULL){
            cout << "No se puede guardar en producto.";
            system("pause");
            return false;
        }
        fwrite(&p, sizeof(Producto), 1, f);
        fclose(f);
    }
    fclose(bk);
    return true;
}

bool recCategoria(){
    Categoria c;
    FILE *bk = fopen("datos/categoriaBK.dat", "rb");
    FILE *orig = fopen("datos/categoria.dat", "wb"); //Seteo a 0 el archivo original
    fclose(orig);
    if(bk == NULL){
        cout << "No se puede leer el categoriaBK.dat .";
        system("pause");
        return false;
    }
    while(fread(&c, sizeof(Categoria), 1, bk)){
        FILE *f = fopen("datos/categoria.dat", "ab");
        if(f == NULL){
            cout << "No se puede guardar en categoria.";
            system("pause");
            return false;
        }
        fwrite(&c, sizeof(Categoria), 1, f);
        fclose(f);
    }
    fclose(bk);
    return true;
}

bool recMovimiento(){
    Movimiento m;
    FILE *bk = fopen("datos/bitacoraBK.dat", "rb");
    FILE *orig = fopen("datos/bitacora.dat", "wb"); //Seteo a 0 el archivo original
    fclose(orig);
    if(bk == NULL){
        cout << "No se puede leer el bitacoraBK.dat .";
        system("pause");
        return false;
    }
    while(fread(&m, sizeof(Movimiento), 1, bk)){
        FILE *f = fopen("datos/bitacora.dat", "ab");
        if(f == NULL){
            cout << "No se puede guardar en bitacora.";
            system("pause");
            return false;
        }
        fwrite(&m, sizeof(Movimiento), 1, f);
        fclose(f);
    }
    fclose(bk);
    return true;
}



