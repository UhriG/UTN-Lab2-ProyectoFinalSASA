#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include "usuario.h"
#include "producto.h"
#include "Fecha.h"

class Movimiento
{
    public:

        void cargar();
        void mostrar(int modo);
        void setLogueado(char *n);
        void setStock(int stk);
        void setMarca(char *m);
        void setProducto(char *p);
        void setCategoriaId(int catId);
        void setTipoMovimiento(int tpMov);
        int getTipoMovimiento(){return tipoMovimiento;};
        char *getLogueado(){return usuarioLogueado;};
        int getStock(){return stock;};
        char *getMarca(){return marca;};
        char *getProducto(){return producto;};
        int getCategoriaId(){return categoria_id;};
        Fecha fa;
        bool escribirDisco();
        int leerDisco(int pos);

    private:
        char usuarioLogueado[20];
        char producto[20];
        char marca[20];
        int categoria_id;
        int tipoMovimiento; //0: egreso - 1: ingreso
        int stock;
        Fecha f;
};

extern Movimiento m;

#endif // MOVIMIENTOS_H
