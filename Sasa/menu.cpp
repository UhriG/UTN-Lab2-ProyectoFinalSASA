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
            case 5:
                menu = false;
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
                crearUsuario();
            break;
            case 2:
                modificarUsuario();
            break;
            case 3:
                eliminarUsuario();
            break;
            case 4:
                listarUsuarios();
            break;
            case 5:
                menu = false;
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
                modificarProducto();
            break;
            case 3:
                eliminarProducto();
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
            cout << "\nIngrese una opcion valida!" << endl << " >";
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
    cTitulo();
    cout << "LISTADO DE TODOS LOS USUARIOS" << endl;
    cout << endl;
    cout << left;

    Usuario u;
	int pos=0;
    cTabla(1); // MODO 1 USUARIO
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
}

// SUB MENU PRODUCTO

void crearProducto(){
    cTitulo();
    Producto p;
    p.cargar();
    if(p.escribirDisco()==true){
        msj("SE CREO PRODUCTO CON ÉXITO", rlutil::WHITE, rlutil::GREEN);
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
            cout << "\nIngrese una opcion valida!" << endl << " >";
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
    cTitulo();
    string nombre;
    int id;
    cout << "*MODIFICAR CATEGORÍA" << endl;
    cout << "INGRESAR LOS SIGUIENTES DATOS " << endl;
    cout << "ID CATEGORÍA: " << endl;
    while(!(cin >> id)){
        msj("INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }
    //funcion buscar id
    cout << "INGRESAR NOMBRE NUEVO: " << endl;
    cin >> nombre;
    cout << endl;
    msj("SE CREO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
}

void eliminarCategoria(){
    cTitulo();
    int id;
    char conf;
    bool estado = true;
    cout << "*ELIMINAR CATEGORÍA" << endl;
    cout << "INGRESAR ID CATEGORÍA" << endl;
    while(!(cin >> id)){
        msj("INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << "ELIMINAR? (SI/NO): " << endl;
    conf = getche();
    while(conf!='S' && conf!='s' && conf!='N' && conf!='n'){
        cout << "\nIngrese una opcion valida!" << endl << " >";
        conf = getche();
    }
    if(conf == 'S' || conf == 's'){
        estado = false;
        msj("SE ELIMINO CORRECTAMENTE", rlutil::WHITE, rlutil::GREEN);
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
    if(guardo > 0){
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
    if(rec > 0){
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

void listarProductoPorCodDes(){
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
