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
        cout << "2) MODIFICAR USUARIO" << endl;
        cout << "3) ELIMINAR USUARIO" << endl;
        cout << "4) LISTAR USUARIOS" << endl;
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
                modificarUsuario();
            break;
            case 3:
                eliminarUsuario();
            break;
            case 4:
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

void modificarUsuario(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    Usuario u;
    int pos, id;
    cout << "*MODIFICAR USUARIO" << endl;
    cout << "INGRESAR ID USUARIO: ";
    cin >> id;
    cout << endl;
    pos = buscarID(id);
    if(pos!=-1){
		u.leerDisco(pos);
		u.mostrar(2);
		cout << endl;
		cout << "1- NOMBRE 2- CONTRASEÑA 3- PERFIL" << endl;
		cout << "ELEGIR UNA OPCIÓN: ";
		int opc;
		cin >> opc;
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
                cin >> per;
                u.setPerfil(per);
            break;
            case 0:
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
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    int id, pos;
    char resp[2];
    cout << "*ELIMINAR USUARIO" << endl;
    cout << "INGRESAR ID USUARIO: ";
    cin >> id;
    cout << endl;
    pos = buscarID(id);
    Usuario u;
    if(pos!=-1){
        int ancho = 10;
        u.leerDisco(pos);
        u.mostrar(2);
        cout << endl;
        cout << "ELIMINAR? (SI/NO): ";
        cin >> resp;
        if(resp == "SI" || resp == "si"){
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
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "LISTADO DE TODOS LOS USUARIOS" << endl;
    cout << endl;
    cout << left;

    Usuario u;
	int pos=0;

	int ancho = 15;
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
}

// SUB MENU PRODUCTO

void crearProducto(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    Producto p;
    p.cargar();
    if(p.escribirDisco()==true){
        msj("SE CREO PRODUCTO CON ÉXITO", rlutil::WHITE, rlutil::GREEN);
    } else{
        msj("ERROR AL CREAR PRODUCTO", rlutil::WHITE, rlutil::RED);
    }

}

void modificarProducto(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    int pos, id, stock;
    Producto p;
    cout << "*MODIFICAR PRODUCTO" << endl;
    cout << "INGRESAR ID PRODUCTO: ";
    cin >> id;
    cout << endl;
    pos = buscarCod(id);
    if(pos!=-1){
		p.leerDisco(pos);
		p.mostrar(2);
		cout << endl;
		cout<<"INGRESE NUEVO STOCK: ";
		cin>>stock;
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
    cout << endl;
    pos = buscarCod(id);
    Producto p;
    if(pos!=-1){
        int ancho = 10;
        p.leerDisco(pos);
        p.mostrar(2);
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
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
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
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
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
    int idanterior = -1;;
    int resp=1, i=0;
    while(i<paginas && resp != 0){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << left;
        cout << "*LISTAR TODOS LOS PRODUCTOS POR COD ASCENDENTE" << endl;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "TOTAL DE PRODUCTOS: " << cant << endl;
        cout << "-----------------------------" << endl;
        int ancho = 10;
        cout << setw(4) << "ID" << setw(20) << "NOMBRE" << setw(20) << "MARCA" /*<< setw(ancho) << "CATEGORÍA"*/ << setw(ancho) << "ESTADO" << setw(5) << "STOCK";
        cout << endl << "----------------------------------------------------------------------------"<< endl;
        for(pos; pos < productos; pos++){
            p.leerDisco(pos);
            if(p.getEstado()==1 && p.getId() != idanterior){
                p.mostrar();
                cout << endl << "----------------------------------------------------------------------------"<< endl;
            }
            idanterior = p.getId();
        }
        cout << "PAGINAS: " << paginas << endl;
        cout << "0- SALIR 1- PAGINA SIGUIENTE: > ";
        cin >> resp;
        if(pos == cant){
                msj("NO HAY MÁS DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            productos+=5;
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
    int idanterior = -1;;
    int resp=1, i=0;
    while(i<paginas && resp != 0){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << left;
        cout << "*LISTAR TODOS LOS PRODUCTOS POR COD DESCENDENTE" << endl;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "TOTAL DE PRODUCTOS: " << cant << endl;
        cout << "-----------------------------" << endl;
        int ancho = 10;
        cout << setw(4) << "ID" << setw(20) << "NOMBRE" << setw(20) << "MARCA" /*<< setw(ancho) << "CATEGORÍA"*/ << setw(ancho) << "ESTADO" << setw(5) << "STOCK";
        cout << endl << "----------------------------------------------------------------------------"<< endl;
        for(pos; pos < productos; pos++){
            p.leerDisco(pos);
            if(p.getEstado()==1 && p.getId() != idanterior){
                p.mostrar();
                cout << endl << "----------------------------------------------------------------------------"<< endl;
            }
            idanterior = p.getId();
        }
        cout << "PAGINAS: " << paginas << endl;
        cout << "0- SALIR 1- PAGINA SIGUIENTE: > ";
        cin >> resp;
        if(pos == cant){
                msj("NO HAY MÁS DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            productos+=5;
        }
    }
}

void listarProductoInd(){
    cls();
    title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
    gotoxy(1, 5);
    cout << "LISTAR PRODUCTO INDIVIDUAL" << endl;
    cout << endl;
    cout << left;
    cout << "INGRESAR ID: ";
    int cod, pos;
    cin >> cod;
    pos=buscarCod(cod);
    Producto p;
    p.leerDisco(pos);
	int ancho = 10;
    cout << setw(5) << "ID" << setw(ancho) << "NOMBRE" << setw(ancho) << "MARCA" << setw(10) << "CATEGORÍA" << setw(ancho) << "ESTADO" << setw(4) << "STOCK";
	cout << endl << "----------------------------------------------------------------------------"<< endl;
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
    int idanterior = -1;;
    int resp=1, i=0;
    while(i<paginas && resp != 0){
        cls();
        title("SISTEMA ADMINISTRACION DE STOCK ALMACÉN");
        gotoxy(1, 5);
        cout << left;
        cout << "*LISTAR TODOS LOS PRODUCTOS" << endl;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "TOTAL DE PRODUCTOS: " << cant << endl;
        cout << "-----------------------------" << endl;
        int ancho = 10;
        cout << setw(4) << "ID" << setw(20) << "NOMBRE" << setw(20) << "MARCA" /*<< setw(ancho) << "CATEGORÍA"*/ << setw(ancho) << "ESTADO" << setw(5) << "STOCK";
        cout << endl << "----------------------------------------------------------------------------"<< endl;
        for(pos; pos < productos; pos++){
            p.leerDisco(pos);
            if(p.getEstado()==1 && p.getId() != idanterior){
                p.mostrar();
                cout << endl << "----------------------------------------------------------------------------"<< endl;
            }
            idanterior = p.getId();
        }
        cout << "PAGINAS: " << paginas << endl;
        cout << "0- SALIR 1- PAGINA SIGUIENTE: > ";
        cin >> resp;
        if(pos == cant){
                msj("NO HAY MÁS DATOS QUE MOSTRAR", rlutil::WHITE, rlutil::MAGENTA);
                resp = 0;
            }
        if(resp != 0){
            productos+=5;
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

