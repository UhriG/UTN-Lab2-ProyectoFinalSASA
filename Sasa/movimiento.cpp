#include <iostream>
#include <iomanip>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "producto.h"
#include "Fecha.h"
#include "movimiento.h"
#include "login.h"
#include "categoria.h"
#include "carteles.h"

void Movimiento::mostrar(int modo){
    Categoria c;
    int posCat = buscarIDcat(getCategoriaId());
    c.leerDisco(posCat);
    string tmov[2] = {"Egreso","Ingreso"} , movt[2] = {"-","+"};

    if(modo == 1){ // MODO 1 MUESTRA EN LISTA
        int ancho = 15;
        cout << setw(4) << id;
        cout << setw(ancho) << getLogueado();
        cout << setw(ancho) << getProducto();
        cout << setw(ancho) << getMarca();
        cout << setw(10) << c.getNombre();
        cout << setw(1) << movt[getTipoMovimiento()] << setw(6) << getStock();
        cout << setw(11) << tmov[getTipoMovimiento()];
        fechaMov.mostrarFecha(3);
    } else{ //MODO NORMAL MUESTRA EN UNA COLUMNA
        cout << "ID: "<< id << endl;
        cout << "USUARIO: " << getLogueado() << endl;
        cout << "PRODUCTO: "<< getProducto() << endl;
        cout << "MARCA: "<< getMarca() << endl;
        cout << "CATEGORÍA: "<< c.getNombre() << endl;
        cout << "STOCK: "<< getStock() << endl;
        cout << "MOVIMIENTO: " << tmov[getTipoMovimiento()] << endl;
        cout << "FECHA: ";
        fechaMov.mostrarFecha(2);
    }
}

void Movimiento::setLogueado(char *n){
    strcpy(usuarioLogueado,n);
}

void Movimiento::setCategoriaId(int catId){
    categoria_id = catId;
}

void Movimiento::setStock(int stk){
    stock = stk;
}

void Movimiento::setMarca(char *m){
    strcpy(marca, m);
}

void Movimiento::setProducto(char *p){
    strcpy(producto, p);
}

void Movimiento::setTipoMovimiento(int tpMov){
    tipoMovimiento = tpMov;
}


void Movimiento::cargar(Producto p, int tM){
    id = cantMov()+1;

    Login l;
    l.leerUsuario();

    setLogueado(l.getNombre());
    setProducto(p.getNombre());
    setMarca(p.getMarca());
    setCategoriaId(p.getCatId());
    setStock(p.getStock());
    setTipoMovimiento(tM);

    Fecha f;
    f.fechaActual();
    setFecha(f);
}

void  Movimiento::setFecha(Fecha f){
    fechaMov = f;
}

Fecha Movimiento::getFecha(){
    return fechaMov;
}

bool Movimiento::escribirDisco(){
    bool guardo;
    FILE *f = fopen("datos/bitacora.dat", "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(this,sizeof *this, 1, f);
    fclose(f);
    return guardo;
}

int Movimiento::leerDisco(int pos){
    int x;
	FILE *p;
	p=fopen("datos/bitacora.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		return -1;
    }
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

int cantMov(){
    FILE *f;
    f = fopen("datos/bitacora.dat", "rb");
    if(f == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    cant = bytes / sizeof(Movimiento);
    return cant;
}

void movIngreso(){
    cTitulo();
    int pos, id, stock, stockA;
    Producto p;
    cout << "INGRESAR STOCK" << endl;
    cout << "INGRESAR ID PRODUCTO: ";
    while(!(cin >> id)){
        msj(" INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
        cTitulo();
        cout << "INGRESAR STOCK" << endl;
        cout << "INGRESAR ID PRODUCTO: ";
    }
    cout << endl;
    pos = buscarCod(id);
    if(pos!=-1){
		p.leerDisco(pos);
		p.mostrar(2);
		stockA = p.getStock();
		cout << endl;
		cout<<"INGRESE CANTIDAD DE UNIDADES A INGRESAR: ";

        while(!(cin >> stock) || stock <= 0){
            msj("INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS ENTEROS POSTIVOS", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cTitulo();
            p.mostrar(2);
            cout<<"INGRESE CANTIDAD DE UNIDADES A INGRESAR: ";
        }

        stockA += stock;

		p.setStock(stockA);

		if(p.modDisco(pos)==true){
            msj("SE MODIFICO CON ÉXITO", rlutil::WHITE, rlutil::GREEN);
            Movimiento m;
            p.setStock(stock);
            m.cargar(p, 1);
            m.escribirDisco();
		}

    }else{
		msj("NO EXISTE EL PRODUCTO", rlutil::WHITE, rlutil::RED);
		anykey();
    }
}

void movEgreso(){
    cTitulo();
    int pos, id, stock, stockA;
    Producto p;
    cout << "INGRESAR STOCK" << endl;
    cout << "INGRESAR ID PRODUCTO: ";
    while(!(cin >> id)){
        msj(" INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS", rlutil::WHITE, rlutil::RED);
        cin.clear();
        cin.ignore(123, '\n');
        cTitulo();
        cout << "INGRESAR STOCK" << endl;
        cout << "INGRESAR ID PRODUCTO: ";
    }
    cout << endl;
    pos = buscarCod(id);
    if(pos!=-1){
		p.leerDisco(pos);
		p.mostrar(2);
		stockA = p.getStock();
		cout << endl;
		cout<<"INGRESE CANTIDAD DE UNIDADES A INGRESAR: ";
		while(!(cin >> stock) || stock <= 0){
            msj("INGRESO INCORRECTO - SOLO SE ADMITEN NUMEROS ENTEROS POSITIVOS", rlutil::WHITE, rlutil::RED);
            cin.clear();
            cin.ignore(123, '\n');
            cTitulo();
            p.mostrar(2);
            cout<<"INGRESE CANTIDAD DE UNIDADES A INGRESAR: ";
        }
        stockA -= stock;

		p.setStock(stockA);

		if(p.modDisco(pos)==true){
            msj("SE MODIFICO CON ÉXITO", rlutil::WHITE, rlutil::GREEN);
            Movimiento m;
            p.setStock(stock);
            m.cargar(p, 0);
            m.escribirDisco();
		}

    }else{
		msj("NO EXISTE EL PRODUCTO", rlutil::WHITE, rlutil::RED);
		anykey();
    }
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
