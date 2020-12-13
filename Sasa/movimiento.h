#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include "usuario.h"
#include "producto.h"
#include "Fecha.h"

class Movimiento
{
    private:
        int id;
        char usuarioLogueado[20];
        char producto[20];
        char marca[20];
        int categoria_id;
        int tipoMovimiento; //0: egreso - 1: ingreso
        int stock;
        Fecha fechaMov;
    public:
        void cargar(Producto, int tM);
        void mostrar(int modo);
        void setLogueado(char *n);
        void setStock(int stk);
        void setMarca(char *m);
        void setProducto(char *p);
        void setCategoriaId(int catId);
        void setTipoMovimiento(int tpMov);
        void setFecha(Fecha);
        Fecha getFecha();
        int getId(){return id;};
        int getTipoMovimiento(){return tipoMovimiento;};
        char *getLogueado(){return usuarioLogueado;};
        int getStock(){return stock;};
        char *getMarca(){return marca;};
        char *getProducto(){return producto;};
        int getCategoriaId(){return categoria_id;};
        bool escribirDisco();
        int leerDisco(int pos);
        void eliminarTemp();
};

int cantMov();
int cantMovNombre(char *nombre, int modo);
void movIngreso();
void movEgreso();
int buscarMovNombre(char *nombreB, int modo);
bool copiaMovimiento(); // crea bk de bitacora.dat
bool recMovimiento(); // recupera bk de bitacora.dat
int modoListarFecha(int modo, int *fechas); // Lista las opciones desde la memoria
bool expCsvMovimiento(); // // exporta datos a csv
void vecMovimiento(int *vec, int cant, char *nombre, int modo);
#endif // MOVIMIENTOS_H
