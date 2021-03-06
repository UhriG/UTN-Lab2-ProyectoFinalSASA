#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h> /// para la funcion TIME
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
#include "validaciones.h"

// MENUES PRINCIPAL
void menuPrincipal(){
    bool menu = true;
    int opc;
    while(menu){
        cMenuPrincipal();
        while(!(cin >> opc)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
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
            default: msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
                break;
        }
    }
}

void menuUsuario(){
    bool menu = true;
    int opc;
    while(menu){
        cMenu(1); // CARTEL MENU GENERAL ( 1-USUARIO )
        while(!(cin >> opc)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenu(1); // CARTEL MENU GENERAL ( 1-USUARIO )
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
                msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

void menuProducto(){
    bool menu = true;
    int opc;
    while(menu){
        cMenu(2); // CARTEL MENU GENERAL ( 2-PRODUCTO )
        while(!(cin >> opc)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenu(2); // CARTEL MENU GENERAL ( 2-PRODUCTO )
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
                msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            break;
        }
    }
}

void menuCategoria(){
    bool menu = true;
    int opc;
    while(menu){
        cMenu(3); // CARTEL MENU GENERAL ( 3-CATEGOR�A )
        while(!(cin >> opc)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenu(3); // CARTEL MENU GENERAL ( 3-CATEGOR�A )
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
                msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
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
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
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
                msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
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
		cout << "NOMBRE: 1 \tCONTRASE�A: 2 \tPERFIL: 3 \tSALIR: 5" << endl;
		cout << "ELEGIR UNA OPCI�N: ";
		int opc;
		while(!(cin >> opc)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        switch(opc){
            case 1:
                char n[20];
                cout << "INGRESAR NOMBRE: ";
                validarNombre(n);
                u.setNombre(n);
            break;
            case 2:
                char p[10];
                cout << "INGRESAR PASSWORD: ";
                validarNombre(p);
                u.setPassword(p);
            break;
            case 3:
                int per;
                cout << "INGRESAR PERFIL: ";
                while(!(cin >> per)){
                    msj("OPCI�N INCORRECTA: 1 - ADMIN \t2 - SUPERVISOR \t3 - OPERADOR", rlutil::WHITE, rlutil::RED);
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                u.setPerfil(per);
            break;
            case 5:
                return;
        }
		if(u.modDisco(pos)==true){
            msj("SE MODIFICO CON �XITO", rlutil::WHITE, rlutil::GREEN);
		}
    }else{
		msj("NO EXISTE EL USUARIO", rlutil::WHITE, rlutil::RED);
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
            cout << "\nIngrese una opci�n v�lida!" << endl << " >";
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
        cListar(cant, 1,0,1); // SIEMPRE PASAR CANT
        cTabla(1); // MODO 1 USUARIO
        for(pos; pos < usuarios; pos++){
            u.leerDisco(pos);
            if(u.getId() != idanterior){
                u.mostrar();
                cLinea(120);
            }
            idanterior = u.getId();
        }
        cout << "*PAGINA: " << hoja << " / " << paginas << endl;
        cout << endl;
        cout << "0- SALIR | INDIQUE P�GINA: > ";
        while(!(cin >> resp)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
            msj("NO HAY M�S DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
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
        msj("SE CREO PRODUCTO CON �XITO", rlutil::WHITE, rlutil::GREEN);
        Movimiento m;
        m.cargar(p, 1);//SI EL PRODUCTO SE CREA CON EXITO SE GUARDA EL MOVIMIENTO EN LA BITACORA
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

		cout << "PRODUCTO A MODIFICAR CATEGOR�A, PRESIONAR UNA TECLA." << endl;
		anykey();

		listarCategoriaSimple();
        cout << "> CATEGOR�A ID: ";
        p.setCategoria(validarCategoria());

		/*cout<<"INGRESE NUEVO STOCK: ";
		while(!(cin >> stock)){
            msj("INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS ENTEROS", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
		p.setStock(stock);*/
		if(p.modDisco(pos)==true){
            msj("SE MODIFICO CON �XITO", rlutil::WHITE, rlutil::GREEN);
		}

    }else{
		msj("NO EXISTE EL PRODUCTO", rlutil::WHITE, rlutil::RED);
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
            cout << "\nIngrese una opci�n v�lida!" << endl << " >";
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
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
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
                msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
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
        msj("SE CREO CORRECTAMENTE LA CATEGOR�A", rlutil::WHITE, rlutil::GREEN);
    }else{
        msj("ERROR AL CREAR CATEGOR�A", rlutil::WHITE, rlutil::GREEN);
    }
}


void modificarCategoria(){
    cTitulo();
    Categoria c;
    int pos, id;
    cout << "*MODIFICAR CATEGOR�A" << endl;
    cout << "INGRESAR ID CATEGOR�A: ";

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
		cout << "ELEGIR UNA OPCI�N: ";
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
                validarNombre(n);
                c.setNombre(n);
            break;
            case 5:
                return;
        }
		if(c.modDisco(pos)==true){
            msj("SE MODIFICO CON �XITO", rlutil::WHITE, rlutil::GREEN);
		}
    }else{
		msj("NO EXISTE LA CATEGOR�A", rlutil::WHITE, rlutil::RED);
    }
}


void eliminarCategoria(){
    cTitulo();
    int id, pos;
    char conf;
    cout << "*ELIMINAR CATEGOR�A" << endl;
    cout << "INGRESAR ID CATEGOR�A: ";
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
            cout << "\nIngrese una opci�n v�lida!" << endl << " >";
            conf = getche();
        }
        if(conf == 's' || conf == 'S'){
            int baja = 0;
            c.setEstado(baja);
            if(c.modDisco(pos)==true){
                msj("SE ELIMINO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
            }
        }else{
            msj("NO SE ELIMINO LA CATEGOR�A", rlutil::WHITE, rlutil::RED);
        }
    }else{
		msj("NO EXISTE LA CATEGOR�A", rlutil::WHITE, rlutil::RED);
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
        cListar(cant, 3,0,1); // SIEMPRE PASAR CANT
        cTabla(3); // MODO 3 CATEGOR�A
        for(pos; pos < categorias; pos++){
            c.leerDisco(pos);
            if(c.getId() != idanterior){
                c.mostrar();
                cLinea(120);
            }
            idanterior = c.getId();
        }
        cout << "*PAGINA: " << hoja << " / " << paginas << endl;
        cout << endl;
        cout << "0- SALIR | INDIQUE PAGINA: > ";
        while(!(cin >> resp)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
            msj("NO HAY M�S DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
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
    srand(time(NULL));
    int numR = rand(), conf=0;
    cTitulo();
    cout << "INGRESE EL SIGUIENTE PIN: " << numR << endl;
    cout << "> ";
    cin >> conf;
    if(conf == numR){
        cCargando();
        int guardo =0;
        guardo += copiaUsuario();
        guardo += copiaProducto();
        guardo += copiaCategoria();
        guardo += copiaMovimiento();
        if(guardo == 4){
            msj("SE CREO COPIA DE SEGURIDAD",rlutil::WHITE, rlutil::GREEN);
        } else {
            msj("ERROR AL CREAR COPIA DE SEGURIDAD",rlutil::WHITE, rlutil::RED);
        }
    }else{msj("PIN INCORRECTO", rlutil::WHITE, rlutil::RED);}
}

void recuperarCopia(){
    srand(time(NULL));
    int numR = rand(), conf=0;
    cTitulo();
    cout << "INGRESE EL SIGUIENTE PIN: " << numR << endl;
    cout << "> ";
    cin >> conf;
    if(conf == numR){
        cCargando();
        int rec = 0;
        rec += recUsuario();
        rec += recProducto();
        rec += recCategoria();
        rec += recMovimiento();
        if(rec == 4){
            msj("SE RECUPERO CORRECTAMENTE",rlutil::WHITE, rlutil::GREEN);
        } else {
            msj("ERROR AL RECUPERAR COPIA DE SEGURIDAD",rlutil::WHITE, rlutil::RED);
        }
    }else{msj("PIN INCORRECTO", rlutil::WHITE, rlutil::RED);}
}

void exportarDatos(){
    srand(time(NULL));
    int numR = rand(), conf=0;
    cTitulo();
    cout << "INGRESE EL SIGUIENTE PIN: " << numR << endl;
    cout << "> ";
    cin >> conf;
    if(conf == numR){
        cCargando();
        int exp =0;
        exp += expCsvUsuario();
        exp += expCsvProducto();
        exp += expCsvCategoria();
        exp += expCsvMovimiento();
        if(exp == 4){
            msj("SE EXPORTARON LOS DATOS A CSV",rlutil::WHITE, rlutil::GREEN);
        } else {
            msj("ERROR AL EXPORTARON DATOS",rlutil::WHITE, rlutil::RED);
        }
    }else{msj("PIN INCORRECTO", rlutil::WHITE, rlutil::RED);}
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
        cListar(cant, 2,1); // SIEMPRE PASAR CANT
        cTabla(2); // MODO 2 PRODUCTO
        for(pos; pos < productos; pos++){
            p.leerDisco(pos);
            if(p.getId() != idanterior){
                p.mostrar();
                cLinea(120);
            }
            idanterior = p.getId();
        }
        cout << "*PAGINA: " << hoja << " / " << paginas << endl;
        cout << endl;
        cout << "0- SALIR | INDIQUE P�GINA: > ";
        while(!(cin >> resp)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
                msj("NO HAY M�S DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
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
        cListar(cant, 2,2); // SIEMPRE PASAR CANT
        cTabla(2); // MODO 2 PRODUCTO
        for(pos; pos > productos; pos--){
            p.leerDisco(pos);
            if(p.getId() != idanterior && p.getId() != 0){
                p.mostrar();
                cLinea(120);
            }
            idanterior = p.getId();
        }
        cout << "PAGINA: " << hoja << " / " << paginas << endl;
        cout << "0- SALIR | INDIQUE P�GINA: > ";
        while(!(cin >> resp)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
                msj("NO HAY M�S DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
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
    cLinea(120);
    msj("PRESIONAR UNA TECLA", rlutil::WHITE, rlutil::GREEN);
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
        cListar(cant,2,0,1);
        cTabla(2); // MODO 2 PRODUCTO
        for(pos; pos < productos; pos++){
            p.leerDisco(pos);
            if(p.getId() != idanterior){
                p.mostrar();
                cLinea(120);
            }
            idanterior = p.getId();
        }
        cout << "PAGINA: " << hoja << " / " << paginas << endl;
        cout << "0- SALIR | INDIQUE P�GINA: > ";
        while(!(cin >> resp)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
                msj("NO HAY M�S DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            pos = 5 *(hoja-1);
            productos = pos + 5;
        }
    }
}

// MEN� BIT�CORA
void menuMovimientos(){
    bool menu = true;
    int opc;
    while(menu){
        cMenuMovimientos(); // CARTEL MENU GENERAL ( USUARIO )
        while(!(cin >> opc)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenuMovimientos(); // CARTEL MENU GENERAL ( USUARIO )
        }

        switch(opc){
            case 1:
                movIngreso();
            break;
            case 2:
                movEgreso();
            break;
            case 3:
                listarBitacora();
            break;
            case 4:
                menu = false;
            break;
            default:
                msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
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
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cMenuBitacora(); // CARTEL MENU GENERAL ( USUARIO )
        }

        switch(opc){
            case 1:
                listarMovimientosTodos();
            break;
            case 2:
                listarMovimientosPorUsuario();
            break;
            case 3:
                listarMovimientosPorProducto();
            break;
            case 4:
               listarMovimientosPorFecha();
            break;
            case 5:
                menu = false;
            break;
            default:
                msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
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
        cListar(cant,4,0,1);
        cTabla(4); // MODO 4 BITACORA
        for(pos; pos < movimientos; pos++){
            m.leerDisco(pos);
            if(m.getId() != idanterior && m.getId() != 0){
                m.mostrar(1);
                cLinea(120);
            }
            idanterior = m.getId();
        }
        cout << "PAGINA: " << hoja << " / " << paginas << endl;
        cout << "0- SALIR | INDIQUE P�GINA: > ";
        while(!(cin >> resp)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
                msj("NO HAY M�S DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            pos = 5 *(hoja-1);
            movimientos = pos + 5;
        }
    }
}

void listarMovimientosPorUsuario(){
    cTitulo();
    cout << left;
    cout << "INGRESAR NOMBRE DE USUARIO: ";
    char nombre[15];
    while(!(cin >> nombre)){
        msj("INGRESO INCORRECTO - SOLO SE ADMITEN LETRAS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }

    Movimiento m;
    int idanterior = -1, hoja=1, resp=1;
    int cant = cantMovNombre(nombre,1), pos = 0, movimientos = 5, paginas;
    if(cant % movimientos == 0){paginas = cant / movimientos;}
    else{paginas = (cant / movimientos)+1;}

    int mov[cant]={};
    vecMovimiento(mov,cant,nombre,1);

    while(resp != 0){
        cTitulo();
        cListar(cant,4,1,1);
        cTabla(4); // MODO 4 BITACORA
        for(pos; pos < movimientos; pos++){
            m.leerDisco(mov[pos]);
            if(strcmp(nombre,m.getLogueado())==0 && m.getId() != idanterior && m.getId() != 0){
                m.mostrar(1);
                cLinea(120);
            }
            idanterior = m.getId();
        }
        cout << "PAGINA: " << hoja << " / " << paginas << endl;
        cout << "0- SALIR | INDIQUE P�GINA: > ";
        while(!(cin >> resp)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
                msj("NO HAY M�S DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            pos = 5 *(hoja-1);
            movimientos = pos + 5;
        }
    }
}

void listarMovimientosPorProducto(){
    cTitulo();
    cout << left;
    cout << "INGRESAR NOMBRE DE PRODUCTO: ";
    char nombre[15];
    while(!(cin >> nombre)){
        msj("INGRESO INCORRECTO - SOLO SE ADMITEN LETRAS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }

    Movimiento m;
    int idanterior = -1, hoja=1, resp=1;
    int cant = cantMovNombre(nombre,2), pos = 0, movimientos = 5, paginas;
    if(cant % movimientos == 0){paginas = cant / movimientos;}
    else{paginas = (cant / movimientos)+1;}

    int mov[cant]={};
    vecMovimiento(mov,cant,nombre,2);

    while(resp != 0){
        cTitulo();
        cListar(cant,4,2,1);
        cTabla(4); // MODO 4 BITACORA
        for(pos; pos < movimientos; pos++){
            m.leerDisco(mov[pos]);
            if(strcmp(nombre,m.getProducto())==0 && m.getId() != idanterior && m.getId() != 0){
                m.mostrar(1);
                cLinea(120);
            }
            idanterior = m.getId();
        }
        cout << "PAGINA: " << hoja << " / " << paginas << endl;
        cout << "0- SALIR | INDIQUE P�GINA: > ";
        while(!(cin >> resp)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
                msj("NO HAY M�S DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            pos = 5 *(hoja-1);
            movimientos = pos + 5;
        }
    }
}

void listarMovimientosPorFecha(){
    cTitulo();
    // VARIOS FILTROS 1- D�A ESPECIF�CO 2- MES Y A�O 3- A�O
    int modo, fechas[3]={};
    cout << left;
    cListarMovFecha();
    cout << "INGRESAR OPCI�N A LISTAR: ";
    while(!(cin >> modo)){
        msj("INGRESO INCORRECTO - SOLO SE ADMITEN N�MEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }
    modoListarFecha(modo,fechas);
    cTitulo();
    Movimiento m;
    int idanterior = -1, hoja=1, resp=1;
    int cant = cantMovFecha(fechas,modo), pos = 0, movimientos = 5, paginas;
    if(cant % movimientos == 0){paginas = cant / movimientos;}
    else{paginas = (cant / movimientos)+1;}

    int mov[cant]={};
    vecMovimientoFecha(mov,cant,fechas,modo);

    cListar(cant,4,3,1);
    while(resp != 0){
        cTitulo();
        cListar(cant,4,3,1);
        cTabla(4); // MODO 4 BITACORA
        for(pos; pos < movimientos; pos++){
            m.leerDisco(mov[pos]);
            if(m.getId() != idanterior && m.getId() != 0){
                m.mostrar(1);
                cLinea(120);
            }
            idanterior = m.getId();
        }
        cout << "PAGINA: " << hoja << " / " << paginas << endl;
        cout << "0- SALIR | INDIQUE P�GINA: > ";
        while(!(cin >> resp)){
            msj("OPCI�N INCORRECTA", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
        }
        hoja = resp;
        if(pos == cant || hoja > paginas){
                msj("NO HAY M�S DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            pos = 5 *(hoja-1);
            movimientos = pos + 5;
        }
    }
}



